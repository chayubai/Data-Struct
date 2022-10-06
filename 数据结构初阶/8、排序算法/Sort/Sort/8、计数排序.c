#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

void CountSort(int* a, int n)
{
	//1、求出最大的数和最小的数
	int max = a[0], min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
		if (a[i] < min)
		{
			min = a[i];
		}
	}

	//计算映射空间的近似大小
	int range = max - min + 1;

	//开辟数组空间
	int* count = (int*)malloc(sizeof(int) * range);//需要检查开辟空间是否成功
	memset(count, 0, sizeof(int) * range);//初始化为0
	
	//2、统计数出现的次数
	for (int i = 0; i < n; i++)
	{
		count[a[i]-min]++;//在a[i]-min相对位置++
	}

	//3、将count数组中的数，放入到原数组中
	int j = 0;
	for (int i = 0; i < range; i++)
	{
		while (count[i]--)
		{
			a[j] = i + min;//下标+min = 最初的值。a[j++] = i + min;
			j++;
		}
	}
	free(count);
}
//时间复杂度:O(N) = n + n range
//即：O(N) = n + range
//说明他适用于范围集中的一组整型数据排序，使用范围具有局限性。
//空间复杂度：O(N) = range
int main()
{
	int a[] = { 6, 2, 4, 5, 1, 3, -1 };
	int n = sizeof(a) / sizeof(int);
	CountSort(a, sizeof(a) / sizeof(int));

	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}