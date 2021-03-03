#pragma once
#include <iostream>
#include <string>
using namespace std;
// �������ɫ����
enum Color
{
	RED,
	BLACK
};

// �������㶨��
template<class T>
struct RBTreeNode
{
	RBTreeNode<T>* left;	// �ڵ������
	RBTreeNode<T>* right;	// �ڵ���Һ���
	RBTreeNode<T>* parent;	// �ڵ�ĸ��ڵ�
	T data;		// �ڵ��б����ֵ
	Color color;	// �ڵ����ɫ

	RBTreeNode(const T& x = T(), Color c = RED) :left(nullptr), right(nullptr), parent(nullptr), data(x), color(c){}
};

// ������
template<class T>
struct RBTreeIterator
{
	typedef RBTreeNode<T> Node;
	typedef RBTreeIterator<T> self;
public:
	RBTreeIterator(Node* n = nullptr) : node(n){}
	// ����ָ�����Ƶķ���
	T& operator*()
	{
		return node->data;
	}
	T* operator->()
	{
		return &(operator*());
	}
	/*
	�ұȵ�ǰ�ڵ��� ���нڵ�����С�Ľڵ㣺
	1. �����ǰ�ڵ�����������ڣ�Ӧ������������������Сֵ�ڵ㣨����ࣩ
	2. �����ǰ�ڵ�������������ڣ�Ӧ������˫���в��ϲ���
	*/
	self& operator++()
	{
		Increment();
		return *this;
	}
	self& operator++(int)
	{
		self temp(*this);
		Increment();
		return temp;
	}

	/*
	�ұȵ�ǰ������С�� ���нڵ�������:
	1. �����ǰ�ڵ�����������ڣ�Ӧ�������������������ֵ�ڵ㣨���Ҳࣩ
	2. �����ǰ�ڵ�������������ڣ�
	*/
	self& operator--()
	{
		Decrement();
		return *this;
	}
	self& operator--(int)
	{
		self temp(*this);
		Decrement();
		return temp;
	}
	bool operator!=(const self& s)const
	{
		return node != s.node;
	}
	bool operator==(const self& s)const
	{
		return node == s.node;
	}

private:
	Node* node;		// ��װ �ڵ�ָ��

	// �ҵ�ǰ�������ĺ�һ��λ��
	void Increment()
	{
		if (node->right)
		{
			// ��ǰ�ڵ��������������ڣ�������������Ѱ����Сֵ
			node = node->right;
			while (node->left)
			{
				node = node->left;
			}
		}
		else
		{
			// ��ǰ�ڵ�������������ڣ��ڸ��ڵ���Ѱ�ұȵ�ǰ�ڵ��Ľڵ�
			// ʲô����²�����أ� ��node��˫�׵�����ʱ�������ҵ�
			Node* parent = node->parent;
			while (node == parent->right)
			{
				node = parent;
				parent = parent->parent;
			}
			// ��ֹ����������������û��������ʱ��������ǡ���ڸ��ڵ��λ��
			if (node->right != parent)
				node = parent;	// ��ʱnode��ָ�򸸽ڵ��б�֮ǰ�ڵ��Ľڵ� 
		}
	}
	// �ҵ�ǰ��������ǰһ��λ��
	void Decrement()
	{
		if (node == node->parent->parent && RED == node->color)
		{
			// node �� end ��λ��
			node = node->right;

		}
		else if (node->left)
		{
			// �� node �������������Ľڵ�
			node = node->left;
			while (node->right)
			{
				node = node->right;
			}
		}
		else
		{
			// ������������ -> Ӧ�õ� node ��˫�����ҳ��� node С�Ľڵ�
			Node* parent = node->parent;
			while (node == parent->left)
			{
				node = parent;
				parent = node->parent;
			}

			node = parent;
		}

	}
};

// ������ṹ������
// T �� ��ʾ������з��õ�Ԫ������
// KOFP����ʾ��T����ȡKey
template<class T, class KOFP>
class RBTree
{
	typedef RBTreeNode<T> Node;
	
public:
	typedef RBTreeIterator<T> iterator;
	RBTree()
	{
		_size = 0;
		head = new Node();
		head->left = head;
		head->right = head;
		head->parent = nullptr;		// ����RBT���޽ڵ㣬��ͷ���ĸ�ָ��ָ��nullptr

	}
	~RBTree()
	{
		Destroy(head->parent);
		delete head;
		head = nullptr;
		_size = 0;
	}

