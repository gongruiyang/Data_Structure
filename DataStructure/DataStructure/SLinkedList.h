#ifndef _SLINKEDLIST_H_
#define _SLINKEDLIST_H_
#include "common.h"
//***************************************************************************************
//常量定义
typedef int SLTDateType;
/*****************************************************************************/
//单向循环链表
typedef struct SListNode
{
	SLTDateType data;
	struct SListNode* next;
}SListNode;
//***************************************************************************************
//函数声明
// 动态申请一个节点
SListNode* BuySListNode(SLTDateType x);
// 单链表打印
void SListPrint(SListNode* plist);
// 单链表尾插
void SListPushBack(SListNode** pplist, SLTDateType x);
// 单链表的头插
void SListPushFront(SListNode** pplist, SLTDateType x);
// 单链表的尾删
void SListPopBack(SListNode** pplist);
// 单链表头删
void SListPopFront(SListNode** pplist);
// 单链表查找
SListNode* SListFind(SListNode* plist, SLTDateType x);
// 单链表在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？
void SListInsertAfter(SListNode* pos, SLTDateType x);
// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？
void SListEraseAfter(SListNode* pos);
// 单链表的销毁
void SListDestory(SList* plist);
//***************************************************************************************
//函数实现

#endif /* _SLINKEDLIST_H_ */