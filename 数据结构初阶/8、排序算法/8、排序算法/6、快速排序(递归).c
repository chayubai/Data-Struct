#define _CRT_SECURE_NO_WARNINGS 1
//��������֮��������

// ��������˼�룺
//��ȡ������Ԫ�������е�ĳԪ����Ϊ��׼ֵ�����ո������뽫�����򼯺Ϸָ���������У���������������
//Ԫ�ؾ�С�ڻ�׼ֵ����������������Ԫ�ؾ����ڻ�׼ֵ��Ȼ���������������ظ��ù��̣�ֱ������Ԫ�ض���������Ӧλ����Ϊֹ��

//һ���ڿӷ�������
//��1������������ÿ��ֻ��һ����
//��ѡһ���ؼ���key(key��ֵһ��ȡ����������±��Ӧ�������������ұ��±��Ӧ����)����Ϊ�ԱȵĶ��󣬽���ȡ����ȡ������±��Ԫ�ؿ��������Ϊ�ӣ�
//��������ұߣ�begin����ȥ�Ҵ��ڹؼ���key��ֵ�����ϴ��ֵ������С��ٸ��¿ӵ�λ��
//���������ߣ�end���ң�ȥ��С�ڹؼ���key��ֵ������С��ֵ������С��ٸ��¿ӵ�λ��
//����begin,end����������������ȥ��ֱ����begin == end��ʱ�����key�ŵ����һ���ӵ�λ�ã�ͬʱ��¼�м���λ�á���ʱ���м������ź��ˡ�
//��2���������㷨˼��
//ͨ������˼�룺������������ʹ�����ֽ�ɹؼ������Ҷ���һ�����������ⲻ����С�������ٷֵ������⡣
//��key�����±�Ϊ�ֽ磬�ָ��������䡣��������ͬ����ķ���������ѡ���Ե�key�����е�������......
//���������ȥ��ֱ�����䱻��С��һ����ʱ������С��key�Ķ�����ߣ�����key�Ķ����ұߡ�

//ע�⣺����������ǣ��������������С�ģ��ұ��Ҵ�� ������С�

#include <stdio.h>
//��������ÿ��ֻ��һ����
//B               E  key
//6 3 5 2 7 8 9 4 1  6

//B               E  key
//��3 5 2 7 8 9 4 1  6
//B               E  key
//1 3 5 2 7 8 9 4��  6
//        B       E  key
//1 3 5 2 ��8 9 4 7  6
//        B    E     key
//1 3 5 2 4 8 9�� 7  6
//          B   E    key
//1 3 5 2 4 ��9 8 7  6
//          E
//          B        key
//1 3 5 2 4 ��9 8 7  6
//          E
//          B  
//1 3 5 2 4 6 9 8 7   

