#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//void MergeSortNonR(int* a, int n)//数组元素奇数个时，最后一个元数，导致两两一归并越界
//{
//	int* tmp = (int*)malloc(sizeof(int) * n);
//
//	int gap = 1;//每组数据的个数
//	
//	while (gap < n)
//	{
//		for (int i = 0; i < n; i += 2 * gap)//gap=N时，i控制归并的次数
//		{
//			//【i，i+gap-1】【i+gap，i+2*gap-1】。这里右半区间可能不存在
//			//归并 - 取有序区间放入到新数组
//			int begin1 = i, end1 = i + gap - 1;
//			int begin2 = i + gap, end2 = i + 2 * gap - 1;
//			int index = i;//不能赋值0
//			while (begin1 <= end1 && begin2 <= end2)
//			{
//				if (a[begin1] < a[begin2])
//				{
//					tmp[index++] = a[begin1++];
//				}
//				else
//				{
//					tmp[index++] = a[begin2++];
//				}
//			}
//			//如果前半区间有剩余
//			while (begin1 <= end1)
//			{
//				tmp[index++] = a[begin1++];
//			}
//			//如果后半区间有剩余
//			while (begin2 <= end2)
//			{
//				tmp[index++] = a[begin2++];
//			}
//		}
//		//(一次性)将新数组中的数拷贝到原数组中
//		for (int j = 0; j <= n; j++)
//		{
//			a[j] = tmp[j];
//		}
//		gap *= 2;//控制每组数据的个数
//	}
//
//	free(tmp);
//}

void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);

	int gap = 1;//每组数据的个数

	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			//【i，i+gap-1】【i+gap，i+2*gap-1】
			//归并 - 取有序区间放入到新数组
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;

			//归并过程中右半区间可能不存在,不需要处理，如：6, 2 | 4, 5 | 1, 3 | -1
			if (begin2 >= n)
			{
				break;
			}
			//归并过程中右半区间算多了，如：2, 6 , 4, 5 | 1, 3 ,-1 
			if (end2 >= n)
			{
				end2 = n - 1;//修正区间到有效区间中
			}
			//注意：也存在左半区间有问题，如10, 6, 7, 1 | 3, 9, 4, 2 | 2, 3 ,4

			int index = i;//不能赋值0
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
			//归并一部分，拷贝一部分
			//放在里面,且修改结束条件，将新数组中的数拷贝到原数组中，否则会拷入随机值
			//例如没有修改：6, 2 | 4, 5 | 1, 3 | -1
			//原数组： 6, 2, 4, 5, 1, 3, -1
			//处理后： 6, 2, 4, 5, 1, 3  (最后一个数不处理)
			//将处理后的数拷贝回去：6, 2, 4, 5, 1, 3, 随机值(结束条件为n导致随机值)
			for (int j = i; j <= end2; j++)//j <= i + 2 * gap - 1，不能这样，因为前面对end进行修正了，再使用这个条件，就会越界访问
			{
				a[j] = tmp[j];
			}
		}
		gap *= 2;
	}
	free(tmp);
}
//时间复杂度都是O(N*logN)
//int main()
//{
//	int a[] = { 6, 2, 4, 5, 1, 3, -1 };
//	int n = sizeof(a) / sizeof(int);
//	MergeSortNonR(a, sizeof(a) / sizeof(int));
//
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	return 0;
//}