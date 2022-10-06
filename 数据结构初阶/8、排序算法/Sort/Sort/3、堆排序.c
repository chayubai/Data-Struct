#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//void Swap(int* c, int* p)
//{
//	int tmp = *c;
//	*c = *p;
//	*p = tmp;
//}
//向下调整算法：必须左右子树都是大堆或小堆 - 此处建小堆
//下调整算法最多调整高度次。即时间复杂度O(N) = logN。即2 h -1 – x = N 得：高度h = log(N+1+x)
//void AdjustDown(int* a, int n, int root)
//{
//	int parent = root;
//	int child = parent * 2 + 1;//默认左孩子
//	//下标不能超过n
//	while (child < n)//n是数组元素个数，也是数组最大下标的下一个值，即child <= n-1
//	{
//		//1、选出左右孩子中小的那个
//		if ((child+1 < n) && (a[child + 1] < a[child]))//左孩子大时。
//		{//同时极端情况下，存在没有右孩子，因此右孩子下标满足child + 1 < n,即child + 1在数组最大下标范围内
//
//			//由于取小的值与父节点比较，即需要更换为右孩子的下标
//			child += 1;//左右孩子下标相差1
//		}
//		//2、取小的值，如果小于父节点，则小的节点的值做父节点，即交换
//		if (a[child] < a[parent])
//		{
//			Swap(&a[child], &a[parent]);
//			//更新新的父节点和默认左孩子节点
//			parent = child;
//			child = parent * 2 + 1;
//		}
//		else
//		{
//			//由于前提条件左右子树必须为小堆，如果来到这里，可判断后面都满足小堆
//			break;
//		}
//	}
//}

//void AdjustDown(int* a, int n, int root)
//{
//	int parent = root;
//	int child = parent * 2 + 1;//默认左孩子
//	//下标不能超过n
//	while (child < n)//n是数组元素个数，也是数组最大下标的下一个值，即child <= n-1
//	{
//		//1、选出左右孩子中大的那个
//		if ((child+1 < n) && (a[child + 1] > a[child]))//右孩子大时。
//		{//同时极端情况下，存在没有右孩子，因此右孩子下标满足child + 1 < n,即child + 1在数组最大下标范围内
//
//			//由于取大的值与父节点比较，即需要更换为右孩子的下标
//			child += 1;//左右孩子下标相差1
//		}
//		//2、取大的值，如果大于父节点，则大的节点的值做父节点，即交换
//		if (a[child] > a[parent])
//		{
//			Swap(&a[child], &a[parent]);
//			//更新新的父节点和右孩子节点
//			parent = child;
//			child = parent * 2 + 1;
//		}
//		else
//		{
//			break;
//		}
//	}
//}

//堆排序时间复杂度：O(N*logN)
//void HeapSort(int* a, int n)
//{
//	//1、建堆 - 从完全二叉树倒着顺序，使用向下调整算法建堆
//	//建大堆
//	//建堆时间复杂度：O(N)
//	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
//	{//已知孩子节点，可得父节点
//		AdjustDown(a, n, i);
//	}
//
//	//2、排升序 - 建大堆为基础
//	int end = n - 1;
//	while (end > 0)
//	{
//		Swap(&a[0], &a[end]);
//		AdjustDown(a, end, 0);
//		--end;
//	}
//}

//int main()
//{
//	int a[] = { 5, 2, 4, 6, 1, 3 };
//
//	int n = sizeof(a) / sizeof(a[0]);
//
//	HeapSort(a, n);
//
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	return 0;
//}