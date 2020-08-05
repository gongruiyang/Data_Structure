#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_
#include "common.h"
//***************************************************************************************
//��������
typedef int ET;
/*****************************************************************************/
//��������
typedef struct Node
{
	ET data;		//���ڴ洢����
	Node* next;		//���ڴ洢�¸��ڵ�ĵ�ַ
}Node;
typedef Node* List;
//***************************************************************************************
//��������
void linkedListInitial(List* phead);		
//��ͷ��㵥���� ��������
#if 0
void linkedListCreateWithoutHeadNodeFromTail(List* phead);	//ͷ�巨
void linkedListCreateWithoutHeadNodeFromHead(List* phead);	//β�巨
#endif 
void  linkedListInitial(List* phead);											//��ʼ������
void  linkedListWithoutHeadNodeAddFromHead(List* phead, ET val);				//ͷ�巨
void  linkedListWithoutHeadNodeAddFromTail(List* phead, ET val);				//β�巨
Node* linkedLIstWithoutHeadNodeGetHead(List* phead);							//��ȡͷ���
Node* linkedListWithoutHeadNodeGetTail(List* phead);							//��ȡβ���
int   linkedListWithoutHeadNodeGetLength(List* phead);							//��ȡ����
void  linkedListWithoutHeadNodeDropHead(List* phead);							//ɾ��ͷ���
void  linkedListWithoutHeadNodeDropTail(List* phead);							//ɾ��β�ڵ�
void  linkedListWithoutHeadNodeSortByValue(List* phead);						//����
void  linkedListWithoutHeadNodeInsertByValue(List* phead, ET val);				//��ֵ����
void  linkedListWithoutHeadNodeInsertByPosition(List* phead, int pos, ET val);	//��λ�ò���
void  linkedListWithoutHeadNodeDropByValue(List* phead, ET val);				//��ֵɾ��
void  linkedListWithoutHeadNodeDropByPosition(List* phead, int pos, ET val);	//��λ��ɾ��
void  linkedListWithoutHeadNodeReverseList(List* phead);						//��ת����
void  linkedListWithoutHeadNodeShowData(List* phead);							//չʾ����
void  linkedListWithoutHeadNodeClearList(List* phead);							//�������
void  linkedListWithoutHeadNodeDestroyList(List* phead);						//�ݻ�����
void  linkedListWithoutHeadNodeEraseByValue(List* phead, ET val);				//ȫ����ɾ��ĳһ��ֵ

//��ͷ��������µ�ͷ�巨��β�巨
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
//��ͷ��㵥���� ����ʵ��
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

	if (p == NULL){	//��Ϊ��ʱ 
		*phead = (Node*)malloc(sizeof(Node));
		assert(*phead != NULL);
		(*phead)->data = val;
		(*phead)->next = NULL;
	}
	else{			//��ǿ�ʱ 
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
		printf("���ѿգ��޷�ɾ����\n");
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
	printf("��Ԫ�����ɾ����\n");
}
void  linkedListWithoutHeadNodeDropTail(List* phead){
	assert(phead != NULL);
	if ((*phead) == NULL){
		printf("���ѿգ��޷�ɾ����\n");
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
	printf("ĩβ�����ɾ����\n");
}
void  linkedListWithoutHeadNodeSortByValue(List* phead){
	assert(phead != NULL);
	if ((*phead) == NULL){
		printf("���ѿգ��޷�����\n");
		return;
	}
	if ((*phead)->next == NULL)	return; 	//һ�����
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
	if ((*phead) == NULL){	//���ʱ
		linkedListWithoutHeadNodeAddFromHead(phead, val);
		printf("��ֵ����������ɣ�\n");
		return;
	}
	linkedListWithoutHeadNodeSortByValue(phead);

	Node* s = (Node*)malloc(sizeof(Node));
	s->data = val;
	s->next = NULL;

	if ((*phead)->next == NULL && (*phead)->data > val){	//����ֻ��һ������val�Ľ��ʱ
		s->next = *phead;
		*phead = s;
		printf("��ֵ����������ɣ�\n");
		return;
	}
	Node* p = *phead;
	while (p->next != NULL && p->next->data < val){
		p = p->next;
	}
	s->next = p->next;
	p->next = s;
	printf("��ֵ����������ɣ�\n");
}
void  linkedListWithoutHeadNodeInsertByPosition(List* phead, int pos, ET val){
	assert(phead != NULL);
	int len = linkedListWithoutHeadNodeGetLength(phead);
	if (pos <= 0 || pos > len){
		printf("����λ�ò��Ϸ���\n");
		return;
	}
	int position = pos;
	position--;

	Node* s = (Node*)malloc(sizeof(Node));
	s->data = val;
	s->next = NULL;

	if (position == 0){
		linkedListWithoutHeadNodeAddFromHead(phead, val);
		printf("����%dλ���ϲ���%d\n", pos, val);
		return;
	}
	Node* p = *phead;
	while (position != 1){
		p = p->next;
		position--;
	}
	s->next = p->next;
	p->next = s;
	printf("����%dλ���ϲ���%d\n", pos, val);
}
void  linkedListWithoutHeadNodeDropByValue(List* phead, ET val){
	assert(phead != NULL);
	if ((*phead) == NULL){
		printf("�ձ��޷�ɾ��\n");
		return;
	}
	linkedListWithoutHeadNodeSortByValue(phead);

	Node* p = *phead;
	if (p->data == val){
		*phead = p->next;
		free(p);
		printf("��һ�γ��ֵ�%d��������ѱ�ɾ��!\n", val);
		return;
	}
	while (p->next != NULL){
		if (p->next->data == val){
			Node* q = p->next;
			p->next = q->next;
			free(q);
			printf("��һ�γ��ֵ�%d��������ѱ�ɾ��!\n", val);
			return;
		}
		p = p->next;
	}
	printf("û��%d�������!\n", val);
}
void  linkedListWithoutHeadNodeDropByPosition(List* phead, int pos){
	assert(phead != NULL);
	int len = linkedListWithoutHeadNodeGetLength(phead);
	if (pos <= 0 || pos > len){
		printf("ɾ��λ�ò��Ϸ���\n");
		return;
	}
	int position = pos;
	position--;

	if (position == 0){
		linkedListWithoutHeadNodeDropHead(phead);
		printf("��ɾ��%dλ���ϵ����ݣ�\n", pos);
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
	printf("��ɾ��%dλ���ϵ����ݣ�\n", pos);
}
void  linkedListWithoutHeadNodeReverseList(List* phead){	
	assert(phead != NULL);
	if ((*phead)->next == NULL){
		printf("������ɣ�\n");
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
	printf("������ɣ�\n");
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
		printf("��գ��޷�ɾ����\n");
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
//��ͷ��㵥���� ����ʵ��
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