/*
//��������ÿ��ֻ��һ����
//������룺
void QuickSort01(int* a, int n)
{
	int begin = 0, end = n - 1;//�±�
	int pivot = begin;//�ӵ��±ꡣ�����һ���±�����ֵΪkey�����һ�οӵ�λ��Ϊ��һ���±��λ��
	int key = a[begin];//ѡ����ߵ��±����Ϊkey

	while (begin < end)//begin == end��������
	{
		//�ұ���С�ģ��ŵ����(��С��key��ֵ)
		while (a[end] >= key)//����ǽ�����������д����ѭ��������
		{
			end--;
		}
		//��С�ķŵ���ߵĿ���Լ��γ��µĿ�λ
		a[pivot] = a[end];
		pivot = end;//���¿ӵ��±�

		//����Ҵ�ģ��ŵ��ұ�(�Ҵ���key��ֵ)
		while (a[begin] <= key)
		{
			begin++;
		}
		//����ķŵ��ұߵĿ���Լ��γ��µĿ�λ
		a[pivot] = a[begin];
		pivot = begin;//���¿ӵ��±�
	}

	//��ʱ��begin == end�����������һ���ӵ�λ��,
	pivot = begin;//����pivot = end;//��¼�м���λ��
	a[pivot] = key;
}
*/
//���ԣ�6 3 5 2 7 8 9 4 1
//ע�����ϴ���ĵ��Թ��̣�
//�۲�a[0] a[1] a[2] a[3] a[4] a[5] a[6] a[7] a[8] begin end pivot key��ֵ�ı仯 
//�п��ܴӵ�ǰend�±�λ����С��һֱû���ҵ�С���ͻ�һֱend--��������󳬹���begin���±꣬������û���ҵ������ִ��ҡ�
//�п��ܴӵ�ǰbegin�±�λ���Ҵ�һֱû���ҵ��󣬾ͻ�һֱbegin++��������󳬹���end���±꣬������û���ҵ������ִ��ҡ�
//�Ż���
/*
void QuickSort01(int* a, int n)
{
	int begin = 0, end = n - 1;
	int pivot = begin;
	int key = a[begin];

	while (begin < end)//begin == end��������
	{
		//�ұ���С�ģ��ŵ����
		while (begin < end && a[end] >= key)//����a[end] >= key�Ƚϣ���ǰ��begin < endҲ���ǲ�����ȣ��򽻲棬����ύ��end��begin
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
	pivot = begin;//��¼�м���λ��
	a[pivot] = key;
}
*/
//ע�⣺���������ݺ�ż�������ݣ����ն��ǵ�begin == end�������������
void QuickSort01(int* a, int left, int right)//left��0�±꣬right��n-1�±�
{
	//�����䲻����ʱ����һ��ֵ��ʱ�򣬲���Ҫ�ţ�����
	if (left >= right)
		return;

	//ֻ��������ڲŽ��п���
	int begin = left, end = right;//����begin = left, end = right;���ڻ�ݹ飬����begin, end���ǹ̶���
	int pivot = begin;
	int key = a[begin];

	while (begin < end)//begin == end��������
	{
		//�ұ���С�ģ��ŵ����
		while (begin < end && a[end] >= key)
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

	//��left��right�� => ��left��pivot-1��pivot��pivot+1��right��,���ƶ�����ǰ�����
	//������������������������������� ����������������򣿷��εݹ�
	//û��С�����Ż�
	QuickSort01(a, left, pivot - 1);
	QuickSort01(a, pivot + 1, right);
}

#if 0
int main()
{
	int a[] = { 6, 2, 4, 5, 1, 3, -1 };
	int n = sizeof(a) / sizeof(int);
	QuickSort01(a, 0, sizeof(a) / sizeof(int) - 1);

	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}
#endif
//ʱ�临�Ӷȣ�
//��������(��һ����)��ʱ�临�Ӷȣ��������м��ߣ��ϼƹ�N�Σ���F(N) = N = O(N)
//��������£�ÿ�����������С��ȣ����ָ��������������ÿ��ѡ��key�����м�ʱ��n��������Ӧn����㣬��������ĸ߶�h = log2 (N+1),
//ÿһ���ʱ�临�Ӷ�ΪO(N)��һ����h = log2 (N+1)��, �ʣ���ʱ�临�Ӷȣ�F(N) = N * log2 (N+1) = O(N * log2 N)
//������������ʱ������˳�����򣩣�ѡ����ߵĻ����ұߵ���keyʱ��ÿ�ε�������ֻ�ź�����߻����ұߵ�һ����
//F(N) = N + (N-1) + (N-2) + ... + 1��(�Ȳ�����)��ʱ�临�Ӷȣ�O(N^2)

//���ڵ������ʱ�򣬿��ŵ�ʱ�临�ӶȺܴ�Ч�ʾͺܵͣ���ν��������⣿
//���������key��ѡȡ
//1��ȡ�м�ֵ��key
//2��ȡ���ֵ��key
//3������ȡ�У���ѡȡ��ˣ��м䣬�Ҷˡ�Ҳ����ȡ�Ȳ������Ҳ������С��ֵ��key

int GetMidInex(int* a, int left, int right);
void swap05(int* a, int* b);

void QuickSort02(int* a, int left, int right)//left��0�±꣬right��n-1�±�
{
	//�����䲻����ʱ
	if (left >= right)
		return;

	int index = GetMidInex(a, left, right); //���ߵ��м���
	swap05(&a[left], &a[index]);//��index��Ϊkey���������leftλ�õ���������ʹ��beginλ�õ�ֵΪ���ߵ��м��ߣ��Ӷ������߼�����Ҫ�Ķ���

	//ֻ��������ڲŽ��п���
	int begin = left, end = right;
	int pivot = begin;//�����һ���±�����ֵΪkey�����һ�οӵ�λ��Ϊ��һ���±��λ�ã��������Ѿ�Ϊ���ߵ��м����±�
	int key = a[begin];//���ڽ�����һ�£�����a[begin]�����ϻ���ȡ���ߵ��м�����Ϊkey

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

	//��left��right�� => ��left��pivot-1��pivot��pivot+1��right��,ǰ���������������
	//������������������������������� ����������������� -- ���εݹ�
	//û��С�����Ż�
	QuickSort02(a, left, pivot - 1);
	QuickSort02(a, pivot + 1, right);

	/*
	//ע�⣺����������д��룬�����������������Ż�

	//����󼸲�ݹ���ô��������Ż�����С�����Ż�����ֹ�ݹ���ô���̫��
	//���赱������������ݸ���С��10��ʹ�ò�������
	//���赱�������������ݸ�������10��ʹ�ÿ�������
	//С�����Ż���ֵ���Ǹ��������������ģ��ٷ�һ��ȡ13
	if ((pivot - 1) - left > 10)//�ٷ���13
	{
		QuickSort(a, left, pivot - 1);//ÿ�ε��ÿ��ţ����Ǵ�aָ�뿪ʼ�ݹ�
	}
	else
	{
		InsertSort(a + left, ((pivot - 1) - left) + 1);//InsertSort(ĳ����������±��ָ�룬Ԫ�ظ���)����һ����0��ʼ
	}
	if (right - (pivot + 1) > 10)//�ٷ���13
	{
		QuickSort(a, pivot + 1, right);//ÿ�ε��ÿ��ţ����Ǵ�aָ�뿪ʼ�ݹ�
	}
	else
	{
		InsertSort(a + pivot + 1, (right - (pivot + 1)) + 1);//InsertSort(ĳ����������±��ָ�룬Ԫ�ظ���)����һ����0��ʼ
	}
	*/

	//ע�⣺����һ�㲻����д����ȡ�к�С�����Ż�����ʱ��
}
//����ȡ�У�������ˣ��м䣬�Ҷˣ��Ȳ�������Ҳ������С����λ����
int GetMidInex(int* a, int left, int right)
{
	int mid = (left + right) / 2;//int mid = (left + right) >> 1;���Ч�ʸ�һЩ
	//left mid right
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])//a[left] < a[mid]��a[mid] < a[right]
		{
			return mid;
		}
		else if (a[left] > a[right])//a[left] < a[mid]��a[mid] > a[right]��a[left] > a[right] ��a[right] < a[left] < a[mid]
		{
			return left;
		}
		else//a[left] < a[mid]��a[mid] > a[right]��a[left] < a[right] ��a[left] < a[right] < a[mid]
		{
			return right;
		}
	}
	else //a[left] > a[mid]
	{
		if (a[mid] > a[right])//a[left] > a[mid]��a[mid] > a[right]
		{
			return mid;
		}
		else if (a[left] < a[right])//a[left] > a[mid]��a[mid] < a[right]��a[left] < a[right] ��a[mid] < a[left] < a[right]
		{
			return left;
		}
		else//a[left] > a[mid]��a[mid] < a[right]��a[left] > a[right] ��a[mid] < a[right] < a[left]
		{
			return right;
		}
	}
}
void swap05(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

//-----------------------------------------------------------------------------------------------------------------------------------

//1���ڿӷ�
//�������� - ȷ�����С�ұߴ� - ÿ��ֻ��һ����
//����һ�����begin == end���������һ���ӵ��±꣬�Ӷ������㷨���ָ�����
int Part1Sort(int* a, int left, int right)
{
	int index = GetMidInex(a, left, right); //���ߵ��м���
	swap05(&a[left], &a[index]);//��index��Ϊkey����left����

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

//2������ָ�뷨(����)��Ҳ��hoare�汾
//��1������������ÿ��ֻ��һ����
//��ѡһ���ؼ���key(key��ֵһ��ȡ����������±꣬�������ұ��±�)����Ϊ�ԱȵĶ���
//begin����ߣ�ȥ�Ҵ��ڹؼ���key�±��Ӧ��ֵ��end���ұߣ�ȥ��С�ڹؼ���key�±��Ӧ��ֵ��Ȼ�������±��Ӧ����������
//����begin,end����������������ȥ��ֱ����begin == end��ʱ������±괦�Ķ�Ӧ������key�±��Ӧ����������ͬʱ��¼�м���λ�á���ʱ���м������ź��ˡ�
//��2���������㷨˼��
//ͨ������˼�룺������������ʹ�����ֽ�ɹؼ������Ҷ���һ�����������ⲻ����С�������ٷֵ������⡣
//��key�±�Ϊ�ֽ磬�ָ��������䡣��������ͬ����ķ���������ѡ���Ե�key�����е�������......
//���������ȥ��ֱ�����䱻��С��һ����ʱ������С��key�Ķ�����ߣ�����key�Ķ����ұߡ�

//ע�⣺����������ǣ��������������С�ģ��ұ��Ҵ�� Ȼ�󽻻���
int Part2Sort(int* a, int left, int right)
{
	int index = GetMidInex(a, left, right); //���ߵ��м���
	swap05(&a[left], &a[index]);//��index��Ϊkey

	//ֻ��������ڲŽ��п���
	int begin = left, end = right;
	int keyi = begin;

	while (begin < end)//��Ȼ򽻴������
	{
		//�ұ���С��
		while (begin < end && a[end] >= a[keyi])//������Ҫbegin < end�������Խ��
		{//a[end] > a[keyi]�����ܻ���ѭ������5 1 2 4 3 5 8 7 9 
			end--;
		}

		//����Ҵ��
		while (begin < end && a[begin] <= a[keyi])//������Ҫbegin < end�������Խ��
		{//a[begin] < a[keyi]�����ܻ���ѭ������5 1 2 4 3 5 8 7 9
			begin++;
		}
		//���ԣ�5 1 2 4 3 5 8 7 9 
		//��keyΪ5ʱ��a[end] > a[keyi]��С��a[begin] < a[keyi]�Ҵ����begin��5��ʼ�Ҵ��ұ�end��9��ʼ��С����ʱ��������������һֱ��ѭ���������
		//ע�����ϴ���ĵ��Թ��̣�
		//�۲�a[0] a[1] a[2] a[3] a[4] a[5] a[6] a[7] a[8] begin end  keyi��ֵ�ı仯 
		//�п��ܴӵ�ǰend�±�λ����С��һֱû���ҵ�С���ͻ�һֱend--��������󳬹���begin���±꣬������û���ҵ������ִ��ҡ�
		//�п��ܴӵ�ǰbegin�±�λ���Ҵ�һֱû���ҵ��󣬾ͻ�һֱbegin++��������󳬹���end���±꣬������û���ҵ������ִ��ҡ�

		//����
		swap05(&a[begin], &a[end]);
	}

	//��ʱbegin == end����������keyi����������ǽ��������
	swap05(&a[begin], &a[keyi]);//swap05(&a[end], &a[keyi]);

	return begin;//����һ�������м�λ�á�ͬʱҲ��¼���м���λ��
}
//ע�⣺�ڿӷ���������ָ�뷨ͬ��a[begin] < a[key]��a[end] > a[key]������ѭ����
//ע�⣺���������ݺ�ż�������ݣ����ն��ǵ�begin == end���������������Ϊ�ڲ�����ѭ������һ�����ն����ߵ���һ���±��λ�á�

//3��ǰ��ָ�뷨(����)
//��1������������ÿ��ֻ��һ����
//��ѡһ���ؼ���key(key��ֵһ��ȡ����������±꣬�������ұ��±�)����Ϊ�ԱȵĶ���
//����key������������±ꡣ����curָ��������±�+1����prevָ��������±ꡣ
//curȥ��С�ڹؼ���key�±��Ӧ��ֵ�������ǰλ�õ��������㣬cur++�������ǰλ�õ������㣬��prev++��Ȼ��cur��prev�����±�λ�õ���������
//����cur,prev����������������ȥ��ֱ����cur == ���ұ��±�ʱ�����ٽ�prev�±������key�±��Ӧ����������ͬʱ��¼�м���λ�á���ʱ���м������ź��ˡ�
//��2���������㷨˼��
//ͨ������˼�룺������������ʹ�����ֽ�ɹؼ������Ҷ���һ�����������ⲻ����С�������ٷֵ������⡣
//��key�±�Ϊ�ֽ磬�ָ��������䡣��������ͬ����ķ���������ѡ���Ե�key�����е�������......
//���������ȥ��ֱ�����䱻��С��һ����ʱ������С��key�Ķ�����ߣ�����key�Ķ����ұߡ�

//���ģ��������򣬰�С�����������ȥ
//ע�⣺����������ǣ���������cur�Ҵ��ڹؼ���key�±��Ӧ��ֵ��Ȼ�󻻵���ߡ�
int Part3Sort(int* a, int left, int right)
{
	int index = GetMidInex(a, left, right); //���ߵ��м���
	swap05(&a[left], &a[index]);//��index��Ϊkey

	//ֻ��������ڲŽ��п���
	int keyi = left;
	int prev = left, cur = left + 1;

	while (cur <= right)//curֱ���������ұߵ������±꣬����
	{
		//cur��С��
		/*
		if (a[cur] < a[keyi])
		{
			prev++;
			swap05(&a[prev], &a[cur]);
		}
		*/

		//�Ż�һ�£���prev++;֮�������λ����cur��λ��Ϊͬһ��λ�ã����Բ�����
		if (a[cur] < a[keyi] && ++prev != cur)
		{
			swap05(&a[prev], &a[cur]);
		}
		cur++;
	}
	//��ʱ��cur�ߵ�β����keyi����
	swap05(&a[keyi], &a[prev]);

	return prev;//����һ��������м���λ�á�ͬʱ��¼�м�����λ��
}
void QuickSort(int* a, int left,int right)//left��0�±꣬right��n-1�±�
{
	//�����䲻����ʱ
	if (left >= right)
		return;

	//int keyIndex = Part1Sort(a, left, right);
	//int keyIndex = Part2Sort(a, left, right);
	int keyIndex = Part3Sort(a, left, right);

	//��left��right�� => ��left��keyIndex-1��keyIndex��keyIndex+1��right��,ǰ���������������
	//������������������������������� ����������������� -- ���εݹ�
	//û��С�����Ż�
	QuickSort(a, left, keyIndex - 1);
	QuickSort(a, keyIndex + 1, right);
	
	//���ݹ���ô��������Ż�����С�����Ż�����ֹ�ݹ���ô���̫��
	/*if (keyIndex - 1 - left > 10)//�ٷ���13
	{
		QuickSort(a, left, keyIndex - 1);
	}
	else
	{
		InsertSort(a + left, keyIndex - 1 - left + 1);
	}
	if (right - (keyIndex + 1) > 10)
	{
		QuickSort(a, keyIndex + 1, right);
	}
	else
	{
		InsertSort(a + keyIndex + 1, right - (keyIndex + 1) + 1);
	}*/
}
#if 0
int main()
{
	int a[] = { 90, 99, 92, 93, 16, 3, 16 };
	int n = sizeof(a) / sizeof(int);
	QuickSort(a, 0, sizeof(a) / sizeof(int) - 1);

	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}
#endif
//��ע��߽�ֵ�Ŀ��ơ������������˼�룺������ǰ����������������߼����໭ͼ��

//��������������ܽ᣺
//1. ��������������ۺ����ܺ�ʹ�ó������ǱȽϺõģ����ԲŸҽп�������
//2. ʱ�临�Ӷȣ�O(N * logN)
//3. �ռ临�Ӷȣ�O(logN)
//4. �ȶ��ԣ����ȶ