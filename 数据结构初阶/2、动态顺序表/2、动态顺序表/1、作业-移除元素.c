#define _CRT_SECURE_NO_WARNINGS 1
//1、移除元素
//给你一个数组nums和一个值val，你需要原地移除所有数值等于val的元素，并返回移除后数值的新长度
//不要使用额外的数值空间，你必须仅使用O(1)额外空间，时间复杂度为O(N)并原地修改输入数组。
//元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
//原地修改，即不能腾挪空间

//方法1、如果下标的值为val，则将后面的数据都往前挪一位覆盖前面的val。时间空间复杂度会很大
//|
//0 1 2 2 3 0 4 2    val = 2
//  |
//0 1 2 2 3 0 4 2
//    |
//0 1 2 3 0 4 2
//    |
//0 1 3 0 4 2
//      |
//0 1 3 0 4 2
//        |
//0 1 3 0 4 2
//          |
//0 1 3 0 4
//如，假设n个元素，最坏的可能所有的元素都为val，则时间复杂度为：(n-1)+(n-2)+(n-3)... =  O(N^2)
//空间复杂度为:O(1)
/*
#include <stdio.h>
int removeElement(int* nums, int numsSize, int val)
{
    int i = 0;
    while(i < numsSize)
    {
        if(nums[i]==val)
        {
            //挪动数据
            int start = i;
            while(start < numsSize-1)
            {
                nums[start] = nums[start+1];
                start++;
            }
            //原数组元素个数减少一个
            numsSize--;
        }
        else
        {
            i++;
        }
    }
    return i;//返回数组元素个数
}
*/

//方法2、(以空间换时间)如果不限空间复杂度，可以：
//开辟一块空间和数组相同大小的空间，依次遍历nums数组中的元素，将不是val的元素放入开辟的空间中
//然后将空间的元素拷贝到原数组中将其覆盖，最后将size大小置为：原始数组元素个数 - val的个数
//此时，最坏情况没有val值的元素，Fn = N+N,时间复杂度为O(N),空间复杂度为O(N)
/*
#include <stdio.h>
int removeElement(int* nums, int numsSize, int val)
{
    //开辟一块和数组相同大小的空间
    int* tmp = (int*)malloc(sizeof(int)*numsSize);
    //将不是val的元素放入开辟的空间中
    int i = 0;
    int j = 0;
    while(i < numsSize)
    {
        if(nums[i]!=val)
        {
            tmp[j] = nums[i];
            j++;
            i++;
        }
        else
        {
            i++;
        }
    }
    //将空间的元素拷贝到原数组中
    int n = 0;
    while(n< j)
    {
        nums[n] = tmp[n];
        n++;
    }
    //将size大小置为：原始数组元素个数 - val的个数
    numsSize = j;

    free(tmp);
    tmp=NULL;
    return numsSize;//返回数组元素个数
}
*/

//方法3、(在方法2的基础上变化，找不是val的数，放在新数组中)找不是val的数，放在原数组中
//把src找到不是val的数，往dest上放。使用两个下标一开始都同时指向第一个元素，
//第一个下标src，如果src位置元素不是val，将该元素放到下标dest位置，然后src++,dest++。
//如果src位置元素是val，src++。
//注意：如果前几个都不是val，则会自己放自己身上放。
//最坏情况没有val值的元素，F(N)=N,时间复杂度为O(N)，空间复杂度为O(1)
#include <stdio.h>
int removeElement(int* nums, int numsSize, int val)
{
	int src = 0, dest = 0;
	while (src < numsSize)//想的是结束的条件，写的是继续的条件
	{
		if (nums[src] != val)
		{
			//nums[dest] = nums[src];
			//src++;
			//dest++;
			nums[dest++] = nums[src++];//先使用src或dest的值，再++
		}
		else
		{
			src++;
		}
	}
	return dest;//返回新数组元素的个数
}

/*
int main()
{
	int nums[] = { 1,3,3,2,3,5,3,5,3,6,0,3,3,3 };
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	int val = 3;
	int ret = removeElement(nums, numsSize, val);
    int i = 0;
	for (i = 0; i < ret; i++)
	{
		printf("%d ", nums[i]);
	}
	return 0;
}
*/

//画图，走读代码，写博客。