#ifndef _BCLINKEDLIST_H_
#define _BCLINKEDLIST_H_
#include "common.h"
//***************************************************************************************
//��������
typedef int ET;
typedef struct Node
{
	ET data;
	Node* next;
	Node* prev;
}Node;
typedef Node* BCList;
//***************************************************************************************
//��������
void BCLinkedListInitial(BCList phead);

//***************************************************************************************
//����ʵ��
void BCLinkedListInitial(BCList phead){

}

#endif // _BCLINKEDLIST_H_
