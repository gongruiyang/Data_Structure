#ifndef _SEQQUEUE_H_
#define _SEQQUEUE_H_
#include "common.h"
/*****************************************************************************/
//定义常量
#define DEFAULT_QUEUE_CAPACITY 8
#define DEFAULT_CAPACITY_GROW_MULTIPLE 2
typedef int ET;
/*****************************************************************************/
//顺序队列
typedef struct SeqQueue
{
	ET *base;
	size_t	capacity;
	size_t	head;
	size_t tail;
}SeqQueue;
/*****************************************************************************/
//函数声明
void SeqQueueInitial(SeqQueue *psq, size_t cap);
bool IsEmpty(SeqQueue *psq);
bool IsFull(SeqQueue *psq);
void CapacityGrow(SeqQueue *psq);
void SeqQueueIn(SeqQueue *psq, ET x);
void SeqQueueOut(SeqQueue *psq);
ET SeqQueueGetHead(SeqQueue *psq);
ET SeqQueueGetTail(SeqQueue *psq);
size_t SeqQueueGetLength(SeqQueue *psq);
void SeqQueueShowData(SeqQueue *psq);
void SeqQueueDestroy(SeqQueue *psq);
/*****************************************************************************/
//函数定义
void SeqQueueInitial(SeqQueue *psq, size_t cap){
	assert(psq != NULL);
	psq->capacity = cap > DEFAULT_QUEUE_CAPACITY ? cap : DEFAULT_QUEUE_CAPACITY;
	psq->head = psq->tail = 0;
	psq->base = (ET*)malloc(sizeof(ET)* psq->capacity);
}
bool IsEmpty(SeqQueue *psq){
	assert(psq != NULL);
	if (psq->tail == 0){
		return true;
	}
	return false;
}
bool IsFull(SeqQueue *psq){
	assert(psq != NULL);
	if (psq->tail == psq->capacity){
		return true;
	}
	return false;
}
void CapacityGrow(SeqQueue *psq){
	assert(psq != NULL);
	psq->capacity *= DEFAULT_CAPACITY_GROW_MULTIPLE;
	ET* new_base = (ET*)realloc(psq->base, psq->capacity);
	psq->base = new_base;
}
void SeqQueueIn(SeqQueue *psq, ET x){
	assert(psq != NULL);
	if (IsFull(psq)){
		CapacityGrow(psq);
	}
	psq->base[psq->tail++] = x;
}
void SeqQueueOut(SeqQueue *psq){
	assert(psq != NULL);
	if (psq->tail == psq->head){	//空队列 
		return;
	}
	else{
		if (psq->tail == 1){
			psq->tail--;
		}
		else{
			int i = psq->head;
			for (; i < psq->tail - 1; i++){
				psq->base[i] = psq->base[i + 1];
			}
			psq->tail--;
		}
	}
}
ET SeqQueueGetHead(SeqQueue *psq){
	assert(psq != NULL);
	if (IsEmpty(psq)){
		return;
	}
	return psq->base[psq->head];
}
ET SeqQueueGetTail(SeqQueue *psq){
	assert(psq != NULL);
	if (IsEmpty(psq)){
		return;
	}
	return psq->base[psq->tail - 1];
}
size_t SeqQueueGetLength(SeqQueue *psq){
	assert(psq != NULL);
	return psq->tail;
}
void SeqQueueShowData(SeqQueue *psq){
	assert(psq != NULL);
	int i = psq->head;
	printf("Head <- ");
	for (; i < psq->tail; i++){
		printf("%d <- ", psq->base[i]);
	}
	printf("Tail.\n");
}
void SeqQueueDestroy(SeqQueue *psq){
	assert(psq != NULL);
	psq->head = psq->tail = psq->capacity = 0;
	free(psq->base);
	psq = NULL;
}

#endif /*_SEQQUEUE_H_*/