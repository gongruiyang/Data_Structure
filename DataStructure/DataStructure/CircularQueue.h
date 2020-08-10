#ifndef _CIRCULARQUEUE_H_
#define _CIRCULARQUEUE_H_
#include "common.h"
/*****************************************************************************/
//���峣��
typedef int ET;
/*****************************************************************************/
//ѭ������
typedef struct {
	ET* base;
	int head;
	int tail;
	int cap;
	int size;
} MyCircularQueue;
/*****************************************************************************/
//��������
MyCircularQueue* myCircularQueueCreate(int k);	/** �����������ö��г���Ϊ k */
bool myCircularQueueIsEmpty(MyCircularQueue* obj);/** ���ѭ�������Ƿ�Ϊ�� */
bool myCircularQueueIsFull(MyCircularQueue* obj);/** ���ѭ�������Ƿ������� */
bool myCircularQueueEnQueue(MyCircularQueue* obj, ET value);/** ��ѭ�����в���һ��Ԫ�ء�����ɹ������򷵻��� */
void myCircularQueueShowData(MyCircularQueue* obj); /*��ӡ�����е�Ԫ��*/
bool myCircularQueueDeQueue(MyCircularQueue* obj);/** ��ѭ��������ɾ��һ��Ԫ�ء�����ɹ�ɾ���򷵻��� */
int myCircularQueueFront(MyCircularQueue* obj);/** �Ӷ��׻�ȡԪ�ء��������Ϊ�գ����� -1  */
int myCircularQueueRear(MyCircularQueue* obj);/** ��ȡ��βԪ�ء��������Ϊ�գ����� -1 */
void myCircularQueueFree(MyCircularQueue* obj); /*�ݻٶ��нṹ*/
/*****************************************************************************/
//��������
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
		printf("�ն��У�");
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