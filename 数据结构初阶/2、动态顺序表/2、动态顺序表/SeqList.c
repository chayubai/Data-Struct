#define _CRT_SECURE_NO_WARNINGS 1
//顺序表

//注意：函数的参数设计，是根据自己具体要实现什么功能而设计的。

#include "SeqList.h"
//1、初始化
//传值调用
//void SeqListInit(SL s)
//{
//	/*
//	//方法一：
//	s.size = 0;
//	s.a = NULL;
//	s.capacity = 0;//由于a指向的空间没有，容量即为0
//	*/
//
//	//方法二：
//	s.a = (SLDataType*)malloc(sizeof(SLDataType) * 4);//开辟四个SLDataType类型的空间大小
//	if (s.a == NULL)
//	{
//		printf("申请内存失败\n");
//		exit(-1);//结束程序
//	}
//	s.size = 0;
//	s.capacity = 4;//容量为存储类型的个数
//}

//传址调用
void SeqListInit(SL* ps)
{
	//方法1：
	/*
	ps->size = 0;
	ps->a = NULL;
	ps->capacity = 0;//由于a指向的空间没有，容量即为0
	*/

	//方法2：
	ps->a = (SLDataType*)malloc(sizeof(SLDataType) * 4);//一开始就开辟4个连续大小的空间
	if (ps->a == NULL)
	{
		printf("申请内存失败\n");
		exit(-1);
	}
	ps->size = 0;
	ps->capacity = 4;
}

//11、空间销毁
void SeqListDestory(SL* ps)
{
	free(ps->a);//释放空间，即释放ps所指向的空间a
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}

