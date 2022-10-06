#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//摸一张牌，对它进行排序 - - 插入排序
//一把牌全部摸上来，进行排序  - - 选择排序
//思路：升序：
//假设a[0]是最大的，依次与后n-1个数比较，如果有更大的则更新最大的数，放在a[0]位置
//假设a[1]是最大的，依次与后n-2个数比较，如果有更大的则更新最大的数，放在a[1]位置
//...
//即重复使用“在一个数组中找最大数的一个”

//错误答案：
//void SelectSort(int* a, int n)
//{
//    for (int j = 0; j < n-1; j++)
//    {
//        int max = a[j];
//        for (int i =j + 1; i < n; i++)
//        {
//            if (max < a[i])
//                swap(&max, &a[i]);//这里交换无法实现
//        }
//        a[j] = max;
//    }
//}

//正确答案：
//思路：升序
//假设下标为0的数是最小的，依次与后n-1个数比较，如果有更小的则，记录它的下标，更新最小的数的下标，再把它放在a[0]位置
//假设下标为1的数是最小的，依次与后n-2个数比较，如果有更小的则，记录它的下标，更新最小的数的下标，再把它放在a[1]位置
//...
//即重复使用“在一个数组中找最大数的一个”
//void swap(int* a, int* b) 
//{
//    int temp = *a;
//    *a = *b;
//    *b = temp;
//}
void selection_sort(int arr[], int len)
{
    int i, j;
    for (i = 0; i < len - 1; i++)//需要确定多少个最大的数
    {
        int min = i;
        for (j = i + 1; j < len; j++) //假设依次下标i为最大的数和后【i+1，n-1-i】区间的数比较
        {
            if (arr[j] < arr[min])    //找到目前最大值
                min = j;                //记录更大的数的下标
            swap(&arr[min], &arr[i]);    //做交換
        }
    }
}

//一次选两个数，最大和最小的下标的数，分别放在两端
//void SelectSort(int* a, int n)
//{
//    int begin = 0, end = n - 1;
//    while (begin < end)
//    {
//        int max = begin, min = begin;
//        for (int i = begin; i <= end; i++)
//        {
//            if (a[i] < a[min])
//            {
//                min = i;
//            }
//            if (a[i] > a[max])
//            {
//                max = i;
//            }
//        }
//        swap(&a[begin], &a[min]);//对于6, 2, 4, 5, 1, 3, -1，结果就会出问题
//        //分析原因：由于下一步和上一步连续执行，将max位置的下标的数又换回到end位置
//        swap(&a[max], &a[end]);
//        begin++;
//        end--;
//    } 
//}

//最好或最坏的结果：时间复杂度都是：O(N) = N * N
//第一次，N次
//第二次，N-2次
//第三次，N-4次
//...

void SelectSort(int* a, int n)
{
    int begin = 0, end = n - 1;
    while (begin < end)
    {
        int max = begin, min = begin;
        for (int i = begin; i <= end; i++)
        {
            if (a[i] < a[min])
            {
                min = i;
            }
            if (a[i] > a[max])
            {
                max = i;
            }
        }//6, 2, 4, 5, 1, 3, -1
        swap(&a[begin], &a[min]);
        //如果begin和max重叠
        if (begin == max)
            max = min;//由于交换了一下，max的数的下标为min的下标
        swap(&a[max], &a[end]);
        begin++;
        end--;
    }
}

//int main()
//{
//	int a[] = { 6, 2, 4, 5, 1, 3, -1};
//
//	int n = sizeof(a) / sizeof(a[0]);
//    //selection_sort(a, n);
//    SelectSort(a, n);
//
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	return 0;
//}