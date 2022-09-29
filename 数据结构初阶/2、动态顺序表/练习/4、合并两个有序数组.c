#define _CRT_SECURE_NO_WARNINGS 1
//4、合并两个有序数组
//给你两个有序整数数组nums1和nums2，请你将nums2合并到num1中，使num1成为一个有序数组
//1、初始化nums1和nums2的元素数量分别为m和n
//2、你可以假设nums1有足够的空间（空间大小大于或等于m+n）来保存nums2中的元素
//输入：
//nums1 = [1,2,3],m = 3
//nums2 = [2,5,6],n = 3
//输出：[1,2,2,3,5,6]

//方法一：
//直接将第二个数组的值拷贝到第一个数组后面，然后排序，时间复杂度为O((M+N)*log2(M+N))
/*
#include <stdio.h>
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    //将nums2数组中的数据拷贝到nums1中
    int i = m;
    int j = 0;
    while(i<(m+n))
    {
        nums1[i] = nums2[j];
        i++;
        j++;
    }
    //排序nums1
    for(int i = 0;i < (m + n) - 1;i++)
    {
        for(int j= 0;j < (m + n) - i - 1;j++)
        {
            if(nums1[j]>nums1[j+1])
            {
                int tmp = nums1[j];
                nums1[j] = nums1[j+1];
                nums1[j+1] = tmp;
            }
        }
    }
}
 */

 //插入思想：如果第二个数组的元素比第一个大，比第二个小或等，则放在第二个数的前面
 //第一个指针指向nums1数组的第一个元素，第二个指针指向nums2的第一个元素
 //用第二个指针依次与第一个数组中的元素比较，如果大于第一个元素，则第一个指针++，且小于等于第二个元素时
//则把第二个数以及后面的数挪动一下，将第二个指针指向的数据放入中间。后第二个指针++，继续上面的过程
/*
#include <stdio.h>
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    int i2 = 0;//nums2的下标
    while(i2 < n)
    {
        int i1 = 0;//nums1的下标
        while(i1<m)
        {
            if(nums2[i2]<=nums1[i1])
            {
                //挪动数据
                int end = m-1;
                while(end>=i1)
                {
                     nums1[end+1] = nums1[end];
                     end--;
                }
                nums1[i1] = nums2[i2];
                m++;
                i2++;
                break;
            }
            else
            {
                i1++;
            }
        }
    }

}

int main()
{
	int nums1[1024] = { -1,1,2,3};//nums1数组的空间足够大
	int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
	int m = 4;
	int nums2[] = { -2,-1,0 };
	int nums2Size = sizeof(nums2) / sizeof(nums2[0]);
	int n = nums2Size;
	merge(nums1, nums1Size, m, nums2, nums2Size, n);
    int i = 0;
	for (i = 0; i < (n+m); i++)
		printf("%d ", nums1[i]);

	return 0;
}
*/

//优化：两个指针，第一个指针指向nums1数组元素的最后一个位置，第二个指针指向nums2数组元素的第一个位置
//从后往前比，如果第二个指针指向的数据小于第一个指针指向的数据，则第一个指针--，直到大于或等于第一个指针的数据
//然后，将第一个指针的位置及以后的数都往后挪
//如果第二个指针指向的数据大于等于第一个指针指向的数据，则直接放在后面
//对于1，2，3，0，0，0和-2，-1，0，此时时间复杂度为：O(M*N)
/*
#include <stdio.h>
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{

    int i2 = 0;//nums2的下标
    while (i2 < n)
    {
        int i1 = m - 1;//nums1的下标
        while (i1 >= 0)
        {
            if (nums2[i2] < nums1[i1])
            {
                i1--;
            }
            else
            {
                //挪动数据，大于等于之后的所有数，不包括前一位
                int end = m - 1;
                while (end >= i1 + 1)
                {
                    nums1[end + 1] = nums1[end];
                    end--;
                }
                nums1[i1 + 1] = nums2[i2];
                i2++;
                m++;
                break;
            }
        }
        if (i1 == -1)
        {
            //挪动数据
            int end = m - 1;
            while (end >= 0)
            {
                nums1[end + 1] = nums1[end];
                end--;
            }
            nums1[0] = nums2[i2];
            i2++;
            m++;
        }
    }
}

int main()
{
    //1，2，3，0，0，0和-2，-1，0
    int nums1[1024] = { -1,1,2,3 };//nums1数组的空间足够大
    int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
    int m = 4;
    int nums2[] = { -2,-1,0 };
    int nums2Size = sizeof(nums2) / sizeof(nums2[0]);
    int n = nums2Size;
    merge(nums1, nums1Size, m, nums2, nums2Size, n);
    int i = 0;
    for (i = 0; i < (n + m); i++)
        printf("%d ", nums1[i]);

    return 0;
}
 */

