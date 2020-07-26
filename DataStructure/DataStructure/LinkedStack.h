#ifndef _LINKEDSTACK_H
#define _LINKEDSTACK_H
#include "common.h"
/*****************************************************************************/
//定义常量
typedef int ET;
/*****************************************************************************/
//链栈
typedef struct StackNode{
	ET data;
	struct StackNode* next;
}StackNode;
typedef StackNode* LinkStack;
/*****************************************************************************/
//函数声明
void LinkedStackInitial(LinkStack *pst);
StackNode* GetNode(ET val);
void LinkedStackAddTop(LinkStack *pst, ET val);
void LinkedStackDeletePop(LinkStack *pst);
ET LinkedStackGetTop(LinkStack *pst);
void LinkedStackShowData(LinkStack *pst);
int LinkedStackGetLength(LinkStack *pst);
void LinkedStackDestroy(LinkStack *pst);
/*****************************************************************************/
//函数定义
void LinkedStackInitial(LinkStack *pst){
	assert(pst != NULL);
	*pst = NULL;
}
StackNode* GetNode(ET val){	//申请结点 
	StackNode* s = (StackNode*)malloc(sizeof(StackNode));
	assert(s != NULL);
	s->data = val;
	s->next = NULL;
	return s;
}
void LinkedStackAddTop(LinkStack *pst, ET val){
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
	if (*pst == NULL){	//空栈 
		printf("空栈！\n");
		return;
	}
	else{	//栈非空 
		StackNode* temp = *pst;
		if (temp->next == NULL){		//栈只有一个元素 
			free(temp);
			*pst = NULL;
		}
		else{						//栈中有多个元素 
			while (temp->next->next != NULL){
				temp = temp->next;
			}
			StackNode* p = temp->next;
			free(p);
			temp->next = NULL;
		}
	}
}
ET LinkedStackGetTop(LinkStack *pst){
	assert(pst != NULL);
	if (*pst == NULL){	//空栈 
		printf("空栈！\n");
		return -1;
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
void LinkedStackShowData(LinkStack *pst){
	assert(pst != NULL);
	if (*pst == NULL){		//空栈 
		printf("空栈！\n");
	}
	else{					//栈非空 
		StackNode* temp = *pst;
		printf("  |==|\n");
		int i = 0;
		while (temp->next != NULL){
			printf("%2d|%2d|\n", i, temp->data);
			printf("  |↓|\n");
			temp = temp->next;
			i++;
		}
		printf("%2d|%2d|\n", i, temp->data);
	}
}
int LinkedStackGetLength(LinkStack *pst){
	assert(pst != NULL);
	int len = 1;
	if (*pst == NULL){
		len = 0;
	}
	else{
		StackNode* p = *pst;
		while (p->next != NULL){
			p = p->next;
			len++;
		}
	}
	return len;
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
#endif	/*_LINKEDSTACK_H*/