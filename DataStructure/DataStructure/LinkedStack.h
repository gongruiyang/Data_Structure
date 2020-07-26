#ifndef _LINKEDSTACK_H
#define _LINKEDSTACK_H
#include "common.h"
/*****************************************************************************/
//���峣��
typedef int ET;
/*****************************************************************************/
//��ջ
typedef struct StackNode{
	ET data;
	struct StackNode* next;
}StackNode;
typedef StackNode* LinkStack;
/*****************************************************************************/
//��������
void LinkedStackInitial(LinkStack *pst);
StackNode* GetNode(ET val);
void LinkedStackAddTop(LinkStack *pst, ET val);
void LinkedStackDeletePop(LinkStack *pst);
ET LinkedStackGetTop(LinkStack *pst);
void LinkedStackShowData(LinkStack *pst);
int LinkedStackGetLength(LinkStack *pst);
void LinkedStackDestroy(LinkStack *pst);
/*****************************************************************************/
//��������
void LinkedStackInitial(LinkStack *pst){
	assert(pst != NULL);
	*pst = NULL;
}
StackNode* GetNode(ET val){	//������ 
	StackNode* s = (StackNode*)malloc(sizeof(StackNode));
	assert(s != NULL);
	s->data = val;
	s->next = NULL;
	return s;
}
void LinkedStackAddTop(LinkStack *pst, ET val){
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
	if (*pst == NULL){	//��ջ 
		printf("��ջ��\n");
		return;
	}
	else{	//ջ�ǿ� 
		StackNode* temp = *pst;
		if (temp->next == NULL){		//ջֻ��һ��Ԫ�� 
			free(temp);
			*pst = NULL;
		}
		else{						//ջ���ж��Ԫ�� 
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
	if (*pst == NULL){	//��ջ 
		printf("��ջ��\n");
		return -1;
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
void LinkedStackShowData(LinkStack *pst){
	assert(pst != NULL);
	if (*pst == NULL){		//��ջ 
		printf("��ջ��\n");
	}
	else{					//ջ�ǿ� 
		StackNode* temp = *pst;
		printf("  |==|\n");
		int i = 0;
		while (temp->next != NULL){
			printf("%2d|%2d|\n", i, temp->data);
			printf("  |��|\n");
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