#include <stdio.h>
#include <Windows.h>




/*	��������Ѱ���������ĺ�ΪĿ�������ҵ���ź÷���
ʱ�临�Ӷȣ�O(n*n)
�ռ临�Ӷȣ�2*int
*/
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
	//nums���ڱ��洫��������׵�ַ��numsSize�Ǵ�����������ݸ���
	//target��2���ݵĺ�����returnSize���ڱ��淵�ص����������ݵĸ���
	int *result = (int*)malloc(sizeof(int)* 2);	
	//��̬����һ��ռ����ڴ洢����int�����ݵ����飬����resultָ������ڴ�

	int i, j;
	for (i = 0; i < numsSize; i++)
	{
		for (j = 0; j < numsSize; j++){
			if (i != j){
				if (nums[i] + nums[j] == target){	//�������������֮�͵���Ŀ������
					result[0] = i;		//����뿪�ٵĿռ�֮��
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
	//��������ߵ����˵����û���ҵ���������֮��Ϊtarget���򷵻ص����ָ�룬ָ��Ŀռ��в�������
}
