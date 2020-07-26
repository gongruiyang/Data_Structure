#ifndef _LINKEDQUEUE_H_
#define _LINKEDQUEUE_H_
#include "common.h"
/*****************************************************************************/
//���峣��
typedef int ET;
/*****************************************************************************/
//������
typedef struct Node
{
	ET data;
	Node* next;
}Node;
typedef struct LinkedQueue
{
	Node* head;
	Node* tail;
}LinkedQueue;
/*****************************************************************************/
//��������
Node* CreateNode(ET val);
bool IsEmpty(LinkedQueue *pq);
void LinkedQueueInit(LinkedQueue *pq);
void LinkedQueueIn(LinkedQueue *pq, ET val);
void LinkedQueueOut(LinkedQueue *pq);
ET LinkedQueueGetFront(LinkedQueue *pq);
int LinkedQueueSize(LinkedQueue *pq);
void LinkedQueueShow(LinkedQueue *pq);
void LinkedQueueDestroy(LinkedQueue *pq);
/*****************************************************************************/
//��������
Node* CreateNode(ET val){
	Node* s = (Node*)malloc(sizeof(Node));
	assert(s != NULL);
	s->data = val;
	s->next = NULL;
	return s;
}
bool IsEmpty(LinkedQueue *pq){
	assert(pq != NULL);
	return pq->head == NULL;
}
void LinkedQueueInit(LinkedQueue *pq){
	assert(pq != NULL);
	pq->head = pq->tail = NULL;
}
void LinkedQueueIn(LinkedQueue *pq, ET val){
	assert(pq != NULL);
	Node* s = CreateNode(val);
	if (pq->head == NULL){	//�ն��� 
		pq->head = pq->tail = s;
	}
	else{	//���зǿ� 
		pq->tail->next = s;
		pq->tail = s;
	}
}
void LinkedQueueOut(LinkedQueue *pq){
	assert(pq != NULL);
	Node* s = pq->head;
	if (pq->head == NULL){	//�ն��� 
		return;
	}
	else{	//���зǿ� 
		if (pq->head->next == pq->tail){	//ֻ��һ��Ԫ�� 
			pq->head = pq->tail = NULL;
			free(s);
		}
		else{	//���Ԫ�� 
			pq->head = s->next;
			free(s);
		}
	}
}
ET LinkedQueueGetFront(LinkedQueue *pq){
	assert(pq != NULL);
	if (pq->head == NULL)	//�ն��� 
		return -1;
	return pq->tail->data;
}
int LinkedQueueSize(LinkedQueue *pq){
	assert(pq != NULL);
	size_t len = 0;
	if (pq->head == NULL){
		return len;
	}
	else{
		Node* p = pq->head;
		while (p != NULL){
			p = p->next;
			len++;
		}
	}
	return len;
}
void LinkedQueueShow(LinkedQueue *pq){
	assert(pq != NULL);
	Node* p = pq->head;
	printf("Head->");
	while (p != NULL){
		printf("%d->", p->data);
		p = p->next;
	}
	printf("Tail.\n");
}
void LinkedQueueDestroy(LinkedQueue *pq){
	assert(pq != NULL);
	if (pq->head == NULL){
		return;
	}
	else{
		Node* p = pq->head;
		Node* q = pq->head;
		while (q != NULL){
			q = q->next;
			free(p);
			p = q;
		}
		pq->head = pq->tail = NULL;
	}
}
#endif	/*_LINKEDQUEUE_H_*/