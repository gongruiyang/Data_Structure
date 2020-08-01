#ifndef _HEAP_H_
#define _HEAP_H_
#include "common.h"
//***************************************************************************************
//常量定义
#define DEFAULT_HEAP_CAPACITY 20
typedef int ET;
//***************************************************************************************
//最小堆结构
typedef struct MinHeap
{
	ET* base;
	size_t capacity;
	size_t size;
}MinHeap;
//***************************************************************************************
//方法声明
void HeapInitial(MinHeap* php, size_t cap);
void HeapInsertData(MinHeap* php, ET x);
void HeapShow(MinHeap* php);
void HeapDeleteByValue(MinHeap* php, ET x);
//***************************************************************************************
//方法实现
void HeapInitial(MinHeap* php, size_t cap){
	assert(php != NULL);
	php->capacity = cap > DEFAULT_HEAP_CAPACITY ? cap : DEFAULT_HEAP_CAPACITY;
	php->base = (ET*)malloc(sizeof(ET)*php->capacity);
	php->size = 0;
}
void Swap(ET* x, ET* y){
	ET temp = *x;
	*x = *y;
	*y = temp;
}
bool IsEmpty(MinHeap* php){
	assert(php != NULL);
	return php->size == 0;
}
void HeapShiftUp(MinHeap* php, int start){
	int j = start;
	int i = (j - 1) / 2;
	while (j > 0){
		if (php->base[j] < php->base[i]){
			Swap(&php->base[j], &php->base[i]);
			j = i;
			i = (j - 1) / 2;
		}
		else{
			break;
		}
	}

}
void HeapInsertData(MinHeap* php, ET x){
	assert(php != NULL);
	if (php->size >= php->capacity){
		printf("不能插入！\n");
		return;
	}
	php->base[php->size] = x;
	HeapShiftUp(php, php->size);
	php->size++;
}
void HeapShiftDown(MinHeap* php, int start){
	int j = start;
	int i = php->base[2 * j + 1] < php->base[2 * j + 2] ? (2 * j + 1) : (2 * j + 2);
	while (j < php->size){
		if (php->base[j] > php->base[i]){
			Swap(&php->base[j], &php->base[i]);
			j = i;
			i = php->base[2 * j + 1] < php->base[2 * j + 2] ? (2 * j + 1) : (2 * j + 2);
		}
		else{
			break;
		}
	}
}
void HeapDeleteRoot(MinHeap* php){
	assert(php != NULL);
	if (IsEmpty(php)){
		printf("空树！\n");
		return;
	}
	php->base[0] = php->base[php->size - 1];
	php->size--;
	HeapShiftDown(php, 0);
}
void HeapShow(MinHeap* php){
	assert(php != NULL);
	int i = 0;
	for (; i < php->size; i++){
		printf("%d ", php->base[i]);
	}
	printf("\n");
}

#endif