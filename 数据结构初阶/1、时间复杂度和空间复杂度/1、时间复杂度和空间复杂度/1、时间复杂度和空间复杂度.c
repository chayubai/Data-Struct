#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//时间复杂度：算法中的基本操作的执行次数。表示方式：大O的渐近表示法。

//如何计算算法的时间复杂度？
//1、请计算一下Func1基本操作++count执行了多少次？
/*
void Func1(int N)
{
	int count = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			++count;
		}
	}
	for (int k = 0; k < 2 * N; ++k)
	{
		++count;
	}
	int M = 10;
	while (M--)
	{
		++count;
	}
	printf("%d\n", count);
}
*/
//Func1执行的基本操作的准确次数：F(N) = N*N + 2*N + 10
//随着N的增大，这个表达式中的N^2对结果的影响是最大的
//因此对于Func1函数，N^2对整个表达式的影响较大。故Func1的时间复杂度为：O(N^2)

/**************************************************************************
时间复杂度的计算方法：
1、如果表达式是确定的常数，用常数1取代运行时间中的所有加法常数。
2、时间复杂度是一个估算，计算执行基本操作的次数，一般取表达式中影响最大的那一项,也就是只保留最高阶项。
3、如果是最高阶项存在且项的系数不是1，则去除与这个项相乘的常数。得到的结果就是大O阶。
4、另外有些算法的时间复杂度存在最好、平均和最坏情况：
最坏情况：任意输入规模的最大运行次数(上界)
平均情况：任意输入规模的期望运行次数
最好情况：任意输入规模的最小运行次数(下界)
例如：在一个长度为N数组中搜索一个数据x
最好情况：1次找到
最坏情况：N次找到
平均情况：N/2次找到
在实际中一般情况关注的是算法的最坏运行情况，所以数组中搜索数据时间复杂度为O(N)
***************************************************************************/

//2、计算Func2的时间复杂度？
/*
void Func2(int N)
{
	int count = 0;
	for (int k = 0; k < 2 * N; ++k)
	{
		++count;
	}
	int M = 10;
	while (M--)
	{
		++count;
	}
	printf("%d\n", count);
}
*/
//Func2执行的基本操作的准确次数：F(N) = 2*N + 10
//随着N的增大，这个表达式中的2N对结果的影响是最大的
//由于最高阶项的系数不是1，则去除该常数。故Func2的时间复杂度为：O(N)

//3、计算Func3的时间复杂度？
/*
void Func3(int N, int M)
{
	int count = 0;
	for (int k = 0; k < M; ++k)
	{
		++count;
	}
	for (int k = 0; k < N; ++k)
	{
		++count;
	}
	printf("%d\n", count);
}
*/
//Func3执行的基本操作的准确次数：F(N) = N + M
//故，Func3的时间复杂度为：O(N + M)
//注意：
//如果N远大于M，则Func3的时间复杂度为：O(N)。
//如果M和n相差不大，则Func3的时间复杂度为：O(N)或O(M)。

//4、计算Func4的时间复杂度？
/*
void Func4(int N)
{
	int count = 0;
	for (int k = 0; k < 100; ++k)
	{
		++count;
	}
	printf("%d\n", count);
}
*/
//Func4执行的基本操作的准确次数：F(N) = 100
//F(N) = 100 ，用1取代基本操作的执行次数中所有加法常数，故Func4的时间复杂度为：O(1)
//注意：如果将算法优化到O(1)，说明是优化到常数次。

//5、计算strchr的时间复杂度？
/*
const char* strchr(const char* str, char character)
{
	while (*str != '\0')
	{
		if (*str == character)
			return str;

		++str;
	}

	return NULL;
}
*/
//strchr函数：从字符串中找一个字符。类似于数组中找数。
//假设字符串的长度是N，
//如果是要找的字符在第一个位置，找一次就找到了。故最好情况，时间复杂度为O(1)
//如果是要找的字符在中间位置，则要找N/2次才能找到。故平均情况，F(N) = N/2,时间复杂度为O(N)
//如果是要找的字符在最后一个位置，则要找N次才能找到。故最坏情况，时间复杂度为O(N)
//由于时间复杂度取最坏的次数的复杂度，故strchr的时间复杂度为：O(N)
//注意：对于一个函数中出现了函数调用也需要算入时间复杂度：如strchr(str, ch); 则该函数调用的时间复杂度为：O(N)

