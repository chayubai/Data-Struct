#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//void MergeSortNonR(int* a, int n)//����Ԫ��������ʱ�����һ��Ԫ������������һ�鲢Խ��
//{
//	int* tmp = (int*)malloc(sizeof(int) * n);
//
//	int gap = 1;//ÿ�����ݵĸ���
//	
//	while (gap < n)
//	{
//		for (int i = 0; i < n; i += 2 * gap)//gap=Nʱ��i���ƹ鲢�Ĵ���
//		{
//			//��i��i+gap-1����i+gap��i+2*gap-1���������Ұ�������ܲ�����
//			//�鲢 - ȡ����������뵽������
//			int begin1 = i, end1 = i + gap - 1;
//			int begin2 = i + gap, end2 = i + 2 * gap - 1;
//			int index = i;//���ܸ�ֵ0
//			while (begin1 <= end1 && begin2 <= end2)
//			{
//				if (a[begin1] < a[begin2])
//				{
//					tmp[index++] = a[begin1++];
//				}
//				else
//				{
//					tmp[index++] = a[begin2++];
//				}
//			}
//			//���ǰ��������ʣ��
//			while (begin1 <= end1)
//			{
//				tmp[index++] = a[begin1++];
//			}
//			//������������ʣ��
//			while (begin2 <= end2)
//			{
//				tmp[index++] = a[begin2++];
//			}
//		}
//		//(һ����)���������е���������ԭ������
//		for (int j = 0; j <= n; j++)
//		{
//			a[j] = tmp[j];
//		}
//		gap *= 2;//����ÿ�����ݵĸ���
//	}
//
//	free(tmp);
//}

void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);

	int gap = 1;//ÿ�����ݵĸ���

	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			//��i��i+gap-1����i+gap��i+2*gap-1��
			//�鲢 - ȡ����������뵽������
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;

			//�鲢�������Ұ�������ܲ�����,����Ҫ�����磺6, 2 | 4, 5 | 1, 3 | -1
			if (begin2 >= n)
			{
				break;
			}
			//�鲢�������Ұ���������ˣ��磺2, 6 , 4, 5 | 1, 3 ,-1 
			if (end2 >= n)
			{
				end2 = n - 1;//�������䵽��Ч������
			}
			//ע�⣺Ҳ����������������⣬��10, 6, 7, 1 | 3, 9, 4, 2 | 2, 3 ,4

			int index = i;//���ܸ�ֵ0
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
			//�鲢һ���֣�����һ����
			//��������,���޸Ľ������������������е���������ԭ�����У�����´�����ֵ
			//����û���޸ģ�6, 2 | 4, 5 | 1, 3 | -1
			//ԭ���飺 6, 2, 4, 5, 1, 3, -1
			//����� 6, 2, 4, 5, 1, 3  (���һ����������)
			//����������������ȥ��6, 2, 4, 5, 1, 3, ���ֵ(��������Ϊn�������ֵ)
			for (int j = i; j <= end2; j++)//j <= i + 2 * gap - 1��������������Ϊǰ���end���������ˣ���ʹ������������ͻ�Խ�����
			{
				a[j] = tmp[j];
			}
		}
		gap *= 2;
	}
	free(tmp);
}
//ʱ�临�Ӷȶ���O(N*logN)
//int main()
//{
//	int a[] = { 6, 2, 4, 5, 1, 3, -1 };
//	int n = sizeof(a) / sizeof(int);
//	MergeSortNonR(a, sizeof(a) / sizeof(int));
//
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	return 0;
//}