#define _CRT_SECURE_NO_WARNINGS 1
//希尔排序（缩小增量排序）是在直接插入排序的基础上的优化
//1、先进行预排序，让数组接近有序
//2、进行直接插入排序

#include <stdio.h>
//预排序：即将数组进行gap为间隔进行分组，对多个分组进行排序，使得接近有序
//9 8 7 6 5 4 3 2 1
//假设gap == 3 
//则：
//9 # # 6 # # 3 # # 0 排序后：0 # # 3 # # 6 # # 9
//8 # # 5 # # 2 排序后：2 # # 5 # # 8
//7 # # 4 # # 1 排序后：1 # # 4 # # 7
//即：
//i = 0  6和9对换   6 # # 9   6 8 7 9 5 4 3 2 1 0
//i = 1  5和8对换   5 # # 8   6 5 7 9 8 4 3 2 1 0
//i = 2  4和7对换   4 # # 7   6 5 4 9 8 7 3 2 1 0
//i = 3  直接插入排序6 9 3    3 5 4 6 8 7 9 2 1 0
//...
//i = 6 = n - gap - 1  0 2 1 3 5 4 6 8 7 9 
//0 2 1 3 5 4 6 8 7 9 直接插入排序：1 2 3 4 5 6 7 8 9
//void ShellSort(int* a, int n)
//{
//	int gap = 3;//gap = 1即直接插入排序，但这样gap间隔固定写死了
//	//把间隔为gap的多组数据同时排
//	for (int i = 0; i < n - gap; i++)
//	{
//		int end = i;
//		int tmp = a[end + gap];
//		while (end >= 0)
//		{
//			if (tmp < a[end])
//			{
//				a[end + gap] = a[end];
//				end -= gap;
//			}
//			else
//			{
//				break;
//			}
//		}
//		a[end + gap] = tmp;
//	}
//}

void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 2;//或者gap = gap / 3 +1 保证最后一次gap = 1
		//把间隔为gap的多组数据同时排
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}
//时间复杂度：
//n/3/3/3 .../3 = 1 =>n = log3 n
//当gap很大时，下面预排序时间复杂度O(N)
//当gap很小时，数组已经很接近有序了，这时预排序差不多也是O(N)
//总时间复杂度为：O(log3 n * N)

//int main()
//{
//	int a[] = { 5, 2, 4, 6, 1, 3 };
//	int n = sizeof(a) / sizeof(a[0]);
//
//	ShellSort(a, n);
//
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	return 0;
//}