//6、计算BubbleSort的时间复杂度？
/*
void BubbleSort(int* a, int n)
{
	assert(a);
	for (size_t end = n; end > 0; --end)
	{
		int exchange = 0;
		for (size_t i = 1; i < end; ++i)
		{
			if (a[i - 1] > a[i])
			{
				Swap(&a[i - 1], &a[i]);
				exchange = 1;
			}
		}
		if (exchange == 0)
			break;
	}
}
*/
//最好的结果（已经排好序了）：只走了一次循环，F(N) =n-1，故时间复杂度为： O(n)
//第一趟冒泡：N-1
//第二趟冒泡：N-2
// ...
//第 N趟冒泡：1
//最坏的结果：F(N) = (n - 1) + (n - 2) + (n - 3) + ... + 1 的等差数列的和 = (n - 1 + 1) * (n - 1) / 2，故时间复杂度为：O(n^2)

//注意：并不是所有的算法时间复杂度一层循环就是O(N)，两层循环就是O(N^2)，这是错误的。
//具体计算算法时间复杂度，要理解算法思想，求出准确次数，再估算。

//7、计算BinarySearch的时间复杂度？
/*
int BinarySearch(int* a, int n, int x)
{
	assert(a);
	int begin = 0;
	int end = n;
	while (begin < end)
	{
		int mid = begin + ((end - begin) >> 1);
		if (a[mid] < x)
			begin = mid + 1;
		else if (a[mid] > x)
			end = mid;
		else
			return mid;
	}
	return -1;
}
*/
//(二分查找：前提排序)
//最好的情况，要查找的位置就是第一次的中间位置。Fn = 1，故时间复杂度为O(1)
//最坏的情况：假设最多找了x次，找到了。
//N/2/2/2... = 1，1 * 2 * 2 * 2 * 2 … 2 * 2 = N 即 2^X = N ，x = log2 N
//2^Fn = N，Fn = log2N，故时间复杂度为O(log2N)
//注意：算法的复杂度计算中，由于不好书写底数，有些地方写成O(logN)。也有些书写成lgN，严格来说是不正确的。

//8、计算阶乘递归Factorial的时间复杂度？
/*
long long Factorial(size_t N)
{
	return N < 2 ? N : Factorial(N - 1) * N;
}
*/
//Factorial求n！
//Factorial(10)
//Factorial(9) * 10
//Factorial(8) * 9
//…
//Factorial(2) * 3
//Factorial(1) * 2
//一共递归调用了N次，每次函数基本操作次数的时间复杂度为O(1)，故时间复杂度为：O(N)
//递归算法的时间复杂度如何计算：递归次数 * 每次递归函数基本操作次数的时间复杂度。
//如果外层有个循环，Factorial函数，则时间复杂度为：O(N * N)

//9、计算斐波那契数递归Fib的时间复杂度？
/*
long long Fib_r(size_t N)
{
	return N < 2 ? N : Fib_r(N - 1) + Fib_r(N - 2);
} 
*/
/******************************************************************************************
斐波那契数：后一项是前两项之和。
Fib(0) = 0    Fib(1) = 1     Fib(n) = Fib(n - 1) + Fib(n - 2)

                           Fib(n)								调用1次 = 2^0
               Fib(n - 1)            Fib(n - 2)					调用2次 = 2^1
      Fib(n - 2)   Fib(n - 3)   Fib(n - 3)    Fib(n - 4)		调用4次 = 2^2
          …                   …                …
		没有调用
Fib(1)				没有调用			没有调用				调用2^(n - 1)次
递归算法的时间复杂度：递归次数*每次递归调用的时间复杂度
F(n) = 2^0 + 2^1 + 2^2 + … + 2^(n - 1) - X 的等比数列求和= 2^n - 1 - X，时间复杂度：O(2^n)
X表示没有调用的项数。
可以假设n为某个具体的数，再画图判断次数。
对于此算法，数据越大，效果越差（某一项的次数重复计算太多）
斐波那契数的递归实现是一个没有实际作用的函数。当测试计算Fib(50)时，特别慢。
故：未来算斐波那契数，或者青蛙跳台阶问题，不要使用该方法
*******************************************************************************************/
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
//优化计算第n项的斐波那契数。
long long* Fib(size_t N)
{
	long long* fibArray = (long long*)malloc(sizeof(long long) * (N + 1));//开辟数组空间。保存整个斐波那契数。//多开一个空间
	
	if (fibArray == NULL)//判断是否开辟成功
	{
		printf("%s\n", strerror(errno));	
	}
	else
	{
		fibArray[0] = 0;//对第一项赋值
		if (N == 0)//判断是否开辟了0个字节的空间，否则fibArray[1]会越界
			return fibArray;
		fibArray[1] = 1;//对第二项赋值
		//以空间换时间
		//由前两项计算后一项的值
		for (int i = 2; i <= N; ++i)//这里i要等于N,数组中的第N个数才能计算完，则此时访问会越界，所以必须多开一个空间的数组。
		{
			fibArray[i] = fibArray[i - 1] + fibArray[i - 2];
		}
		printf("%lld\n", fibArray[N]);	//打印第N的斐波那契数
	}
	return fibArray;
}
int main()
{
	long long* tmp = NULL;
	tmp = Fib(50);
	free(tmp);
	tmp = NULL;
	return 0;
}
*/
//故：未来算斐波那契数，或者青蛙跳台阶问题，使用该方法

