#include "SeqList.h"
//1����ʼ��
void SeqListInit(SL* ps)
{
	ps->a = (SLDataType*)malloc(sizeof(SLDataType) * 4);//һ��ʼ�Ϳ���4��������С�Ŀռ�
	if (ps->a == NULL)
	{
		printf("�����ڴ�ʧ��\n");
		exit(-1);
	}
	ps->size = 0;
	ps->capacity = 4;
}

//2��β��
void SeqListPushBack(SL* ps, SLDataType x)
{
    assert(ps);//����ָ��Ϊ�գ��򱨴�
    SeqListCheckCapacity(ps);
    ps->a[ps->size] = x;
    ps->size++;
}

//3����ӡ
void SeqListPrint(SL* ps)//���ﴮ�ṹ��Ҳ���ԣ�����ָ��Ч�ʸ���
{
    assert(ps);//����ָ��Ϊ�գ��򱨴�
    for(int i = 0;i < ps->size;i++)
    {
        printf("%d ",ps->a[i]);
    }
    printf("\n");
}

//4��βɾ
void SeqListPopBack(SL* ps)
{
    assert(ps);//����ָ��Ϊ�գ��򱨴�
	assert(ps->size > 0);//��������Ϊ��ɾ�����򱨴�
    ps->size--;
}

//6����������Ƿ�Ҫ����
void SeqListCheckCapacity(SL* ps)
{
    assert(ps);//����ָ��Ϊ�գ��򱨴�
    //����
    if(ps->size == ps->capacity)
    {
        ps->capacity *= 2;
        ps->a = (SLDataType*)realloc(ps->a,sizeof(SLDataType)*ps->capacity);
        if(ps->a == NULL)
        {
            printf("����ʧ��\n");
            exit(-1);
        }
    }
}

//5��ͷ��
void SeqListPushFront(SL* ps, SLDataType x)
{
    assert(ps);//����ָ��Ϊ�գ��򱨴�
    SeqListCheckCapacity(ps);
    int end = ps->size - 1;
    while(end >= 0)
    {
        ps->a[end+1] = ps->a[end];
        end--;
    }
    ps->a[0] = x;
    ps->size++;
}

//7��ͷɾ
void SeqListPopFront(SL* ps)
{
    assert(ps);
    assert(ps->size>0);//��������Ϊ��ɾ�����򱨴�
    int start = 0;
    while(start < ps->size-1)
    {
        ps->a[start] = ps->a[start+1];
        start++;
    }
    ps->size--;
}

//11���ռ�����
void SeqListDestory(SL* ps)
{
    assert(ps);
    free(ps->a);//�ͷſռ䣬���ͷ�ps��ָ��Ŀռ�a
    ps->a = NULL;
    ps->size = ps->capacity = 0;
}

//8�������±�Ϊpos��λ�ò���
void SeqListInsert(SL* ps, int pos, SLDataType x)
{
    assert(ps);
    assert(pos >= 0 && pos <= ps->size);//����λ����Ч��
    SeqListCheckCapacity(ps);
    int end = ps->size - 1;
    while(end >= pos)
    {
        ps->a[end+1] = ps->a[end];
        end--;
    }
    ps->a[pos] = x;
    ps->size++;
    //��pos = sizeʱ�൱��β��
    //��pos = 0ʱ�൱��ͷ��
}

//9������λ��ɾ��
void SeqListErase(SL* ps, int pos)
{
    assert(ps);
    assert(pos >= 0 && pos <= ps->size);
    int start = pos;
    while(start < ps->size - 1)
    {
        ps->a[start] = ps->a[start+1];
        start++;
    }
    ps->size--;
    //��pos = sizeʱ�൱��βɾ
    //��pos = 0ʱ�൱��ͷɾ
}

//10��˳������
int SeqListFind(SL* psl, SLDataType x)//�����ҵ��������±�
{
    assert(psl);
    int i = 0;
    while(i < psl->size)
    {
       if(psl->a[i] == x)
       {
           return i;
       }
       i++;
    }
    return -1;

}
