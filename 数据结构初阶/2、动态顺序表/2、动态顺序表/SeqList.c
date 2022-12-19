#define _CRT_SECURE_NO_WARNINGS 1
//˳���

//ע�⣺�����Ĳ�����ƣ��Ǹ����Լ�����Ҫʵ��ʲô���ܶ���Ƶġ�

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
//	s.a = (SLDataType*)malloc(sizeof(SLDataType) * 4);//�����ĸ�SLDataType���͵Ŀռ��С
//	if (s.a == NULL)
//	{
//		printf("�����ڴ�ʧ��\n");
//		exit(-1);//��������
//	}
//	s.size = 0;
//	s.capacity = 4;//����Ϊ�洢���͵ĸ���
//}

//��ַ����
void SeqListInit(SL* ps)
{
	//����1��
	/*
	ps->size = 0;
	ps->a = NULL;
	ps->capacity = 0;//����aָ��Ŀռ�û�У�������Ϊ0
	*/

	//����2��
	ps->a = (SLDataType*)malloc(sizeof(SLDataType) * 4);//һ��ʼ�Ϳ���4��������С�Ŀռ�
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
void SeqListPrint(SL* ps)//���ﴫ�ṹ��Ҳ���ԣ�����ָ��Ч�ʸ���
{
	assert(ps);//����ָ��Ϊ�գ��򱨴�
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

//7����������Ƿ�Ҫ����
//��ʹ�õ�һ�ַ�����ʼ��ʱ��
/*
void SeqListCheckCapacity(SL* ps)
{
	assert(ps);
	//�ж��Ƿ��������ˣ����������Ҫ����
	if (ps->size == ps->capacity)//û�пռ��ռ�����
	{
		//SLDataType* tmp = (SLDataType*)realloc(ps->a, sizeof(SLDataType) * ps->capacity * 2);
		//����ֱ�ӿ��ٿռ䣬���ڳ�ʼ��capacity=0����ps->capacity *= 2;�൱��capacity  = 0 * 2 = 0

		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType* tmp = (SLDataType*)realloc(ps->a, sizeof(SLDataType) * newcapacity);
		if (tmp == NULL)
		{
			printf("����ʧ��\n");
			exit(-1);//�����������˳�����return -1���˳���ǰ������������ֹ����
		}
		else
		{
			ps->a = tmp;
			//ps->capacity *= 2;
			ps->capacity = newcapacity;
		}
	}
}
*/
void SeqListCheckCapacity(SL* ps)//��ֵ����
{
	//�ж��Ƿ��������ˣ����������Ҫ����
	if (ps->size == ps->capacity)
	{
		ps->capacity *= 2;//ÿ������������2��������ֹƵ������
		SLDataType* tmp = (SLDataType*)realloc(ps->a, sizeof(SLDataType) * ps->capacity);
		if (ps->a == NULL)
		{
			printf("����ʧ��\n");
			exit(-1);//��������
		}
		ps->a = tmp;
	}
}

//2��β�� - size�������ݵĸ�����Ҳ�����һ�����ݵ���һ�����ݵ��±�
//void SeqListPushBack(SL* ps, SLDataType x)//2��
//{
//	assert(ps);//����ָ��Ϊ�գ��򱨴�
//	ps->a[ps->size] = x;
//	ps->size++;
//}

//��ʹ�õ�һ�ַ�����ʼ��ʱ��
/*
void SeqListPushBack(SL* ps, SLDataType x)
{
	assert(ps);//����ָ��Ϊ�գ��򱨴�
	//�ж��Ƿ��������ˣ����������Ҫ����
	if (ps->size == ps->capacity)
	{
		//SLDataType* tmp = (SLDataType*)realloc(ps->a, sizeof(SLDataType) * ps->capacity * 2);
		//����ֱ�ӿ��ٿռ䣬���ڳ�ʼ��capacity=0����ps->capacity *= 2;�൱��capacity  = 0 * 2 = 0

		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType* tmp = (SLDataType*)realloc(ps->a, sizeof(SLDataType) * newcapacity);
		if (tmp == NULL)
		{
			printf("����ʧ��\n");
			exit(-1);//��������
		}
		else
		{
			ps->a = tmp;	
			//ps->capacity *= 2;
			ps->capacity = newcapacity;
		}
	}
	ps->a[ps->size] = x;
	ps->size++;
}
*/

//void SeqListPushBack(SL* ps, SLDataType x)//4��
//{
//	assert(ps);//����ָ��Ϊ�գ��򱨴�
//	//�ж��Ƿ��������ˣ����������Ҫ����
//	if (ps->size == ps->capacity)
//	{
//		ps->capacity *= 2;//ÿ������������2��������ֹƵ������
//		SLDataType* tmp = (SLDataType*)realloc(ps->a, sizeof(SLDataType) * ps->capacity);
//		if (ps->a == NULL)
//		{
//			printf("����ʧ��\n");
//			exit(-1);//��������
//		}
//		ps->a = tmp;
//	}
//	ps->a[ps->size] = x;
//	ps->size++;
//}

//void SeqListPushBack(SL* ps, SLDataType x)//8��
//{
//	assert(ps);
//	SeqListCheckCapacity(ps);//��ֵ���ã�void SeqListCheckCapacity(SL* ps)�β�ps��SeqListCheckCapacity(ps)��ʵ��ps��ָ��SeqList s;
//	ps->a[ps->size] = x;
//	ps->size++;
//}

void SeqListPushBack(SL* ps, SLDataType x)//14��
{
	//���ϴ����൱�ڣ������һ��sizeλ�ò���x
	SeqListInsert(ps, ps->size, x);//��ֵ����
}

//5��βɾ
//void SeqListPopBack(SL* ps)//5��
//{
//  //assert(ps);//����ָ��Ϊ�գ��򱨴�
//  //����size��Ч�ԣ�����һ��
//	//assert(ps->size > 0);//��������Ϊ��ɾ�����򱨴�
//	//�����һ��������Ϊ0����ɾ��������ȱ���ǣ����ڴ˴����ݱ�����0����û������
//	//����ɾ�����ݱ���û��ɾ������ɾ������һ��ɾ���ݣ�ֻ��Ҫ--���ɡ�������Ҫ��һ��ps->a[ps->size - 1] = 0;	
//	//ps->a[ps->size - 1] = 0;
// 
//  //����size��Ч�ԣ�����������ֹɾ��������
//	if(ps->size > 0)
//	{
//		ps->size--;	//ֱ�ӽ����ݸ������٣��Ӷ�����ӡ��Ϊɾ��
//	}
//}

void SeqListPopBack(SL* ps)//16��
{
	//���ϴ����൱�ڣ������һ��sizeλ��ɾ��
	SeqListErase(ps, ps->size - 1);//��ֵ����
}

//6��ͷ��
//void SeqListPushFront(SL* ps, SLDataType x)//6��
//{
//	assert(ps);//����ָ��Ϊ�գ��򱨴�
//  //Ҳ��Ҫ�ж������Ƿ����ˣ����Խ��ù��ܷ�װ��һ������
// 
//	//�����һ�����ݿ�ʼ�����ν�ÿ�����������ƶ�������ӵ�һ�����ݿ�ʼ�����ƶ����������ָ��Ǻ��������
//	int end = ps->size - 1;//�±꣬����һ��ָ�����һ�����ݵ�λ��
//	while (end >= 0)//ע��������ѭ��д���Ǽ���������������ǽ���������
//	{
//		ps->a[end + 1] = ps->a[end];
//		end--;
//	}
//  /*Ҳ����ʹ��memmoveʵ��*/
//	ps->a[0] = x;
//	ps->size++;
//}

//void SeqListPushFront(SL* ps, SLDataType x)//9��
//{
//	assert(ps);
//	SeqListCheckCapacity(ps);
//	//�����һ�����ݿ�ʼ�����ν�ÿ�����������ƶ�������ӵ�һ�����ݿ�ʼ�����ƶ����������ָ��Ǻ��������
//	int end = ps->size - 1;//�±꣬����һ��ָ�����һ�����ݵ�λ��
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
	SeqListInsert(ps, 0, x);//��ֵ����
}

//10��ͷɾ
//void SeqListPopFront(SL* ps)
//{
//  assert(ps);//����ָ��Ϊ�գ��򱨴�
//	assert(ps->size > 0);//��������Ϊ��ɾ�����򱨴�
//	//�ӵڶ������ݿ�ʼ�����ν�ÿ��������ǰ�ƶ�
//	int start = 0;//�±꣬����һ��ָ���һ�����ݵ�λ��
//	while (start < ps->size-1)//ע����������start <= ps->size-2
//	{
//		ps->a[start] = ps->a[start + 1];//���±��һ��λ�õ�������ǰŲ
//		start++;
//	}
//	/*
//	int start = 1;//�±꣬����һ��ָ��ڶ������ݵ�λ��
//	while (start < ps->size)//ע����������start <= ps->size-1
//	{
//		ps->a[start - 1] = ps->a[start];//���±굱ǰλ�õ�������ǰŲ
//		start++;
//	}
//	*/
//  /*Ҳ����ʹ��memmoveʵ��*/
// 
//	//���һ��������Ϊ0��Ҳ���Բ���Ҫ����ps->a[ps->size] = 0;
//	//ps->a[ps->size] = 0;
//	ps->size--;
//}

void SeqListPopFront(SL* ps)//17��
{
	//���ϴ����൱�ڣ��ڵ�һ��0λ��ɾ��
	SeqListErase(ps, 0);//��ֵ����
}

//12�������±�Ϊpos��λ�ò��� - ������posǰ��
void SeqListInsert(SL* ps, int pos, SLDataType x)
{
	//�ڸ�����posλ�ã������һ�����ݿ�ʼ�����ν�ÿ�����������ƶ����ж��Ƿ�����
	//1����������
	assert(ps);//Ϊ�治ִ��
	assert(pos <= ps->size && pos >= 0);//�±�λ������Ч�ģ���0 <= pos <= size
	//ע��pos���±꣬ԭ���±겻�ܳ���ps->size-1�����ڿ��������һ��λ��β�壬�����±����Ϊsize
	//2�����ᴦ��
	/*
	if(pos > ps->size || pos < 0)//������size�±괦����
	{
		printf("pos invalid\n");//���ﲻ��ʹ��perror��C��������ʧ�ܣ��ſ���ʹ��perror
		return;
	}
	*/

	//�ж�����
	SeqListCheckCapacity(ps);
	int end = ps->size - 1;//�±�
	while (end >= pos)//д�����������������������
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[pos] = x;
	ps->size++;
	//��pos = sizeʱ�൱��β��
	//��pos = 0ʱ�൱��ͷ��
}

//13������λ��ɾ�� - ɾ���±�pos��������
void SeqListErase(SL* ps, int pos)
{
	//�ڸ�����posλ�ã�����λ�ú�����ݿ�ʼ�����ν�ÿ��������ǰ�ƶ�
	assert(ps);
	assert(pos < ps->size && pos >= 0);//��ʹ��size_t posʱ�����Ϊunsigned int���Բ�Ҫ���pos >= 0
	//ע�⣺pos���±꣬�±겻�ܳ���ps->size-1
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
	//��pos = size - 1ʱ�൱��βɾ
	//��pos = 0ʱ�൱��ͷɾ
}

//18��˳������
int SeqListFind(SL* ps, SLDataType x)//�����ҵ��������±�
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

//19��˳����޸� - �޸�pos�±�λ�õ�����
void SeqListModify(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos < ps->size && pos >= 0);
	ps->a[pos] = x;
}