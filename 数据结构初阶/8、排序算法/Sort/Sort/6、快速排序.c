#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//B               E
//6 3 5 2 7 8 9 4 1  6
//B               E
//  3 5 2 7 8 9 4 1  6
//B               E
//1 3 5 2 7 8 9 4    6
//        B       E
//1 3 5 2 7 8 9 4    6
//        B      E
//1 3 5 2  8 9 4 7   6
//        B    E
//1 3 5 2 4 8 9  7   6
//          B  E
//1 3 5 2 4 8 9  7   6
//          B  E
//1 3 5 2 4  9 8 7   6
//          E
//          B  
//1 3 5 2 4  9 8 7   6
//          E
//          B  
//1 3 5 2 4 6 9 8 7   

//void QuickSort(int* a, int n)
//{
//	int begin = 0, end = n - 1;
//	int pivot = begin;//假设第一个下标所在值为key，则第一次坑的位置为第一个下标的位置
//	int key = a[begin];
//
//	while (begin < end)
//	{
//		//右边找小的，放到左边
//		while (a[end] >= key)
//		{
//			end--;
//		}
//		//将小的放到左边的坑里，自己形成新的坑位
//		a[pivot] = a[end];
//		pivot = end;
//
//		//左边找大的，放到右边
//		while (a[begin] <= key)
//		{
//			begin++;
//		}
//		//将大的放到右边的坑里，自己形成新的坑位
//		a[pivot] = a[begin];
//		pivot = begin;
//	}
//
//	//相遇，最后一个坑的位置
//	pivot = begin;
//	a[pivot] = key;
//}
//注意以上代码的调试过程

//void QuickSort(int* a, int n)
//{
//	int begin = 0, end = n - 1;
//	int pivot = begin;//假设第一个下标所在值为key，则第一次坑的位置为第一个下标的位置
//	int key = a[begin];
//
//	while (begin < end)
//	{
//		//右边找小的，放到左边
//		while (begin < end && a[end] >= key)//这里a[end] >= key比较，有前提，否则会交叉end和begin
//		{
//			end--;
//		}
//		//将小的放到左边的坑里，自己形成新的坑位
//		a[pivot] = a[end];
//		pivot = end;
//
//		//左边找大的，放到右边
//		while (begin < end && a[begin] <= key)
//		{
//			begin++;
//		}
//		//将大的放到右边的坑里，自己形成新的坑位
//		a[pivot] = a[begin];
//		pivot = begin;
//	}
//
//	//相遇，最后一个坑的位置
//	pivot = begin;
//	a[pivot] = key;
//}

int GetMidInex(int* a, int left, int right);
void Swap(int* a, int* b);

//挖坑法
//单趟排序 - 确定左边小右边大 - 每次只排一个数
//int Part1Sort(int* a, int left, int right)
//{
//	int index = GetMidInex(a, left, right); //三者的中间者
//	Swap(&a[left], &a[index]);//将inexr作为key
//
//	//只有区间存在才进行快排
//	int begin = left, end = right;
//	int pivot = begin;//假设第一个下标所在值为key，则第一次坑的位置为第一个下标的位置
//	int key = a[begin];
//
//	while (begin < end)
//	{
//		//右边找小的，放到左边
//		while (begin < end && a[end] >= key)//这里a[end] >= key比较，有前提，否则会交叉end和begin
//		{
//			end--;
//		}
//		//将小的放到左边的坑里，自己形成新的坑位
//		a[pivot] = a[end];
//		pivot = end;
//
//		//左边找大的，放到右边
//		while (begin < end && a[begin] <= key)
//		{
//			begin++;
//		}
//		//将大的放到右边的坑里，自己形成新的坑位
//		a[pivot] = a[begin];
//		pivot = begin;
//	}
//
//	//相遇，最后一个坑的位置
//	pivot = begin;
//	a[pivot] = key;
//
//	return pivot;//返回一趟排序，中间位置
//}

//前后指针法
//单趟排序 - 确定左边小右边大 - 每次只排一个数
int Part2Sort(int* a, int left, int right)
{
	int index = GetMidInex(a, left, right); //三者的中间者
	Swap(&a[left], &a[index]);//将inexr作为key

	//只有区间存在才进行快排
	int begin = left, end = right;
	int keyi = begin;

	while (begin < end)
	{
		//右边找小的
		while (begin < end && a[end] >= a[keyi])//这里需要begin < end，否则会越界
		{//a[end] > a[keyi]，可能会死循环，如5 1 2 4 3 5 8 7 3 
			end--;
		}

		//左边找大的
		while (begin < end && a[begin] <= a[keyi])//这里需要begin < end，否则会越界
		{//a[end] < a[keyi]，可能会死循环，如5 1 2 4 3 5 8 7 3 
			begin++;
		}

		//交换
		Swap(&a[begin], &a[end]);
	}

	//相遇，与keyi交换
	Swap(&a[begin], &a[keyi]);

	return begin;//返回一趟排序，中间位置
}

