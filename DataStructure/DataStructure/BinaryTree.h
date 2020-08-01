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
//***************************************************************************************
//��������
/*	�������Ĵ���	*/
void BinaryTreeInitial(BTree *t);
void BinaryTreeCreate(BTree *t);
/*	�������ı���	*/
//�ݹ��㷨
void BinaryTreeVLR(BTree t);
void BinaryTreeLVR(BTree t);
void BinaryTreeLRV(BTree t);
//�ǵݹ�
void BinaryTreeVLR_Nor(BTree t);
void BinaryTreeLVR_Nor(BTree t);
void BinaryTreeLRV_Nor(BTree t);

int BinaryTreeSize(BTree t);

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