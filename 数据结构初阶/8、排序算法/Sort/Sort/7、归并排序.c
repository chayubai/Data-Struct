#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//˼���Ϻ�������������
void _MergeSort(int* a, int left, int right, int* tmp)
{
	//���ֻ��һ��ֵ�����߽���
	if (left >= right)
	{
		return;
	}
	int mid = (left + right) >> 1;
	//���衾left,mid����mid,right��,�ݹ���������ʹ����������ô�Ϳ��Թ鲢
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid+1, right, tmp);

	//�鲢 - ȡ����������뵽������
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int index = left;//���ܸ�ֵ0
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[index++] = a[begin1++];
		}
		else
		{
			tmp[index++] = a[begin2++];
		}
	}
	//���ǰ��������ʣ��
	while (begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}
	//������������ʣ��
	while (begin2 <= end2)
	{
		tmp[index++] = a[begin2++];
	}

	//���������е���������ԭ������
	for (int i = left; i <= right; i++)
	{
		a[i] = tmp[i];
	}
}
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
}
//int main()
//{
//	int a[] = { 6, 2, 4, 5, 1, 3, -1 };
//	int n = sizeof(a) / sizeof(int);
//	MergeSort(a, 0,sizeof(a)/sizeof(int)-1);
//
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	return 0;
//}