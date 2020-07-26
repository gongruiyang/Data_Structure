#ifndef _SEQSTACK_H_
#define _SEQSTACK_H_
#include "common.h"
/*****************************************************************************/
//定义常量
#define DEFAULT_STACK_CAPACITY 8
#define DEFAULT_STACK_GROW_MULTIPLE 2
typedef int ET;
/*****************************************************************************/
//顺序栈
typedef struct SeqStack
{
	ET* base;
	size_t capacity;
	int top;
}SeqStack;
/*****************************************************************************/
//函数声明
void SeqStackInitial(SeqStack* p, size_t cap);
bool IsEmpty(SeqStack* p);
bool IsFull(SeqStack* p);
void SeqStackGrow(SeqStack* p);
void SeqStackAddTop(SeqStack* p, ET val);
void SeqStackShowData(SeqStack* p);
void SeqStackDeleteTop(SeqStack* p);
ET SeqStackGetTop(SeqStack* p);
int SeqStackGetSize(SeqStack* p);
int SeqStackGetCapacity(SeqStack* p);
void SeqStackDestroy(SeqStack* p);
void SeqStackClear(SeqStack* p);
/*****************************************************************************/
//函数定义
void SeqStackInitial(SeqStack* p, size_t cap){
	assert(p != NULL);
	p->capacity = cap > DEFAULT_STACK_CAPACITY ? cap : DEFAULT_STACK_CAPACITY;
	p->top = 0;
	p->base = (ET*)malloc(sizeof(ET)* p->capacity);
}
bool IsEmpty(SeqStack* p){
	assert(p != NULL);
	return p->top == 0;
}
bool IsFull(SeqStack* p){
	assert(p != NULL);
	return p->top == p->capacity;
}
void SeqStackGrow(SeqStack* p){
	assert(p != NULL);
	p->capacity *= DEFAULT_STACK_GROW_MULTIPLE;
	ET* new_base = (ET*)realloc(p->base, sizeof(ET)* p->capacity);
	p->base = new_base;
}
void SeqStackAddTop(SeqStack* p, ET val){
	assert(p != NULL);
	if (IsFull(p)){
		SeqStackGrow(p);
	}
	p->base[p->top++] = val;
}
void SeqStackShowData(SeqStack* p){
	assert(p != NULL);
	if (IsEmpty(p)){
		printf("空表！\n");
		return;
	}
	int index = p->top - 1;
	while (index >= 0){
		printf("%2d|%2d|\n", index, p->base[index]);
		index--;
	}
	printf("  |__|\n");
}
void SeqStackDeleteTop(SeqStack* p){
	assert(p != NULL);
	if (IsEmpty(p)){
		printf("空表！\n");
		return;
	}
	p->top--;
}
ET SeqStackGetTop(SeqStack* p){
	assert(p != NULL);
	if (IsEmpty(p)){
		printf("空表！\n");
		return;
	}
	return 	p->base[p->top - 1];
}
int SeqStackGetSize(SeqStack* p){
	assert(p != NULL);
	if (IsEmpty(p)){
		printf("空表！\n");
		return;
	}
	return p->top;
}
int SeqStackGetCapacity(SeqStack* p){
	assert(p != NULL);
	if (IsEmpty(p)){
		printf("空表！\n");
		return;
	}
	return p->capacity;
}
void SeqStackDestroy(SeqStack* p){
	assert(p != NULL);
	p->capacity = DEFAULT_STACK_CAPACITY;
	p->top = 0;
	free(p->base);
	p->base = NULL;
}
void SeqStackClear(SeqStack* p){
	p->capacity = DEFAULT_STACK_CAPACITY;
	p->top = 0;
}
#endif	/*_SEQSTACK_H_*/