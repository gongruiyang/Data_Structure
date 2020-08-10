#ifndef _SORT_H_
#define _SORT_H_
#include "common.h"
//Function Declaration
void PrintArray(int* ar, int left, int right);
void InsertSort(int *ar, int left, int right);	//Insert Sort


//Function Definition
void PrintArray(int* ar, int left, int right)
{
	for (int i = left; i < right; i++)
	{
		printf("%d ", ar[i]);
	}
	printf("\n");
}



#endif /* _SORT_H_ */