	// ������
	iterator begin()
	{
		return iterator(head->left);
	}
	iterator end()
	{
		return iterator(head);
	}
	// �������ݹ�������
	pair<iterator, bool> insert(const T& data)
	{
		Node*& root = getRoot();	// ��������

		// 1. ����BST�Ĺ���Ѱ�Ҳ������λ��
		// 1.1 ��rootΪ�գ�����Ҫ����root�ڵ�
		if (nullptr == root)
		{
			root = new Node(data, BLACK);	// �����Ĭ��Ϊ��ɫ
			root->parent = head;
			head->left = root;
			head->right = root;
			_size = 1;
			return make_pair(iterator(root), true);
		}

		// 1.2 ��root��Ϊ�գ�����ҪѰ�Ҳ���λ��
		Node* cur = root;
		Node* parent = head;
		KOFP key;
		
		while (cur)
		{
			parent = cur;
			if (key(data) < key(cur->data))
				cur = cur->left;
			else if (key(data) > key(cur->data))
				cur = cur->right;
			else   // �ýڵ����
				return make_pair(iterator(cur), true);
		}

		// 1.3 �ҵ�����λ�ú󣬲����½ڵ�
		Node* newNode = new Node(data);
		cur = newNode;
		if (data < parent->data)
			parent->left = cur;
		else
			parent->right = cur;
		cur->parent = parent;

		// 2. ����Ƿ�Υ�����ʣ��������ڵ�Ԥ��˫�׽ڵ����ɫ�Ƿ�Ϊ��ɫ
		while (parent != head && RED == parent->color)
			/*
			���ϵ�������ֹ������
			1. ��˫�׽ڵ���ɫΪ��ɫ���ʾ����Ҫ��������֮��Ҫ����
			2. parent�ڵ㵽��headʱ������������ֹ֮ͣ����
			*/
		{
			// Υ�����ʱ��֣�cur��parent�����ڵ㶼�Ǻ�ɫ��
			Node* grandFather = parent->parent;
			if (parent == grandFather->left)
			{
				// ���һ������˫�����游�ڵ�����
				Node* uncle = grandFather->right;
				if (uncle && RED == uncle->color)
				{
					/* 
					���һ��uncle��������Ϊ��ɫ
					���������
					1. cur���ڵ���ɫ��Ϊ��ɫ
					2. cur�游�ڵ���ɫ��Ϊ��ɫ
					3. ���ϵ���cur��parentָ��
					*/
					parent->color = BLACK;
					uncle->color = BLACK;
					grandFather->color = RED;
					cur = grandFather;
					parent = cur->parent;
				}
				else  //���2�����3
				{
					// uncle�ڵ㲻���� || uncle�ڵ�Ϊ��ɫ
					if (cur == parent->right)
					{
						// ���3 �� ת��Ϊ ���2
						LeftRotation(parent);
						std::swap(parent, cur);
					}
					// ���2
					grandFather->color = RED;
					parent->color = BLACK;
					RightRotation(grandFather);
				}
			}
			else
			{
				// ���һ�����ľ��������˫�����游�ڵ���Ҳ�
				Node* uncle = grandFather->left;
				if (uncle && RED == uncle->color)
				{
					// ���һ�������������Ϊ��ɫ
					parent->color = BLACK;
					uncle->color = BLACK;
					grandFather->color = RED;
					cur = grandFather;
					parent = cur->parent;
				}
				else
				{
					// uncle�ڵ㲻���� || uncle�ڵ�Ϊ��ɫ
					if (cur == parent->left)
					{
						// ���3 �� ת��Ϊ ���2
						RightRotation(parent);
						std::swap(parent, cur);
					}
					// ���2
					parent->color = BLACK;  // whileѭ����ֹ�������
					grandFather->color = RED;
					LeftRotation(grandFather);
				}
			}
		}
		// �½ڵ����� ����ͷ��������ָ��
		root->color = BLACK;
		head->left = getLeftMin();
		head->right = getRightMax();

		_size++;
		return make_pair(iterator(newNode), true);
	}
	// ����������
	void swap(RBTree<T, KOFP>& t)
	{
		std::swap(head, t.head);
		std::swap(_size, t._size);
	}
	// ��պ����������Ч�ڵ�
	void clear()
	{
		Destroy(getRoot());
		_size = 0;
	}
	// ������������
	void inOrder()
	{
		InOrder(head->parent);
		cout << endl;
	}
	// �жϸ����Ƿ�Ϊ�����
	bool isValidRBTree()
	{
		// �����Ǻ����
		Node* root = getRoot();
		if (root == nullptr)
			return true;

		// ���ǿ� -> ʹ������ȷ��
		/*
		���ʣ�
		1. ÿ����㲻�Ǻ�ɫ���Ǻ�ɫ
		2. ���ڵ��Ǻ�ɫ��
		3. ���һ���ڵ��Ǻ�ɫ�ģ��������������ӽ���Ǻ�ɫ��
		4. ����ÿ����㣬�Ӹý�㵽�����к��Ҷ���ļ�·���ϣ��� ������ͬ��Ŀ�ĺ�ɫ���
		5. ÿ��Ҷ�ӽ�㶼�Ǻ�ɫ��(�˴���Ҷ�ӽ��ָ���ǿս��)
		*/
		if (root->color != BLACK)
		{
			cout << "Υ��������2������㲻�Ǻ�ɫ�ģ�" << endl;
			return false;
		}

		// ����3������4ͬʱ���
		size_t blackCount = 0;
		Node* cur = root;
		while (cur)
		{
			if (cur->color == BLACK)
				blackCount++;
			cur = cur->left;
		}
		size_t pathBlackCount = 0;	// �������浥��·���к�ɫ�ڵ�ĸ���
		return _ValidRBTree(root, pathBlackCount, blackCount);
	}
	// ������صĲ���
	size_t size() const
	{
		return _size;
	}
	// �жϺ�����Ƿ�Ϊ��
	bool empty()
	{
		return head->parent == nullptr;
	}
	// ����ĳ���ڵ㲢����������
	iterator find(const T& data)
	{
		Node* cur = getRoot();
		KOFP key;
		while (cur)
		{
			if (key(data) == key(cur->data))
				return iterator(cur);
			else if (key(data) < key(cur->data))
				cur = cur->left;
			else
				cur = cur->right;
		}
		return end();
	}

private:
	Node* head;	 // ָ������ͷ����ָ��
	size_t _size;	// ���������Ľڵ����

