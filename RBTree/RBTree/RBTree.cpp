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
	RBTreeNode<T>* left;	// �ڵ������
	RBTreeNode<T>* right;	// �ڵ���Һ���
	RBTreeNode<T>* parent;	// �ڵ�ĸ��ڵ�
	T data;		// �ڵ��б����ֵ
	Color color;	// �ڵ����ɫ

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
		head->parent = nullptr;		// ����RBT���޽ڵ㣬��ͷ���ĸ�ָ��ָ��nullptr
	}
	~RBTree()
	{
		Destroy(head->parent);
		delete head;
		head = nullptr;
	}
	bool insert(const T& data)
	{
		Node* root = getRoot();	// ��������

		// 1. ����BST�Ĺ���Ѱ�Ҳ������λ��
		// 1.1 ��rootΪ�գ�����Ҫ����root�ڵ�
		if (root == nullptr)
		{
			root = new Node(data,BLACK);	// �����Ĭ��Ϊ��ɫ
			root->parent = head;
			head->left = head->right = head->parent = root;
			return true;
		}
		// 1.2 ��root��Ϊ�գ�����ҪѰ�Ҳ���λ��
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
		// 1.3 �ҵ�����λ�ú󣬲����½ڵ�
		cur = new Node(data);
		if (data < parent->data)
			parent->left = cur;
		else
			parent->right = cur;
		cur->parent = parent;

		// 2. ����Ƿ�Υ�����ʣ��������ڵ�Ԥ��˫�׽ڵ����ɫ�Ƿ�Ϊ��ɫ
		while (parent != head && parent->color == RED)	
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
				if (uncle != nullptr && uncle->color == RED)
				{
					/* 
					���һ��uncle��������Ϊ��ɫ
					���������
						1. cur���ڵ���ɫ��Ϊ��ɫ
						2. cur�游�ڵ���ɫ��Ϊ��ɫ
						3. ���ϵ���cur��parentָ��
					*/
					parent->color = uncle->color = BLACK;
					grandFather->color = RED;
					cur = grandFather;
					parent = parent->parent;
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
				if (uncle != nullptr && uncle->color == RED)
				{
					// ���һ�������������Ϊ��ɫ
					parent->color = uncle->color = BLACK;
					grandFather->color = RED;
					cur = grandFather;
					parent = parent->parent;
				}
				else
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
					parent->color = BLACK;	// whileѭ����ֹ�������
					LeftRotation(grandFather);
				}
			}
		}
		// �½ڵ����� ����ͷ��������ָ��
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
		size_t pathBlackCount = 0;
		return _ValidRBTree(root, pathBlackCount, blackCount);
	}

private:
	Node* head;	 // ָ������ͷ����ָ��

	bool _ValidRBTree(Node* root,  size_t pathBlackCount, const size_t blackCount)
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
		if (nullptr == pparent) // ���Ǹ���㣬�޸�����rootָ��
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
	void LeftRotation()
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
		if (nullptr == pparent) // ���Ǹ���㣬�޸�����rootָ��
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
