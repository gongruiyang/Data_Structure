#include <iostream>
using namespace std;

template<class T>
struct AVLTreeNode
{
	AVLTreeNode<T>* left;
	AVLTreeNode<T>* right;
	AVLTreeNode<T>* parent;
	T _data;
	int _bf; //表示该结点的平衡因子

	AVLTreeNode(const T& x = T()) :left(nullptr), right(nullptr), parent(nullptr), _data(x), _bf(0){}
};

template<class T>
class AVLTree
{
	typedef AVLTreeNode<T> Node;
public:
	AVLTree() :_root(nullptr){}
	~AVLTree(){ DestroyTree(_root); }
	bool insert(const T& data)	// 保证元素值不重复
	{
		// 1. 按照二叉搜索树规则插入新节点
		// 1.1 树为空
		if (_root == nullptr)	
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
			parent = cur;	//保存父节点
			if (data < cur->_data)
				cur = cur->left;
			else if (data > cur->_data)
				cur = cur->right;
			else
				return false;
		}
		// 1.2.2 插入结点
		cur = new Node(data);
		if (data < parent->_data)
			parent->left = cur;
		else
			parent->right = cur;
		cur->parent = parent;

		// 2. 新节点插入后，一直向上调整父节点平衡因子
		while (parent)
		{
			// 2.1 更新父节点
			if (cur == parent->left)
				(parent->_bf)--;
			else
				(parent->_bf)++;

			// 2.2 向上找爸爸
			if (parent->_bf == 0)
				break;
			else if (parent->_bf == -1 || parent->_bf == 1)
			{
				// 以parent为根的子树的高度增加了一层，继续向上一层更新
				cur = parent;
				parent = cur->parent;
			}
			else
			{
				//  parent的平衡因子为 2或-2，需要对parent为根的二叉树进行旋转处理
				//	parent与cur的_bf的正负：同号用单旋，异号用双旋
				if (parent->_bf == 2)	// 右子树高
				{
					if (cur->_bf == 1)	// 左单旋
						LeftRotation(parent);
					else			// 右左双旋
						Right_Left_DoubleRotation(parent);
				}
				else	// 左子树高
				{
					if (cur->_bf == -1)	//右单旋
						RightRotation(parent);
					else	// 左右双旋
						Left_Right_DoubleRotation(parent);
				} 
				break;
			}
		} // end while
		return true;
	}
	void InOrder()
	{
		InOrder(_root);
		cout << endl;
	}

private:
	Node* _root;

	void RightRotation(Node* parent)	// 右单旋：新节点插入到较高左子树的左子树上
	{
		Node* subL = parent->left;	// 父节点的左孩子节点
		Node* subLR = subL->right;	// 父节点的左孩子节点的右孩子节点

		Node* pparent = parent->parent; // 可能parent是非根结点，需要记录parent的父结点
		
		/*
		右单旋：
			1. 父节点的左指针指向subLR，实现将parent的右子树下降一层
			2. subL的右指针指向parent，实现将parent的左子树上升一层
		*/
		// 右单旋 1
		parent->left = subLR;
		if (subLR)	// 防止subLR是nullptr
			subLR->parent = parent;
		// 右单旋 2
		subL->right = parent;
		parent->parent = subL;
		subL->parent = pparent;

		// parent可能是根结点，可能是非根结点
		if (pparent == nullptr)	// 若是根结点，修改树的root指向
			_root = subL;
		else	// 若是非根结点，修改parent父节点的指针指向
		{
			if (pparent == pparent->left)		// 判断parent是父节点的哪个孩子节点
				pparent->left = subL;
			else
				pparent->right = subL;
		}
		parent->_bf = subL->_bf = 0;
	}
	void LeftRotation(Node* parent)	// 左单旋：新节点插入到较高右子树的右子树上
	{
		Node* subR = parent->right;	// 父节点的右孩子节点
		Node* subRL = subR->left;	// 父节点的右孩子节点的左孩子节点
		Node* pparent = parent->parent; // 可能parent是非根结点，需要记录parent的父结点

		/*
		左单旋：
			1. parent节点的右指针指向subRL，实现将parent的右子树下降一层
			2. subR的左指针指向parent，实现将parent的左子树上升一层
		*/
		// 左单旋 1
		parent->right = subRL;
		if (subRL)	// 防止subRL是nullptr
			subRL->parent = parent;
		// 左单旋 2
		subR->left = parent;
		parent->parent = subR;
		subR->parent = pparent;

		// parent可能是根结点，可能是非根结点
		if (pparent == nullptr)	// 若是根结点，修改树的root指向
			_root = subR;
		else	// 若是非根结点，修改parent父节点的指针指向
		{
			if (pparent == pparent->left)		// 判断parent是父节点的哪个孩子节点
				pparent->left = subR;
			else
				pparent->right = subR;
		}
		parent->_bf = subR->_bf = 0;
	}
	void Left_Right_DoubleRotation(Node* parent)
	{
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
	void InOrder(Node* root)
	{
		if (root)
		{
			InOrder(root->left);
			cout << root->_data << " ";
			InOrder(root->right);
		}
	}
	void DestroyTree(Node*& root)	// 后序销毁二叉树
	{
		if (root)
		{
			DestroyTree(root->left);
			DestroyTree(root->right);
			delete root;
			root = nullptr;
		}
	}
};


void testAVL()
{
	int array[] = { 16, 3, 7/*, 11, 9, 26, 18, 14, 15*/ };
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