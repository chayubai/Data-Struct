#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

void CountSort(int* a, int n)
{
	//1���������������С����
	int max = a[0], min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
		if (a[i] < min)
		{
			min = a[i];
		}
	}

	//����ӳ��ռ�Ľ��ƴ�С
	int range = max - min + 1;

	//��������ռ�
	int* count = (int*)malloc(sizeof(int) * range);//��Ҫ��鿪�ٿռ��Ƿ�ɹ�
	memset(count, 0, sizeof(int) * range);//��ʼ��Ϊ0
	
	//2��ͳ�������ֵĴ���
	for (int i = 0; i < n; i++)
	{
		count[a[i]-min]++;//��a[i]-min���λ��++
	}

	//3����count�����е��������뵽ԭ������
	int j = 0;
	for (int i = 0; i < range; i++)
	{
		while (count[i]--)
		{
			a[j] = i + min;//�±�+min = �����ֵ��a[j++] = i + min;
			j++;
		}
	}
	free(count);
}
//ʱ�临�Ӷ�:O(N) = n + n range
//����O(N) = n + range
//˵���������ڷ�Χ���е�һ��������������ʹ�÷�Χ���о����ԡ�
//�ռ临�Ӷȣ�O(N) = range
int main()
{
	int a[] = { 6, 2, 4, 5, 1, 3, -1 };
	int n = sizeof(a) / sizeof(int);
	CountSort(a, sizeof(a) / sizeof(int));

	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}