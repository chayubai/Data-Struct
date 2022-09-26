#define _CRT_SECURE_NO_WARNINGS 1
//4、旋转数组
//给定一个数组，将数组中的元素向右移动k个位置，其中k是非负数。
//1、尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题
//2、你可以使用空间复杂度为O(1)的原地算法解决这个问题吗？
//原地算法：即不开新的空间，在原数组上处理

//输入：nums = [1,2,3,4,5,6,7],k = 3
//输出：[5,6,7,1,2,3,4]
//向右旋转1步：7，1，2，3，4，5，6
//向右旋转2步：6，7，1，2，3，4，5
//向右旋转3步：5，6，7，1，2，3，4

//方法一、旋转一次：将最后一个数据放入tmp中，把前面几个数据往后拷贝一下，最后把tmp数据放入第一个位置
//即：每次旋转一个，保存最后一个，前n-1个数依次往后挪动。最后一个数放到第一个位置
//时间复杂度为：O(k*N) - 旋转一次 ,挪了N-1 次,放了1次，一共N次。空间复杂度：O(1)
/*
void rotate(int* nums,int numsSize,int k)
{
    k %= numsSize;
    while(k)
    {
        //保存最后一个数
        int tmp = nums[numsSize-1];
        //将前面几个数据都往后挪一位
        int end = numsSize-2;
        while(end>=0)
        {
            nums[end+1] = nums[end];
            end--;
        }
        //把保存的数放入第一个位置
        nums[0] = tmp;
        k--;
    }
}
*/

/*
void rotate(int* nums,int numsSize,int k)
{
    k %= numsSize;
	while(k--)//必须后置--，旋转k次
	for(int i = 0; i < k; ++i)
	{
		int tmp = nums[numsSize - 1];//保存最后一个数
		//从倒数第二个开始往后都后移动一次
		for(int end = numsSize - 2； end >= 0; --end)
		{
			nums[end + 1] = nums[end];
		}
		//将最初保存的最后一个数放入第一个位置
		nums[0] = tmp;
	}
}
*/

//方法二、将后k个数，存入到一个新数组中，将剩余的数往后挪动，最后将新数组中的数放到前k个位置
//时间复杂度：O(N)
//空间复杂度：O(k)
//注意：k大于数组的元素个数时，则k % 元素的个数
#include <stdio.h>
#include <stdlib.h>
/*
void rotate(int* nums,int numsSize,int k)
{
    k %= numsSize;
    //开辟一个大小为k个元素的数组
    int* tmp = (int*)malloc(sizeof(int)*k);
    //将后k个数存入到新数组中
    int i = k - 1;
    int s = numsSize-1;
    while(i >= 0)
    {
        tmp[i] = nums[s];
        i--;
        s--;
    }

    //验证是否将数据成功放入新数组中
    //i = 0;
    //while(i<k)
    //{
    //    printf("%d ",tmp[i]);
    //    i++;
    //}

     //将前numsSize-k个数往前挪k个位置
    int end = numsSize - k - 1;
    while(end>=0)
    {
        nums[end+k] = nums[end];
        end--;
    }

    //将新数组中的数放入原数组中
    int j = 0;
    while(j < k)
    {
        nums[j] = tmp[j];
        j++;
    }
    free(tmp);
    tmp = NULL;
}
*/

//如果是创建一个新数组，把后k个数先存入新数组，再把前n-k个数存入新数组，最后把新数组中的数拷贝到原来的数组中
//此时,时间复杂度：O(N),空间复杂度为O(N)
/*
void rotate(int* nums,int numsSize,int k)
{
    k %= numsSize;
    //开辟一个大小为numsSize个元素的数组
    int* tmp = (int*)malloc(sizeof(int)*numsSize);
    //先将后k个数存入到新数组中
    int i = k - 1;
    int s = numsSize-1;
    while(i >= 0)
    {
        tmp[i] = nums[s];
        i--;
        s--;
    }
    //再将前numsSize-k个数存入到新数组中
    int j = k;
    int s2 = 0;
    while(j < numsSize)
    {
        tmp[j] = nums[s2];
        j++;
        s2++;
    }

    //最后将新数组中的值拷贝到原数组中
    for(int i = 0;i<numsSize;i++)
    {
        nums[i]=tmp[i];
    }
}
 */

//方法三、三步翻转法：
//[1,2,3,4,5,6,7] k = 3
//[4,3,2,1,7,6,5],前n-k个逆置，后k个逆置
//[5,6,7,1,2,3,4],整体逆置
//逆置：对应为两端交换
//时间复杂度：O(N)        :K + N-K + N = 2N
//空间复杂度：O(1)
/*
#include <stdio.h>
//逆置
void reverse(int* nums, int left, int right)
{
	while (left < right)
	{
		int tmp = nums[left];
		nums[left] = nums[right];
		nums[right] = tmp;
		left++;
		right--;
	}
}
void rotate(int* nums, int numsSize, int k)
{
	k %= numsSize;//k大于数组的元素个数 - 可以不用if判断 4 % 7 = 4

	//numsSize = 7 k = 3
	//1 - 4
	//0 - numsSize - k - 1
	//5-7
	//numsSize - k - numsSize - 1
	reverse(nums, 0, numsSize - k - 1);
	reverse(nums, numsSize - k, numsSize - 1);
	reverse(nums, 0, numsSize - 1);
}

int main()
{
	int nums[] = { 1,2,3,4,5,6,7 };
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	int k = 1;
	rotate(nums, numsSize, k);
	int i = 0;
	for (i = 0; i < numsSize; i++)
		printf("%d ", nums[i]);
	return 0;
}
*/
