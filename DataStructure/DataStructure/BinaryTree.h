#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_
#include "common.h"
//***************************************************************************************
//��������
typedef char ET;
/*****************************************************************************/
//������
typedef struct BinaryTreeNode
{
	ET data;
	BinaryTreeNode* leftNode;
	BinaryTreeNode* rightNode;
}BTNode;
typedef BTNode* BTree;
/*****************************************************************************/
//��ջ
typedef BTNode* LSET;
typedef struct StackNode{
	LSET data;
	struct StackNode* next;
}StackNode;
typedef StackNode* LinkStack;

StackNode* GetNode(LSET val){	//������ 
	StackNode* s = (StackNode*)malloc(sizeof(StackNode));
	assert(s != NULL);
	s->data = val;
	s->next = NULL;
	return s;
}
void LinkedStackAddTop(LinkStack *pst, LSET val){
	assert(pst != NULL);
	StackNode* s = GetNode(val);
	if (*pst == NULL){	//��ջ 
		*pst = s;
	}
	else{	//ջ�ǿ� 
		StackNode* temp = *pst;
		while (temp->next != NULL){
			temp = temp->next;
		}
		temp->next = s;
	}
}
void LinkedStackDeletePop(LinkStack *pst){
	assert(pst != NULL);
	if (*pst == NULL){	 
		printf("��ջ��\n");
		return;
	}
	else{	
		StackNode* temp = *pst;
		if (temp->next == NULL){
			free(temp);
			*pst = NULL;
		}
		else{						
			while (temp->next->next != NULL){
				temp = temp->next;
			}
			StackNode* p = temp->next;
			free(p);
			temp->next = NULL;
		}
	}
}
void LinkedStackInitial(LinkStack *pst){
	assert(pst != NULL);
	*pst = NULL;
}
bool LinkedStackIsEmpty(LinkStack *pst){
	assert(pst != NULL);
	return (*pst) == NULL;
}
LSET LinkedStackGetTop(LinkStack *pst){
	assert(pst != NULL);
	if (*pst == NULL){	//��ջ 
		printf("��ջ��\n");
		return NULL;
	}
	else{	//ջ�ǿ� 
		StackNode* temp = *pst;
		if (temp->next == NULL){		//ջֻ��һ��Ԫ�� 
			return temp->data;
		}
		else{						//ջ���ж��Ԫ�� 
			while (temp->next->next != NULL){
				temp = temp->next;
			}
			StackNode* p = temp->next;
			return p->data;
		}
	}
}
void LinkedStackDestroy(LinkStack *pst){
	assert(pst != NULL);
	if (*pst == NULL){
		return;
	}
	else{
		StackNode* p = *pst;
		StackNode* q = *pst;
		while (q != NULL){
			q = q->next;
			free(p);
			p = q;
		}
	}
	*pst = NULL;
}
//***************************************************************************************
//��������
/*	�������Ĵ���	*/
void BinaryTreeInitial(BTree *t);										//��ʼ��������
void BinaryTreeCreate(BTree *t);										//����������
BTree BinaryTreeGetTree();												//�������봴��һ��������
BTree BinaryTreeStrToTree(const char* str, int* i);						//�����ַ�������������
BTree BinaryTree_VLR_LVR_To_Tree(const char* vlr, const char* lvr, int n);		//����ǰ������������������������

/*	�������ı���	*/
//�ݹ��㷨
void BinaryTreeVLR(BTree t);		//ǰ������ݹ��㷨
void BinaryTreeLVR(BTree t);		//��������ݹ��㷨
void BinaryTreeLRV(BTree t);		//��������ݹ��㷨
void BinaryTreeLevel(BTree t);		//�������
//�ǵݹ�
void BinaryTreeVLR_Nor(BTree t);	//ǰ������ǵݹ��㷨
void BinaryTreeLVR_Nor(BTree t);	//��������ǵݹ��㷨
void BinaryTreeLRV_Nor(BTree t);	//��������ǵݹ��㷨
void BinaryTreeLevel_Nor(BTree t);	

