#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//��һ���ƣ������������� - - ��������
//һ����ȫ������������������  - - ѡ������
//˼·������
//����a[0]�����ģ��������n-1�����Ƚϣ�����и���������������������a[0]λ��
//����a[1]�����ģ��������n-2�����Ƚϣ�����и���������������������a[1]λ��
//...
//���ظ�ʹ�á���һ�����������������һ����

//����𰸣�
//void SelectSort(int* a, int n)
//{
//    for (int j = 0; j < n-1; j++)
//    {
//        int max = a[j];
//        for (int i =j + 1; i < n; i++)
//        {
//            if (max < a[i])
//                swap(&max, &a[i]);//���ｻ���޷�ʵ��
//        }
//        a[j] = max;
//    }
//}

//��ȷ�𰸣�
//˼·������
//�����±�Ϊ0��������С�ģ��������n-1�����Ƚϣ�����и�С���򣬼�¼�����±꣬������С�������±꣬�ٰ�������a[0]λ��
//�����±�Ϊ1��������С�ģ��������n-2�����Ƚϣ�����и�С���򣬼�¼�����±꣬������С�������±꣬�ٰ�������a[1]λ��
//...
//���ظ�ʹ�á���һ�����������������һ����
//void swap(int* a, int* b) 
//{
//    int temp = *a;
//    *a = *b;
//    *b = temp;
//}
void selection_sort(int arr[], int len)
{
    int i, j;
    for (i = 0; i < len - 1; i++)//��Ҫȷ�����ٸ�������
    {
        int min = i;
        for (j = i + 1; j < len; j++) //���������±�iΪ�������ͺ�i+1��n-1-i����������Ƚ�
        {
            if (arr[j] < arr[min])    //�ҵ�Ŀǰ���ֵ
                min = j;                //��¼����������±�
            swap(&arr[min], &arr[i]);    //�����Q
        }
    }
}

//һ��ѡ��������������С���±�������ֱ��������
//void SelectSort(int* a, int n)
//{
//    int begin = 0, end = n - 1;
//    while (begin < end)
//    {
//        int max = begin, min = begin;
//        for (int i = begin; i <= end; i++)
//        {
//            if (a[i] < a[min])
//            {
//                min = i;
//            }
//            if (a[i] > a[max])
//            {
//                max = i;
//            }
//        }
//        swap(&a[begin], &a[min]);//����6, 2, 4, 5, 1, 3, -1������ͻ������
//        //����ԭ��������һ������һ������ִ�У���maxλ�õ��±�����ֻ��ص�endλ��
//        swap(&a[max], &a[end]);
//        begin++;
//        end--;
//    } 
//}

//��û���Ľ����ʱ�临�Ӷȶ��ǣ�O(N) = N * N
//��һ�Σ�N��
//�ڶ��Σ�N-2��
//�����Σ�N-4��
//...

void SelectSort(int* a, int n)
{
    int begin = 0, end = n - 1;
    while (begin < end)
    {
        int max = begin, min = begin;
        for (int i = begin; i <= end; i++)
        {
            if (a[i] < a[min])
            {
                min = i;
            }
            if (a[i] > a[max])
            {
                max = i;
            }
        }//6, 2, 4, 5, 1, 3, -1
        swap(&a[begin], &a[min]);
        //���begin��max�ص�
        if (begin == max)
            max = min;//���ڽ�����һ�£�max�������±�Ϊmin���±�
        swap(&a[max], &a[end]);
        begin++;
        end--;
    }
}

//int main()
//{
//	int a[] = { 6, 2, 4, 5, 1, 3, -1};
//
//	int n = sizeof(a) / sizeof(a[0]);
//    //selection_sort(a, n);
//    SelectSort(a, n);
//
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	return 0;
//}