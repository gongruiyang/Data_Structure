#ifndef _SORT_H_
#define _SORT_H_
#include "common.h"

int dlta[] = { 5, 3, 2, 1 };
//Function Declaration
/* Help Function */
void PrintArray(int* ar, int left, int right);
void swap(int *x, int* y);

/* Insertion Sort */
void InsertSort_swap(int *ar, int left, int right);
void InsertSort_NoSwap(int *ar, int left, int right);
void InsertSort_Move(int *ar, int left, int right);
void BinaryInsertSort(int *ar, int left, int right);	
void TwoWayInsertSort(int *ar, int left, int right);
void ShellSort(int *ar, int left, int right);
#if 0
void ShellInsert(int *ar, int n, int dk);
void ShellSort(int *ar,int n,int dlta[], int t);
#endif

/* Selection Sort */
void SelectSort(int *ar, int left, int right);
void HeapSort(int *ar, int left, int right);

/* Exchange Sort */
void HeapSort(int *ar, int left, int right);
void QuickSort_Hoare(int *ar, int left, int right);

/* Merge Sort */
void MergeSort(int *ar, int left, int right);

/* Radix Sort */
void RadixSort(int *ar, int left, int right);

//Function Definition
void PrintArray(int* ar, int left, int right)
{
	for (int i = left; i < right; i++)
	{
		printf("%d ", ar[i]);
	}
	printf("\n");
}
void swap(int *x, int* y){
	int temp = *x;
	*x = *y;
	*y = temp;
}
void InsertSort_swap(int *ar, int left, int right){
	int i;
	for (i = left + 1; i < right; ++i)
	{
		int end = i;
		while (end > left && ar[end] < ar[end - 1])
		{
			swap(&ar[end], &ar[end - 1]);
			end--;
		}
	}
}
void InsertSort_NoSwap(int *ar, int left, int right){
	int i;
	for (i = left + 1; i < right; ++i)
	{
		int temp = ar[i];
		int end = i;
		while (end > left && temp < ar[end - 1])
		{
			ar[end] = ar[end - 1];
			end--;
		}
		ar[end] = temp;
	}
}
void InsertSort_Move(int *ar, int left, int right){
	int i, j;
	int k;
	for (j = left + 1; j < right; j++)
	{
		int temp = ar[j];
		for (i = left; i < j; i++)
		{
			if (temp < ar[i])
			{
				for (k = j; k > i; k--)
				{
					ar[k] = ar[k - 1];
				}
				ar[i] = temp;
				break;
			}
			else
			{
				continue;
			}
		}
	}
}
void BinaryInsertSort(int *ar, int left, int right){
	int i;
	for (i = left + 1; i < right; i++)
	{
		int low = left;
		int high = i - 1;
		int mid;
		int temp = ar[i];
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (ar[mid] < ar[i])
				low = mid + 1;
			else
				high = mid - 1;
		}
		int j;
		for (j = i; j > mid; j--)
		{
			ar[j] = ar[j - 1];
		}
		ar[mid] = temp;
	}
}
void TwoWayInsertSort(int *ar, int left, int right){
	int n = right - left;
	int *a = (int*)malloc(sizeof(int)* n);
	int first = 0, final = 0;
	a[0] = ar[0];
	int i;
	for (i = left + 1; i < n; i++)
	{
		if (ar[i] >= a[0])
		{	//后插 
			int j = 0;
			while (j <= final && ar[i] > a[j])
				j++;
			if (j <= final)
			{
				int k;
				for (k = final + 1; k > j; k--)
					a[k] = a[k - 1];
			}
			a[j] = ar[i];
			final++;
		}
		else
		{	//前插 
			if (first == 0)
			{
				first = n - 1;
				a[first] = ar[i];
			}
			else
			{
				int j = n - 1;
				while (j >= first && ar[i] < a[j])
					j--;
				if (j >= first){
					int k;
					for (k = first - 1; k < j; k++)
						a[k] = a[k + 1];
				}
				a[j] = ar[i];
				first--;
			}
		}
	}

	//将排序好的数据 复制 回原数组中 
	if (first == 0){
		int z;
		for (z = 0; z < n; z++)
			ar[z] = a[z];
	}
	else
	{
		int index = first;
		i = 0;
		while (index <= n - 1)
		{
			ar[i] = a[index];
			index++;
			i++;
		}
		index = 0;
		while (index <= final)
		{
			ar[i] = a[index];
			index++;
			i++;
		}
	}
}
#if 0
//Book
void ShellInsert(int *ar, int n, int dk){
	int i, j;
	for (i = dk; i < n; i++)
	{
		if (ar[i] < ar[i - dk])
		{
			int tmp = ar[i];
			for (j = i - dk; j >= 0 && tmp < ar[j]; j -= dk)
				ar[j + dk] = ar[j];
			ar[j + dk] = tmp;
		}
	}
}
void ShellSort(int *ar, int n, int dlta[], int dltaSize){
	int k;
	for (k = 0; k < dltaSize; k++)
		ShellInsert(ar, n, dlta[k]);
}

