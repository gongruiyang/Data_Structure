#ifndef _SCLINKEDLIST_H_
#define _SCLINKEDLIST_H_
#include "common.h"
//***************************************************************************************
//��������
typedef int ET;
/*****************************************************************************/
//����ѭ������
typedef struct Node
{
	ET data;
	Node* next;
}Node;
typedef Node* SCList;
//***************************************************************************************
//��������
void SCLinkedListInitial(SCList *phead);
Node* SCLinkedListGetNode(ET val);
void SCLinkedListAddFromHead(SCList *phead);
void SCLinkedListAddFromTail(SCList *phead);
void SCLinkedListShowData(SCList phead);
//***************************************************************************************
//����ʵ��
void SCLinkedListInitial(SCList *phead){
	*phead = NULL;
}
Node* SCLinkedListGetNode(ET val){
	Node* s = (Node*)malloc(sizeof(Node));
	assert(s != NULL);
	s->data = val;
	s->next = NULL;
	return s;
}
void SCLinkedListAddFromTail(SCList *phead, ET val){
	assert(phead != NULL);
	Node* s = SCLinkedListGetNode(val);
	Node* p = *phead;
	if (p == NULL){
		*phead = s;
		s->next = *phead;	//s->next = *phead;
	}
	else{
		while (p->next != *phead){
			p = p->next;
		}
		p->next = s;
		s->next = *phead;
	}
}
void SCLinkedListAddFromHead(SCList *phead, ET val){
	assert(phead != NULL);
	Node* s = SCLinkedListGetNode(val);
	Node* p = *phead;
	if (p == NULL){
		*phead = s;
	}
	else{
		while (p->next != *phead){
			p = p->next;
		}
		p->next = s;
	}
	s->next = *phead;
	*phead = s;
}
void SCLinkedListShowData(SCList phead){
	if (phead == NULL){
		printf("����ѭ������Ϊ�գ�\n");
		return;
	}
	printf("Over->%d->", phead->data);
	Node* p = phead->next;
	while (p != phead){
		printf("%d->", p->data);
		p = p->next;
	}
	printf("Over\n");
}
#endif /*_SCLINKEDLIST_H_*/
