#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"
//数组栈初始化
//void StackInit(ST* ps)//形参不会影响实参，传实参的地址，形参就能改变实参
//{
//	assert(ps);
//	ps->a = NULL;
//	ps->top = 0;//初始top = 0，表示top指向栈顶数据的下一个，即先放数据再++。初始top = -1.表示top指向栈顶数据，即先++再放数据
//	ps->capacity = 0;
//}

void StackInit(ST* ps)//形参不会影响实参，传实参的地址，形参就能改变实参
{
	assert(ps);
	ps->a = (STDataType*)malloc(sizeof(STDataType)*4);
	if (ps->a == NULL)
	{
		printf("malloc failed\n");
		exit(-1);
	}
	ps->top = 0;//top = 0，表示top指向栈顶数据的下一个，即先放数据再++。top = -1.表示top指向栈顶数据，即先++再放数据
	ps->capacity = 4;
}
//数组栈的插入
//void StackPush(ST* ps, STDataType x)
//{
//	assert(ps);
//	if (ps->top == ps->capacity)
//	{
//		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
//		STDataType* tmp = realloc(ps->a, sizeof(STDataType) * newCapacity);
//		if (tmp == NULL)
//		{
//			printf("realloc failed\n");
//			exit(-1);
//		}
//		ps->a = tmp;
//		ps->capacity = newCapacity;
//	}
//	ps->a[ps->top] = x;
//	ps->top++;
//}

void StackPush(ST* ps, STDataType x)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		STDataType* tmp = realloc(ps->a, sizeof(STDataType) * (ps->capacity * 2));
		if (tmp == NULL)
		{
			printf("realloc failed\n");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = ps->capacity * 2;
	}
	ps->a[ps->top] = x;
	ps->top++;
}

//数组栈销毁
void StackDestroy(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}

//数组栈的删除
void StackPop(ST* ps)
{
	assert(ps);
	//栈空了，调用pop直接中止程序报错
	//assert(ps->top > 0);相当于assert(!StackEmpty(ps));
	assert(!StackEmpty(ps));
	ps->top--;
}

//栈顶的数据
STDataType StackTop(ST* ps)
{
	assert(ps);
	//assert(ps->top > 0);相当于assert(!StackEmpty(ps));
	assert(!StackEmpty(ps));
	return ps->a[ps->top - 1];
}

//数组栈的大小
int StackSize(ST* ps)
{
	assert(ps);
	return ps->top;//top既是栈的栈顶的下标的前一个，也是栈的大小
}
//判断栈是否为空
bool StackEmpty(ST* ps)
{
	assert(ps);
	/*if (ps->top == 0)
	{
		return true;
	}
	else
	{
		return false;
	}*/
	return ps->top == 0;
}