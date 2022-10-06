#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "Stack.h"
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int Part1Sort(int* a, int left, int right)
{
	int index = GetMidInex(a, left, right); //���ߵ��м���
	Swap(&a[left], &a[index]);//��index��Ϊkey

	//ֻ��������ڲŽ��п���
	int begin = left, end = right;
	int pivot = begin;//�����һ���±�����ֵΪkey�����һ�οӵ�λ��Ϊ��һ���±��λ��
	int key = a[begin];

	while (begin < end)
	{
		//�ұ���С�ģ��ŵ����
		while (begin < end && a[end] >= key)//����a[end] >= key�Ƚϣ���ǰ�ᣬ����ύ��end��begin
		{
			end--;
		}
		//��С�ķŵ���ߵĿ���Լ��γ��µĿ�λ
		a[pivot] = a[end];
		pivot = end;

		//����Ҵ�ģ��ŵ��ұ�
		while (begin < end && a[begin] <= key)
		{
			begin++;
		}
		//����ķŵ��ұߵĿ���Լ��γ��µĿ�λ
		a[pivot] = a[begin];
		pivot = begin;
	}

	//���������һ���ӵ�λ��
	pivot = begin;
	a[pivot] = key;

	return pivot;//����һ�������м�λ��
}
//�ݹ��ȱ�ݣ�ջ֡���̫�ջ�ռ䲻���ã����ܻ����
//�ǵݹ飺
//1���ݹ�ķǵݹ飺1��ֱ�Ӹĳ�ѭ�����򵥵ݹ飩2���������ݽṹ��ջģ��ʵ�ֵݹ���̣����ӵݹ飩
void QuickSortNonR(int* a, int n)
{
	ST st;//����ȳ� - ʹ������ȳ���,�ұ�����ջ
	StackInit(&st);
	StackPush(&st, n - 1);//������, ���±���ջ�����ͨ�������±굽�ڿӷ��ĺ����У����е�������
	StackPush(&st, 0);//������

	while (!StackEmpty(&st))
	{
		int left = StackTop(&st);//����
		StackPop(&st);

		int right = StackTop(&st);//����
		StackPop(&st);

		int keyIndex = Part1Sort(a, left, right);
		//��left��right�� => ��left��keyIndex-1��keyIndex��keyIndex+1��right��
		
		//��������������ָ�������⣬�����ң��������ٳ�ջ���ٵ�������
		if (keyIndex + 1 < right)
		{
			StackPush(&st, right); //������
			StackPush(&st, keyIndex + 1);//������
		}

		if (left < keyIndex - 1)
		{
			StackPush(&st, keyIndex - 1);//������
			StackPush(&st, left);//������
		}
	}
	StackDestroy(&st);
}
//�ݹ�ʵ�֣�1+2+3+...+n
int f(int n)//������f(10000)ʱ������stack flowջ���
{
	return n <= 1 ? 1 : f(n - 1) + n;
}//�ݹ����̫�������û�д�ġ�����ջ�Ŀռ䲻����

//�ݹ�ͷǵݹ�Ŀ�������Ч�ʲ��
//int main()
//{
//	int a[] = { 6, 2, 4, 5, 1, 3, -1 };
//	int n = sizeof(a) / sizeof(int);
//	QuickSortNonR(a, sizeof(a) / sizeof(int));
//
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	return 0;
//}