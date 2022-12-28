#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//归并排序非递归思路：
//所有的第一次每组一个数据和一个数据的归并，两个数据就有序了。最后拷贝到原数组继续分组归并。
//所有的第二次每组两个数据和两个数据的归并，四个数据就有序了。最后拷贝到原数组继续分组归并。
//所有的第三次每组四个数据和四个数据的归并，…直到有序。

//问题代码：
/*
void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);

	int gap = 1;//每组数据的个数
	
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)//gap = N时，i控制归并的次数
		{
			//【i，i+gap-1】【i+gap，i+2*gap-1】。
			
			//归并思路
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;
			int index = i;
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
		}
		//(一次性)将新数组中的数全部拷贝到原数组中
		for (int j = 0; j <= n; j++)
		{
			a[j] = tmp[j];
		}

		//控制下次归并每组数据的个数
		gap *= 2;
	}

	free(tmp);
}
*/
//测试用例：10,6,7,1,3,9,4,2,8
//注意以上代码的调试过程：
//观察a[0] a[1] a[2] a[3] a[4] a[5] a[6] a[7] a[8] begin1 end1 begin2 end2的值的变化 
//数组元素奇数个时，最后一个元素，导致归并越界。因为归并的过程中，每次归并的元素个数不一定是gap的整数倍。
//导致两个情况：1、右半区间不存在。2、右半区间部分存在。
//也可能导致另外一种情况：3、左半区间部分存在，右半区间不存在。
//解决方法：
//1、如果右半区间不存在，直接将那几个元素直接拷贝下来。或者直接不处理。因为左半区间已经有序，不需要归并。
//2、如果右半区间部分存在，修正区间
//3、如果左半区间部分存在。直接将那几个元素直接拷贝下来。

void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
		return;

	int gap = 1;//每组数据的个数

	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			//【i，i+gap-1】【i+gap，i+2*gap-1】
			//归并思路
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;

			//1、归并过程中右半区间可能不存在,不需要处理归并，因为左半区间已经有序，不需要归并。如：6, 2 | 4, 5 | 1, 3 | -1
			if (begin2 >= n)
			{
				break;
			}
			//2、归并过程中右半区间算多了，如：2, 6 , 4, 5 | 1, 3 ,-1 
			if (end2 >= n)//end2 = i + 2 * gap - 1 >= n，修正
			{
				end2 = n - 1;//修正区间到有效区间中
			}
			//注意：也存在左半区间有问题，如10, 6, 7, 1 | 3, 9, 4, 2 | 2, 3 ,4
			//这种情况下，不仅左半区间部分存在，而且右半区间不存在。
			//解法方法：类似于右半区间的问题。但是左半区间的部分数据需要处理。但是需要将数据拷贝到新数组中，
			//否则，按上面的一次性拷贝所有的数据，这个操作就会将新数组中后面的随机值，拷贝覆盖到原数组中。
			//所以，可以归并一次，拷贝一次。

			int index = i;
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
			//放在里面,且修改初始条件和结束条件，将新数组中的数拷贝到原数组中，否则会拷入随机值
			//例如没有修改：6, 2 | 4, 5 | 1, 3 | -1
			//原数组： 6, 2, 4, 5, 1, 3, -1
			//处理后： 6, 2, 4, 5, 1, 3  (最后一个数不处理)
			//将处理后的数拷贝回去：6, 2, 4, 5, 1, 3, 随机值(结束条件为n导致随机值)
			for (int j = i; j <= end2; j++)//j <= i + 2 * gap - 1，不能这样，因为前面对end2进行修正了，如果万一再使用i + 2 * gap - 1，就会越界访问
			{
				a[j] = tmp[j];
			}
		}
		gap *= 2;
	}
	free(tmp);
}
//利用队列或者栈也能模拟实现，相对而言利用队列方便一些，但面临区间修正的问题。

//多注意边界值的控制。快速排序核心思想：类似于前序遍历。多调试理解逻辑。多画图。

//时间复杂度都是O(N*logN)
#if 0
int main()
{
	int a[] = { 6, 2, 4, 5, 1, 3, -1 };
	int n = sizeof(a) / sizeof(int);
	MergeSortNonR(a, n);

	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}
#endif