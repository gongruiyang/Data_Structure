#ifndef _SEQLIST_H_
#define _SEQLIST_H_
#include "common.h"
/*****************************************************************************/
//定义常量
#define DEFAULT_CAPACITY 8					//默认初始化容量
#define DEFAULT_SIZE 0						//默认初始化大小
#define AUTO_CAPACITY_GROWTH_MULTIPLE 2		//自动容量增长倍数
typedef int ET;								//Element Type
/*****************************************************************************/
//顺序表
typedef struct SeqList
{
	ET *base;
	size_t capacity;
	size_t size;

}SeqList;
/*****************************************************************************/
//函数声明
bool IsFull(SeqList *plist);			//判断表是否满
bool IsEmpty(SeqList *plist);			//判断表是否空
void SeqListInitial(SeqList *plist);	//初始化顺序表
void SeqListDestroy(SeqList *plist);	//销毁顺序表
void SeqListShowData(SeqList *plist);	//展示数据
void SeqListAddDataFromBack(SeqList *plist, ET value);		//尾插数据
void SeqListAddDataFromFront(SeqList *plist, ET value);		//头插数据
void SeqListDeleteFromFront(SeqList *plist);	//头删数据
void SeqListDeleteFromBack(SeqList *plist);		//尾删数据
size_t SeqListGetCurrentCapacity(SeqList *plist);	//获取当前最大容量
size_t SeqListGetCurrentSize(SeqList *plist);		//获取当前表大小
void SeqListClearData(SeqList *plist);			//清空表中数据
void SeqListSort(SeqList *plist);				//升序排列数据
void SeqListInsertByValue(SeqList *plist, ET value);				//按照数值大小插入数据
void SeqListInsertByPosition(SeqList *plist, ET value, int pos);	//按照位置插入数据
void SeqListDeleteByValue(SeqList *plist, ET value);		//按照数值删除数据
void SeqListDeleteByPosition(SeqList *plist, int pos);		//按照位置删除数据
void SeqListFindByValue(SeqList *plist, ET value);		//获取某个值第一次出现的下标
void SeqListFindByPosition(SeqList *plist, int pos);	//获取某个位置上面的值
void SeqListReverse(SeqList *plist);				//逆置顺序表
/*****************************************************************************/
//函数定义
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
		printf("扩容失败！\n");
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
	printf("顺序表中的数据有：");
	for (size_t i = 0; i < plist->size; i++)
	{
		printf("%d ", plist->base[i]);
	}
	puts("\n");
}
void SeqListAddDataFromBack(SeqList *plist, ET value){
	assert(plist != NULL);
	if (IsFull(plist) && !Increment(plist)){
		printf("自动扩容失败导致无法加入数据！\n");
		return;
	}
	plist->base[plist->size] = value;
	plist->size++;

}
void SeqListAddDataFromFront(SeqList *plist, ET value){
	assert(plist != NULL);
	if (IsFull(plist) && !Increment(plist)){
		printf("自动扩容失败导致无法加入数据！\n");
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
		printf("表已空！\n");
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
		printf("表已空！\n");
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
		printf("自动扩容失败导致无法加入数据！\n");
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
		printf("插入位置不合法！\n");
		return;
	}
	if (IsFull(plist) && !Increment(plist)){
		printf("自动扩容失败导致无法加入数据！\n");
		return;
	}
	for (size_t i = plist->size; i >= pos; i--)
	{
		plist->base[i] = plist->base[i - 1];
	}
	plist->base[pos - 1] = value;
	plist->size++;
	printf("插入成功！\n");
}
void SeqListDeleteByValue(SeqList *plist, ET value){
	assert(plist != NULL);
	if (IsEmpty(plist)){
		printf("表已空！\n");
		return;
	}
	size_t index = 0;
	while (value != plist->base[index] && index < plist->size){
		index++;
	}
	if (index == plist->size){
		printf("表中没有%d这个数据！\n", value);
		return;
	}
	for (size_t i = index; i < plist->size; i++)
	{
		plist->base[i] = plist->base[i + 1];
	}
	plist->size--;
	printf("删除成功！\n");
}
void SeqListDeleteByPosition(SeqList *plist, int pos){
	assert(plist != NULL);
	if (IsEmpty(plist)){
		printf("表已空！\n");
		return;
	}
	pos -= 1;
	if (pos < 0 || pos >= plist->size){
		printf("删除位置不合法！\n");
		return;
	}
	for (size_t i = pos; i < plist->size; i++)
	{
		plist->base[i] = plist->base[i + 1];
	}
	plist->size--;
	printf("删除成功！\n");
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
		printf("找不到%d这个数据！\n", value);
	}
	else{
		printf("%d这个数据第一次出现的下标为：%d\n", value, pos + 1);
	}
}
void SeqListFindByPosition(SeqList *plist, int pos){
	assert(plist != NULL);
	if (pos <= 0 || pos >= plist->size + 1){
		printf("查找位置不合法！\n");
		return;
	}
	printf("%d位置上的数据为：%d\n", pos, plist->base[pos - 1]);
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