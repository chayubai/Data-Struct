//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <stdlib.h>
////����쳲��������ݹ�Fib��ʱ�临�Ӷȣ�
//long long Fib_r(size_t N)
//{
//	return N < 2 ? N : Fib_r(N - 1) + Fib_r(N - 2);
//} 
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <errno.h>
////�Ż������n���쳲���������
//long long* Fib(size_t N)
//{
//	long long* fibArray = (long long*)malloc(sizeof(long long) * (N + 1));//��������ռ䡣��������쳲���������//�࿪һ���ռ�
//	
//	if (fibArray == NULL)//�ж��Ƿ񿪱ٳɹ�
//	{
//		printf("%s\n", strerror(errno));	
//	}
//	else
//	{
//		fibArray[0] = 0;//�Ե�һ�ֵ
//		if (N == 0)//�ж��Ƿ񿪱���0���ֽڵĿռ䣬����fibArray[1]��Խ��
//			return fibArray;
//		fibArray[1] = 1;//�Եڶ��ֵ
//		//�Կռ任ʱ��
//		//��ǰ��������һ���ֵ
//		for (int i = 2; i <= N; ++i)//����iҪ����N,�����еĵ�N�������ܼ����꣬���ʱ���ʻ�Խ�磬���Ա���࿪һ���ռ�����顣
//		{
//			fibArray[i] = fibArray[i - 1] + fibArray[i - 2];
//		}
//		printf("%lld\n", fibArray[N]);	//��ӡ��N��쳲�������
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