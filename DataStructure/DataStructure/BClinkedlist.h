#ifndef _BCLINKEDLIST_H_
#define _BCLINKEDLIST_H_
#include "common.h"
//***************************************************************************************
//��������
typedef int ET;
/*****************************************************************************/
//˫��ѭ������
typedef struct Node
{
	ET data;
	Node* next;
	Node* prev;
}Node;
typedef Node* BCList;
//***************************************************************************************
//��������
Node*  CreateNode(ET val);								//���첢����һ���ڵ�
void   BCLinkedListInitial(BCList* phead);				//��ʼ����ͷ�ڵ��˫������
void   BCLinkedListAddFromBack(BCList* phead, ET val);	//β�巨
void   BCLinkedListAddFromHead(BCList* phead, ET val);	//ͷ�巨
bool   IsEmpty(BCList* phead);							//�жϱ��Ƿ�Ϊ��
void   BCLinkedListDeleteFromBack(BCList* phead);		//βɾ
void   BCLinkedListDeleteFromHead(BCList* phead);		//ͷɾ
Node*  BCLinkedListGetBack(BCList phead);				//��ȡβ���
Node*  BCLinkedListGetHead(BCList phead);				//��ȡͷ���
size_t BCLinkedListGetListLength(BCList phead);			//��ȡ����
void   BCLinkedListClear(BCList* phead);				//��ձ�������
void   BCLinkedListDestroy(BCList* phead);				//�ݻٱ�ṹ
Node*  BCLinkedListFindByValue(BCList* phead);			//��ֵ���Ҳ���ȡ��Ӧ���
void   BCLinkedListInsertByValue(BCList* phead);		//��ֵ������
void   BCLinkedListSortByData(BCList* phead);			//��������
void   BCLinkedListReverseList(BCList* phead);			//��ת����
void   BCLinkedListShowData(BCList phead);				//��ʾ��������
//***************************************************************************************
//����ʵ��
Node* CreateNode(ET val){
	Node* s = (Node*)malloc(sizeof(Node));
	assert(s != NULL);
	s->data = val;
	s->next = s->prev = s;
	return s;
}
void BCLinkedListInitial(BCList* phead){
	*phead = CreateNode(-1);
}
void BCLinkedListAddFromBack(BCList* phead, ET val){
	assert(phead != NULL);
	Node* s = CreateNode(val);
	Node* p = (*phead)->prev;

	(*phead)->prev = s;
	s->next = *phead;
	s->prev = p;
	p->next = s;

}
void BCLinkedListAddFromHead(BCList* phead, ET val){
	assert(phead != NULL);
	Node* s = CreateNode(val);
	Node* p = (*phead)->next;

	s->next = p;
	s->prev = *phead;
	(*phead)->next = s;
	p->prev = s;
}
void BCLinkedListShowData(BCList phead){
	Node* p = phead->next;
	while (p != phead){
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
bool IsEmpty(BCList* phead){
	if ((*phead)->prev == (*phead)){
		return true;
	}
	return false;
}
void BCLinkedListDeleteFromBack(BCList* phead){
	assert(phead != NULL);
	if (IsEmpty(phead)){
		printf("��գ��޷�ɾ����\n");
		return;
	}
	Node* s = (*phead)->prev;

	(*phead)->prev = s->prev;
	s->prev->next = *phead;

	free(s);
}
void BCLinkedListDeleteFromHead(BCList* phead){
	assert(phead != NULL);
	if (IsEmpty(phead)){
		printf("��գ��޷�ɾ����\n");
		return;
	}

	Node* s = (*phead)->next;
	Node* p = s->next;

	(*phead)->next = p;
	p->prev = *phead;

	free(s);
}
Node* BCLinkedListGetBack(BCList* phead){
	assert(phead != NULL);
	if (IsEmpty(phead)){
		printf("��գ��޷���ã�\n");
		return NULL;
	}
	return (*phead)->prev;
}
Node* BCLinkedListGetHead(BCList* phead){
	assert(phead != NULL);
	if (IsEmpty(phead)){
		printf("��գ��޷���ã�\n");
		return NULL;
	}
	return (*phead)->next;
}
size_t BCLinkedListGetListLength(BCList* phead){
	assert(phead != NULL);
	Node* p = (*phead)->next;
	size_t len = 0;

	while (p != (*phead)){
		p = p->next;
		len++;
	}
	return len;
}
void BCLinkedListClear(BCList* phead){
	assert(phead != NULL);
	Node* p = (*phead)->next;
	Node* q = (*phead)->next;
	while (q != (*phead)){
		q = q->next;
		free(p);
		p = q;
	}
	(*phead)->next = *phead;
	(*phead)->prev = *phead;
}
void BCLinkedListDestroy(BCList* phead){
	assert(phead != NULL);

	Node* p = (*phead)->next;
	Node* q = (*phead)->next;
	(*phead)->next = NULL;

	while (q != NULL){
		q = q->next;
		free(p);
		p = q;
	}
	*phead = NULL;
}
Node* BCLinkedListFindByValue(BCList* phead, ET key){
	assert(phead != NULL);

	Node* p = (*phead)->next;
	while (p != (*phead) && p->data != key){
		p = p->next;
	}
	if (p == *phead) return NULL;
	return p;
}
void BCLinkedListInsertByValue(BCList* phead, ET val){
	assert(phead != NULL);
	Node *p = (*phead)->next;
	while (p != *phead && p->data < val){
		p = p->next;
	}
	if (p == *phead){
		BCLinkedListAddFromBack(phead, val);
	}
	else{
		Node* s = CreateNode(val);
		Node* q = p->prev;

		q->next = s;
		s->next = p;
		p->prev = s;
		s->prev = q;
	}
}
void BCLinkedListSortByData(BCList* phead){
	assert(phead != NULL);
	Node *p = (*phead)->next->next;
	Node *q = (*phead)->next->next;
	(*phead)->prev->next = NULL;
	(*phead)->next->next = (*phead);
	(*phead)->prev = (*phead)->next;
	while (q != NULL){
		q = q->next;
		if ((*phead)->next->data > p->data){
			BCLinkedListAddFromHead(phead, p->data);
			free(p);
		}
		else{
			Node* temp = (*phead)->next;
			while (temp->next != (*phead) && temp->data < p->data){
				temp = temp->next;
			}
			if (temp->next == (*phead)){
				BCLinkedListAddFromBack(phead, p->data);
				free(p);
			}
			else{
				p->next = temp;
				p->prev = temp->prev;
				temp->prev->next = p;
				temp->prev = p;
			}
		}
		p = q;
	}
}
void BCLinkedListReverseList(BCList* phead){
	assert(phead != NULL);
	if (IsEmpty(phead))	return;

	Node* p = (*phead)->prev;
	Node* q = (*phead)->prev;

	(*phead)->next->prev = NULL;	//����ѭ���������� 

	//��ͷ����ÿ�
	(*phead)->next = (*phead)->prev = *phead;

	while (q != NULL){
		q = q->prev;
		BCLinkedListAddFromBack(phead, p->data);
		free(p);
		p = q;
	}
}


#endif // _BCLINKEDLIST_H_