//方法二：取小的放到新数组中，再把新数组拷贝到原数组中
//开辟一个大小为两个数组大小之和的空间。
//两个指针分别指向两个数组中的第一个元素。比较两个指针指向的元素的大小，取小的元素先放到新空间中。
//小的指针++，大的指针不++
//当有一个数组走到尾时，即没有数据比较时，直接将剩余的数据加到新数组的后面,最后拷回到nums1中
//两个数据都遍历了一遍，时间复杂度为O(M+N)  //空间复杂度为;O(M+N) - 以空间换时间
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    //开辟新空间
	int* tmp = malloc(sizeof(int) * (n + m));
	if (tmp == NULL)
		return;
	int i = 0;//指向开辟空间的第一个位置

	int i1 = 0, i2 = 0;//两个变量分别指向两个数组的第一个元素
	while (i1 < m && i2 < n)//有一个走到了尾就结束，都没有走到尾就继续循环
	{
		if (nums1[i1] < nums2[i2])
		{
			tmp[i] = nums1[i1];
			i++;
			i1++;
			//以上代码简洁化
			//tmp[i++] = nums1[i1++];
		}
		else
		{
			tmp[i] = nums2[i2];
			i++;
			i2++;
		}
	}
	//如果数组nums1没有走到尾
	while (i1 < m)
	{
		tmp[i] = nums1[i1];
		i++;
		i1++;
	}
	//如果数组nums2没有走到尾
	while (i2 < n)
	{
		tmp[i] = nums2[i2];
		i++;
		i2++;
	}
	//拷到nums1数组中
	memcpy(nums1, tmp, sizeof(int) * (n + m));
	free(tmp);
	tmp = NULL;
}
*/

//方法三、nums1和nums2都从后往前走，取大的从后往前放
//如果num2中下标位置的元素大于nums1中下标位置的元素，则把大的元素放入元素所在的最后一个位置
//依次放入。如果nums2中的数据走完了，则结束。如果nums1没走完，而nums2走完了，无需处理，直接结束。
//如果nums1中的数据走完了，则把nums2中的数据依次放入原数组中的前n个位置
//空间复杂度为;O(M+N)
/*
 void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
	int end1 = m - 1;
	int end2 = n - 1;
	int end = m + n - 1;
	while (end1 >= 0 && end2 >= 0)//有一个走到了头就结束，都没有走到头就继续循环
	{
		if (nums1[end1] > nums2[end2])
		{
			nums1[end] = nums1[end1];
			end--;
			end1--;
		}
		else
		{
			nums1[end] = nums2[end2];
			end--;
			end2--;
		}
	}
	//如果数组nums2没有走到头，将nums2中剩余的数据放入nums1中前n个位置
	while (end2 >= 0)
	{
		nums1[end] = nums2[end2];
		end--;
		end1--;
	}
	//如果数组nums1没有走到头，不需要处理
}

int main()
{
	//1，2，3，0，0，0和-2，-1，0
	int nums1[1024] = { -1,1,2,3};//nums1数组的空间足够大
	int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
	int m = 4;
	int nums2[] = { -2,-1,0 };
	int nums2Size = sizeof(nums2) / sizeof(nums2[0]);
	int n = nums2Size;
	merge(nums1, nums1Size, m, nums2, nums2Size, n);
    int i = 0;
	for (i = 0; i < (n+m); i++)
		printf("%d ", nums1[i]);

	return 0;
}
 */
