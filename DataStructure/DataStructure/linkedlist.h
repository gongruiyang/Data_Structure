#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_
#include "common.h"
//***************************************************************************************
//常量定义
typedef int ET;
/*****************************************************************************/
//单向链表
typedef struct Node
{
	ET data;		//用于存储数据
	Node* next;		//用于存储下个节点的地址
}Node;
typedef Node* List;
//***************************************************************************************
//函数声明
void linkedListInitial(List* phead);		
//无头结点单链表 函数声明
#if 0
void linkedListCreateWithoutHeadNodeFromTail(List* phead);	//头插法
void linkedListCreateWithoutHeadNodeFromHead(List* phead);	//尾插法
#endif 
void  linkedListInitial(List* phead);											//初始化链表
void  linkedListWithoutHeadNodeAddFromHead(List* phead, ET val);				//头插法
void  linkedListWithoutHeadNodeAddFromTail(List* phead, ET val);				//尾插法
Node* linkedLIstWithoutHeadNodeGetHead(List* phead);							//获取头结点
Node* linkedListWithoutHeadNodeGetTail(List* phead);							//获取尾结点
int   linkedListWithoutHeadNodeGetLength(List* phead);							//获取表长度
void  linkedListWithoutHeadNodeDropHead(List* phead);							//删除头结点
void  linkedListWithoutHeadNodeDropTail(List* phead);							//删除尾节点
void  linkedListWithoutHeadNodeSortByValue(List* phead);						//排序
void  linkedListWithoutHeadNodeInsertByValue(List* phead, ET val);				//按值插入
void  linkedListWithoutHeadNodeInsertByPosition(List* phead, int pos, ET val);	//按位置插入
void  linkedListWithoutHeadNodeDropByValue(List* phead, ET val);				//按值删除
void  linkedListWithoutHeadNodeDropByPosition(List* phead, int pos, ET val);	//按位置删除
void  linkedListWithoutHeadNodeReverseList(List* phead);						//反转链表
void  linkedListWithoutHeadNodeShowData(List* phead);							//展示数据
void  linkedListWithoutHeadNodeClearList(List* phead);							//清空链表
void  linkedListWithoutHeadNodeDestroyList(List* phead);						//摧毁链表
void  linkedListWithoutHeadNodeEraseByValue(List* phead, ET val);				//全表彻底删除某一个值

//有头结点的情况下的头插法和尾插法
void linkedListCreateWithHeadNodeFromHead(List* phead);
void linkedListCreateWithHeadNodeFromTail(List* phead);

