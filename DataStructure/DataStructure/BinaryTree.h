#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_
#include "common.h"
//***************************************************************************************
//常量定义
typedef char ET;
/*****************************************************************************/
//二叉树
typedef struct BinaryTreeNode
{
	ET data;
	BinaryTreeNode* leftNode;
	BinaryTreeNode* rightNode;
}BTNode;
typedef BTNode* BTree;
/*****************************************************************************/
//链栈
typedef BTNode* LSET;
typedef struct StackNode{
	LSET data;
	struct StackNode* next;
}StackNode;
typedef StackNode* LinkStack;

StackNode* GetNode(LSET val){	//申请结点 
	StackNode* s = (StackNode*)malloc(sizeof(StackNode));
	assert(s != NULL);
	s->data = val;
	s->next = NULL;
	return s;
}
void LinkedStackAddTop(LinkStack *pst, LSET val){
	assert(pst != NULL);
	StackNode* s = GetNode(val);
	if (*pst == NULL){	//空栈 
		*pst = s;
	}
	else{	//栈非空 
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
		printf("空栈！\n");
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
	if (*pst == NULL){	//空栈 
		printf("空栈！\n");
		return NULL;
	}
	else{	//栈非空 
		StackNode* temp = *pst;
		if (temp->next == NULL){		//栈只有一个元素 
			return temp->data;
		}
		else{						//栈中有多个元素 
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
//函数声明
/*	二叉树的创建	*/
void BinaryTreeInitial(BTree *t);										//初始化二叉树
void BinaryTreeCreate(BTree *t);										//创建二叉树
BTree BinaryTreeGetTree();												//根据输入创造一个二叉树
BTree BinaryTreeStrToTree(const char* str, int* i);						//根据字符串创建二叉树
BTree BinaryTree_VLR_LVR_To_Tree(const char* vlr, const char* lvr, int n);		//根据前序遍历和中序遍历创建二叉树

/*	二叉树的遍历	*/
//递归算法
void BinaryTreeVLR(BTree t);		//前序遍历递归算法
void BinaryTreeLVR(BTree t);		//中序遍历递归算法
void BinaryTreeLRV(BTree t);		//后序遍历递归算法
void BinaryTreeLevel(BTree t);		//层出遍历
//非递归
void BinaryTreeVLR_Nor(BTree t);	//前序遍历非递归算法
void BinaryTreeLVR_Nor(BTree t);	//中序遍历非递归算法
void BinaryTreeLRV_Nor(BTree t);	//后序遍历非递归算法
void BinaryTreeLevel_Nor(BTree t);	

/* 其他操作 */
int		BinaryTreeSize(BTree t);						//计算树结点个数
int		BinaryTreeHeight(BTree t);						//计算树深度
BTNode* BinaryTreeGetLeftTree(BTNode *p);				//返回左子树
BTNode* BinaryTreeGetRightTree(BTNode *p);				//返回右子树
BTNode* BinaryTreeFindNode(BTree t, ET key);			//按值查找
BTNode* BinaryTreeGetParentNode(BTree t, BTNode *p);	//查找p的父节点
BTNode* BinaryTreeCloneTree(BTree t);					//拷贝一个二叉树返回
bool    BinaryTreeEqualTree(BTree t1, BTree t2);		//判断两个二叉树是否相等

/*****************************************************************************/
//函数定义
void BinaryTreeInitial(BTree *t){
	*t = NULL;
}
void BinaryTreeCreate(BTree *t){
	assert(t != NULL);
	ET value;
	scanf("%c", &value);
	if (value == '#'){	//#代表建树结束 
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
		BTNode* t = (BTNode*)malloc(sizeof(BTNode));	//创建父结点
		t->data = val;
		t->leftNode = BinaryTreeGetTree();				//创建左子结点
		t->rightNode = BinaryTreeGetTree();				//创建右子结点
		return t;
	}
}
#if 0	//错误写法 原因：递归返回时，指针指向未改变
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
			while (t != NULL)	//将t置于树的最左侧
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
			while (t != NULL)	//将t置于树的最左侧
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

	t_copy->data = t->data;		//克隆父节点
	t_copy->leftNode = BinaryTreeCloneTree(t->leftNode);		//克隆左子树
	t_copy->rightNode = BinaryTreeCloneTree(t->rightNode);		//克隆右子树
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