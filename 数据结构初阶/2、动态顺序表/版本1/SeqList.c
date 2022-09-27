
#define _CRT_SECURE_NO_WARNINGS 1
//˳���

#include "SeqList.h"
//1����ʼ��
//��ֵ����
//void SeqListInit(SL s)
//{
//	/*
//	//����һ��
//	s.size = 0;
//	s.a = NULL;
//	s.capacity = 0;//����aָ��Ŀռ�û�У�������Ϊ0
//	*/
//
//	//��������
//	s.a = (SLDataType*)malloc(sizeof(SLDataType) * 4);//���������ĸ�SLDataType���͵Ŀռ��С
//	if (s.a == NULL)
//	{
//		printf("�����ڴ�ʧ��\n");
//		exit(-1);//��������
//	}
//	s.size = 0;
//	s.capacity = 4;//����Ϊ�洢���͵ĸ���
//
//	/*
//	//��������
//	//��̬˳���ĳ�ʼ��
//	memest(s.a, 0, sizeof(SLDataType)* 4);//���ĸ�Ԫ�ص������ʼ��
//	s.size = 0;
//	*/
//}

//��ַ����
void SeqListInit(SL* ps)
{
	ps->a = (SLDataType*)malloc(sizeof(SLDataType) * 4);
	if (ps->a == NULL)
	{
		printf("�����ڴ�ʧ��\n");
		exit(-1);
	}
	ps->size = 0;
	ps->capacity = 4;
}

//11���ռ�����
void SeqListDestory(SL* ps)
{
	free(ps->a);//�ͷſռ䣬���ͷ�ps��ָ��Ŀռ�a
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}

//3����ӡ
void SeqListPrint(SL* ps)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

//7����������Ƿ�Ҫ����
void SeqListCheckCapacity(SL* ps)
{
	//�ж��Ƿ��������ˣ����������Ҫ����
	if (ps->size == ps->capacity)
	{
		ps->capacity *= 2;//ÿ������������2��������ֹƵ������
		ps->a = realloc(ps->a, sizeof(SLDataType) * ps->capacity);
		if (ps->a == NULL)
		{
			printf("����ʧ��\n");
			exit(-1);//��������
		}
	}
}

//2��β�� - size�������ݵĸ�����Ҳ�����һ�����ݵ���һ�����ݵ��±�
//��ʹ�õ�һ�ַ�����ʼ��ʱ��
//void SeqListPushBack(SL* ps, SLDataType x)
//{
//	assert(ps);
//	//�ж��Ƿ��������ˣ����������Ҫ����
//	if (ps->size == ps->capacity)
//	{
//		//SLDataType* tmp = realloc(ps->a, sizeof(SLDataType) * ps->capacity);
//		//����ֱ�ӿ��ٿռ䣬����ps->capacity *= 2;�൱��capacity  = 0 * 2 = 0
//		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
//		SLDataType* tmp = realloc(ps->a, sizeof(SLDataType) * newcapacity);
//		if (tmp == NULL)
//		{
//			printf("����ʧ��\n");
//			exit(-1);//��������
//		}
//		else
//		{
//			ps->a = tmp;	
//			//ps->capacity *= 2;
//			ps->capacity = newcapacity;
//		}
//	}
//	ps->a[ps->size] = x;
//	ps->size++;
//}

//void SeqListPushBack(SL* ps, SLDataType x)//2��
//{
//	assert(ps);
//	ps->a[ps->size] = x;
//	ps->size++;
//
//}

//void SeqListPushBack(SL* ps, SLDataType x)//4��
//{
//	assert(ps);
//	//�ж��Ƿ��������ˣ����������Ҫ����
//	if (ps->size == ps->capacity)
//	{
//		ps->capacity *= 2;//ÿ������������2��������ֹƵ������
//		ps->a = realloc(ps->a, sizeof(SLDataType) * ps->capacity);
//		if (ps->a == NULL)
//		{
//			printf("����ʧ��\n");
//			exit(-1);//��������
//		}
//	}
//	ps->a[ps->size] = x;
//	ps->size++;
//}

//void SeqListPushBack(SL* ps, SLDataType x)//8��
//{
//	assert(ps);
//	SeqListCheckCapacity(ps);
//	ps->a[ps->size] = x;
//	ps->size++;
//}

void SeqListPushBack(SL* ps, SLDataType x)//14��
{
	//���ϴ����൱�ڣ������һ��sizeλ�ò���x
	SeqListInsert(ps, ps->size, x);
}

