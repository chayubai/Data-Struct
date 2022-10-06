#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//B               E
//6 3 5 2 7 8 9 4 1  6
//B               E
//  3 5 2 7 8 9 4 1  6
//B               E
//1 3 5 2 7 8 9 4    6
//        B       E
//1 3 5 2 7 8 9 4    6
//        B      E
//1 3 5 2  8 9 4 7   6
//        B    E
//1 3 5 2 4 8 9  7   6
//          B  E
//1 3 5 2 4 8 9  7   6
//          B  E
//1 3 5 2 4  9 8 7   6
//          E
//          B  
//1 3 5 2 4  9 8 7   6
//          E
//          B  
//1 3 5 2 4 6 9 8 7   

//void QuickSort(int* a, int n)
//{
//	int begin = 0, end = n - 1;
//	int pivot = begin;//�����һ���±�����ֵΪkey�����һ�οӵ�λ��Ϊ��һ���±��λ��
//	int key = a[begin];
//
//	while (begin < end)
//	{
//		//�ұ���С�ģ��ŵ����
//		while (a[end] >= key)
//		{
//			end--;
//		}
//		//��С�ķŵ���ߵĿ���Լ��γ��µĿ�λ
//		a[pivot] = a[end];
//		pivot = end;
//
//		//����Ҵ�ģ��ŵ��ұ�
//		while (a[begin] <= key)
//		{
//			begin++;
//		}
//		//����ķŵ��ұߵĿ���Լ��γ��µĿ�λ
//		a[pivot] = a[begin];
//		pivot = begin;
//	}
//
//	//���������һ���ӵ�λ��
//	pivot = begin;
//	a[pivot] = key;
//}
//ע�����ϴ���ĵ��Թ���

//void QuickSort(int* a, int n)
//{
//	int begin = 0, end = n - 1;
//	int pivot = begin;//�����һ���±�����ֵΪkey�����һ�οӵ�λ��Ϊ��һ���±��λ��
//	int key = a[begin];
//
//	while (begin < end)
//	{
//		//�ұ���С�ģ��ŵ����
//		while (begin < end && a[end] >= key)//����a[end] >= key�Ƚϣ���ǰ�ᣬ����ύ��end��begin
//		{
//			end--;
//		}
//		//��С�ķŵ���ߵĿ���Լ��γ��µĿ�λ
//		a[pivot] = a[end];
//		pivot = end;
//
//		//����Ҵ�ģ��ŵ��ұ�
//		while (begin < end && a[begin] <= key)
//		{
//			begin++;
//		}
//		//����ķŵ��ұߵĿ���Լ��γ��µĿ�λ
//		a[pivot] = a[begin];
//		pivot = begin;
//	}
//
//	//���������һ���ӵ�λ��
//	pivot = begin;
//	a[pivot] = key;
//}

int GetMidInex(int* a, int left, int right);
void Swap(int* a, int* b);

//�ڿӷ�
//�������� - ȷ�����С�ұߴ� - ÿ��ֻ��һ����
//int Part1Sort(int* a, int left, int right)
//{
//	int index = GetMidInex(a, left, right); //���ߵ��м���
//	Swap(&a[left], &a[index]);//��inexr��Ϊkey
//
//	//ֻ��������ڲŽ��п���
//	int begin = left, end = right;
//	int pivot = begin;//�����һ���±�����ֵΪkey�����һ�οӵ�λ��Ϊ��һ���±��λ��
//	int key = a[begin];
//
//	while (begin < end)
//	{
//		//�ұ���С�ģ��ŵ����
//		while (begin < end && a[end] >= key)//����a[end] >= key�Ƚϣ���ǰ�ᣬ����ύ��end��begin
//		{
//			end--;
//		}
//		//��С�ķŵ���ߵĿ���Լ��γ��µĿ�λ
//		a[pivot] = a[end];
//		pivot = end;
//
//		//����Ҵ�ģ��ŵ��ұ�
//		while (begin < end && a[begin] <= key)
//		{
//			begin++;
//		}
//		//����ķŵ��ұߵĿ���Լ��γ��µĿ�λ
//		a[pivot] = a[begin];
//		pivot = begin;
//	}
//
//	//���������һ���ӵ�λ��
//	pivot = begin;
//	a[pivot] = key;
//
//	return pivot;//����һ�������м�λ��
//}

//ǰ��ָ�뷨
//�������� - ȷ�����С�ұߴ� - ÿ��ֻ��һ����
int Part2Sort(int* a, int left, int right)
{
	int index = GetMidInex(a, left, right); //���ߵ��м���
	Swap(&a[left], &a[index]);//��inexr��Ϊkey

	//ֻ��������ڲŽ��п���
	int begin = left, end = right;
	int keyi = begin;

	while (begin < end)
	{
		//�ұ���С��
		while (begin < end && a[end] >= a[keyi])//������Ҫbegin < end�������Խ��
		{//a[end] > a[keyi]�����ܻ���ѭ������5 1 2 4 3 5 8 7 3 
			end--;
		}

		//����Ҵ��
		while (begin < end && a[begin] <= a[keyi])//������Ҫbegin < end�������Խ��
		{//a[end] < a[keyi]�����ܻ���ѭ������5 1 2 4 3 5 8 7 3 
			begin++;
		}

		//����
		Swap(&a[begin], &a[end]);
	}

	//��������keyi����
	Swap(&a[begin], &a[keyi]);

	return begin;//����һ�������м�λ��
}