	bool _ValidRBTree(Node* root, size_t pathBlackCount, const size_t blackCount)
	{
		if (nullptr == root)
			return true;

		if (root->color == BLACK)
			pathBlackCount++;
			

		Node* parent = root->parent;
		// parent != head ��ʾrootһ�����Ǻ�����ĸ���㣬parentһ������Ч�ڵ�
		if (parent != head && parent->color == RED && root->color == RED)
		{
			cout << "Υ������3����������һ��ĺ�ɫ���" << endl;
			return false;
		}

		// root��һ��Ҷ�ӽڵ�
		if (root->left == nullptr && root->right == nullptr)
		{
			if (pathBlackCount != blackCount)
			{
				cout << "Υ������4��·���к�ɫ�ڵ�ĸ�����ͬ��" << endl;
				return false;
			}
		}
		return _ValidRBTree(root->left, pathBlackCount, blackCount) && _ValidRBTree(root->right, pathBlackCount, blackCount);
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
	void RightRotation(Node* parent)
	{
		Node* subL = parent->left; // ���ڵ�����ӽڵ�
		Node* subLR = subL->right; // ���ڵ�����ӽڵ���Һ��ӽڵ�

		/*
		�ҵ�����
		1. ���ڵ����ָ��ָ��subLR��ʵ�ֽ�parent���������½�һ��
		2. subL����ָ��ָ��parent��ʵ�ֽ�parent������������һ��
		*/

		// �ҵ��� 1
		parent->left = subLR;
		if (subLR) // ������֧�ĳ�����subLR��nullptr
			subLR->parent = parent;

		// �ҵ��� 2
		subL->right = parent;
		// ��Ϊparent������ĳ���ڵ������������ڸ���parent��˫��ǰ�����Ƚ���֮ǰ��˫�׼�¼
		Node* pparent = parent->parent; // ����parent�ǷǸ���㣬��Ҫ��¼parent�ĸ����
		parent->parent = subL;
		subL->parent = pparent;

		// parent�����Ǹ��ڵ㣺��Ҫ�޸�_root
		// parentҲ������һ������: ��Ҫ�޸�pparent����/��ָ�����ָ��
		if (head == pparent) // ���Ǹ���㣬�޸�����rootָ��
		{
			// ��ת֮ǰparent�Ǹ��ڵ�
			head->parent = subL;
		}
		else // ���ǷǸ���㣬�޸�parent���ڵ��ָ��ָ��
		{
			// parent��ĳ���ڵ������
			if (parent == pparent->left) // �ж�parent�Ǹ��ڵ���ĸ����ӽڵ�
				pparent->left = subL;
			else
				pparent->right = subL;
		}
	}
	void LeftRotation(Node* parent)
	{
		Node* subR = parent->right; // ���ڵ���Һ��ӽڵ�
		Node* subRL = subR->left; // ���ڵ���Һ��ӽڵ�����ӽڵ�

		/*
		������
		1. parent�ڵ����ָ��ָ��subRL��ʵ�ֽ�parent���������½�һ��
		2. subR����ָ��ָ��parent��ʵ�ֽ�parent������������һ��
		*/
		// ���� 1
		parent->right = subRL;
		if (subRL) // ���⣺�ҵ�֧, ��ֹsubRL��nullptr
			subRL->parent = parent;
		// ���� 2
		subR->left = parent;
		Node* pparent = parent->parent; // ��Ҫ����parent��subR��˫��
		parent->parent = subR;
		subR->parent = pparent;

		// ��ת֮ǰ��parent�����Ǹ���㣬�����ǷǸ����
		// parent�Ǹ��ڵ㣺�޸�_root��ָ��
		// parent���������޸�ԭparent��||��ָ�����ָ��
		if (head == pparent) // ���Ǹ���㣬�޸�����rootָ��
		{
			head->parent = subR;
		}
		else  // ���ǷǸ���㣬�޸�parent���ڵ��ָ��ָ��
		{
			if (parent == pparent->left)  // �ж�parent�Ǹ��ڵ���ĸ����ӽڵ�
				pparent->left = subR;
			else
				pparent->right = subR;
		}

	}
	Node*& getRoot()	// ��ȡͷ���
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