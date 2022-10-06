#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//思想上很类似与后序遍历
void _MergeSort(int* a, int left, int right, int* tmp)
{
	//如果只有一个值，或者交叉
	if (left >= right)
	{
		return;
	}
	int mid = (left + right) >> 1;
	//假设【left,mid】【mid,right】,递归左右区间使其有升序，那么就可以归并
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid+1, right, tmp);

	//归并 - 取有序区间放入到新数组
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int index = left;//不能赋值0
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[index++] = a[begin1++];
		}
		else
		{
			tmp[index++] = a[begin2++];
		}
	}
	//如果前半区间有剩余
	while (begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}
	//如果后半区间有剩余
	while (begin2 <= end2)
	{
		tmp[index++] = a[begin2++];
	}

	//将新数组中的数拷贝到原数组中
	for (int i = left; i <= right; i++)
	{
		a[i] = tmp[i];
	}
}
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
}
//int main()
//{
//	int a[] = { 6, 2, 4, 5, 1, 3, -1 };
//	int n = sizeof(a) / sizeof(int);
//	MergeSort(a, 0,sizeof(a)/sizeof(int)-1);
//
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	return 0;
//}