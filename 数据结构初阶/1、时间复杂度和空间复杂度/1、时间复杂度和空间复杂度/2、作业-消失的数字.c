#define _CRT_SECURE_NO_WARNINGS 1
//1����ʧ������
//����nums������0��n������������������ȱ��һ������д�����ҳ��Ǹ�ȱʧ��������
//���а취��O(N)ʱ���������
//���룺[3,0,1]
//�����2

//˼·һ�����������ж�ǰһ���ǲ��ǱȺ�һ����/��1
//������������򣬺�һ��Ԫ�ز������ǰһ��Ԫ�ض�1������ʧ������Ϊ�±�Ϊi��Ԫ��+1
//����ǽ������򣬺�һ��Ԫ�ز������ǰһ��Ԫ����1������ʧ������Ϊ�±�Ϊi��Ԫ��-1
//���������׼ȷִ�д������ټ���ȽϵĴ�����
//��ʱ�临�Ӷ�ΪO(n^2)��������Ҫ�󡣿��������ʱ�临�Ӷ�ΪO(N*log2 N)
//�ռ临�Ӷ�ΪO(1)
/*
#include <stdio.h>
void Sort(int nums[],int numsSize)
{
	for(int i = 0;i<numsSize-1;i++)
	{
		for(int j = 0;j<numsSize-i-1;j++)
		{
			if(nums[j] > nums[j+1])
			{
				int tmp = nums[j];
				nums[j] = nums[j+1];
				nums[j+1] = tmp;
			}
		}
	}
}
int main()
{
	int nums[] = { 9,6,4,2,3,5,7,0,1 };
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	Sort(nums,numsSize);
	int missingNumber = 0;
	for(int i = 0;i < numsSize;i++)
	{
		printf("%d ", nums[i]);
	}
	printf("\n");

	for(int i = 0;i < numsSize - 1;i++)
	{
		if(nums[i+1] - nums[i] != 1)
		{
			missingNumber = i+1;
			break;
		}
	}

	printf("ȱʧ������Ϊ��%d\n", missingNumber);
	return 0;
}
*/

//˼·�����Բ�ȱ��������ͣ��ټ�ȥȱʧ������ĺ�
//(0+1+2+...+n)-(a[0]+a[1]+a[2]+...a[n-1])
//��0��N�����ӵ�һ������ret1���ٰ������е����ӵ�һ������ret2
//ret1 - ret2����Ҫ�ҵ���
//�ȼ�����ȱʧ������ĺ͵Ĵ������ټ�����ȱʧ����ĺ͵Ĵ�����
//��ʱ�临�Ӷ�ΪO(N)
//�ռ临�Ӷ�ΪO(1)
/*
#include <stdio.h>
int missingNumber(int* nums, int numsSize)
{
	int x = 0;
	int y = 0;
	//ȱʧ���������
	for (size_t i = 0; i < numsSize; i++)
	{
		x += nums[i];
	}
	//��0-n�е������
	for (size_t i = 0; i <= numsSize; i++)//ע�⣺�����������Ϊi <= numsSize��i < numsSize+1
	{
		y += i;
	}
	return y - x;
}
int main()
{
	int nums[] = { 9,6,4,2,3,5,7,0,1 };
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	printf("ȱʧ������Ϊ��%d\n", missingNumber(nums, numsSize));
	return 0;
}
*/

//˼·��������num��Ҫ�ҵ���,�����ʼ��Ϊ0���ȸ������е�����򣬺���0��n֮�����е�����򣬽��num����Ҫ�ҵ���

//������������������Ԫ����01234 ��ʵ��������3����nums[4]={0,1,2,4}��numsSize = 4
//����ѭ���������� x = 0 ^ 1 ^ 2 ^ 4
//����ѭ���������󣬾ͱ���� x = x ^ 0 ^ 1 ^ 2 ^ 3 ^ 4 ������Ϊx = 3
//ԭ����ͬ�������������0��0 ^ a = a��
//�ȼ�����ȱʧ���������Ĵ������ټ�����ȱʧ�������Ĵ�����
//��ʱ�临�Ӷ�ΪO(N)
//�ռ临�Ӷ�ΪO(1)
//��˼������Сʱ�����û�кõ�˼·��ȥ�������˵Ĵ����˼·�����֮���Լ���ʵ��һ�£��������ͼ�¼��

/*
#include <stdio.h>
int missingNumber(int* nums, int numsSize)//numsΪ���飬numsSizeΪ�����Ԫ�ظ���
{
	int x = 0;//�����������ֵ�Ľ����0���κ��������Ϊ�κ���
	//�Ⱥ������е������
	for (size_t i = 0; i < numsSize; i++)
	{
		x ^= nums[i];
	}
	//�ٺ͡�0,n���е������
	for (size_t i = 0; i <= numsSize; i++)//ע�⣺�����������Ϊi <= numsSize��i < numsSize+1
	{
		x ^= i;
	}
	return x;
}
int main()
{
	int nums[] = { 9,6,4,2,3,5,7,0,1 };
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	printf("ȱʧ������Ϊ��%d\n", missingNumber(nums, numsSize));
	return 0;
}
*/

//˼·�ģ�����һ��N�Ŀռ䡣�����е�ֵ�Ǽ����ڵڼ���λ��д�����ֵ��
//ʱ�临�Ӷȣ�O(N)
//�ռ临�Ӷȣ�O(N)


//��ͼ���߶����룬д���͡