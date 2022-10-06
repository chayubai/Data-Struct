#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

//时间复杂度：O(N) = N*N
//第一次比较N次
//第一次比较N-1次
//第一次比较N-2次
//...
//最好的情况，即有序：O(N) = N

//void BubbleSort(int* a, int n)
//{
//	for (int i = 0; i < n - 1; i++)//趟数
//	{
//		int exchange = 0;//判断是否已经有序
//		for (int j = i; j < n - i - 1; j++)//每一趟，确定的最大值
//		{
//			if (a[j] > a[j+1])//尽量使用这种方式比较if (a[j] > a[j+1])，否则没有控制行边界导致越界
//			{
//				swap(&a[j], &a[j+1]);
//				exchange = 1;
//			}
//		}
//		if(exchange == 0)
//			break;
//	}
//}

void BubbleSort(int* a, int n)
{
	int end = n;
	while(end > 0)
	{
		int exchange = 0;
		for (int j = 1; j < end; j++)//每一趟，确定的最大值
		{
			if (a[j - 1] > a[j])//if (a[j] > a[j+1])这种情况会越界
			{
				swap(&a[j - 1], &a[j]);
				exchange = 1;
			}
		}
		if (exchange == 0)
			break;
		end--;
	}
}

//跟直接插入排序相比，比直接选择排序好，比直接插入排序差
//int main()
//{
//	int a[] = { 6, 2, 4, 5, 1, 3, -1 };
//
//	int n = sizeof(a) / sizeof(a[0]);
//
//	BubbleSort(a, n);
//
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	return 0;
//}