//5��βɾ
//void SeqListPopBack(SL* ps)//5��
//{
//	//����һ��
//	//assert(ps->size > 0);
//	//�����һ��������Ϊ0����ɾ��������ȱ���ǣ����ڴ˴����ݱ�����0����û������
//	//����ɾ�����ݱ���û��ɾ������ɾ�����ʣ�һ��ɾ���ݣ�ֻ��Ҫ--���ɡ�������Ҫ��һ��ps->a[ps->size - 1] = 0;
//	//��������
//	//ps->a[ps->size - 1] = 0;
//	if(ps->size >= 0)
//	{
//		ps->size--;	
//	}
//}

void SeqListPopBack(SL* ps)//16��
{
	assert(ps->size > 0);
	//���ϴ����൱�ڣ������һ��sizeλ��ɾ��
	//SeqListErase(ps, ps->size - 1);
}

//6��ͷ��
//void SeqListPushFront(SL* ps, SLDataType x)//6��
//{
//	assert(ps);
//	//�����һ�����ݿ�ʼ�����ν�ÿ�����������ƶ�������ӵ�һ�����ݿ�ʼ�����ƶ����������ָ��Ǻ��������
//	int end = ps->size - 1;//����һ��ָ�����һ���ռ��λ��
//	while (end >= 0)//ע��������ѭ��д���Ǽ���������������ǽ���������
//	{
//		ps->a[end + 1] = ps->a[end];
//		end--;
//	}
//	ps->a[0] = x;
//	ps->size++;
//}

//void SeqListPushFront(SL* ps, SLDataType x)//9��
//{
//	assert(ps);
//	SeqListCheckCapacity(ps);
//	//�����һ�����ݿ�ʼ�����ν�ÿ�����������ƶ�������ӵ�һ�����ݿ�ʼ�����ƶ����������ָ��Ǻ��������
//	int end = ps->size - 1;//����һ��ָ�����һ���ռ��λ��
//	while (end >= 0)//ע��������ѭ��д���Ǽ���������������ǽ���������
//	{
//		ps->a[end + 1] = ps->a[end];
//		end--;
//	}
//	ps->a[0] = x;
//	ps->size++;
//}

void SeqListPushFront(SL* ps, SLDataType x)//15��
{
	//���ϴ����൱�ڣ��ڵ�һ��0λ�ò���x
	//SeqListInsert(ps, 0, x);
}

//10��ͷɾ
//void SeqListPopFront(SL* ps)//10��
//{
//	assert(ps->size > 0);
//	//����һ��������Ϊ0�����ӵڶ������ݿ�ʼ�����ν�ÿ��������ǰ�ƶ�
//	int start = 0;//����һ��ָ�����һ���ռ��λ��
//	while (start < ps->size-1)//ע����������start <= ps->size-2
//	{
//		ps->a[start] = ps->a[start + 1];
//		start++;
//	}
//	/*
//	int start = 1;//����һ��ָ�����һ���ռ��λ��
//	while (start < ps->size)//ע����������start <= ps->size-2
//	{
//		ps->a[start - 1] = ps->a[start];
//		start++;
//	}
//	*/
//	//���һ��������Ϊ0��Ҳ���Բ���Ҫ����ps->a[ps->size] = 0;
//	//ps->a[ps->size] = 0;
//	ps->size--;
//}

void SeqListPopFront(SL* ps)//17��
{
	//���ϴ����൱�ڣ��ڵ�һ��0λ��ɾ��
	//SeqListErase(ps, 0);
}

//12������λ�ò���
void SeqListInsert(SL* ps, int pos, SLDataType x)
{
	//�ڸ�����λ�ã������һ�����ݿ�ʼ�����ν�ÿ�����������ƶ����ж��Ƿ�����
	assert(ps);//Ϊ�治ִ��
	assert(pos <= ps->size && pos >= 0);//����λ������Ч�ԣ���0 <= pos <= size

	//�ж�����
	SeqListCheckCapacity(ps);
	int end = ps->size - 1;
	while (end >= pos)//д�����������������������
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[pos] = x;
	ps->size++;
}
//13������λ��ɾ��
void SeqListErase(SL* ps, int pos)
{
	//�ڸ�����λ�ã�����λ�ú�ĵڶ������ݿ�ʼ�����ν�ÿ��������ǰ�ƶ�
	assert(ps);
	assert(pos < ps->size&& pos >= 0);//��ʹ��size_t posʱ������Ϊunsigned int�ʿ��Բ�Ҫ���pos >= 0
	int start = pos;
	while (start < ps->size - 1)//start <= ps->size - 2
	{
		ps->a[start] = ps->a[start + 1];
		start++;
	}
	/*
	int start = pos+1;
	while (start < ps->size)
	{
		ps->a[start-1] = ps->a[start];
		start++;
	}
	*/
	ps->size--;
}
//18��˳������
int SeqListFind(SL* ps, SLDataType x)
{
	assert(ps);
	int i = 0;
	while (i < ps->size)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
		i++;
	}
	return -1;
}