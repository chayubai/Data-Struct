
#define _CRT_SECURE_NO_WARNINGS 1
//˳���

#include "SeqList.h"
//1����ʼ��
//��ַ����
void SeqListInit(SL* ps)
{
	//����һ��
	ps->size = 0;
	ps->a = NULL;
	ps->capacity = 0;//����aָ��Ŀռ�û�У�������Ϊ0
}

//7����������Ƿ�Ҫ����
void SeqListCheckCapacity(SL* ps)
{
	//�ж��Ƿ��������ˣ����������Ҫ����
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity*2;
		SLDataType* tmp = realloc(ps ->a, sizeof(SLDataType) * newcapacity);
		if (tmp == NULL)
		{
			printf("����ʧ��\n");
			exit(-1);//��������
		}
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
}

 //2��β�� - size�������ݵĸ�����Ҳ�����һ�����ݵ���һ�����ݵ��±�
void SeqListPushBack(SL* ps, SLDataType x)
{
    SeqListCheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
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

//4���ռ�����
void SeqListDestory(SL* ps)
{
	free(ps->a);//�ͷſռ䣬���ͷ�ps��ָ��Ŀռ�a
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}

//5��βɾ
void SeqListPopBack(SL* ps)
{
	//�����ԣ���ֹɾ��������
	/*
    if(ps->size > 0)
    {
        ps->size--;//ֱ�ӽ����ݸ������٣��Ӷ�����ӡ��Ϊɾ��
    }
    */
    //��������
    assert(ps->size > 0);//����size��Ч��
    ps->size--;
}

//6��ͷ��
void SeqListPushFront(SL* ps, SLDataType x)
{
	SeqListCheckCapacity(ps);
	//�����һ�����ݿ�ʼ�����ν�ÿ�����������ƶ�������ӵ�һ�����ݿ�ʼ�����ƶ����������ָ��Ǻ��������
	int end = ps->size - 1;//����һ��ָ�����һ���ռ��λ��
	while (end >= 0)//ע��������ѭ��д���Ǽ���������������ǽ���������
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[0] = x;
	ps->size++;
}

//8��ͷɾ
void SeqListPopFront(SL* ps)
{
	int start = 0;
	while (start < ps->size)
	{
		ps->a[start - 1] = ps->a[start];
		start++;
	}
	ps->size--;
}

//9������λ�ò���
void SeqListInsert(SL* ps, int pos, SLDataType x)
{
	//�ڸ�����λ�ã������һ�����ݿ�ʼ�����ν�ÿ�����������ƶ����ж��Ƿ�����
	assert(ps);//Ϊ�治ִ��
	assert(pos <= ps->size && pos >= 0);//����λ������Ч�ģ���0 <= pos <= size

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

//10������λ��ɾ��
void SeqListErase(SL* ps, int pos)
{
	//�ڸ�����λ�ã�����λ�ú�ĵڶ������ݿ�ʼ�����ν�ÿ��������ǰ�ƶ�
	assert(ps);
	assert(pos <= ps->size&& pos >= 0);//��ʹ��size_t posʱ������Ϊunsigned int�ʿ��Բ�Ҫ���pos >= 0
	int start = pos;
	while (start < ps->size - 1)//start <= ps->size - 2
	{
		ps->a[start] = ps->a[start + 1];
		start++;
	}
	/*
	int start = pos + 1;
	while (start < ps->size)
	{
		ps->a[start - 1] = ps->a[start];
		start++;
	}
	*/
	ps->size--;
}

 //11��˳������
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

//�޸�
void SeqListModify(SL* ps, int pos,SLDataType x)
{
	assert(ps);
	assert(pos <= ps->size&& pos >= 0);
    ps->a[pos] = x;
}
