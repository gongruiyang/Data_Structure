#include <stdio.h>
#include <Windows.h>




/*	暴力遍历寻找两个数的和为目标数，找到存放好返回
时间复杂度：O(n*n)
空间复杂度：2*int
*/
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
	//nums用于保存传入的数组首地址，numsSize是传入数组的数据个数
	//target是2数据的和数，returnSize用于保存返回的数组中数据的个数
	int *result = (int*)malloc(sizeof(int)* 2);	
	//动态开辟一块空间用于存储两个int型数据的数组，并用result指向这块内存

	int i, j;
	for (i = 0; i < numsSize; i++)
	{
		for (j = 0; j < numsSize; j++){
			if (i != j){
				if (nums[i] + nums[j] == target){	//如果符合两个数之和等于目标数据
					result[0] = i;		//则存入开辟的空间之中
					result[1] = j;
					*returnSize = 2;	
					return result;
				}
				else{
					continue;
				}
			}
		}
	}
	return result;		
	//程序如果走到这里，说明并没有找到两个数据之和为target，则返回的这个指针，指向的空间中并无数据
}
