#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include "Stack.h"

//�ݹ�ʵ�֣�1 + 2 + 3 + ... + n
//1 2 3 4 ... n
//f(n) = 1 + 2 + 3 + ... n-1 + n
//f(n) = [1 + 2 + 3 + ... n-1] + n = f(n-1)+n
//...
//f(3) = [1 + 2]+3 = f(2)+3
//f(2) = [1]+2 = f(1)+2
int f(int n)
{
	return n <= 1 ? 1 : f(n - 1) + n;
}
//������f(10000)ʱ������stack overflowջ���
//�ݹ����̫�������û�д�ġ�����ջ�Ŀռ䲻����

//�ݹ��ȱ�ݣ�ջ֡���̫�ջ�ռ䲻���ã����ܻ����.

//�ǵݹ飺
//1���ݹ�ķǵݹ飺1��ֱ�Ӹĳ�ѭ�����򵥵ݹ飩2���������ݽṹ��ջģ��ʵ�ֵݹ���̣����ӵݹ飩

int PartSort(int* a, int left, int right);
//����ջģ��ݹ����
void QuickSortNonR(int* a, int n)
{
	ST st;//����ȳ� - ʹ������ȳ���,�ұ�����ջ
	StackInit(&st);
	StackPush(&st, n - 1);//�����±���ջ�����ͨ�������±굽�ڿӷ��ĺ����У����е���������ΪҪ�ȳ���
	StackPush(&st, 0);//�����±���ջ��

	while (!StackEmpty(&st))
	{
		int left = StackTop(&st);//ȡջ���е�Ԫ��(���±�)
		StackPop(&st);

		int right = StackTop(&st);//ȡջ���е�Ԫ��(���±�)
		StackPop(&st);

		int keyIndex = PartSort(a, left, right);//�����µ�key�±�
		//��left��right�� => ��left��keyIndex-1��keyIndex��keyIndex+1��right��
		
		//���µ�key�ֽ磬��������������ָ�������⣬�����ң��������ٳ�ջ���ٵ�������
		if (keyIndex + 1 < right)//�Ұ�������ڣ��������ջ
		{
			StackPush(&st, right); //������
			StackPush(&st, keyIndex + 1);//������
		}

		if (left < keyIndex - 1)//���������ڣ��������ջ
		{
			StackPush(&st, keyIndex - 1);//������
			StackPush(&st, left);//������
		}
	}
	StackDestroy(&st);
}
void swap06(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
//��������
int PartSort(int* a, int left, int right)
{
	//ע�ͣ���������ߵ���keyֵ���������
	//int index = GetMidInex(a, left, right); //���ߵ��м���
	//swap06(&a[left], &a[index]);//��index��Ϊkey����left����

	//ֻ��������ڲŽ��п���
	int begin = left, end = right;
	int pivot = begin;//�����һ���±�����ֵΪkey�����һ�οӵ�λ��Ϊ��һ���±��λ��
	int key = a[begin];

	while (begin < end)//begin == end��������
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
	pivot = begin;//���¿ӵ�λ�ã�ͬʱ��¼�м���λ��
	a[pivot] = key;

	return pivot;//����һ��������߶���keyС���ұ߶���key���м��Ǹ������±�
}
//�ݹ�ͷǵݹ�Ŀ�������Ч�ʲ�ࡣ
//ע�⣺����������ǣ��������������С�ģ��ұ��Ҵ�� ������С�

//��ע��߽�ֵ�Ŀ��ơ������������˼�룺������ǰ����������������߼����໭ͼ��

//ע�⣺Ҳ����ʹ�ö���ģ��ݹ���̡�
//ջģ��ݹ���̣�������䴦����󣬲Ŵ����Ұ����䡣����ݹ���̡�
//����ģ��ݹ���̣�һ��һ��Ĵ�������ݹ���̡�

//ע�⣺��Щ���У��ῼ�죬��������ķǵݹ���̣���һ�������Ľ�����ڶ��������Ľ�����ڶ��������Ľ�������Ƕ���ģ��ʵ�ֵݹ�ĵڶ��˽����
//Ҳ�ῼ���������ͬ˼·(�ڿӷ�������ָ�뷨��ǰ��ָ�뷨���ǵݹ�)��һ�������Ľ����
//����49 38 65 97 76 13 27 49����
//�ǵݹ���ŵ�һ�������ǣ�27 38 13 49 76 97 65 49
//�ǵݹ���ŵڶ��������ǣ�13 27 38 49 49 65 76 97

//ע�⣺����ϵͳ��ջ�Ͷѿռ䣬�����ݽṹ�е�ջ�Ͷ��ǲ�ͬ�ġ�

#if 0
int main()
{
	int a[] = { 6, 2, 4, 5, 1, 3, -1 };
	int n = sizeof(a) / sizeof(int);
	QuickSortNonR(a, sizeof(a) / sizeof(int));

	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}
#endif