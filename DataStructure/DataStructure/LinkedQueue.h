#ifndef _LINKEDQUEUE_H_
#define _LINKEDQUEUE_H_
#include "common.h"
/*****************************************************************************/
//定义常量
typedef int ET;
/*****************************************************************************/
//链队列
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
//函数声明
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
//函数定义
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
	if (pq->head == NULL){	//空队列 
		pq->head = pq->tail = s;
	}
	else{	//队列非空 
		pq->tail->next = s;
		pq->tail = s;
	}
}
void LinkedQueueOut(LinkedQueue *pq){
	assert(pq != NULL);
	Node* s = pq->head;
	if (pq->head == NULL){	//空队列 
		return;
	}
	else{	//队列非空 
		if (pq->head->next == pq->tail){	//只有一个元素 
			pq->head = pq->tail = NULL;
			free(s);
		}
		else{	//多个元素 
			pq->head = s->next;
			free(s);
		}
	}
}
ET LinkedQueueGetFront(LinkedQueue *pq){
	assert(pq != NULL);
	if (pq->head == NULL)	//空队列 
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