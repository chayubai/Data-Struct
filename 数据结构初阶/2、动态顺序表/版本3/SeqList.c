#include "SeqList.h"
//1、初始化
void SeqListInit(SL* ps)
{
	ps->a = (SLDataType*)malloc(sizeof(SLDataType) * 4);//一开始就开辟4个连续大小的空间
	if (ps->a == NULL)
	{
		printf("申请内存失败\n");
		exit(-1);
	}
	ps->size = 0;
	ps->capacity = 4;
}

//2、尾插
void SeqListPushBack(SL* ps, SLDataType x)
{
    assert(ps);//断言指针为空，则报错
    SeqListCheckCapacity(ps);
    ps->a[ps->size] = x;
    ps->size++;
}

//3、打印
void SeqListPrint(SL* ps)//这里串结构体也可以，但传指针效率更好
{
    assert(ps);//断言指针为空，则报错
    for(int i = 0;i < ps->size;i++)
    {
        printf("%d ",ps->a[i]);
    }
    printf("\n");
}

//4、尾删
void SeqListPopBack(SL* ps)
{
    assert(ps);//断言指针为空，则报错
	assert(ps->size > 0);//断言数据为空删除，则报错
    ps->size--;
}

//6、检查容量是否要扩容
void SeqListCheckCapacity(SL* ps)
{
    assert(ps);//断言指针为空，则报错
    //增容
    if(ps->size == ps->capacity)
    {
        ps->capacity *= 2;
        ps->a = (SLDataType*)realloc(ps->a,sizeof(SLDataType)*ps->capacity);
        if(ps->a == NULL)
        {
            printf("扩容失败\n");
            exit(-1);
        }
    }
}

//5、头插
void SeqListPushFront(SL* ps, SLDataType x)
{
    assert(ps);//断言指针为空，则报错
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

//7、头删
void SeqListPopFront(SL* ps)
{
    assert(ps);
    assert(ps->size>0);//断言数据为空删除，则报错
    int start = 0;
    while(start < ps->size-1)
    {
        ps->a[start] = ps->a[start+1];
        start++;
    }
    ps->size--;
}

//11、空间销毁
void SeqListDestory(SL* ps)
{
    assert(ps);
    free(ps->a);//释放空间，即释放ps所指向的空间a
    ps->a = NULL;
    ps->size = ps->capacity = 0;
}

//8、任意下标为pos的位置插入
void SeqListInsert(SL* ps, int pos, SLDataType x)
{
    assert(ps);
    assert(pos >= 0 && pos <= ps->size);//断言位置有效性
    SeqListCheckCapacity(ps);
    int end = ps->size - 1;
    while(end >= pos)
    {
        ps->a[end+1] = ps->a[end];
        end--;
    }
    ps->a[pos] = x;
    ps->size++;
    //当pos = size时相当于尾插
    //当pos = 0时相当于头插
}

//9、任意位置删除
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
    //当pos = size时相当于尾删
    //当pos = 0时相当于头删
}

//10、顺序表查找
int SeqListFind(SL* psl, SLDataType x)//返回找到的数的下标
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
