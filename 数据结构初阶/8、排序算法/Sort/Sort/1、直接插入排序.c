#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//����Ϊ��������
void InsertSort(int* a,int n)
{
	//�������򣺵�һ����������Ϊ��0,0��n������Ҫ��n-1�ˣ������Ƶ�������Ĵ���
	for (int i = 0; i < n - 1; i++)//������n-1��
	{
		//��������
		//��0��end����������end+1λ�õ�ֵ�����ȥ���á�0��end+1������
		int end = i;//ע��end���ܵ���n-1������end+1��Խ��
		int tmp = a[end + 1];//����end�����������ֹ����Ų���Ѻ�һ���������ˣ��޷�֪����Ҫ�������
		//2 4 5 6 | 1 3
		//1 2 4 5 6 | 3
		while (end >= 0)//����tmp >= a[end]
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				//tmp >= a[end]���ߣ�tmp�����е�����ҪС
				//������Ҫ�������ݵ�end��һ��λ��,��a[end + 1] = tmp;
				break;//ʹ��break��������������ݣ�a[end + 1] = tmp;����ѭ�����棬���Ժϲ����������
			}
		}
		a[end + 1] = tmp;
	}
}
//ʱ�临�Ӷȣ�
//������ - ��һ���Ѿ��������������ʱ��O(N) = 1+2+3+4 ... + (n-)1 = O(N^2)
//��õ���� - ��һ���Ѿ����������˳��ʱ��O(N)
//int main()
//{
//	int a[] = { 5, 2, 4, 6, 1, 3 };
//	int n = sizeof(a) / sizeof(a[0]);
//
//	InsertSort(a, n);
//
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	return 0;
//}