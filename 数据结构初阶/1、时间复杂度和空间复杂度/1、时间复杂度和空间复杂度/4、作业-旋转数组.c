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

//方法一、旋转一次：将最后一个数据保存到tmp中，把前面几个数据往后拷贝一下，最后把tmp数据放入第一个位置
//即：每次旋转一个，保存最后一个，前n-1个数依次往后挪动，最后一个数放到第一个位置。
//旋转k个位置，则需要循环重复k次。
//旋转一次 ,需要挪了N-1 次,和放置最后一个数1次，一共N次。需要旋转k次。
//F(N) = [1 + (N-1)] * K = N*K，时间复杂度为：O(k*N)，空间复杂度：O(1)
/*
void rotate(int* nums,int numsSize,int k)
{
    k %= numsSize;
    while(k)
    {
        //保存最后一个数
        int tmp = nums[numsSize-1];
        //将前面几个数据都往后挪一位
        int end = numsSize-2;//倒数第二个数的下标
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
    //while(k--)//必须后置--，旋转k次。k--返回k，则k--循环k次
    for(int i = 0; i < k; ++i)
    {
        int tmp = nums[numsSize - 1];//保存最后一个数
        //从倒数第二个开始往后都后移动一次
        for(int end = numsSize - 2； end >= 0; --end)//倒数第二个数的下标
        {
            nums[end + 1] = nums[end];
        }
        //将最初保存的最后一个数放入第一个位置
        nums[0] = tmp;
    }
}
*/

//方法二、将后k个数，存入到一个容量为k的新数组中，将剩余的数往后挪动，最后将新数组中的数放到前k个位置
//【1，2，3，4，5，6，7】 -> 【5，6，7，1，2，3，4】
//F(N) = K + (N-K) + K = N+k，时间复杂度：O(N+k)
//空间复杂度：O(k)。
//如果先将后k个数，存入到一个新数组中，再将剩余的数拷贝到新数组中，最后将所有的数拷贝到原空间中。
//则需要开辟k个数的空间。那么空间复杂度为：O(k)
//注意：以空间换时间
//注意：k大于数组的元素个数时，则k % 元素的个数
#include <stdio.h>
#include <stdlib.h>
/*
void rotate(int* nums,int numsSize,int k)
{
    k %= numsSize;
    //开辟一个大小为k个元素的数组
    int* tmp = (int*)malloc(sizeof(int)*k);
    //将后k个数存入到新数组中的对应位置上
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

    //将前numsSize-k个数往后挪k个位置
    int end = numsSize - k - 1;
    while(end>=0)
    {
        nums[end+k] = nums[end];
        end--;
    }

    //将新数组中的k个数放入原数组中
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

//如果是创建一个容量为n的新数组，把后k个数先存入新数组，再把前n-k个数存入新数组，最后把新数组中的数拷贝到原来的数组中
//此时,F(N) = K + (N-K) + N = 2N，时间复杂度：O(N),空间复杂度为O(N)
//注意：以时间换空间，这样如果是一个很大的数组，就需要开辟一个很大的空间，可能空间不够用。
/*
void rotate(int* nums,int numsSize,int k)
{
    k %= numsSize;
    //开辟一个大小为numsSize个元素的数组
    int* tmp = (int*)malloc(sizeof(int)*numsSize);
    //先将后k个数存入到新数组中的对应位置上
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

 //方法三、三步翻转法
 //[1,2,3,4,5,6,7] k = 3
 //[4,3,2,1,7,6,5],前n-k个逆置，后k个逆置
 //[5,6,7,1,2,3,4],整体逆置
 //逆置：对应为两端交换
 //F(N) = K/2 + (N-K)2/ + N/2 = N，时间复杂度：O(N)        
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

     //1,2,3,4,5,6,7
     //numsSize = 7 k = 3
     //0 - 3
     //0 - (numsSize - k - 1)
     //4 - 6
     //(numsSize - k) - (numsSize - 1)

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

 //画图，走读代码，写博客。