//ǰ��ָ�뷨
//�������� - ȷ�����С�ұߴ� - ÿ��ֻ��һ����
int Part3Sort(int* a, int left, int right)
{
	int index = GetMidInex(a, left, right); //���ߵ��м���
	Swap(&a[left], &a[index]);//��inexr��Ϊkey

	//ֻ��������ڲŽ��п���
	int keyi = left;
	int prev = left, cur = left + 1;

	while (cur <= right)
	{
		//cur��С��
		/*if (a[cur] < a[keyi])
		{
			prev++;
			Swap(&a[prev], &a[cur]);
		}*/
		if (a[cur] < a[keyi] && prev++ != cur)//���prev++ == cur�Ϳ��Բ�����
		{
			prev++;
			Swap(&a[prev], &a[cur]);
		}
		cur++;
	}

	//��keyi����
	Swap(&a[keyi], &a[prev]);

	return prev;//����һ�������м�λ��
}

//void QuickSort(int* a, int left,int right)//left��0�±꣬right��n-1�±�
//{
//	//�����䲻����ʱ
//	if (left >= right)
//		return;
//
//	//int index = GetMidInex(a, left, right); //���ߵ��м���
//	//Swap(&a[left], &a[index]);//��inexr��Ϊkey
//
//	////ֻ��������ڲŽ��п���
//	//int begin = left, end = right;
//	//int pivot = begin;//�����һ���±�����ֵΪkey�����һ�οӵ�λ��Ϊ��һ���±��λ��
//	//int key = a[begin];
//
//	//while (begin < end)
//	//{
//	//	//�ұ���С�ģ��ŵ����
//	//	while (begin < end && a[end] >= key)//����a[end] >= key�Ƚϣ���ǰ�ᣬ����ύ��end��begin
//	//	{
//	//		end--;
//	//	}
//	//	//��С�ķŵ���ߵĿ���Լ��γ��µĿ�λ
//	//	a[pivot] = a[end];
//	//	pivot = end;
//
//	//	//����Ҵ�ģ��ŵ��ұ�
//	//	while (begin < end && a[begin] <= key)
//	//	{
//	//		begin++;
//	//	}
//	//	//����ķŵ��ұߵĿ���Լ��γ��µĿ�λ
//	//	a[pivot] = a[begin];
//	//	pivot = begin;
//	//}
//
//	////���������һ���ӵ�λ��
//	//pivot = begin;
//	//a[pivot] = key;
//
//	int keyIndex = Part1Sort(a, left, right);
//	//int keyIndex = Part2Sort(a, left, right);
//	//int keyIndex = Part3Sort(a, left, right);
//
//	//��left��right�� => ��left��keyIndex-1��keyIndex��keyIndex+1��right��,ǰ���������������
//	//������������������������������� ����������������� -- ���εݹ�
//	//û��С�����Ż�
//	QuickSort(a, left, keyIndex - 1);
//	QuickSort(a, keyIndex + 1, right);
//	
//	//���ݹ���ô��������Ż�����С�����Ż�����ֹ�ݹ���ô���̫��
//	/*if (keyIndex - 1 - left > 10)//�ٷ���13
//	{
//		QuickSort(a, left, keyIndex - 1);
//	}
//	else
//	{
//		InsertSort(a + left, keyIndex - 1 - left + 1);
//	}
//	if (right - (keyIndex + 1) > 10)
//	{
//		QuickSort(a, keyIndex + 1, right);
//	}
//	else
//	{
//		InsertSort(a + keyIndex + 1, right - (keyIndex + 1) + 1);
//	}*/
//}
//ʱ�临�Ӷȣ�
//���������ʱ�临�Ӷȣ��������м��ߣ��ϼƹ�N�Σ���O(N) = N
//��������£�ÿ�����������С��ȣ���������������ʱ�临�Ӷȣ�O(N * log2 N)
//������������ʱ����ÿ��ֻ�ų�һ������(�Ȳ�����)��ʱ�临�Ӷȣ�O(N * N)
//���������key��ѡȡ������ȡ�У���ѡȡ��ˣ��м䣬�Ҷˣ��Ȳ������Ҳ������С��ֵ

int GetMidInex(int* a, int left, int right)
{
	int mid = (left + right) / 2;//int mid = (left + right) >> 1;
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if (a[left] > a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else //a[left] > a[mid]
	{
		if (a[mid] > a[right])
		{
			return mid;
		}
		else if (a[left] < a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
}
//void Swap(int* a, int* b)
//{
//	int tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//int main()
//{
//	int a[] = { 6, 2, 4, 5, 1, 3, -1 };
//	int n = sizeof(a) / sizeof(int);
//	QuickSort(a, 0,sizeof(a)/sizeof(int)-1);
//
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	return 0;
//}