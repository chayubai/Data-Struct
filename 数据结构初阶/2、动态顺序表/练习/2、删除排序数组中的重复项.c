#define _CRT_SECURE_NO_WARNINGS 1
//2、删除排序数组中的重复项
//给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
//不要使用额外的数组空间，你必须在原地修改输入数组，并在使用O(1)额外空间的条件下完成。

//方法1、两个指针，第一个指针指向第一个元素，第二个指针指向第二个元素，
//如果这两个数相同，则从第二个指针开始把这个位置及后面所有的数据都往前挪
//如果这两个数不相同，两个指针都++
//如果重复的项太多，此方法时间复杂度较大
/*
#include <stdio.h>
int removeDuplicates(int* nums, int numsSize)
{
    //判断是否为空数组
	if (numsSize == 0)
		return 0;

	int start1 = 0;
	int start2 = 1;
	//遍历数组
	while(start2<=numsSize-1)
    {
        if(nums[start1]==nums[start2])
        {
            //挪动数据
            int start = start2;
            while(start<=numsSize-1)
            {
                nums[start-1] = nums[start];
                start++;
            }
            //原数组个数减一
            numsSize--;
        }
        else
        {
            start1++;
            start2++;
        }
    }
	return numsSize;
}
 */

//方法2、两个指针指向的数据不相同,则保留第一个指针的元素放入新数组中
//第一步：开辟一个足够大的空间
//第二步：使用两个指针，第一个指针指向第一个数据，第二个指针指向第二个数据
//如果不同，则拿下第一个指针的数据存入新空间中，再两个指针++
//如果相同，则直接两个指针++，直到不相同
//第三步：当最后一次如果两个指针的数据不同，则最后一个数据也拿到新空间中
//第三步：当最后一次如果两个指针的数据相同，则其中任意一个数据也拿到新空间中
//第四步：最后把数组的元素拷贝到旧数组中
/*
#include <stdio.h>
#include <stdlib.h>
int removeDuplicates(int* nums, int numsSize)
{
    //判断是否为空数组
	if (numsSize == 0)
		return 0;

    //第一步：开辟一个足够大的空间
    int* tmp = malloc(sizeof(int)*1024);
    if(tmp == NULL)
    {
        return -1;
    }

	int start1 = 0;
	int start2 = 1;
	int i = 0;//开辟的新数组的下标
	//遍历数组
	while(start2<=numsSize-1)
    {
        //两个指针指向的数据不相同,则保留第一个指针的元素放入新数组中
        if(nums[start1]!=nums[start2])
        {

            //保留第一个指针的数据
            tmp[i] = nums[start1];
            i++;
            start1++;
            start2++;

            //第三步：当最后一次如果两个指针的数据不同，则最后一个数据也拿到新空间中
            if(start1 == numsSize-1)
            {
                tmp[i] = nums[start1];
            }
        }
        else
        {
            //第三步：当最后一次如果两个指针的数据相同，则其中任意一个数据也拿到新空间中
            if(start2 == numsSize-1)
            {
                tmp[i] = nums[start1];
            }
            start1++;
            start2++;
        }

    }

    //第四步：最后把数组的元素拷贝到旧数组中
    int j = 0;//原数组的下标
    for(j = 0;j<=i;j++)
    {
        nums[j]=tmp[j];
    }

    free(tmp);
    tmp = NULL;
	return j;//返回数组的个数
}
*/

//方法3、在上面的基础上，如果不相同则将下标为prev的值给下标为dest
//使用两个指针，第一个指针prev指向第一个数据，第二个指针cur指向第二个数据，dest指向第一个数据
//如果不同，则拿下第一个prev指针的数据覆盖到dest指向的数据，dest++，两个指针++
//如果相同，仅仅两个指针++，直到两个指针不同
//当最后一次如果两个指针的数据不同，则第一个指针和第二个指针指向的数据都要覆盖到dest指向的数据
//当最后一次如果两个指针的数据相同，则第一个指针的数据覆盖到dest的位置
/*
 #include <stdio.h>
int removeDuplicates(int* nums, int numsSize)
{
	//判断是否为空数组
	if (numsSize == 0)
		return 0;
	//1 1 2 2 2 3 3
	//1 1 2 2 2 3 4
	//1 2 2 3 3 4 4
	int prev = 0, cur = 1, dest = 0;
	while (cur < numsSize)
	{
		if (nums[prev] != nums[cur])
		{
			nums[dest] = nums[prev];
			prev++;
			cur++;
			dest++;
		}
		else
		{
			prev++;
			cur++;
		}

	}
	//此时cur = numsSize，prev = numsSize
	nums[dest] = nums[prev];
	dest++;//由于返回新数组的长度，需要dest++，否则下面i <= ret
	prev++;//此行无所谓

	return dest;//返回数组的个数
}
 */

//方法4、在上面的基础上，去重 - 将第二个指针指向的数据与第一个指针不同时，更新第一个指针指向第二个指针指向的数据
//使用两个指针，第一个指针i指向第一个数据，第二个指针j指向第二个数据，dest指向第一个数据
//如果不同，则拿下第一个i指针的数据覆盖到dest指向的数据，dest++，i = j,j++
//如果相同，仅仅j++，直到两个指针不同
//当最后一次如果两个指针的数据不同，则第一个指针和第二个指针指向的数据都要覆盖到dest指向的数据
//当最后一次如果两个指针的数据相同，则第一个指针的数据覆盖到dest的位置
#include <stdio.h>
int removeDuplicates(int* nums, int numsSize)
{
	//判断是否为空数组
	if (numsSize == 0)
		return 0;

	int i = 0, j = 1, dest = 0;
	while (j < numsSize)
	{
		if (nums[i] != nums[j])
		{
			nums[dest] = nums[i];
			i = j;
			j++;
			dest++;
		}
		else
		{
			j++;
		}
	}

	nums[dest] = nums[i];
	dest++;//由于返回新数组的长度，需要dest++，否则下面i <= ret

	return dest;//返回数组的个数
}
int main()
{
	int nums[] = { 1,1,2,2,2,3,3 };
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	int ret = removeDuplicates(nums, numsSize);
	int i = 0;
	for (i = 0; i < ret; i++)
	{
		printf("%d ", nums[i]);
	}
	return 0;
}