//Teacher
void ShellInsert(int *ar, int left, int right, int dk)
{
	for (int i = left + dk; i < right; ++i)
	{
		if (ar[i] < ar[i - dk])
		{
			int tmp = ar[i];
			int end = i - dk;
			while (end >= left && tmp < ar[end])
			{
				ar[end + dk] = ar[end];
				end -= dk;
			}
			ar[end + dk] = tmp;
		}
	}
}
void ShellSort(int *ar, int left, int right)
{
	int t = sizeof(dlta) / sizeof(dlta[0]);
	for (int k = 0; k < t; ++k)
		ShellInsert(ar, left, right, dlta[k]);
}
#endif
void ShellSort(int *ar, int left, int right){
	int dk = right - left;
	while (dk > 1)
	{
		dk = dk / 3 + 1; //这里不一定是3，开发中会给出设置增量的方式 
		int i;
		for (i = left + dk; i < right; ++i)
		{
			if (ar[i] < ar[i - dk])
			{
				int tmp = ar[i];
				int end = i - dk;
				while (end >= left && tmp < ar[end])		//将数据交换到最适合的位置 
				{
					ar[end + dk] = ar[end];
					end -= dk;
				}
				ar[end + dk] = tmp;
			}
		}
	}
}
int GetMinIndex(int *ar, int left, int right){
	int min = ar[left];
	int index = left;
	for (int i = left + 1; i < right; i++)
	{
		if (ar[i] < min){
			min = ar[i];
			index = i;
		}
	}
	return index;
}
void SelectSort(int *ar, int left, int right){
	for (int i = left; i < right; i++)
	{
		int index = GetMinIndex(ar, i, right);
		if (index != i)
			swap(&ar[index], &ar[i]);
	}
}
void ShiftDown(int *ar, int left,int right, int curpos){
	int n = right - left;
	int j = curpos;
	int i = ar[2 * j + 1] > ar[2 * j + 2] ? (2 * j + 1) : (2 * j + 2);
	while (j < n){
		if (i<n && ar[j] < ar[i]){
			swap(&ar[j], &ar[i]);
			j = i;
			i = ar[2 * j + 1] > ar[2 * j + 2] ? (2 * j + 1) : (2 * j + 2);
		}
		else{
			break;
		}
	}
}
void HeapSort(int *ar, int left, int right){
	//创建堆
	int n = right - left;
	int cur = n / 2 - 1 + left;
	while (cur > 0)
	{
		ShiftDown(ar, left,right, cur);
		cur--;
	}
	//排序
	int end = right - 1;
	while (end > left)
	{
		swap(&ar[end], &ar[left]);
		end--;
		ShiftDown(ar, left, end, left);
	}
}
void BubbleSort(int *ar, int left, int right){
	int i = 0;
	int j;
	for (; i<right - left; i++){
		for (j = i + 1; j<right - left; j++){
			if (ar[i] > ar[j]){
				swap(&ar[i], &ar[j]);
			}
		}
	}
}
void BubbleSort_1(int *ar, int left, int right)
{
	int n = right - left;
	for (int i = left; i<n - 1; ++i)
	{
		for (int j = left; j<n - i - 1; ++j)
		{
			if (ar[j] > ar[j + 1])
			{
				swap(&ar[j], &ar[j + 1]);
			}
		}
	}
}
void BubbleSort_2(int *ar, int left, int right)
{
	int n = right - left;
	bool is_swap = false;
	for (int i = left; i<n - 1; ++i)
	{
		for (int j = left; j<n - i - 1; ++j)
		{
			if (ar[j] > ar[j + 1])
			{
				swap(&ar[j], &ar[j + 1]);
				is_swap = true;
			}
		}
		if (!is_swap)
			break;
		else
			is_swap = false;
	}
}
int Partition_H(int* ar, int left, int right){
	int key = ar[left];
	while (left < right)
	{
		while (left<right && ar[right] >= key)
			right--;
		swap(&ar[left], &ar[right]);
		while (left<right && ar[left] <= key)
			left++;
		swap(&ar[left], &ar[right]);
	}
	return left;
}
void QuickSort_Hoare(int *ar, int left, int right){
	/*  右边大于左边 --
	右边小于左边 交换
	左边小于右边 --
	左边大于右边 交换
	*/
	if (left >= right) return;
	int pos = Partition_H(ar, left, right - 1);	//分割，左边小于关键值，右边大于关键值 
	QuickSort_Hoare(ar, left, pos);
	QuickSort_Hoare(ar, pos + 1, right);
}
void _MergeSort(int *ar, int left, int right, int *tmp){
	//1.先分解：一半一半分解，最终成一个一个的数据
	if (left >= right)
		return;
	int mid = (left + right) / 2;
	_MergeSort(ar, left, mid, tmp);
	_MergeSort(ar, mid + 1, right, tmp);
	//2.后排序：将原来数据排序好归并到新空间中 
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int i = 0;
	//比较两部分 按顺序放入新空间 
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (ar[begin1] < ar[begin2])
		{
			tmp[i] = ar[begin1];
			i++, begin1++;
		}
		else
		{
			tmp[i] = ar[begin2];
			i++, begin2++;
		}
	}

	//将没放完的那一半 全部放入 
	while (begin1 <= end1)
	{
		tmp[i] = ar[begin1];
		i++, begin1++;
	}
	while (begin2 <= end2)
	{
		tmp[i] = ar[begin2];
		i++, begin2++;
	}
	memcpy(ar + left, tmp, sizeof(int)*(right - left + 1));
}
void MergeSort(int *ar, int left, int right){
	int n = right - left;
	int *tmp = (int*)malloc(sizeof(int)* n);
	assert(tmp != NULL);
	//归并排序的过程
	_MergeSort(ar, left, right - 1, tmp);
	free(tmp);
	tmp = NULL;
}

#define K 2
#define RADIX_VAL 10
List list[RADIX_VAL];
int GetKey(int value, int k){
	int key;
	while (k >= 0)
	{
		key = value % 10;
		value /= 10;
		k--;
	}
	return key;
}
void Distribute(int* ar, int left, int right, int k){
	int i;
	for (i = left; i < right; i++){
		int key = GetKey(ar[i], k);
		AddFromTail(&list[key], ar[i]);
	}
}
void Collect(int* ar){
	int k = 0, i = 0;
	for (; i<RADIX_VAL; i++)
	{
		while (!IsEmpty(&list[i]))
		{
			ar[k] = GetHead(&list[i])->data;
			k++;
			DropTail(&list[i]);
		}
	}
}
void RadixSort(int *ar, int left, int right){
	//初始化链表数组
	int i;
	for (i = 0; i<RADIX_VAL; i++)
		Initial(&list[i]);

	for (i = 0; i<K; i++)
	{
		//分发 
		Distribute(ar, left, right, i);
		//收回 
		Collect(ar);
	}

}

#endif /* _SORT_H_ */