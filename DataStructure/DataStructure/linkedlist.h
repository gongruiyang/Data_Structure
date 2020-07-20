#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_
#include "common.h"
//***************************************************************************************
//��������
typedef int ET;
typedef struct Node
{
	ET data;		//���ڴ洢����
	Node* next;		//���ڴ洢�¸��ڵ�ĵ�ַ
}Node;
typedef Node* List;
//***************************************************************************************
//��������
void linkedListInitial(List* phead);		
//û��ͷ��������µ�ͷ�巨��β�巨
void linkedListCreateWithoutHeadNodeFromTail(List* phead);
void linkedListCreateWithoutHeadNodeFromHead(List* phead);
//��ͷ��������µ�ͷ�巨��β�巨
void linkedListCreateWithHeadNodeFromHead(List* phead);
void linkedListCreateWithHeadNodeFromTail(List* phead);
void linkedListShow(List* phead);
//***************************************************************************************
//��������
void linkedListInitial(List* phead){
	assert(phead != NULL);
	*phead = NULL;
}
void linkedListCreateWithoutHeadNodeFromTail(List* phead){
	assert(phead != NULL);
	*phead = (Node*)malloc(sizeof(Node));
	assert(*phead != NULL);
	(*phead)->data = 1;
	(*phead)->next = NULL;

	Node* p = *phead;
	for (int i = 2; i <= 10; i++)
	{
		Node* s = (Node*)malloc(sizeof(Node));
		assert(s != NULL);
		s->data = i;
		s->next = NULL;

		p->next = s;
		p = s;
	}
}
void linkedListCreateWithoutHeadNodeFromHead(List* phead){
	assert(phead != NULL);
	*phead = (Node*)malloc(sizeof(Node));
	assert(phead != NULL);
	(*phead)->data = 1;
	(*phead)->next = NULL;
	int i = 2;
	for (; i <= 10; i++){
		Node* s = (Node*)malloc(sizeof(Node));
		assert(s != NULL);
		s->data = i;

		s->next = *phead;
		*phead = s;
	}
}
void linkedListCreateWithHeadNodeFromHead(List* phead){
	assert(phead != NULL);
	*phead = (Node*)malloc(sizeof(Node));
	assert(phead != NULL);

	(*phead)->data = -1;
	(*phead)->next = NULL;

	int i = 1;
	for (; i <= 10; i++)
	{
		Node* s = (Node*)malloc(sizeof(Node));
		assert(s != NULL);
		s->data = i;

		s->next = (*phead)->next;
		(*phead)->next = s;
	}
}
void linkedListCreateWithHeadNodeFromTail(List* phead){
	assert(phead != NULL);
	*phead = (Node*)malloc(sizeof(Node));
	assert(phead != NULL);
	(*phead)->data = -1;
	(*phead)->next = NULL;

	Node *p = *phead;
	int i = 1;
	for (; i <= 10; i++)
	{
		Node* s = (Node*)malloc(sizeof(Node));
		assert(s != NULL);
		s->data = i;
		s->next = NULL;
		
		p->next = s;
		p = s;
	}
}

void linkedListShow(List phead){
	Node *p = phead;
	while (p != NULL){
		printf("%d--->", p->data);
		p = p->next;
	}
	printf("Over\n");
}
#endif // !_LINKEDLIST_H_