//空间复杂度：算法在运行过程中临时占用的变量的个数。表示方式：大O的渐近表示法。
//注意：计算空间复杂度的方法跟时间复杂度的方法类似。(可以计算数据的类型个数)

//时间复杂度不计算时间，计算大概的运算次数（最坏时间使用情况）
//空间复杂度不计算空间，计算大概定义的变量个数(形参也包含)（最坏空间使用情况）
//对于嵌入式开发，需要考虑空间复杂度。

//1、计算BubbleSort的空间复杂度？
void BubbleSort(int* a, int n)
{
	assert(a);
	for (size_t end = n; end > 0; --end)
	{
		int exchange = 0;
		for (size_t i = 1; i < end; ++i)
		{
			if (a[i - 1] > a[i])
			{
				Swap(&a[i - 1], &a[i]);
				exchange = 1;
			}
		}
		if (exchange == 0)
			break;
	}
}
//a n end exchange i五个变量，注意：a[i - 1] a[i]不计入。即常数个，Fn = 5，故空间复杂度为：O(1)
//时间是累计的，空间是不累计的。所以在循环里面的变量，变量的空间会继续使用。
//注意：函数调用时建立栈帧，将要用到的变量的空间保存下来，从而不销毁。
//对于递归，递归往下，变量不销毁，递归返回，变量依次销毁。

//2、计算Fibonacci的空间复杂度？
long long* Fibonacci(size_t n)
{
	if (n == 0)
		return NULL;
	long long* fibArray = (long long*)malloc((n + 1) * sizeof(long long));
	fibArray[0] = 0;
	fibArray[1] = 1;
	for (int i = 2; i <= n; ++i)
	{
		fibArray[i] = fibArray[i - 1] + fibArray[i - 2];
	}
	return fibArray;
}
//n fibArray fibArray[0] fibArray[1] i 五个变量，fibArray指针指向的变量有N + 1个空间。
//注意：fibArray[i] fibArray[i - 1] fibArray[i - 2]不计入。
//1 + 1 + 1 +（N + 1） + 1 + 1个空间，即Fn = N + 6，故空间复杂度为：O(N)
//斐波那契数还可以用三个变量迭代得到，从而实现空间复杂度为O(1)
//时间复杂度为：F(N) = N-2,即O(N)
//注意：当动态开辟的N改为数字3，则整个算法的空间复杂度位：O(1)

//3、计算阶乘递归Factorial的空间复杂度？
long long Factorial(size_t N)
{
	return N < 2 ? N : Factorial(N - 1) * N;
}
//Factorial求n！
//Factorial(10)
//Factorial(9) * 10
//Factorial(8) * 9
//…
//Factorial(2) * 3
//Factorial(1) * 2
//递归调用了N层，每一次调用建立一个栈帧，共N个栈帧，每个栈帧使用了常数个空间即O(1)
//故空间复杂度为：O(N)
//计算递归调用的空间复杂度：递归的栈帧深度。由于递归函数要建立栈帧，需要消耗空间。
//而“空间是可以重复利用的，不累计”，最多建立N个栈帧，每计算完一个调用，空间就销毁了，再计算下一个调用
//空间复杂度考虑的是最多使用了多少个空间。

//思考：
//4、计算斐波那契数递归Fib的时间复杂度？
/*
long long Fib_r(size_t N)
{
	return N < 2 ? N : Fib_r(N - 1) + Fib_r(N - 2);
}
*/
//因为“空间是可以重复利用的，不累计”该函数递归最多建立N个栈帧，
//再Fib(N) Fib(N-1) Fib(N-2)调用的时候会重复利用建立的N个栈帧的空间。(一条分支先计算，计算完后，再计算一条分支)
//故，
//斐波那契数列的时间复杂度为：O(2^N)
//斐波那契数列的空间复杂度为：O(N)