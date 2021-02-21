#include <iostream>
using namespace std;

// AVL树结点结构
template<class T>
struct AVLTreeNode
{
	AVLTreeNode<T>* left;
	AVLTreeNode<T>* right;
	AVLTreeNode<T>* parent;
	T data;
	int _bf; //表示该结点的平衡因子

	AVLTreeNode(const T& x = T()) :left(nullptr), right(nullptr), parent(nullptr), data(x), _bf(0){}
};


// 假设：AVL树中的值是唯一的
template<class T>
class AVLTree
{
	typedef AVLTreeNode<T> Node;
public:
	AVLTree() : _root(nullptr){}
	~AVLTree(){ Destroy(_root); }
	bool insert(const T& data) // 保证元素值不重复
	{
		// 1. 按照二叉搜索树规则插入新节点
		// 1.1 树为空
		if (nullptr == _root)
		{
			_root = new Node(data);
			return true;
		}

		// 1.2 树不为空
		// 1.2.1 寻找二叉搜索树的插入位置，并保存其双亲
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			parent = cur; //保存父节点
			if (data < cur->data)
				cur = cur->left;
			else if (data > cur->data)
				cur = cur->right;
			else
				return false;
		}

		// 1.2.2 插入结点
		cur = new Node(data);
		if (data < parent->data)
			parent->left = cur;
		else
			parent->right = cur;

		cur->parent = parent;

		// 2. 新节点插入后，一直向上调整父节点平衡因子
		while (parent)
		{
			// 2.1 更新父节点
			if (cur == parent->left)  // parent右子树高度没有变，而左子树高度增加了一层
				parent->_bf--;
			else
				parent->_bf++;

			// 2.2 向上迭代
			if (0 == parent->_bf)
				break;
			else if (-1 == parent->_bf || 1 == parent->_bf)
			{
				// 以parent为根的子树的高度增加了一层，继续向上一层更新
				cur = parent;
				parent = cur->parent;
			}
			else
			{
				//  parent的平衡因子为 2或-2，需要对parent为根的二叉树进行旋转处理
				//	parent与cur的_bf的正负：同号用单旋，异号用双旋
				if (2 == parent->_bf) // 右子树高
				{
					if (1 == cur->_bf) // 左单旋
						// 左单旋
						LeftRotation(parent);
					else  // 右左双旋
						Right_Left_DoubleRotation(parent);
				}
				else // 左子树高
				{
					//parent的平衡因子为-2
					if (-1 == cur->_bf) //右单旋
						RightRotation(parent);
					else  // 左右双旋
						Left_Right_DoubleRotation(parent);
				}
				break;
			}// end if - else if - else
		} // end while
		return true;
	}
	void InOrder()
	{
		InOrder(_root);
		cout << endl;
	}
	bool IsBalanceTree()
	{
		return _IsBalanceTree(_root);
	}

