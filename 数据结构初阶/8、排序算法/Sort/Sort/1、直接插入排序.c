#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//假设为升序排序
void InsertSort(int* a,int n)
{
	//整体排序：第一个有序区间为【0,0】n个数需要排n-1趟，即控制单趟排序的次数
	for (int i = 0; i < n - 1; i++)//这里是n-1，
	{
		//单趟排序：
		//【0，end】区间有序，end+1位置的值插入进去，让【0，end+1】有序
		int end = i;//注意end不能等于n-1，否则end+1会越界
		int tmp = a[end + 1];//保存end后面的数，防止数据挪动把后一个数覆盖了，无法知道需要插入的数
		//2 4 5 6 | 1 3
		//1 2 4 5 6 | 3
		while (end >= 0)//或者tmp >= a[end]
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				//tmp >= a[end]或者，tmp比所有的数都要小
				//这里需要放入数据到end后一个位置,即a[end + 1] = tmp;
				break;//使用break，并都会放入数据，a[end + 1] = tmp;放在循环后面，可以合并这两种情况
			}
		}
		a[end + 1] = tmp;
	}
}
//时间复杂度：
//最坏的情况 - 对一个已经有序的数组逆序时，O(N) = 1+2+3+4 ... + (n-)1 = O(N^2)
//最好的情况 - 对一个已经有序的数组顺序时，O(N)
//int main()
//{
//	int a[] = { 5, 2, 4, 6, 1, 3 };
//	int n = sizeof(a) / sizeof(a[0]);
//
//	InsertSort(a, n);
//
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	return 0;
//}