//前后指针法
//单趟排序 - 确定左边小右边大 - 每次只排一个数
int Part3Sort(int* a, int left, int right)
{
	int index = GetMidInex(a, left, right); //三者的中间者
	Swap(&a[left], &a[index]);//将inexr作为key

	//只有区间存在才进行快排
	int keyi = left;
	int prev = left, cur = left + 1;

	while (cur <= right)
	{
		//cur找小的
		/*if (a[cur] < a[keyi])
		{
			prev++;
			Swap(&a[prev], &a[cur]);
		}*/
		if (a[cur] < a[keyi] && prev++ != cur)//如果prev++ == cur就可以不交换
		{
			prev++;
			Swap(&a[prev], &a[cur]);
		}
		cur++;
	}

	//与keyi交换
	Swap(&a[keyi], &a[prev]);

	return prev;//返回一趟排序，中间位置
}

//void QuickSort(int* a, int left,int right)//left是0下标，right是n-1下标
//{
//	//当区间不存在时
//	if (left >= right)
//		return;
//
//	//int index = GetMidInex(a, left, right); //三者的中间者
//	//Swap(&a[left], &a[index]);//将inexr作为key
//
//	////只有区间存在才进行快排
//	//int begin = left, end = right;
//	//int pivot = begin;//假设第一个下标所在值为key，则第一次坑的位置为第一个下标的位置
//	//int key = a[begin];
//
//	//while (begin < end)
//	//{
//	//	//右边找小的，放到左边
//	//	while (begin < end && a[end] >= key)//这里a[end] >= key比较，有前提，否则会交叉end和begin
//	//	{
//	//		end--;
//	//	}
//	//	//将小的放到左边的坑里，自己形成新的坑位
//	//	a[pivot] = a[end];
//	//	pivot = end;
//
//	//	//左边找大的，放到右边
//	//	while (begin < end && a[begin] <= key)
//	//	{
//	//		begin++;
//	//	}
//	//	//将大的放到右边的坑里，自己形成新的坑位
//	//	a[pivot] = a[begin];
//	//	pivot = begin;
//	//}
//
//	////相遇，最后一个坑的位置
//	//pivot = begin;
//	//a[pivot] = key;
//
//	int keyIndex = Part1Sort(a, left, right);
//	//int keyIndex = Part2Sort(a, left, right);
//	//int keyIndex = Part3Sort(a, left, right);
//
//	//【left，right】 => 【left，keyIndex-1】keyIndex【keyIndex+1，right】,前序遍历二叉树类似
//	//左子区间和右子区间有序，则整体有序 如何让它们整体有序 -- 分治递归
//	//没有小区间优化
//	QuickSort(a, left, keyIndex - 1);
//	QuickSort(a, keyIndex + 1, right);
//	
//	//将递归调用次数进行优化，即小区间优化，防止递归调用次数太大
//	/*if (keyIndex - 1 - left > 10)//官方给13
//	{
//		QuickSort(a, left, keyIndex - 1);
//	}
//	else
//	{
//		InsertSort(a + left, keyIndex - 1 - left + 1);
//	}
//	if (right - (keyIndex + 1) > 10)
//	{
//		QuickSort(a, keyIndex + 1, right);
//	}
//	else
//	{
//		InsertSort(a + keyIndex + 1, right - (keyIndex + 1) + 1);
//	}*/
//}
//时间复杂度：
//单趟排序的时间复杂度：两端往中间走，合计共N次，即O(N) = N
//理想情况下（每次左右区间大小相等，满二叉树），总时间复杂度：O(N * log2 N)
//最坏的情况（有序时），每次只排出一个数，(等差数列)总时间复杂度：O(N * N)
//解决方法：key的选取，三数取中，即选取左端，中间，右端，既不是最大，也不是最小的值

int GetMidInex(int* a, int left, int right)
{
	int mid = (left + right) / 2;//int mid = (left + right) >> 1;
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if (a[left] > a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else //a[left] > a[mid]
	{
		if (a[mid] > a[right])
		{
			return mid;
		}
		else if (a[left] < a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
}
//void Swap(int* a, int* b)
//{
//	int tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//int main()
//{
//	int a[] = { 6, 2, 4, 5, 1, 3, -1 };
//	int n = sizeof(a) / sizeof(int);
//	QuickSort(a, 0,sizeof(a)/sizeof(int)-1);
//
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	return 0;
//}