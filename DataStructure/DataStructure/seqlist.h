#ifndef _SEQLIST_H_
#define _SEQLIST_H_
#include "common.h"
/*****************************************************************************/
//���峣��
#define DEFAULT_CAPACITY 8					//Ĭ�ϳ�ʼ������
#define DEFAULT_SIZE 0						//Ĭ�ϳ�ʼ����С
#define AUTO_CAPACITY_GROWTH_MULTIPLE 2		//�Զ�������������
typedef int ET;								//Element Type
/*****************************************************************************/
//˳���
typedef struct SeqList
{
	ET *base;
	size_t capacity;
	size_t size;

}SeqList;
/*****************************************************************************/
//��������
bool IsFull(SeqList *plist);			//�жϱ��Ƿ���
bool IsEmpty(SeqList *plist);			//�жϱ��Ƿ��
void SeqListInitial(SeqList *plist);	//��ʼ��˳���
void SeqListDestroy(SeqList *plist);	//����˳���
void SeqListShowData(SeqList *plist);	//չʾ����
void SeqListAddDataFromBack(SeqList *plist, ET value);		//β������
void SeqListAddDataFromFront(SeqList *plist, ET value);		//ͷ������
void SeqListDeleteFromFront(SeqList *plist);	//ͷɾ����
void SeqListDeleteFromBack(SeqList *plist);		//βɾ����
size_t SeqListGetCurrentCapacity(SeqList *plist);	//��ȡ��ǰ�������
size_t SeqListGetCurrentSize(SeqList *plist);		//��ȡ��ǰ���С
void SeqListClearData(SeqList *plist);			//��ձ�������
void SeqListSort(SeqList *plist);				//������������
void SeqListInsertByValue(SeqList *plist, ET value);				//������ֵ��С��������
void SeqListInsertByPosition(SeqList *plist, ET value, int pos);	//����λ�ò�������
void SeqListDeleteByValue(SeqList *plist, ET value);		//������ֵɾ������
void SeqListDeleteByPosition(SeqList *plist, int pos);		//����λ��ɾ������
void SeqListFindByValue(SeqList *plist, ET value);		//��ȡĳ��ֵ��һ�γ��ֵ��±�
void SeqListFindByPosition(SeqList *plist, int pos);	//��ȡĳ��λ�������ֵ
void SeqListReverse(SeqList *plist);				//����˳���
/*****************************************************************************/
//��������
bool IsFull(SeqList *plist){
	assert(plist != NULL);
	if (plist->size == plist->capacity){
		return true;
	}
	return false;
}
bool IsEmpty(SeqList *plist){
	if (plist->size == 0){
		return true;
	}
	return false;
}
bool Increment(SeqList *plist){
	assert(plist != NULL);

	ET* new_base = (ET*)realloc(plist->base, sizeof(ET)* AUTO_CAPACITY_GROWTH_MULTIPLE * plist->capacity);
	if (new_base == NULL){
		printf("����ʧ�ܣ�\n");
		return false;
	}

	plist->base = new_base;
	plist->capacity *= AUTO_CAPACITY_GROWTH_MULTIPLE;
	return true;
}
void SwapData(ET* a, ET* b){
	ET temp = *a;
	*a = *b;
	*b = temp;
}
void SeqListInitial(SeqList *plist){
	assert(plist != NULL);
	plist->capacity = DEFAULT_CAPACITY;
	plist->base = (ET*)malloc(sizeof(ET)*plist->capacity);
	plist->size = DEFAULT_SIZE;
}
void SeqListDestroy(SeqList *plist){
	assert(plist != NULL);
	free(plist->base);
	plist->base = NULL;
	plist->capacity = plist->size = 0;
}
void SeqListShowData(SeqList *plist){
	assert(plist != NULL);
	printf("˳����е������У�");
	for (size_t i = 0; i < plist->size; i++)
	{
		printf("%d ", plist->base[i]);
	}
	puts("\n");
}
void SeqListAddDataFromBack(SeqList *plist, ET value){
	assert(plist != NULL);
	if (IsFull(plist) && !Increment(plist)){
		printf("�Զ�����ʧ�ܵ����޷��������ݣ�\n");
		return;
	}
	plist->base[plist->size] = value;
	plist->size++;

}
void SeqListAddDataFromFront(SeqList *plist, ET value){
	assert(plist != NULL);
	if (IsFull(plist) && !Increment(plist)){
		printf("�Զ�����ʧ�ܵ����޷��������ݣ�\n");
		return;
	}
	for (size_t i = plist->size; i > 0; i--)
	{
		plist->base[i] = plist->base[i - 1];
	}
	plist->base[0] = value;
	plist->size++;


}
void SeqListDeleteFromFront(SeqList *plist){
	assert(plist != NULL);
	if (IsEmpty(plist)){
		printf("���ѿգ�\n");
		return;
	}
	for (size_t i = 0; i < plist->size - 1; i++)
	{
		plist->base[i] = plist->base[i + 1];
	}
	plist->size--;
}
void SeqListDeleteFromBack(SeqList *plist){
	assert(plist != NULL);
	if (IsEmpty(plist)){
		printf("���ѿգ�\n");
		return;
	}
	plist->size--;
}
size_t SeqListGetCurrentCapacity(SeqList *plist){
	assert(plist != NULL);
	return plist->capacity;
}
size_t SeqListGetCurrentSize(SeqList *plist){
	assert(plist != NULL);
	return plist->size;
}
void SeqListClearData(SeqList *plist){
	assert(plist != NULL);
	plist->size = 0;
}
void SeqListSort(SeqList *plist){
	for (size_t i = 0; i < plist->size; i++)
	{
		for (size_t j = i; j < plist->size; j++)
		{
			if (plist->base[i]>plist->base[j]){
				SwapData(&plist->base[i], &plist->base[j]);
			}
		}
	}
}
void SeqListInsertByValue(SeqList *plist, ET value){
	SeqListSort(plist);
	if (IsFull(plist) && !Increment(plist)){
		printf("�Զ�����ʧ�ܵ����޷��������ݣ�\n");
		return;
	}
	int index = 0;
	while (value < plist->base[index] && index < plist->size){
		index++;
	}
	for (size_t i = plist->size; i >index; i--)
	{
		plist->base[i] = plist->base[i - 1];
	}
	plist->base[index] = value;
	plist->size++;

}
void SeqListInsertByPosition(SeqList *plist, ET value, int pos){
	assert(plist != NULL);
	if (pos <= 0 || pos >= plist->size + 2){
		printf("����λ�ò��Ϸ���\n");
		return;
	}
	if (IsFull(plist) && !Increment(plist)){
		printf("�Զ�����ʧ�ܵ����޷��������ݣ�\n");
		return;
	}
	for (size_t i = plist->size; i >= pos; i--)
	{
		plist->base[i] = plist->base[i - 1];
	}
	plist->base[pos - 1] = value;
	plist->size++;
	printf("����ɹ���\n");
}
void SeqListDeleteByValue(SeqList *plist, ET value){
	assert(plist != NULL);
	if (IsEmpty(plist)){
		printf("���ѿգ�\n");
		return;
	}
	size_t index = 0;
	while (value != plist->base[index] && index < plist->size){
		index++;
	}
	if (index == plist->size){
		printf("����û��%d������ݣ�\n", value);
		return;
	}
	for (size_t i = index; i < plist->size; i++)
	{
		plist->base[i] = plist->base[i + 1];
	}
	plist->size--;
	printf("ɾ���ɹ���\n");
}
void SeqListDeleteByPosition(SeqList *plist, int pos){
	assert(plist != NULL);
	if (IsEmpty(plist)){
		printf("���ѿգ�\n");
		return;
	}
	pos -= 1;
	if (pos < 0 || pos >= plist->size){
		printf("ɾ��λ�ò��Ϸ���\n");
		return;
	}
	for (size_t i = pos; i < plist->size; i++)
	{
		plist->base[i] = plist->base[i + 1];
	}
	plist->size--;
	printf("ɾ���ɹ���\n");
}
void SeqListFindByValue(SeqList *plist, ET value){
	assert(plist != NULL);
	int pos = -1;
	for (size_t i = 0; i < plist->size; i++)
	{
		if (value == plist->base[i]){
			pos = i;
			break;
		}
	}
	if (-1 == pos){
		printf("�Ҳ���%d������ݣ�\n", value);
	}
	else{
		printf("%d������ݵ�һ�γ��ֵ��±�Ϊ��%d\n", value, pos + 1);
	}
}
void SeqListFindByPosition(SeqList *plist, int pos){
	assert(plist != NULL);
	if (pos <= 0 || pos >= plist->size + 1){
		printf("����λ�ò��Ϸ���\n");
		return;
	}
	printf("%dλ���ϵ�����Ϊ��%d\n", pos, plist->base[pos - 1]);
}
void SeqListReverse(SeqList *plist){
	assert(plist != NULL);
	size_t right = 0, left = plist->size - 1;
	while (right < left){
		SwapData(&plist->base[right], &plist->base[left]);
		right++, left--;
	}
}

#endif /* _SEQLIST_H_ */