#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//void Swap(int* c, int* p)
//{
//	int tmp = *c;
//	*c = *p;
//	*p = tmp;
//}
//���µ����㷨�����������������Ǵ�ѻ�С�� - �˴���С��
//�µ����㷨�������߶ȴΡ���ʱ�临�Ӷ�O(N) = logN����2 h -1 �C x = N �ã��߶�h = log(N+1+x)
//void AdjustDown(int* a, int n, int root)
//{
//	int parent = root;
//	int child = parent * 2 + 1;//Ĭ������
//	//�±겻�ܳ���n
//	while (child < n)//n������Ԫ�ظ�����Ҳ����������±����һ��ֵ����child <= n-1
//	{
//		//1��ѡ�����Һ�����С���Ǹ�
//		if ((child+1 < n) && (a[child + 1] < a[child]))//���Ӵ�ʱ��
//		{//ͬʱ��������£�����û���Һ��ӣ�����Һ����±�����child + 1 < n,��child + 1����������±귶Χ��
//
//			//����ȡС��ֵ�븸�ڵ�Ƚϣ�����Ҫ����Ϊ�Һ��ӵ��±�
//			child += 1;//���Һ����±����1
//		}
//		//2��ȡС��ֵ�����С�ڸ��ڵ㣬��С�Ľڵ��ֵ�����ڵ㣬������
//		if (a[child] < a[parent])
//		{
//			Swap(&a[child], &a[parent]);
//			//�����µĸ��ڵ��Ĭ�����ӽڵ�
//			parent = child;
//			child = parent * 2 + 1;
//		}
//		else
//		{
//			//����ǰ������������������ΪС�ѣ��������������жϺ��涼����С��
//			break;
//		}
//	}
//}

//void AdjustDown(int* a, int n, int root)
//{
//	int parent = root;
//	int child = parent * 2 + 1;//Ĭ������
//	//�±겻�ܳ���n
//	while (child < n)//n������Ԫ�ظ�����Ҳ����������±����һ��ֵ����child <= n-1
//	{
//		//1��ѡ�����Һ����д���Ǹ�
//		if ((child+1 < n) && (a[child + 1] > a[child]))//�Һ��Ӵ�ʱ��
//		{//ͬʱ��������£�����û���Һ��ӣ�����Һ����±�����child + 1 < n,��child + 1����������±귶Χ��
//
//			//����ȡ���ֵ�븸�ڵ�Ƚϣ�����Ҫ����Ϊ�Һ��ӵ��±�
//			child += 1;//���Һ����±����1
//		}
//		//2��ȡ���ֵ��������ڸ��ڵ㣬���Ľڵ��ֵ�����ڵ㣬������
//		if (a[child] > a[parent])
//		{
//			Swap(&a[child], &a[parent]);
//			//�����µĸ��ڵ���Һ��ӽڵ�
//			parent = child;
//			child = parent * 2 + 1;
//		}
//		else
//		{
//			break;
//		}
//	}
//}

//������ʱ�临�Ӷȣ�O(N*logN)
//void HeapSort(int* a, int n)
//{
//	//1������ - ����ȫ����������˳��ʹ�����µ����㷨����
//	//�����
//	//����ʱ�临�Ӷȣ�O(N)
//	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
//	{//��֪���ӽڵ㣬�ɵø��ڵ�
//		AdjustDown(a, n, i);
//	}
//
//	//2�������� - �����Ϊ����
//	int end = n - 1;
//	while (end > 0)
//	{
//		Swap(&a[0], &a[end]);
//		AdjustDown(a, end, 0);
//		--end;
//	}
//}

//int main()
//{
//	int a[] = { 5, 2, 4, 6, 1, 3 };
//
//	int n = sizeof(a) / sizeof(a[0]);
//
//	HeapSort(a, n);
//
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	return 0;
//}