#ifndef _CIRCULARQUEUE_H_
#define _CIRCULARQUEUE_H_
#include "common.h"
/*****************************************************************************/
//定义常量
typedef int ET;
/*****************************************************************************/
//循环队列
typedef struct {
	ET* base;
	int head;
	int tail;
	int cap;
	int size;
} MyCircularQueue;
/*****************************************************************************/
//函数声明
MyCircularQueue* myCircularQueueCreate(int k);	/** 构造器，设置队列长度为 k */
bool myCircularQueueIsEmpty(MyCircularQueue* obj);/** 检查循环队列是否为空 */
bool myCircularQueueIsFull(MyCircularQueue* obj);/** 检查循环队列是否已满。 */
bool myCircularQueueEnQueue(MyCircularQueue* obj, ET value);/** 向循环队列插入一个元素。如果成功插入则返回真 */
void myCircularQueueShowData(MyCircularQueue* obj); /*打印队列中的元素*/
bool myCircularQueueDeQueue(MyCircularQueue* obj);/** 从循环队列中删除一个元素。如果成功删除则返回真 */
int myCircularQueueFront(MyCircularQueue* obj);/** 从队首获取元素。如果队列为空，返回 -1  */
int myCircularQueueRear(MyCircularQueue* obj);/** 获取队尾元素。如果队列为空，返回 -1 */
void myCircularQueueFree(MyCircularQueue* obj); /*摧毁队列结构*/
/*****************************************************************************/
//函数定义
MyCircularQueue* myCircularQueueCreate(int k) {
	MyCircularQueue* q = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	q->cap = k;
	q->base = (ET*)malloc(sizeof(ET)* q->cap);
	assert(q->base != NULL);
	q->size = q->head = q->tail = 0;
	return q;
}
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
	assert(obj != NULL);
	return obj->size == 0;
}
bool myCircularQueueIsFull(MyCircularQueue* obj) {
	assert(obj != NULL);
	return obj->size == obj->cap;
}
bool myCircularQueueEnQueue(MyCircularQueue* obj, ET value) {
	assert(obj != NULL);
	if (!myCircularQueueIsFull(obj) && obj->tail < obj->cap)
	{
		obj->base[obj->tail] = value;
		obj->tail++;
		obj->size++;
	}
	else if (!myCircularQueueIsFull(obj) && obj->tail == obj->cap)
	{
		obj->tail = 0;
		obj->base[obj->tail] = value;
		obj->tail++;
		obj->size++;
	}
	else
		return false;
	return true;
}
void myCircularQueueShowData(MyCircularQueue* obj){
	assert(obj != NULL);
	if (obj->head < obj->tail)
	{
		for (int i = obj->head; i<obj->tail; i++)
		{
			printf("%d ", obj->base[i]);
		}
	}
	else if (obj->head >= obj->tail)
	{
		for (int i = obj->head; i < obj->cap; i++)
		{
			printf("%d ", obj->base[i]);
		}
		for (int i = 0; i < obj->tail; i++)
		{
			printf("%d ", obj->base[i]);
		}
	}
	else if (myCircularQueueIsEmpty(obj))
	{
		printf("空队列！");
	}
	printf("\n");
}
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
	assert(obj != NULL);
	if (myCircularQueueIsEmpty(obj))
		return false;
	else if (obj->head == obj->cap - 1)
		obj->head = 0;
	else
		obj->head++;
	obj->size--;
	return true;
}
int myCircularQueueFront(MyCircularQueue* obj) {
	assert(obj != NULL);
	if (myCircularQueueIsEmpty(obj))
		return -1;
	return obj->base[obj->head];
}
int myCircularQueueRear(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj))
		return -1;
	return obj->base[obj->tail - 1];
}
void myCircularQueueFree(MyCircularQueue* obj) {
	assert(obj != NULL);
	obj->cap = obj->head = obj->size = obj->tail = 0;
	free(obj->base);
	obj->base = NULL;
	free(obj);
	obj = NULL;
}
#endif /* _CIRCULARQUEUE_H_ */