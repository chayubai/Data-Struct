#define _CRT_SECURE_NO_WARNINGS 1
//请你仅使用两个栈实现一个先入先出的队列，队列应当支持一般队列支持的所有操作（push、peek、pop、empty）
//实现MyQueue类：
//void push(int x)将元素x推入队列的末尾
//int pop()从队列的开头移除并返回元素
//int peek()返回队列开头的元素
//boolean empty()如果队列为空，返回true，否则返回false

//队列是先进先出
//栈  是后进先出

//核心思路：符合先进先出
//假设pushA和popB栈，入了1234，如何使得先出1？
//1、入数据，往pushA栈中，入数据
//2、出数据的候，将pushA栈依次从栈顶出数据，转移(栈入数据)到popB栈中保存，然后往popB栈顶出数据。
//只有当popB栈中所有的数据都出完后，再将pushA栈中的数据转移到popB栈中，继续出数据。

//假设：先1 2 3 4入A中，再pop掉4 3 2 1放入到B中，最后再pop掉1。
//如果要入数据，再向A中入5 6。先出完B中的数据，再pop掉5 6放入到B中,最后再pop掉6。
//栈A: 1 2 3 4  ---push
//栈B: 空

//栈A: 空 
//栈B: 4 3 2 1  ---pop

//栈A: 空    
//栈B: 4 3 2

//栈A: 5 6      ---push
//栈B: 4 3 2    

//栈A: 5 6     
//栈B: 4 3 2    ---pop

//栈A: 5 6      
//栈B: 空

//栈A: 空       
//栈B: 5 6      ---pop

//栈A: 空    
//栈B: 5
//即：

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType* a;//指针a，用来维护数组栈
	int top;//栈顶的位置，即栈顶的下标
	int capacity;//数组栈的容量
}ST;

//数组栈初始化
void StackInit(ST* ps);
//数组栈销毁
void StackDestroy(ST* ps);
//数组栈（顶）的插入
void StackPush(ST* ps, STDataType x);
//数组栈（顶）的删除
void StackPop(ST* ps);
//栈顶的数据
STDataType StackTop(ST* ps);
//数组栈的大小
int StackSize(ST* ps);
//判断栈是否为空
bool StackEmpty(ST* ps);

//数组栈初始化
void StackInit(ST* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->top = 0;//top = 0，表示top指向栈顶数据的下一个，即先放数据再++。top = -1.表示top指向栈顶数据，即先++再放数据
	ps->capacity = 0;
}

//数组栈的插入
void StackPush(ST* ps, STDataType x)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STDataType* tmp = realloc(ps->a, sizeof(STDataType) * newCapacity);
		if (tmp == NULL)
		{
			printf("realloc failed\n");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newCapacity;
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
	//assert(ps->top > 0);
	assert(!StackEmpty(ps));
	ps->top--;
}

//栈顶的数据
STDataType StackTop(ST* ps)
{
	assert(ps);
	//assert(ps->top > 0);
	assert(!StackEmpty(ps));
	return ps->a[ps->top - 1];
}

//数组栈的大小
int StackSize(ST* ps)
{
	assert(ps);
	return ps->top;
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

typedef struct {
	ST pushST;
	ST popST;
}MyQueue;

MyQueue* myQueueCreate()
{
	MyQueue* q = (MyQueue*)malloc(sizeof(MyQueue));
	if (q == NULL)
		return NULL;
	//队列由两个栈pushST和popST组成，pushST和popST是由数组组成
	StackInit(&q->pushST);
	StackInit(&q->popST);

	return q;
}

//1、入数据，往pushA栈中，入数据
//2、出数据的候，将pushA栈依次从栈顶出数据，转移(栈入数据)到popB栈中保存，然后往popB栈顶出数据。
void myQueuePush(MyQueue* obj, int x)
{
	assert(obj);
	//在pushST栈中入数据
	StackPush(&obj->pushST, x);
}

//移出并返回队头元素
int myQueuePop(MyQueue* obj)
{
	assert(obj);	//在popST栈中出数据（出数据时，只有当PopST栈没有数据才从PushST倒过去后，再出数据，因为只有倒过来的数据才符合先进先出的顺序，否则直接在popST中出数据）
	if (StackEmpty(&obj->popST))
	{
		while (!StackEmpty(&obj->pushST))
		{
			StackPush(&obj->popST, StackTop(&obj->pushST));
			StackPop(&obj->pushST);
		}
	}
	
	//popST不为空，直接取数据
	int front = StackTop(&obj->popST);
	StackPop(&obj->popST);

	return front;
}

//返回队头元素
int myQueuePeek(MyQueue* obj)
{
	assert(obj);
	//如果popST中没有数据，将PushST中的数据导过去，再返回popST栈顶数据
	if (StackEmpty(&obj->popST))
	{
		while (!StackEmpty(&obj->pushST))
		{
			StackPush(&obj->popST, StackTop(&obj->pushST));
			StackPop(&obj->pushST);
		}
	}

	//如果popST不为空，直接取栈顶数据
	return StackTop(&obj->popST);
}

bool myQueueEmpty(MyQueue* obj)
{
	assert(obj);
	//两个栈都为空，则队列为空
	return StackEmpty(&obj->popST) && StackEmpty(&obj->pushST);
}

void myQueueFree(MyQueue* obj)
{
	assert(obj);
	//注意：队列的结构
	StackDestroy(&obj->pushST);
	StackDestroy(&obj->popST);
	free(obj);
}
#if 0
int main()
{
	MyQueue* q = myQueueCreate();

	myQueuePush(q, 1);
	myQueuePush(q, 2);
	myQueuePush(q, 3);
	myQueuePush(q, 4);

	while (!myQueueEmpty(q))
	{
		int front = myQueuePeek(q);
		printf("%d ", front);
		myQueuePop(q);
	}

	myQueueFree(q);
	return 0;
}
#endif