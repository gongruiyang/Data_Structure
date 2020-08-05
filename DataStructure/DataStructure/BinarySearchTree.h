#ifndef _BINARYSEARCHTREE_H_
#define _BINARYSEARCHTREE_H_
#include "common.h"
//***************************************************************************************
//常量定义
typedef int ET;
//***************************************************************************************
//二叉搜索树
typedef struct BSTNode
{
	ET data;
	BSTNode* left;
	BSTNode* right;
}BSTNode;
typedef BSTNode* BSTree;
//***************************************************************************************
//方法声明
void BSTreeInitial(BSTree* bst);
bool BSTreeInsert(BSTree* t, ET val);
ET BSTreeMinValue(BSTree t);
ET BSTreeMaxValue(BSTree t);
void BSTreeSortPrint(BSTree t);
BSTNode* BSTreeFind(BSTree t, ET key);


//***************************************************************************************
//方法实现
void BSTreeInitial(BSTree* bst){
	*bst = NULL;
}
bool BSTreeInsert(BSTree* t, ET val){
	assert(t != NULL);
	if (*t == NULL){
		*t = (BSTNode*)malloc(sizeof(BSTNode));
		assert(*t != NULL);
		(*t)->data = val;
		(*t)->left = (*t)->right = NULL;
		return true;
	}
	if (val < (*t)->data){
		return BSTreeInsert(&(*t)->left,val);
	}
	else if (val > (*t)->data){
		return BSTreeInsert(&(*t)->right, val);
	}
	else{
		return false;
	}
}
ET BSTreeMinValue(BSTree t){
	assert(t != NULL);
	if (t->left == NULL){
		return t->data;
	}
	return BSTreeMinValue(t->left);
}
ET BSTreeMaxValue(BSTree t){
	assert(t != NULL);
	if (t->right == NULL){
		return t->data;
	}
	return BSTreeMinValue(t->right);
}
void BSTreeSortPrint(BSTree t){
	assert(t != NULL);
	if (t != NULL){
		BSTreeSortPrint(t->left);
		printf("%d ", t->data);
		BSTreeSortPrint(t->right);
	}
}
BSTNode* BSTreeFind(BSTree t, ET key){
	assert(t != NULL);
	BSTNode* p = t;
	while (p != NULL)
	{
		if (p->data < key){
			BSTreeFind(p->right, key);
		}
		else if (p->data > key){
			BSTreeFind(p->left, key);
		}
		else{
			return p;
		}
	}
	return NULL;
}
bool BSTreeErase(BSTree* t, BSTNode* p){
	if (*t != NULL){
		if (p->data < (*t)->data)
			BSTreeErase(&(*t)->left, p);
		else if (p->data > (*t)->data)
			BSTreeErase(&(*t)->right, p);
		else			//找到了p点
		{
			if (p->left == NULL && p->right == NULL){
				free(*t);
				*t = NULL;
			}
			else if (p->left != NULL && p->right == NULL){
				*t = p->left;
				free(p);
			}
			else if (p->left == NULL && p->right != NULL){
				*t = p->right;
				free(p);
			}
			else{
				BSTNode* s = p->left;
				while (s->right != NULL){
					s = s->right;
				}
				p->data = s->data;
				BSTreeErase(&p->left, s);
			}
		}
	}
}
#endif	/* _BINARYSEARCHTREE_H_ */