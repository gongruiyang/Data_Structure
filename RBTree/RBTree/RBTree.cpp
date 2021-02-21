#include <iostream>
using namespace std;

enum Color
{
	RED,
	BLACK
};

template<class T>
struct RBTreeNode
{
	RBTreeNode<T>* left;	// 节点的左孩子
	RBTreeNode<T>* right;	// 节点的右孩子
	RBTreeNode<T>* parent;	// 节点的父节点
	T data;		// 节点中保存的值
	Color color;	// 节点的颜色

	RBTreeNode(const T& x = T(), Color c = RED) :left(nullptr), right(nullptr), parent(nullptr), data(x), color(c){}
};

template<class T>
class RBTree
{
	typedef RBTreeNode<T> Node;
public:
	RBTree()
	{
		head = new Node();
		head->left = head;
		head->right = head;
		head->parent = nullptr;		// 由于RBT中无节点，故头结点的父指针指向nullptr
	}
	~RBTree()
	{
		Destroy(head->parent);
		delete head;
		head = nullptr;
	}
	bool insert(const T& data)
	{
		Node* root = getRoot();	// 保存根结点

		// 1. 按照BST的规则寻找插入结点的位置
		// 1.1 若root为空，则需要建立root节点
		if (root == nullptr)
		{
			root = new Node(data,BLACK);	// 根结点默认为黑色
			root->parent = head;
			head->left = head->right = head->parent = root;
			return true;
		}
		// 1.2 若root不为空，则需要寻找插入位置
		Node* cur = root;
		Node* parent = head;
		while (cur)
		{
			parent = cur;
			if (data < cur->data)
				cur = cur->left;
			else if (data > cur->data)
				cur = cur->right;
			else return false;
		}
		// 1.3 找到插入位置后，插入新节点
		cur = new Node(data);
		if (data < parent->data)
			parent->left = cur;
		else
			parent->right = cur;
		cur->parent = parent;

		// 2. 检测是否违反性质：检测新入节点预期双亲节点的颜色是否都为红色
		while (parent != head && parent->color == RED)	
			/*
				向上迭代的终止条件：
					1. 若双亲节点颜色为黑色则表示不需要调整，反之需要调整
					2. parent节点到达head时继续调整，反之停止调整
			*/
		{
			// 违反性质表现：cur和parent两个节点都是红色的
			Node* grandFather = parent->parent;
			if (parent == grandFather->left)	
			{
				// 情况一二三：双亲在祖父节点的左侧
				Node* uncle = grandFather->right;
				if (uncle != nullptr && uncle->color == RED)
				{
					/* 
					情况一：uncle结点存在且为红色
					解决方法：
						1. cur父节点颜色变为黑色
						2. cur祖父节点颜色变为红色
						3. 向上迭代cur和parent指针
					*/
					parent->color = uncle->color = BLACK;
					grandFather->color = RED;
					cur = grandFather;
					parent = parent->parent;
				}
				else  //情况2和情况3
				{
					// uncle节点不存在 || uncle节点为黑色
					if (cur == parent->right)
					{
						// 情况3 ： 转化为 情况2
						LeftRotation(parent);
						std::swap(parent, cur);
					}
					// 情况2
					grandFather->color = RED;
					parent->color = BLACK;
					RightRotation(grandFather);
				}
			}
			else 
			{
				// 情况一二三的镜像情况：双亲在祖父节点的右侧
				Node* uncle = grandFather->left;
				if (uncle != nullptr && uncle->color == RED)
				{
					// 情况一：叔叔结点存在且为红色
					parent->color = uncle->color = BLACK;
					grandFather->color = RED;
					cur = grandFather;
					parent = parent->parent;
				}
				else
				{
					// uncle节点不存在 || uncle节点为黑色
					if (cur == parent->right)
					{
						// 情况3 ： 转化为 情况2
						LeftRotation(parent);
						std::swap(parent, cur);
					}
					// 情况2
					grandFather->color = RED;
					parent->color = BLACK;	// while循环终止条件达成
					LeftRotation(grandFather);
				}
			}
		}
		// 新节点插入后 更新头结点的左右指针
		head->left = getLeftMin();
		head->right = getRightMax();

		return true;
	}
	void inOrder()
	{
		InOrder(head->parent);
		cout << endl;
	}
	bool isValidRBTree()
	{
		// 空树是红黑树
		Node* root = getRoot();
		if (root == nullptr)
			return true;

		// 树非空 -> 使用性质确定
		/*
		性质：
		1. 每个结点不是红色就是黑色
		2. 根节点是黑色的
		3. 如果一个节点是红色的，则它的两个孩子结点是黑色的
		4. 对于每个结点，从该结点到其所有后代叶结点的简单路径上，均 包含相同数目的黑色结点
		5. 每个叶子结点都是黑色的(此处的叶子结点指的是空结点)
		*/
		if (root->color != BLACK)
		{
			cout << "违反了性质2：根结点不是黑色的！" << endl;
			return false;
		}

		// 性质3和性质4同时检测
		size_t blackCount = 0;
		Node* cur = root;
		while (cur)
		{
			if (cur->color == BLACK)
				blackCount++;
			cur = cur->left;
		}
		size_t pathBlackCount = 0;
		return _ValidRBTree(root, pathBlackCount, blackCount);
	}

private:
	Node* head;	 // 指向红黑树头结点的指针

	bool _ValidRBTree(Node* root,  size_t pathBlackCount, const size_t blackCount)
	{
		if (nullptr == root)
			return true;

		if (root->color == BLACK)
			pathBlackCount++;

		Node* parent = root->parent;
		// parent != head 表示root一定不是红黑树的根结点，parent一定是有效节点
		if (parent != head && parent->color == RED && root->color == RED)
		{
			cout << "违反性质3：存在连在一起的红色结点" << endl;
			return false;
		}

		// root是一个叶子节点
		if (root->left == nullptr && root->right == nullptr)
		{
			if (pathBlackCount != blackCount)
			{
				cout << "违反性质4：路径中黑色节点的个数不同！" << endl;
				return false;
			}
		}
		return _ValidRBTree(root->left, pathBlackCount, blackCount) && _ValidRBTree(root->right, pathBlackCount, blackCount)
	}
	void InOrder(Node* root)
	{
		if (root)
		{
			InOrder(root->left);
			cout << root->data << " ";
			InOrder(root->right);
		}
	}
	void Destroy(Node* root)
	{
		if (root)
		{
			Destroy(root->left);
			Destroy(root->right);
			delete root;
			root = nullptr;
		}
	}
	void RightRotation()
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
			head->parent = subL;
		}
		else // 若是非根结点，修改parent父节点的指针指向
		{
			// parent是某个节点的子树
			if (parent == pparent->left) // 判断parent是父节点的哪个孩子节点
				pparent->left = subL;
			else
				pparent->right = subL;
		}
	}
	void LeftRotation()
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
			head->parent = subR;
		}
		else  // 若是非根结点，修改parent父节点的指针指向
		{
			if (parent == pparent->left)  // 判断parent是父节点的哪个孩子节点
				pparent->left = subR;
			else
				pparent->right = subR;
		}

	}
	Node*& getRoot()	// 获取头结点
	{
		return head->parent;
	}
	Node*& getLeftMin()
	{
		Node* root = getRoot();
		if (nullptr == root)
			return head;
		Node* cur = root;
		while (cur->left)
			cur = cur->left;
		return cur;
	}
	Node*& getRightMax()
	{
		Node* root = getRoot();
		if (root == nullptr) return head;
		Node* cur = root;
		while (cur->right)
			cur = cur->right;
		return cur;
	}
};