private:
	AVLTreeNode<T>* _root;

	void InOrder(Node* root)
	{
		if (root)
		{
			InOrder(root->left);
			cout << root->data << " ";
			InOrder(root->right);
		}
	}
	void Destroy(Node*& root) // 二叉树后序遍历规则：后序销毁二叉树
	{
		if (root)
		{
			Destroy(root->left);
			Destroy(root->right);
			delete root;
			root = nullptr;
		}
	}
	void RightRotation(Node* parent) // 右单旋：新节点插入到较高左子树的左子树上
	{
		Node* subL = parent->left; // 父节点的左孩子节点
		Node* subLR = subL->right; // 父节点的左孩子节点的右孩子节点

		/*
		右单旋：
		1. 父节点的左指针指向subLR，实现将parent的右子树下降一层
		2. subL的右指针指向parent，实现将parent的左子树上升一层
		*/

		// 右单旋 1
		parent->left = subLR;
		if (subLR) // 避免左单支的场景：subLR是nullptr
			subLR->parent = parent;

		// 右单旋 2
		subL->right = parent;
		// 因为parent可能是某个节点的子树，因此在更新parent的双亲前必须先将其之前的双亲记录
		Node* pparent = parent->parent; // 可能parent是非根结点，需要记录parent的父结点
		parent->parent = subL;
		subL->parent = pparent;

		// parent可能是根节点：需要修改_root
		// parent也可能是一棵子树: 需要修改pparent的左/右指针域的指向
		if (nullptr == pparent) // 若是根结点，修改树的root指向
		{
			// 旋转之前parent是根节点
			_root = subL;
		}
		else // 若是非根结点，修改parent父节点的指针指向
		{
			// parent是某个节点的子树
			if (parent == pparent->left) // 判断parent是父节点的哪个孩子节点
				pparent->left = subL;
			else
				pparent->right = subL;
		}
		// 将parent和subL的平衡因子更新为0
		parent->_bf = subL->_bf = 0;
	}
	void LeftRotation(Node* parent)
	{
		Node* subR = parent->right; // 父节点的右孩子节点
		Node* subRL = subR->left; // 父节点的右孩子节点的左孩子节点

		/*
		左单旋：
		1. parent节点的右指针指向subRL，实现将parent的右子树下降一层
		2. subR的左指针指向parent，实现将parent的左子树上升一层
		*/
		// 左单旋 1
		parent->right = subRL;
		if (subRL) // 避免：右单支, 防止subRL是nullptr
			subRL->parent = parent;
		// 左单旋 2
		subR->left = parent;
		Node* pparent = parent->parent; // 需要更新parent和subR的双亲
		parent->parent = subR;
		subR->parent = pparent;

		// 旋转之前：parent可能是根结点，可能是非根结点
		// parent是根节点：修改_root的指向
		// parent是子树：修改原parent左||右指针域的指向
		if (nullptr == pparent) // 若是根结点，修改树的root指向
		{
			_root = subR;
		}
		else  // 若是非根结点，修改parent父节点的指针指向
		{
			if (parent == pparent->left)  // 判断parent是父节点的哪个孩子节点
				pparent->left = subR;
			else
				pparent->right = subR;
		}

		// 将parent和subR的平衡因子更新为0
		parent->_bf = subR->_bf = 0;
	}
	void Left_Right_DoubleRotation(Node* parent)
	{
		// 旋转之前必须要保存subLR, 因为旋转完成之后需要根据subLR之前平衡因的情况来跟新旋转完成后
		// 部分节点的平衡因子
		Node* subL = parent->left;
		Node* subLR = subL->right;
		int bf = subLR->_bf;

		LeftRotation(parent->left);
		RightRotation(parent);

		if (1 == bf)
			subL->_bf = -1;
		else if (-1 == bf)
			parent->_bf = 1;
	}
	void Right_Left_DoubleRotation(Node* parent)
	{
		Node* subR = parent->right;
		Node* subRL = subR->left;
		int bf = subRL->_bf;

		RightRotation(parent->right);
		LeftRotation(parent);

		if (1 == bf)
			parent->_bf = -1;
		else if (-1 == bf)
			subR->_bf = 1;
	}
	int _Height(Node* root)
	{
		if (nullptr == root)	// 函数出口：遍历到nullptr结点
			return 0;

		int leftHeight = _Height(root->left);	// 记录左子树的高度
		int rightHegiht = _Height(root->right);	// 记录右子树的高度
		return leftHeight > rightHegiht ? leftHeight + 1 : rightHegiht + 1;	// 返回最高的子树加上本节点的个数
	}
	bool _IsBalanceTree(Node* root)
	{
		// 空树也是AVL树
		if (nullptr == root)
			return true;

		// 计算root根节点的平衡因子是否正确
		int leftHeight = _Height(root->left);
		int rightHegiht = _Height(root->right);
		int bf = rightHegiht - leftHeight;
		if (abs(bf) > 1 || bf != root->_bf)
		{
			cout << root->data << " 节点的平衡因子有问题" << endl;
			return false;
		}

		return _IsBalanceTree(root->left) && _IsBalanceTree(root->right);
	}
};

void testAVL()
{
	int array[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	AVLTree<int> t;
	for (auto e : array)
		t.insert(e);
	t.InOrder();
}

int main()
{
	testAVL();

	system("pause");
	return 0;
}