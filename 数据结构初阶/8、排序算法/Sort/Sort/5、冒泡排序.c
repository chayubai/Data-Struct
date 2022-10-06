#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

//ʱ�临�Ӷȣ�O(N) = N*N
//��һ�αȽ�N��
//��һ�αȽ�N-1��
//��һ�αȽ�N-2��
//...
//��õ������������O(N) = N

//void BubbleSort(int* a, int n)
//{
//	for (int i = 0; i < n - 1; i++)//����
//	{
//		int exchange = 0;//�ж��Ƿ��Ѿ�����
//		for (int j = i; j < n - i - 1; j++)//ÿһ�ˣ�ȷ�������ֵ
//		{
//			if (a[j] > a[j+1])//����ʹ�����ַ�ʽ�Ƚ�if (a[j] > a[j+1])������û�п����б߽絼��Խ��
//			{
//				swap(&a[j], &a[j+1]);
//				exchange = 1;
//			}
//		}
//		if(exchange == 0)
//			break;
//	}
//}

void BubbleSort(int* a, int n)
{
	int end = n;
	while(end > 0)
	{
		int exchange = 0;
		for (int j = 1; j < end; j++)//ÿһ�ˣ�ȷ�������ֵ
		{
			if (a[j - 1] > a[j])//if (a[j] > a[j+1])���������Խ��
			{
				swap(&a[j - 1], &a[j]);
				exchange = 1;
			}
		}
		if (exchange == 0)
			break;
		end--;
	}
}

//��ֱ�Ӳ���������ȣ���ֱ��ѡ������ã���ֱ�Ӳ��������
//int main()
//{
//	int a[] = { 6, 2, 4, 5, 1, 3, -1 };
//
//	int n = sizeof(a) / sizeof(a[0]);
//
//	BubbleSort(a, n);
//
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	return 0;
//}