/* �������� */
int		BinaryTreeSize(BTree t);						//������������
int		BinaryTreeHeight(BTree t);						//���������
BTNode* BinaryTreeGetLeftTree(BTNode *p);				//����������
BTNode* BinaryTreeGetRightTree(BTNode *p);				//����������
BTNode* BinaryTreeFindNode(BTree t, ET key);			//��ֵ����
BTNode* BinaryTreeGetParentNode(BTree t, BTNode *p);	//����p�ĸ��ڵ�
BTNode* BinaryTreeCloneTree(BTree t);					//����һ������������
bool    BinaryTreeEqualTree(BTree t1, BTree t2);		//�ж������������Ƿ����

/*****************************************************************************/
//��������
void BinaryTreeInitial(BTree *t){
	*t = NULL;
}
void BinaryTreeCreate(BTree *t){
	assert(t != NULL);
	ET value;
	scanf("%c", &value);
	if (value == '#'){	//#���������� 
		*t = NULL;
	}
	else{
		*t = (BTNode*)malloc(sizeof(BTNode));
		assert((*t) != NULL);
		(*t)->data = value;
		BinaryTreeCreate(&(*t)->leftNode);
		BinaryTreeCreate(&(*t)->rightNode);
	}
}
BTree BinaryTreeGetTree(){

	ET val;
	scanf("%c", &val);

	if (val == '#')
		return NULL;
	else
	{
		BTNode* t = (BTNode*)malloc(sizeof(BTNode));	//���������
		t->data = val;
		t->leftNode = BinaryTreeGetTree();				//�������ӽ��
		t->rightNode = BinaryTreeGetTree();				//�������ӽ��
		return t;
	}
}
#if 0	//����д�� ԭ�򣺵ݹ鷵��ʱ��ָ��ָ��δ�ı�
BTree BinaryTreeStrToTree(const char* str){
	assert(str != NULL);
	if (*str == '\0' || *str == '#')
		return NULL;
	else
	{
		BTNode* t = (BTNode*)malloc(sizeof(BTNode));
		t->data = *str;
		t->leftNode = BinaryTreeStrToTree(++str);
		t->rightNode = BinaryTreeStrToTree(++str);
		return t;
	}
}
#endif
BTree BinaryTreeStrToTree(const char* str,int* i){
	assert(str != NULL);
	if (str[*i] == '\0' || str[*i] == '#')
		return NULL;
	else
	{
		BTNode* t = (BTNode*)malloc(sizeof(BTNode));
		t->data = str[*i];
		(*i)++;
		t->leftNode = BinaryTreeStrToTree(str,i);
		(*i)++;
		t->rightNode = BinaryTreeStrToTree(str,i);
		return t;
	}
}
BTree BinaryTree_VLR_LVR_To_Tree(const char* vlr, const char* lvr,int n){

	int k = 0;
	while ((*vlr) != (*lvr))
	{
		lvr++;
		k++;
	}
	if ((*vlr) == '\0')
		return NULL;
	else
	{
		BTNode* t = (BTNode*)malloc(sizeof(BTNode));
		t->leftNode = BinaryTree_VLR_LVR_To_Tree(vlr, lvr - k, k - 1);
		t->rightNode = BinaryTree_VLR_LVR_To_Tree(vlr + k, lvr, n - k - 1);
	}
}

