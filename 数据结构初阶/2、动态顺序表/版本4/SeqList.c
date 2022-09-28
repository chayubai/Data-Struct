
#define _CRT_SECURE_NO_WARNINGS 1
//顺序表

#include "SeqList.h"
//1、初始化
//传址调用
void SeqListInit(SL* ps)
{
	//方法一：
	ps->size = 0;
	ps->a = NULL;
	ps->capacity = 0;//由于a指向的空间没有，容量即为0
}

//7、检查容量是否要扩容
void SeqListCheckCapacity(SL* ps)
{
	//判断是否容量满了，如果满了需要增容
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity*2;
		SLDataType* tmp = realloc(ps ->a, sizeof(SLDataType) * newcapacity);
		if (tmp == NULL)
		{
			printf("扩容失败\n");
			exit(-1);//暴力结束
		}
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
}

 //2、尾插 - size既是数据的个数，也是最后一个数据的下一个数据的下标
void SeqListPushBack(SL* ps, SLDataType x)
{
    SeqListCheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
}

//3、打印
void SeqListPrint(SL* ps)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

//4、空间销毁
void SeqListDestory(SL* ps)
{
	free(ps->a);//释放空间，即释放ps所指向的空间a
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}

//5、尾删
void SeqListPopBack(SL* ps)
{
	//方法以：防止删除空数组
	/*
    if(ps->size > 0)
    {
        ps->size--;//直接将数据个数减少，从而不打印即为删除
    }
    */
    //方法二：
    assert(ps->size > 0);//断言size有效性
    ps->size--;
}

//6、头插
void SeqListPushFront(SL* ps, SLDataType x)
{
	SeqListCheckCapacity(ps);
	//从最后一个数据开始，依次将每个数据往后移动，如果从第一个数据开始依次移动，否则会出现覆盖后面的数据
	int end = ps->size - 1;//定义一个指向最后一个空间的位置
	while (end >= 0)//注意条件，循环写的是继续的条件，想的是结束的条件
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[0] = x;
	ps->size++;
}

//8、头删
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

//9、任意位置插入
void SeqListInsert(SL* ps, int pos, SLDataType x)
{
	//在给出的位置，从最后一个数据开始，依次将每个数据往后移动，判断是否扩容
	assert(ps);//为真不执行
	assert(pos <= ps->size && pos >= 0);//保持位置是有效的，即0 <= pos <= size

	//判断扩容
	SeqListCheckCapacity(ps);
	int end = ps->size - 1;
	while (end >= pos)//写继续的条件，想结束的条件
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[pos] = x;
	ps->size++;
}

//10、任意位置删除
void SeqListErase(SL* ps, int pos)
{
	//在给出的位置，将该位置后的第二个数据开始，依次将每个数据往前移动
	assert(ps);
	assert(pos <= ps->size&& pos >= 0);//当使用size_t pos时，由于为unsigned int故可以不要检查pos >= 0
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

 //11、顺序表查找
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

//修改
void SeqListModify(SL* ps, int pos,SLDataType x)
{
	assert(ps);
	assert(pos <= ps->size&& pos >= 0);
    ps->a[pos] = x;
}
