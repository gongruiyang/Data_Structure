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
//***************************************************************************************
//函数声明
/*	二叉树的创建	*/
void BinaryTreeInitial(BTree *t);
void BinaryTreeCreate(BTree *t);
/*	二叉树的遍历	*/
//递归算法
void BinaryTreeVLR(BTree t);
void BinaryTreeLVR(BTree t);
void BinaryTreeLRV(BTree t);
//非递归
void BinaryTreeVLR_Nor(BTree t);
void BinaryTreeLVR_Nor(BTree t);
void BinaryTreeLRV_Nor(BTree t);

int BinaryTreeSize(BTree t);

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


#endif	/*_BINARYTREE_H_*/