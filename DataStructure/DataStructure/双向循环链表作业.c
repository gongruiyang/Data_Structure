#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <Windows.h>
#pragma warning(disable:4996)

typedef int LTDataType;
typedef struct ListNode
{
	LTDataType _data;
	struct ListNode* _next;
	struct ListNode* _prev;
}ListNode;

// 创建返回链表的头结点.
ListNode* ListCreate(){
	ListNode* pHead = (ListNode*)malloc(sizeof(ListNode));
	assert(pHead != NULL);
	pHead->_data = -1;
	pHead->_next = pHead->_prev = pHead;
	return pHead;
}
// 双向链表销毁
void ListDestory(ListNode* pHead){
	assert(pHead != NULL);
	ListNode* p = pHead;
	ListNode* q = pHead;
	if (q->_next == q){			//空表
		free(pHead);
		pHead = NULL;
		return;
	}
	q = q->_next;
	p = p->_next;
	if (q->_next == pHead){		//只有一个数据结点时
		free(q);
		free(pHead);
		q = NULL;
		pHead = NULL;
		return;
	}
	while (q != pHead){			//表中有多个数据时
		q = q->_next;
		free(p);
		p = q;
	}
	free(pHead);
	pHead = NULL;
}
// 双向链表打印
void ListPrint(ListNode* pHead){
	assert(pHead != NULL);
	ListNode* p = pHead->_next;
	
	printf("Head<->%d<->", pHead->_data);
	while (p != pHead){
		printf("%d<->", p->_data);
		p = p->_next;
	}
	printf("Tail");
}
// 双向链表尾插
void ListPushBack(ListNode* pHead, LTDataType x){
	assert(pHead != NULL);
	ListNode* s = (ListNode*)malloc(sizeof(ListNode));
	assert(s != NULL);
	s->_next = s->_prev = NULL;
	s->_data = x;
	ListNode* p = pHead->_prev;
	p->_next = s;
	s->_next = pHead;
	s->_prev = p;
	pHead->_prev = s;
}
// 双向链表尾删
void ListPopBack(ListNode* pHead){
	assert(pHead != NULL);
	ListNode* p = pHead->_prev;
	if (p == pHead){	//空表
		return;
	}
	ListNode* q = p->_prev;
	q->_next = pHead;
	pHead->_prev = q;
	free(p);
	p = NULL;
}
// 双向链表头插
void ListPushFront(ListNode* pHead, LTDataType x){
	assert(pHead != NULL);
	ListNode* s = (ListNode*)malloc(sizeof(ListNode));
	assert(s != NULL);
	s->_data = x;
	ListNode* p = pHead->_next;
	pHead->_next = s;
	s->_next = p;
	s->_prev = pHead;
	p->_prev = s;
}
// 双向链表头删
void ListPopFront(ListNode* pHead){
	assert(pHead != NULL);
	ListNode* p = pHead->_next;
	if (p == pHead){
		return;
	}
	ListNode* q = p->_next;
	pHead->_next = q;
	q->_prev = pHead;
	free(p);
	p = NULL;
}
// 双向链表查找
ListNode* ListFind(ListNode* pHead, LTDataType x){
	assert(pHead != NULL);
	ListNode* p = pHead->_next;
	while (p != pHead && p->_data != x){
		p = p->_next;
	}
	if (p == pHead){
		return NULL;
	}
	return p;
}
// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x){
	assert(pos != NULL);
	ListNode* s = (ListNode*)malloc(sizeof(ListNode));
	assert(s != NULL);
	s->_data = x;
	ListNode* p = pos->_prev;
	p->_next = s;
	s->_next = pos;
	s->_prev = p;
	pos->_prev = s;
}
// 双向链表删除pos位置的节点
void ListErase(ListNode* pos){
	assert(pos != NULL);
	ListNode* p = pos->_prev;
	ListNode* q = pos->_next;
	p->_next = q;
	q->_prev = p;
	free(pos);
	pos = NULL;
}