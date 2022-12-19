#define _CRT_SECURE_NO_WARNINGS 1
//3、数组形式的整数加法
//对于非负整数X而言，X的数组形式是每位数字按从左到右的顺序形式的数组。
//例如：如果X = 1231，那么其数组形式为[1,2,3,1]
//给定非负整数X的数组形式A，返回整数X+K的数组形式
//输入：A = [1,2,0,0] K = 34
//输出[1,2,3,4]
//解释：1200 + 34 = 1234
//输入：A = [9,9,9,9,9,9,9,9,9,9] K = 1
//输出[1,0,0,0,0,0,0,0,0,0,0,0]

//输入：A = [2,7,4] K = 181
//输出[4,5,5]
//解释：274 + 181 = 455

//方法一：将数组变成整型，即倒序依次取每一位乘它的权重，与K相加后的结果分离每一位，存入数组中。
//注意：对于A+K的值超过了unsigned long long 类型的范围，将不适用
/*
#include <stdio.h>
#include <stdlib.h>
int* addToArrayFrom(int* A, int ASize, int K,int* returnSize)
{
    //1、将A变为整数
    int ai = ASize - 1;//A的下标
    int i = 1;//权重
    unsigned long long result_A = 0;//A数组转为整数的结果
    while(ai >= 0)
    {
        A[ai] *= i;
        result_A += A[ai];
        i *= 10;
        ai--;
    }
    //A + K 的结果
    unsigned long long result = result_A + K;

    //2、开辟空间
    int KSize = 0;//K的位数
	int Knum = K;//防止K的值发生变化，因为后面需要用到计算K每一位与数组每一位的和
	//计算K的位数
	while (Knum)
	{
		KSize++;
		Knum /= 10;
	}
    //开辟空间，存放result分离出来的每一个位
    int len = ASize > KSize ? ASize : KSize;
	int* tmpArr = (int*)malloc(sizeof(int) * (len + 1));
	if (tmpArr == NULL)
		return 0;

    //3、分离每一位存放到数组中
    int a = 0;//新空间数组的下标
    while(result)
    {
        int ret = result % 10;
        tmpArr[a] = ret;
        result /= 10;
        a++;
    }

    //4、逆置数组中的元素
	int left = 0, right = a - 1;
	while (left < right)
	{
		int tmp = tmpArr[left];
		tmpArr[left] = tmpArr[right];
		tmpArr[right] = tmp;
		left++;
		right--;
	}

	*returnSize = a;//将返回值的大小给外面的变量retSize，从而知道循环条件而实现打印
	return tmpArr;
}
int main()
{
	int A[] = { 2,1,5 };
	int K = 806;
	int ASize = sizeof(A) / sizeof(A[0]);
	int retSize = 0;
	int* ret = addToArrayFrom(A, ASize, K, &retSize);

    for (int i = 0; i < retSize; i++)
	{
		printf("%d ", *(ret+i));
	}

	free(ret);
	ret = NULL;
	return 0;
}
 */

//方法二：模拟加法运算符
//两个数相加，最后的结果的位数一定比其中最大的那一个数多一位或等于
//将结果放入开辟出来的空间中

//第一步：计算A的元素个数和K的位数
//第二步：开辟比最大位数大1的空间大小
//第三步：相加 - 依次取A数组中的值与K的每一位对应位相加
//第四步：将结果放入开辟的数组中
//第五步：逆置数组中的元素

#include <stdio.h>
#include <stdlib.h>
int* addToArrayFrom(int* A, int ASize, int K,int* returnSize)
{
	int KSize = 0;//K的位数
	int Knum = K;//防止K的值发生变化，因为后面需要用到计算K每一位与数组每一位的和
	//第一步：计算K的位数
	while (Knum)
	{
		KSize++;
		Knum /= 10;
	}

	//第二步：开辟比最大位数大1的空间大小

	//A+K的结果保存到开辟的数组中，相加的数的结果最多进一位，即数组的大小为A或K中的最多位数+1
	//int* retArr = (int*)malloc(sizeof(int) * ());

	int len = ASize > KSize ? ASize : KSize;//控制相加结束的条件
	int* retArr = (int*)malloc(sizeof(int) * (len + 1));
	if (retArr == NULL)
		return 0;

	//第三步：A和K的对应位相加
	int Ai = ASize - 1;//Ai控制A数组的中元素的位置
	int reti = 0;//新空间数组的下标
	int nextNum = 0;//判断相加后是否进位，必须初始化为0
	while (len--)//,len-- 走len次，--len 走len-1次
	{
	    //  99 A
	    //1234 K
		//对于A数组元素个数小于K的位数，Ai就会发生越界，即K对应位可以没值，但Ai对应位不能没有值
		int a = 0;//当Ai的位置上没有数时，用0取代没有值的Ai位置的数
		if (Ai >= 0)
		{
			a = A[Ai];
			Ai--;
		}

        //当Ai<0时，A上面没有值，用0代替
		int ret = a + K % 10 + nextNum;//保存相加后的那位数
		K = K / 10;
        //判断对应位相加的结果，是否大于9，如果大于9进位
		if (ret > 9)
		{
			ret = ret - 10;
			nextNum = 1;//进位
		}
		else
		{
			nextNum = 0;//防止后一个进位，下一位没有进位
		}

        //第四步：将相加的结果保存到新数组中
		retArr[reti] = ret;
		reti++;
	}

    //由于前面所有位相加后，结束了，需要对最后一个进位的处理
	//A[2,1,5] K = 806
	if (nextNum == 1)
	{
		retArr[reti] = 1;
		reti++;//需要加上，否则，遍历数组交换时，有问题
	}

	//第五步：逆置数组中的元素：左右位置的值交换
	int left = 0, right = reti - 1;
	while (left < right)
	{
		int tmp = retArr[left];
		retArr[left] = retArr[right];
		retArr[right] = tmp;
		left++;
		right--;
	}

	*returnSize = reti;//将返回值的大小给外面的变量retSize，从而知道循环条件而实现打印
	return retArr;
}

//模拟减法运算 - 借位。如果是（小数 - 大数）时，用大减小，再前面添加一个负号
//模拟乘法运算 - 转变为加法。如：10 * 5 = 10 + 10 + 10 + 10 + 10
//模拟除法运算 - 转变为减法。如：10 / 5 = 10 - 5 - 5

//画图，走读代码，写博客。