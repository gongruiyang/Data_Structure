#ifndef _BCLINKEDLIST_H_
#define _BCLINKEDLIST_H_
#include "common.h"
//***************************************************************************************
//常量定义
typedef int ET;
typedef struct Node
{
	ET data;
	Node* next;
	Node* prev;
}Node;
typedef Node* BCList;
//***************************************************************************************
//函数声明
void BCLinkedListInitial(BCList phead);

//***************************************************************************************
//函数实现
void BCLinkedListInitial(BCList phead){

}

#endif // _BCLINKEDLIST_H_
