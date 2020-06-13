#include <stdio.h>
#include <Windows.h>
#pragma warning(disable:4996)
int removeDuplicates(int* nums, int numsSize){
	int count = 1;
	int *q = nums;
	if (numsSize == 0)
		return 0;
	for (int i = 0; i<numsSize; i++){
		if (nums[count - 1] != q[i]){
			count++;
			nums[count - 1] = q[i];
		}
	}
	return count;
}

int main(){
	int a[21] = {  0,0,0,1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6 };
	int size = 21;
	size = removeDuplicates(a, size);
	
	for (int i = 0; i < size; i++)
	{
		printf("%d ", a[i]);
	}
	
	system("pause");
	return 0;
}