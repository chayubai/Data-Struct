#define _CRT_SECURE_NO_WARNINGS 1
//1、消失的数字
//数组nums包含从0到n的所有整数，但其中缺了一个。编写代码找出哪个缺失的整数。
//你有办法在O(N)时间内完成吗？
//输入：[3,0,1]
//输出：2

//思路一：先排序，再判断前一个是不是比后一个多/少1 - 不符合时间复杂度要求
/*
#include <stdio.h>
void Sort(int nums[],int numsSize)
{
    for(int i = 0;i<numsSize-1;i++)
    {
        for(int j = 0;j<numsSize-i-1;j++)
        {
            if(nums[j] > nums[j+1])
            {
                int tmp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = tmp;
            }
        }
    }
}
int main()
{
	int nums[] = { 9,6,4,2,3,5,7,0,1 };
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	Sort(nums,numsSize);
	int missingNumber = 0;
	for(int i = 0;i < numsSize;i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");

	for(int i = 0;i < numsSize - 1;i++)
    {
        if(nums[i+1] - nums[i] != 1)
        {
            missingNumber = i+1;
            break;
        }
    }

	printf("缺失的数字为：%d\n", missingNumber);
	return 0;
}
*/

//思路二：对不缺的数组求和，再减去缺失的数组的和 - 满足
/*
#include <stdio.h>
int missingNumber(int* nums, int numsSize)
{
	int x = 0;
	int y = 0;
	//缺失的数组求和
	for (size_t i = 0; i < numsSize; i++)
	{
		x += nums[i];
	}
	//再和0-n中的数异或
	for (size_t i = 0; i <= numsSize; i++)
	{
		y += i;
	}
	return y - x;
}
int main()
{
	int nums[] = { 9,6,4,2,3,5,7,0,1 };
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	printf("缺失的数字为：%d\n", missingNumber(nums, numsSize));
	return 0;
}
*/

//思路三：num跟数组中的数和0到3之间所有的数异或，结果就是要找的数

//举例：假设完整数组元素是01234 ，实际数组少3，即nums[4]={0,1,2,4}，numsSize = 4
//上面循环异或完后是 x = 0 ^ 1 ^ 2 ^ 4，
//下面循环异或结束后，就变成了 x = x ^ 0 ^ 1 ^ 2 ^ 3 ^ 4 ，最终为x = 3
//原理：相同的两个数异或是0，而数组中没有2，0到3之间都有
//先思考几个小时，如果没有好的思路，去看看别人的代码和思路。理解之后，自己再实现一下，并做博客记录。

/*
#include <stdio.h>
int missingNumber(int* nums, int numsSize)//nums为数组，numsSize为数组的元素个数
{
	int x = 0;//用来保存异或值的结果，0和任何数异或仍为任何数
	//先和数组中的数异或
	for (size_t i = 0; i < numsSize; i++)
	{
		x ^= nums[i];
	}
	//再和0-n中的数异或
	for (size_t i = 0; i <= numsSize; i++)
	{
		x ^= i;
	}
	return x;
}
int main()
{
	int nums[] = { 9,6,4,2,3,5,7,0,1 };
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	printf("缺失的数字为：%d\n", missingNumber(nums, numsSize));
	return 0;
}
 */