void linkedListShow(List* phead);
//***************************************************************************************
#if 0
void linkedListCreateWithoutHeadNodeFromTail(List* phead){
	assert(phead != NULL);
	*phead = (Node*)malloc(sizeof(Node));
	assert(*phead != NULL);

	(*phead)->data = 1;
	(*phead)->next = NULL;

	Node* p = *phead;
	for (int i = 2; i <= 10; i++)
	{
		Node* s = (Node*)malloc(sizeof(Node));
		assert(s != NULL);
		s->data = i;
		s->next = NULL;

		p->next = s;
		p = s;
	}
}
void linkedListCreateWithoutHeadNodeFromHead(List* phead){
	assert(phead != NULL);
	*phead = (Node*)malloc(sizeof(Node));
	assert(phead != NULL);

	(*phead)->data = 1;
	(*phead)->next = NULL;

	int i = 2;
	for (; i <= 10; i++){
		Node* s = (Node*)malloc(sizeof(Node));
		assert(s != NULL);
		s->data = i;

		s->next = *phead;
		*phead = s;
	}
}
#endif 
//无头结点单链表 函数实现
void  linkedListInitial(List* phead){
	assert(phead != NULL);
	*phead = NULL;
}
void  linkedListWithoutHeadNodeAddFromHead(List* phead, ET val){
	assert(phead != NULL);

	Node* s = (Node*)malloc(sizeof(Node));
	assert(s != NULL);
	s->data = val;

	s->next = *phead;
	*phead = s;

}
void  linkedListWithoutHeadNodeAddFromTail(List* phead, ET val){
	assert(phead != NULL);
	Node* p = *phead;

	if (p == NULL){	//表为空时 
		*phead = (Node*)malloc(sizeof(Node));
		assert(*phead != NULL);
		(*phead)->data = val;
		(*phead)->next = NULL;
	}
	else{			//表非空时 
		Node* s = (Node*)malloc(sizeof(Node));
		assert(s != NULL);
		s->data = val;
		s->next = NULL;

		while (p->next != NULL){
			p = p->next;
		}
		p->next = s;
	}
}
Node* linkedLIstWithoutHeadNodeGetHead(List* phead)		
{
	assert(phead != NULL);
	if ((*phead) == NULL){
		return NULL;
	}
	else{
		return (*phead);
	}
}
Node* linkedListWithoutHeadNodeGetTail(List* phead){
	assert(phead != NULL);
	if ((*phead) == NULL){
		return NULL;
	}
	else{
		Node* p = *phead;
		while (p->next != NULL){
			p = p->next;
		}
		return p;
	}
}
int   linkedListWithoutHeadNodeGetLength(List* phead){
	assert(phead != NULL);
	if ((*phead) == NULL) return 0;

	int length = 1;
	Node* p = *phead;
	while (p->next != NULL){
		length++;
		p = p->next;
	}
	return length;
}
void  linkedListWithoutHeadNodeDropHead(List* phead){
	assert(phead != NULL);
	if ((*phead) == NULL){
		printf("表已空！无法删除！\n");
		return;
	}
	Node *p = *phead;
	if (p->next == NULL){
		(*phead) = NULL;
		free(p);
	}
	else{
		(*phead) = p->next;
		free(p);
	}
	printf("首元结点已删除！\n");
}
void  linkedListWithoutHeadNodeDropTail(List* phead){
	assert(phead != NULL);
	if ((*phead) == NULL){
		printf("表已空！无法删除！\n");
		return;
	}
	Node *p = *phead;
	if (p->next == NULL){
		(*phead) = NULL;
		free(p);
	}
	else{
		while (p->next->next != NULL){
			p = p->next;
		}
		Node *q = p->next;
		free(q);
		p->next = NULL;
	}
	printf("末尾结点已删除！\n");
}
void  linkedListWithoutHeadNodeSortByValue(List* phead){
	assert(phead != NULL);
	if ((*phead) == NULL){
		printf("表已空！无法排序！\n");
		return;
	}
	if ((*phead)->next == NULL)	return; 	//一个结点
	Node* p = (*phead)->next;
	Node* q = (*phead)->next;
	(*phead)->next = NULL;
	while (q != NULL){
		q = q->next;
		if ((*phead)->data < p->data){
			Node* temp = *phead;
			while (temp->next != NULL && temp->next->data < p->data){
				temp = temp->next;
			}
			p->next = temp->next;
			temp->next = p;

		}
		else{
			p->next = *phead;
			*phead = p;
		}
		p = q;
	}
}
void  linkedListWithoutHeadNodeInsertByValue(List* phead, ET val)				
{
	assert(phead != NULL);
	if ((*phead) == NULL){	//表空时
		linkedListWithoutHeadNodeAddFromHead(phead, val);
		printf("按值插入数据完成！\n");
		return;
	}
	linkedListWithoutHeadNodeSortByValue(phead);

	Node* s = (Node*)malloc(sizeof(Node));
	s->data = val;
	s->next = NULL;

	if ((*phead)->next == NULL && (*phead)->data > val){	//表中只有一个大于val的结点时
		s->next = *phead;
		*phead = s;
		printf("按值插入数据完成！\n");
		return;
	}
	Node* p = *phead;
	while (p->next != NULL && p->next->data < val){
		p = p->next;
	}
	s->next = p->next;
	p->next = s;
	printf("按值插入数据完成！\n");
}
void  linkedListWithoutHeadNodeInsertByPosition(List* phead, int pos, ET val){
	assert(phead != NULL);
	int len = linkedListWithoutHeadNodeGetLength(phead);
	if (pos <= 0 || pos > len){
		printf("插入位置不合法！\n");
		return;
	}
	int position = pos;
	position--;

	Node* s = (Node*)malloc(sizeof(Node));
	s->data = val;
	s->next = NULL;

	if (position == 0){
		linkedListWithoutHeadNodeAddFromHead(phead, val);
		printf("已在%d位置上插入%d\n", pos, val);
		return;
	}
	Node* p = *phead;
	while (position != 1){
		p = p->next;
		position--;
	}
	s->next = p->next;
	p->next = s;
	printf("已在%d位置上插入%d\n", pos, val);
}
void  linkedListWithoutHeadNodeDropByValue(List* phead, ET val){
	assert(phead != NULL);
	if ((*phead) == NULL){
		printf("空表无法删除\n");
		return;
	}
	linkedListWithoutHeadNodeSortByValue(phead);

	Node* p = *phead;
	if (p->data == val){
		*phead = p->next;
		free(p);
		printf("第一次出现的%d这个数据已被删除!\n", val);
		return;
	}
	while (p->next != NULL){
		if (p->next->data == val){
			Node* q = p->next;
			p->next = q->next;
			free(q);
			printf("第一次出现的%d这个数据已被删除!\n", val);
			return;
		}
		p = p->next;
	}
	printf("没有%d这个数据!\n", val);
}
void  linkedListWithoutHeadNodeDropByPosition(List* phead, int pos){
	assert(phead != NULL);
	int len = linkedListWithoutHeadNodeGetLength(phead);
	if (pos <= 0 || pos > len){
		printf("删除位置不合法！\n");
		return;
	}
	int position = pos;
	position--;

	if (position == 0){
		linkedListWithoutHeadNodeDropHead(phead);
		printf("已删除%d位置上的数据！\n", pos);
		return;
	}
	if (position == len){
		linkedListWithoutHeadNodeGetTail(phead);
	}

	Node* p = *phead;
	while (position != 1){
		p = p->next;
		position--;
	}
	Node* s = p->next;
	p->next = s->next;
	free(s);
	printf("已删除%d位置上的数据！\n", pos);
}
void  linkedListWithoutHeadNodeReverseList(List* phead){	
	assert(phead != NULL);
	if ((*phead)->next == NULL){
		printf("逆置完成！\n");
		return;
	}

	Node* p = (*phead)->next;
	Node* q = (*phead)->next;

	(*phead)->next = NULL;

	while (q != NULL){
		q = q->next;

		p->next = *phead;
		*phead = p;
		p = q;
	}
	printf("逆置完成！\n");
}
void  linkedListWithoutHeadNodeShowData(List phead){
	Node *p = phead;
	while (p != NULL){
		printf("%d--->", p->data);
		p = p->next;
	}
	printf("Over\n");
}
void linkedListWithoutHeadNodeClearList(List* phead){
	assert(phead != NULL);

	Node* p = *phead;
	while ((*phead) != NULL){
		*phead = p->next;
		free(p);
		p = *phead;
	}
}
void linkedListWithoutHeadNodeDestroyList(List* phead){
	assert(phead != NULL);

	Node* p = *phead;
	while ((*phead) != NULL){
		*phead = p->next;
		free(p);
		p = *phead;
	}
}
void linkedListWithoutHeadNodeEraseByValue(List* phead, ET val){
	assert(phead != NULL);
	if ((*phead) == NULL){
		printf("表空，无法删除！\n");
		return;
	}
	linkedListWithoutHeadNodeSortByValue(phead);

	Node* p = *phead;
	Node* q = *phead;

	while (p != NULL){
		if (p->next->data == val){
			break;
		}
		p = p->next;
	}

	q = p->next;

	while (q != NULL){
		if (q->data != val){
			break;
		}
		q = q->next;
	}

	p->next = q;

	if (p->data == val){
		linkedListWithoutHeadNodeDropHead(phead);
	}

}


//***************************************************************************************
//无头结点单链表 函数实现
void linkedListCreateWithHeadNodeFromHead(List* phead){
	assert(phead != NULL);
	*phead = (Node*)malloc(sizeof(Node));
	assert(phead != NULL);

	(*phead)->data = -1;
	(*phead)->next = NULL;

	int i = 1;
	for (; i <= 10; i++)
	{
		Node* s = (Node*)malloc(sizeof(Node));
		assert(s != NULL);
		s->data = i;

		s->next = (*phead)->next;
		(*phead)->next = s;
	}
}
void linkedListCreateWithHeadNodeFromTail(List* phead){
	assert(phead != NULL);
	*phead = (Node*)malloc(sizeof(Node));
	assert(phead != NULL);

	(*phead)->data = -1;
	(*phead)->next = NULL;

	Node *p = *phead;
	int i = 1;
	for (; i <= 10; i++)
	{
		Node* s = (Node*)malloc(sizeof(Node));
		assert(s != NULL);
		s->data = i;
		s->next = NULL;
		
		p->next = s;
		p = s;
	}
}

#endif // !_LINKEDLIST_H_
