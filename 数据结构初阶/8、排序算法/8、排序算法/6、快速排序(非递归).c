#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include "Stack.h"

//递归实现：1 + 2 + 3 + ... + n
//1 2 3 4 ... n
//f(n) = 1 + 2 + 3 + ... n-1 + n
//f(n) = [1 + 2 + 3 + ... n-1] + n = f(n-1)+n
//...
//f(3) = [1 + 2]+3 = f(2)+3
//f(2) = [1]+2 = f(1)+2
int f(int n)
{
	return n <= 1 ? 1 : f(n - 1) + n;
}
//当调用f(10000)时，出现stack overflow栈溢出
//递归深度太深，程序是没有错的。但是栈的空间不够用

//递归的缺陷：栈帧深度太深，栈空间不够用，可能会溢出.

//非递归：
//1、递归改非递归：1、直接改成循环（简单递归）2、借助数据结构的栈模拟实现递归过程（复杂递归）

int PartSort(int* a, int left, int right);
//利用栈模拟递归过程
void QuickSortNonR(int* a, int n)
{
	ST st;//后进先出 - 使得左边先出来,右边先入栈
	StackInit(&st);
	StackPush(&st, n - 1);//先右下标入栈，最后通过传入下标到挖坑法的函数中，进行单趟排序。因为要先出左。
	StackPush(&st, 0);//再左下标入栈。

	while (!StackEmpty(&st))
	{
		int left = StackTop(&st);//取栈顶中的元素(左下标)
		StackPop(&st);

		int right = StackTop(&st);//取栈顶中的元素(右下标)
		StackPop(&st);

		int keyIndex = PartSort(a, left, right);//返回新的key下标
		//【left，right】 => 【left，keyIndex-1】keyIndex【keyIndex+1，right】
		
		//以新的key分界，继续将左右区间分割成子问题，先入右，再入左，再出栈，再单趟排序
		if (keyIndex + 1 < right)//右半区间存在，则继续入栈
		{
			StackPush(&st, right); //先入右
			StackPush(&st, keyIndex + 1);//再入左
		}

		if (left < keyIndex - 1)//左半区间存在，则继续入栈
		{
			StackPush(&st, keyIndex - 1);//先入右
			StackPush(&st, left);//再入左
		}
	}
	StackDestroy(&st);
}
void swap06(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
//单趟排序
int PartSort(int* a, int left, int right)
{
	//注释：利用最左边的作key值，方便调试
	//int index = GetMidInex(a, left, right); //三者的中间者
	//swap06(&a[left], &a[index]);//将index作为key，与left交换

	//只有区间存在才进行快排
	int begin = left, end = right;
	int pivot = begin;//假设第一个下标所在值为key，则第一次坑的位置为第一个下标的位置
	int key = a[begin];

	while (begin < end)//begin == end相等则结束
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
	pivot = begin;//更新坑的位置，同时记录中间数位置
	a[pivot] = key;

	return pivot;//返回一趟排序，左边都不key小，右边都比key大，中间那个数的下标
}
//递归和非递归的快速排序效率差不多。
//注意：降序排序就是，单趟排序，左边找小的，右边找大的 放入坑中。

//多注意边界值的控制。快速排序核心思想：类似于前序遍历。多调试理解逻辑。多画图。

//注意：也可以使用队列模拟递归过程。
//栈模拟递归过程：左半区间处理完后，才处理右半区间。更像递归过程。
//队列模拟递归过程：一层一层的处理。不像递归过程。

//注意：有些题中，会考察，快速排序的非递归过程，第一趟排序后的结果，第二趟排序后的结果。第二趟排序后的结果，就是队列模拟实现递归的第二趟结果。
//也会考察快速排序不同思路(挖坑法，左右指针法，前后指针法，非递归)第一趟排序后的结果。
//对于49 38 65 97 76 13 27 49而言
//非递归快排第一趟排序是：27 38 13 49 76 97 65 49
//非递归快排第二趟排序是：13 27 38 49 49 65 76 97

//注意：操作系统的栈和堆空间，与数据结构中的栈和堆是不同的。

#if 0
int main()
{
	int a[] = { 6, 2, 4, 5, 1, 3, -1 };
	int n = sizeof(a) / sizeof(int);
	QuickSortNonR(a, sizeof(a) / sizeof(int));

	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}
#endif