//3、打印
void SeqListPrint(SL* ps)//这里传结构体也可以，但传指针效率更好
{
	assert(ps);//断言指针为空，则报错
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

//7、检查容量是否要扩容
//当使用第一种方法初始化时：
/*
void SeqListCheckCapacity(SL* ps)
{
	assert(ps);
	//判断是否容量满了，如果满了需要增容
	if (ps->size == ps->capacity)//没有空间或空间满了
	{
		//SLDataType* tmp = (SLDataType*)realloc(ps->a, sizeof(SLDataType) * ps->capacity * 2);
		//不能直接开辟空间，由于初始化capacity=0，当ps->capacity *= 2;相当于capacity  = 0 * 2 = 0

		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType* tmp = (SLDataType*)realloc(ps->a, sizeof(SLDataType) * newcapacity);
		if (tmp == NULL)
		{
			printf("扩容失败\n");
			exit(-1);//暴力结束，退出程序。return -1是退出当前函数，不会终止程序。
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
void SeqListCheckCapacity(SL* ps)//传值调用
{
	//判断是否容量满了，如果满了需要增容
	if (ps->size == ps->capacity)
	{
		ps->capacity *= 2;//每次增加容量的2倍，，防止频繁增容
		SLDataType* tmp = (SLDataType*)realloc(ps->a, sizeof(SLDataType) * ps->capacity);
		if (ps->a == NULL)
		{
			printf("扩容失败\n");
			exit(-1);//暴力结束
		}
		ps->a = tmp;
	}
}

//2、尾插 - size既是数据的个数，也是最后一个数据的下一个数据的下标
//void SeqListPushBack(SL* ps, SLDataType x)//2、
//{
//	assert(ps);//断言指针为空，则报错
//	ps->a[ps->size] = x;
//	ps->size++;
//}

//当使用第一种方法初始化时：
/*
void SeqListPushBack(SL* ps, SLDataType x)
{
	assert(ps);//断言指针为空，则报错
	//判断是否容量满了，如果满了需要增容
	if (ps->size == ps->capacity)
	{
		//SLDataType* tmp = (SLDataType*)realloc(ps->a, sizeof(SLDataType) * ps->capacity * 2);
		//不能直接开辟空间，由于初始化capacity=0，当ps->capacity *= 2;相当于capacity  = 0 * 2 = 0

		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType* tmp = (SLDataType*)realloc(ps->a, sizeof(SLDataType) * newcapacity);
		if (tmp == NULL)
		{
			printf("扩容失败\n");
			exit(-1);//暴力结束
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

//void SeqListPushBack(SL* ps, SLDataType x)//4、
//{
//	assert(ps);//断言指针为空，则报错
//	//判断是否容量满了，如果满了需要增容
//	if (ps->size == ps->capacity)
//	{
//		ps->capacity *= 2;//每次增加容量的2倍，，防止频繁增容
//		SLDataType* tmp = (SLDataType*)realloc(ps->a, sizeof(SLDataType) * ps->capacity);
//		if (ps->a == NULL)
//		{
//			printf("扩容失败\n");
//			exit(-1);//暴力结束
//		}
//		ps->a = tmp;
//	}
//	ps->a[ps->size] = x;
//	ps->size++;
//}

//void SeqListPushBack(SL* ps, SLDataType x)//8、
//{
//	assert(ps);
//	SeqListCheckCapacity(ps);//传值调用，void SeqListCheckCapacity(SL* ps)形参ps和SeqListCheckCapacity(ps)的实参ps都指向SeqList s;
//	ps->a[ps->size] = x;
//	ps->size++;
//}

void SeqListPushBack(SL* ps, SLDataType x)//14、
{
	//以上代码相当于，在最后一个size位置插入x
	SeqListInsert(ps, ps->size, x);//传值调用
}

//5、尾删
//void SeqListPopBack(SL* ps)//5、
//{
//  //assert(ps);//断言指针为空，则报错
//  //断言size有效性，方法一：
//	//assert(ps->size > 0);//断言数据为空删除，则报错
//	//将最后一个数据置为0，即删除，但是缺点是，对于此处数据本身是0，就没有意义
//	//对于删除数据本质没有删除真正删除。故一般删数据，只需要--即可。即不需要这一行ps->a[ps->size - 1] = 0;	
//	//ps->a[ps->size - 1] = 0;
// 
//  //断言size有效性，方法二：防止删除空数组
//	if(ps->size > 0)
//	{
//		ps->size--;	//直接将数据个数减少，从而不打印即为删除
//	}
//}

void SeqListPopBack(SL* ps)//16、
{
	//以上代码相当于，在最后一个size位置删除
	SeqListErase(ps, ps->size - 1);//传值调用
}

//6、头插
//void SeqListPushFront(SL* ps, SLDataType x)//6、
//{
//	assert(ps);//断言指针为空，则报错
//  //也需要判断容量是否满了，可以将该功能封装成一个函数
// 
//	//从最后一个数据开始，依次将每个数据往后移动，如果从第一个数据开始依次移动，否则会出现覆盖后面的数据
//	int end = ps->size - 1;//下标，定义一个指向最后一个数据的位置
//	while (end >= 0)//注意条件，循环写的是继续的条件，想的是结束的条件
//	{
//		ps->a[end + 1] = ps->a[end];
//		end--;
//	}
//  /*也可以使用memmove实现*/
//	ps->a[0] = x;
//	ps->size++;
//}

//void SeqListPushFront(SL* ps, SLDataType x)//9、
//{
//	assert(ps);
//	SeqListCheckCapacity(ps);
//	//从最后一个数据开始，依次将每个数据往后移动，如果从第一个数据开始依次移动，否则会出现覆盖后面的数据
//	int end = ps->size - 1;//下标，定义一个指向最后一个数据的位置
//	while (end >= 0)//注意条件，循环写的是继续的条件，想的是结束的条件
//	{
//		ps->a[end + 1] = ps->a[end];
//		end--;
//	}
//	ps->a[0] = x;
//	ps->size++;
//}

void SeqListPushFront(SL* ps, SLDataType x)//15、
{
	//以上代码相当于，在第一个0位置插入x
	SeqListInsert(ps, 0, x);//传值调用
}

//10、头删
//void SeqListPopFront(SL* ps)
//{
//  assert(ps);//断言指针为空，则报错
//	assert(ps->size > 0);//断言数据为空删除，则报错
//	//从第二个数据开始，依次将每个数据往前移动
//	int start = 0;//下标，定义一个指向第一个数据的位置
//	while (start < ps->size-1)//注意条件，即start <= ps->size-2
//	{
//		ps->a[start] = ps->a[start + 1];//把下标后一个位置的数据往前挪
//		start++;
//	}
//	/*
//	int start = 1;//下标，定义一个指向第二个数据的位置
//	while (start < ps->size)//注意条件，即start <= ps->size-1
//	{
//		ps->a[start - 1] = ps->a[start];//把下标当前位置的数据往前挪
//		start++;
//	}
//	*/
//  /*也可以使用memmove实现*/
// 
//	//最后一个数，置为0，也可以不需要此行ps->a[ps->size] = 0;
//	//ps->a[ps->size] = 0;
//	ps->size--;
//}

void SeqListPopFront(SL* ps)//17、
{
	//以上代码相当于，在第一个0位置删除
	SeqListErase(ps, 0);//传值调用
}

//12、任意下标为pos的位置插入 - 插入在pos前面
void SeqListInsert(SL* ps, int pos, SLDataType x)
{
	//在给出的pos位置，从最后一个数据开始，依次将每个数据往后移动，判断是否扩容
	//1、暴力处理
	assert(ps);//为真不执行
	assert(pos <= ps->size && pos >= 0);//下标位置是有效的，即0 <= pos <= size
	//注意pos是下标，原本下标不能超过ps->size-1，由于可以在最后一个位置尾插，所以下标可以为size
	//2、温柔处理
	/*
	if(pos > ps->size || pos < 0)//可以在size下标处插入
	{
		printf("pos invalid\n");//这里不能使用perror，C函数调用失败，才可以使用perror
		return;
	}
	*/

	//判断扩容
	SeqListCheckCapacity(ps);
	int end = ps->size - 1;//下标
	while (end >= pos)//写继续的条件，想结束的条件
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[pos] = x;
	ps->size++;
	//当pos = size时相当于尾插
	//当pos = 0时相当于头插
}

//13、任意位置删除 - 删除下标pos处的数据
void SeqListErase(SL* ps, int pos)
{
	//在给出的pos位置，将该位置后的数据开始，依次将每个数据往前移动
	assert(ps);
	assert(pos < ps->size && pos >= 0);//当使用size_t pos时，如果为unsigned int可以不要检查pos >= 0
	//注意：pos是下标，下标不能超过ps->size-1
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
	//当pos = size - 1时相当于尾删
	//当pos = 0时相当于头删
}

//18、顺序表查找
int SeqListFind(SL* ps, SLDataType x)//返回找到的数的下标
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

//19、顺序表修改 - 修改pos下标位置的数据
void SeqListModify(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos < ps->size && pos >= 0);
	ps->a[pos] = x;
}