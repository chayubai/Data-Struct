#define _CRT_SECURE_NO_WARNINGS 1
//2、数组中的数字出现的次数
//一个整型数组nums里除两个数字之外，其他数字都出现了两次。
//请写程序找出这两个只出现一次的数字。要求时间复杂度是O(N)，空间复杂度是O(1).
//输入：nums = [2,1,3,1,2,5]
//输出：[3,5](结果输出的顺序不重要，即[5,3]也正确)

//子题发散：消失的数字（在一个数组中，只有一个数只出现一次，其余数字都出现两次，找出这个只出现一次的数字）
//          - 将数组的所有数字异或，结果即为只出现一次的数字

//思路：
//第一步、nums中所有数异或，结果为两个数出现1次的数 异或的值，假设出现一次的这两个数为3和8
//        000000....00000011 = 3
//        000000....00001000 = 8
//        000000....00001011
//第二步、想办法从异或值中，分开这两个数，找二进制中任意一个它里面为1的位。
//        假设找到结果的值第N位为1，则说明两个数的第N位不一样。其中一个数的第N位为1，另一个数的第N位为0
//第三步、分组
//        将原数组中，每个数，如果第N位均为1的数被分到第一组，这组中：其他数出现两次，一个数出现1次
//        将原数组中，每个数，如果第N位均为0的数被分到第二组，这组中：其他数出现两次，一个数出现1次
//        那么出现两次的要么进入了第一组，要么进入第二组，出现1次的一个进入第一组，一个进入第二组
//        这两个数各在一组，其他数成对出现在某一组。
//第四步、两组数各自对所有数进行异或，便得到各组中出现一次的数

//举例：nums = [2,1,3,1,2,5]
//数组中的所有数异或，ret = ret ^ 2^1^3^1^2^5 = 3^5 = 00000110
//依据任意一位为1，找出ret里面第M位为1的位，则3和5的第M位不一样。
//通过1移位和ret按位与，任取一位为1的位，假设第M = 2位为1。
//取原数组中分离出3和5：
//第M位为1的为一组：2，2，3
//第M位位0的为一组：1，1，5

//F(N) = N + N + 32,故时间复杂度：O(N)。空间复杂度：O(1)

#include <stdio.h>
#include <stdlib.h>
int* singleNumber(int* nums, int numsSize, int* returnSize)//nums为数组，numsSize为数组的元素个数，输入型参数，returnSize输出型参数
{
	//第一步：假设出现1次的两个数为x1 = 5和x2 = 3
	int ret = 0;//用来保存异或值的结果
	for (int i = 0; i < numsSize; i++)
	{
		ret ^= nums[i];
	}
	//ret = 000000110

	//第二步：找ret二进制位为1的任意一位，假设为第m位为1
	int m = 0;//控制移位的次数
	while (m < 32)//循环int位数次
	{
		//用1左移M位后与ret，（与运算：同为1，则为1）如果结果为1，则找到了此位为1，否则将1移一位，继续与ret
		//ret = 000000110
		//1<<0= 000000001
		//&     000000000 = 0假
		//将1移1位后
		//ret = 000000110
		//1<<1= 000000010
		//&     000000010 > 0真
		if (ret & (1 << m))
			break;
		else
			m++;
	}

	//第三步：从原数组中分离3和5，边分组边异或
	int x1 = 0;
	int x2 = 0;
	for (int i = 0; i < numsSize; i++)
	{
		if (nums[i] & (1 << m))//第m位为1
		{
			x1 ^= nums[i];
		}
		else//第m位为0
		{
			x2 ^= nums[i];
		}
	}

	//开辟两个int型大小的空间用于返回两个结果
	int* retArr = (int*)malloc(sizeof(int) * 2);
	if (retArr == NULL)
		return 0;
	retArr[0] = x1;
	retArr[1] = x2;

	*returnSize = 2;//returnSize输出型参数
	return retArr;
}
int main()
{
	int nums[] = { 2,1,3,1,2,5,3,8 };
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	int* tmp = NULL;
	int retSize = 0;
	tmp = singleNumber(nums, numsSize, &retSize);
	printf("只出现1次的两个数字为：");
	for (int i = 0; i < retSize; i++)
	{
		printf("%d ", tmp[i]);
	}
	free(tmp);
	tmp = NULL;

	return 0;
}

/*
#include <stdio.h>
int main()
{
	int arr[] = { 1,-2,3,-1,1,-2,3,6 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	int result = 0;
	for (i = 0; i < sz; i++)
	{
		result ^= arr[i];
	}
	int m = 0;
	for (m = 0; m < 32; m++)
	{
		if ((result >> m) & 1)
		{
			break;
		}
	}
	if (m == 32)
	{
		return -1;
	}
	int x1 = 0;
	int x2 = 0;
	for (i = 0; i < sz; i++)
	{
		if ((arr[i] >> m) & 1)
		{
			x1 ^= arr[i];
		}
		else
		{
			x2 ^= arr[i];
		}
	}
	printf("%d %d\n", x1, x2);
	return 0;
}
*/

//画图，走读代码，写博客。