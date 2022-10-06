#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "Stack.h"
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int Part1Sort(int* a, int left, int right)
{
	int index = GetMidInex(a, left, right); //三者的中间者
	Swap(&a[left], &a[index]);//将index作为key

	//只有区间存在才进行快排
	int begin = left, end = right;
	int pivot = begin;//假设第一个下标所在值为key，则第一次坑的位置为第一个下标的位置
	int key = a[begin];

	while (begin < end)
	{
		//右边找小的，放到左边
		while (begin < end && a[end] >= key)//这里a[end] >= key比较，有前提，否则会交叉end和begin
		{
			end--;
		}
		//将小的放到左边的坑里，自己形成新的坑位
		a[pivot] = a[end];
		pivot = end;

		//左边找大的，放到右边
		while (begin < end && a[begin] <= key)
		{
			begin++;
		}
		//将大的放到右边的坑里，自己形成新的坑位
		a[pivot] = a[begin];
		pivot = begin;
	}

	//相遇，最后一个坑的位置
	pivot = begin;
	a[pivot] = key;

	return pivot;//返回一趟排序，中间位置
}
//递归的缺陷：栈帧深度太深，栈空间不够用，可能会溢出
//非递归：
//1、递归改非递归：1、直接改成循环（简单递归）2、借助数据结构的栈模拟实现递归过程（复杂递归）
void QuickSortNonR(int* a, int n)
{
	ST st;//后进先出 - 使得左边先出来,右边先入栈
	StackInit(&st);
	StackPush(&st, n - 1);//先入右, 将下标入栈，最后通过传入下标到挖坑法的函数中，进行单趟排序
	StackPush(&st, 0);//再入左

	while (!StackEmpty(&st))
	{
		int left = StackTop(&st);//出左
		StackPop(&st);

		int right = StackTop(&st);//出右
		StackPop(&st);

		int keyIndex = Part1Sort(a, left, right);
		//【left，right】 => 【left，keyIndex-1】keyIndex【keyIndex+1，right】
		
		//继续将左右区间分割成子问题，先入右，再入左，再出栈，再单趟排序
		if (keyIndex + 1 < right)
		{
			StackPush(&st, right); //先入右
			StackPush(&st, keyIndex + 1);//再入左
		}

		if (left < keyIndex - 1)
		{
			StackPush(&st, keyIndex - 1);//先入右
			StackPush(&st, left);//再入左
		}
	}
	StackDestroy(&st);
}
//递归实现：1+2+3+...+n
int f(int n)//当调用f(10000)时，出现stack flow栈溢出
{
	return n <= 1 ? 1 : f(n - 1) + n;
}//递归深度太深，程序是没有错的。但是栈的空间不够用

//递归和非递归的快速排序效率差不多
//int main()
//{
//	int a[] = { 6, 2, 4, 5, 1, 3, -1 };
//	int n = sizeof(a) / sizeof(int);
//	QuickSortNonR(a, sizeof(a) / sizeof(int));
//
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	return 0;
//}