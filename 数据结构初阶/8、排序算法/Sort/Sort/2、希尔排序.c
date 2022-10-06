#define _CRT_SECURE_NO_WARNINGS 1
//ϣ��������С������������ֱ�Ӳ�������Ļ����ϵ��Ż�
//1���Ƚ���Ԥ����������ӽ�����
//2������ֱ�Ӳ�������

#include <stdio.h>
//Ԥ���򣺼����������gapΪ������з��飬�Զ�������������ʹ�ýӽ�����
//9 8 7 6 5 4 3 2 1
//����gap == 3 
//��
//9 # # 6 # # 3 # # 0 �����0 # # 3 # # 6 # # 9
//8 # # 5 # # 2 �����2 # # 5 # # 8
//7 # # 4 # # 1 �����1 # # 4 # # 7
//����
//i = 0  6��9�Ի�   6 # # 9   6 8 7 9 5 4 3 2 1 0
//i = 1  5��8�Ի�   5 # # 8   6 5 7 9 8 4 3 2 1 0
//i = 2  4��7�Ի�   4 # # 7   6 5 4 9 8 7 3 2 1 0
//i = 3  ֱ�Ӳ�������6 9 3    3 5 4 6 8 7 9 2 1 0
//...
//i = 6 = n - gap - 1  0 2 1 3 5 4 6 8 7 9 
//0 2 1 3 5 4 6 8 7 9 ֱ�Ӳ�������1 2 3 4 5 6 7 8 9
//void ShellSort(int* a, int n)
//{
//	int gap = 3;//gap = 1��ֱ�Ӳ������򣬵�����gap����̶�д����
//	//�Ѽ��Ϊgap�Ķ�������ͬʱ��
//	for (int i = 0; i < n - gap; i++)
//	{
//		int end = i;
//		int tmp = a[end + gap];
//		while (end >= 0)
//		{
//			if (tmp < a[end])
//			{
//				a[end + gap] = a[end];
//				end -= gap;
//			}
//			else
//			{
//				break;
//			}
//		}
//		a[end + gap] = tmp;
//	}
//}

void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 2;//����gap = gap / 3 +1 ��֤���һ��gap = 1
		//�Ѽ��Ϊgap�Ķ�������ͬʱ��
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}
//ʱ�临�Ӷȣ�
//n/3/3/3 .../3 = 1 =>n = log3 n
//��gap�ܴ�ʱ������Ԥ����ʱ�临�Ӷ�O(N)
//��gap��Сʱ�������Ѿ��ܽӽ������ˣ���ʱԤ������Ҳ��O(N)
//��ʱ�临�Ӷ�Ϊ��O(log3 n * N)

//int main()
//{
//	int a[] = { 5, 2, 4, 6, 1, 3 };
//	int n = sizeof(a) / sizeof(a[0]);
//
//	ShellSort(a, n);
//
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	return 0;
//}