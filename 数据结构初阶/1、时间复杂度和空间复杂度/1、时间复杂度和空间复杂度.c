//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <stdlib.h>
////计算斐波那契数递归Fib的时间复杂度？
//long long Fib_r(size_t N)
//{
//	return N < 2 ? N : Fib_r(N - 1) + Fib_r(N - 2);
//} 
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <errno.h>
////优化计算第n项的斐波那契数。
//long long* Fib(size_t N)
//{
//	long long* fibArray = (long long*)malloc(sizeof(long long) * (N + 1));//开闭数组空间。保存整个斐波那契数。//多开一个空间
//	
//	if (fibArray == NULL)//判断是否开辟成功
//	{
//		printf("%s\n", strerror(errno));	
//	}
//	else
//	{
//		fibArray[0] = 0;//对第一项赋值
//		if (N == 0)//判断是否开辟了0个字节的空间，否则fibArray[1]会越界
//			return fibArray;
//		fibArray[1] = 1;//对第二项赋值
//		//以空间换时间
//		//由前两项计算后一项的值
//		for (int i = 2; i <= N; ++i)//这里i要等于N,数组中的第N个数才能计算完，则此时访问会越界，所以必须多开一个空间的数组。
//		{
//			fibArray[i] = fibArray[i - 1] + fibArray[i - 2];
//		}
//		printf("%lld\n", fibArray[N]);	//打印第N的斐波那契数
//	}
//	return fibArray;
//}
//int main()
//{
//	long long* tmp = NULL;
//	tmp = Fib(50);
//	free(tmp);
//	tmp = NULL;
//	return 0;
//}