void BinaryTreeVLR(BTree t){
	if (t != NULL){
		printf("%c ", t->data);
		BinaryTreeVLR(t->leftNode);
		BinaryTreeVLR(t->rightNode);
	}
}
void BinaryTreeLVR(BTree t){
	if (t != NULL){
		BinaryTreeLVR(t->leftNode);
		printf("%c ", t->data);
		BinaryTreeLVR(t->rightNode);
	}
}
void BinaryTreeLRV(BTree t){
	if (t != NULL){
		BinaryTreeLRV(t->leftNode);
		BinaryTreeLRV(t->rightNode);
		printf("%c ", t->data);
	}
}
void BinaryTreeVLR_Nor(BTree t){
	if (t != NULL){
		LinkStack st;
		LinkedStackInitial(&st);
		LinkedStackAddTop(&st, t);
		while (LinkedStackIsEmpty(&st))
		{
			BTNode* p = LinkedStackGetTop(&st);
			LinkedStackDeletePop(&st);
			printf("%c ", p->data);
			if (p->rightNode != NULL)
				LinkedStackAddTop(&st, p->rightNode);
			if (p->leftNode != NULL)
				LinkedStackAddTop(&st, p->leftNode);
		}
		LinkedStackDestroy(&st);
	}
}
void BinaryTreeLVR_Nor(BTree t){
	if (t != NULL){
		LinkStack st;
		LinkedStackInitial(&st);
		do 
		{
			while (t != NULL)	//��t�������������
			{
				LinkedStackAddTop(&st, t);
				t = t->leftNode;
			}
			BTNode* p = LinkedStackGetTop(&st);
			LinkedStackDeletePop(&st);
			printf("%c ", p->data);
			if (p->rightNode != NULL)
				t = p->rightNode;
		} while (!LinkedStackIsEmpty(&st) || t != NULL);
	}
}
void BinaryTreeLRV_Nor(BTree t){
	if (t != NULL){
		LinkStack st;
		LinkedStackInitial(&st);
		BTNode* pre = NULL;
		do 
		{
			while (t != NULL)	//��t�������������
			{
				LinkedStackAddTop(&st, t);
				t = t->leftNode;
			}
			BTNode* p = LinkedStackGetTop(&st);
			
			
			if (p->rightNode != NULL || p->rightNode == pre)
			{
				LinkedStackDeletePop(&st);
				printf("%c ", p->data);
				pre = p;
			}
			else
				t = p->rightNode;
		} while (!LinkedStackIsEmpty(&st));
	}
}


int  BinaryTreeSize(BTree t){
	assert(t != NULL);
	if (t == NULL)
		return 0;
	else
		return BinaryTreeSize(t->leftNode) + BinaryTreeSize(t->rightNode) + 1;
}
int  BinaryTreeHeight(BTree t){
	if (t == NULL)
		return 0;
	else
	{
		int left_H = BinaryTreeHeight(t->leftNode);
		int right_H = BinaryTreeHeight(t->rightNode);
		return (left_H > right_H ? left_H : right_H) + 1;
	}
}
BTNode* BinaryTreeFindNode(BTree t, ET key){
	if (t->data == key || t == NULL)
		return t;
	
	BTNode* p = BinaryTreeFindNode(t->leftNode, key);
	if (p != NULL)
		return p;
	return BinaryTreeFindNode(t->rightNode, key);
		
}
BTNode* BinaryTreeGetParentNode(BTree t, BTNode *p){
	if (t == NULL || p == NULL || t == p) return NULL;
	if (t->leftNode == p || t->rightNode == p)
		return t;
	BTNode* q = BinaryTreeGetParentNode(t->leftNode, p);
	if (q != NULL)
		return q;
	return BinaryTreeGetParentNode(t->rightNode, p);
}
BTNode* BinaryTreeGetLeftTree(BTNode *p){
	if (p == NULL) return NULL;
	return p->leftNode;
}
BTNode* BinaryTreeGetRightTree(BTNode *p){
	if (p == NULL) return NULL;
	return p->rightNode;
}
BTNode* BinaryTreeCloneTree(BTree t){
	if (t == NULL) return NULL;

	BTNode* t_copy = (BTNode*)malloc(sizeof(BTNode));
	assert(t_copy != NULL);

	t_copy->data = t->data;		//��¡���ڵ�
	t_copy->leftNode = BinaryTreeCloneTree(t->leftNode);		//��¡������
	t_copy->rightNode = BinaryTreeCloneTree(t->rightNode);		//��¡������
	return t_copy;
}
bool BinaryTreeEqualTree(BTree t1, BTree t2){
#if 0
	if (t1 == NULL && t2 == NULL) return true;
	if (t1 == NULL || t2 == NULL) return false;
	if (t1->data != t2->data)
		return false;
	return BinaryTreeEqualTree(t1->leftNode, t2->leftNode) && BinaryTreeEqualTree(t1->rightNode, t2->rightNode);
#endif
	if (t1 == NULL && t2 == NULL) return true;
	if (t1 == NULL || t2 == NULL) return false;
	return (t1->data == t2->data && 
		BinaryTreeEqualTree(t1->leftNode, t2->leftNode) && 
		BinaryTreeEqualTree(t1->rightNode, t2->rightNode));
}


#endif	/*_BINARYTREE_H_*/