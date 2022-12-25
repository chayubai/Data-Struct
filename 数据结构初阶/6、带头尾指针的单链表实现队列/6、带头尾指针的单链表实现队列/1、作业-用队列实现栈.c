#define _CRT_SECURE_NO_WARNINGS 1
//请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部操作（push、top、pop、empty）
//实现MyStack类：
//void push(int x)将元素x压入栈顶
//int pop()移出并返回栈顶元素
//int top()返回栈顶元素
//boolean empty()如果栈是空的，返回true，否则返回false

//队列是先进先出
//栈  是后进先出

//核心思路思路：符合后进先出
//假设A和B队列，入了1234，如何使得先出4？
//1、入数据，往不为空的队列中，入数据，保持另一个队列为空
//2、出数据的时候，依次出队头的数据，转移(队列入数据)到另一个队列中保存。只剩最后一个数据时，pop掉。
//也就是说，出数据的时候，将前n-1个数据转移到为空的队列中。
//就能实现后进先出的规则。

//假设：先1 2 3 4入A中，再pop掉1 2 3放入到B中。最后再pop掉4。
//如果要入数据，再向不为空的B中入5 6。再pop掉1 2 3 5放入到A中,最后再pop掉6。
//队列A: 1 2 3 4  ---push
//队列B: 空

//队列A: 4    ---pop
//队列B: 1 2 3

//队列A: 空    
//队列B: 1 2 3

//队列A: 1 2     
//队列B: 3    ---pop

//队列A: 1 2     
//队列B: 空

//队列A: 1 2 5 6   ---push
//队列B: 空

//队列A: 6    ---pop
//队列B: 1 2 5
//即：来回倒，出最后一个数

#include "Queue.h"

//匿名结构体名称为MyStack
typedef struct {
	Queue q1;
	Queue q2;
}MyStack;

//匿名结构体的变量为MyStack
//struct {
//
//}MyStack;

//返回栈的指针
MyStack* myStackCreate()
{
	/*
	MyStack st;
	return &st;//不能返回局部变量的地址
	//st为局部变量，出了作用域，&st变成野指针
	*/

	MyStack* st = (MyStack*)malloc(sizeof(MyStack));
	if (st == NULL)
		return NULL;
	//栈由两个队列q1和q2组成，q1和q2是由链表组成
	QueueInit(&st->q1);//->优先级高于&
	QueueInit(&st->q2);

	return st;
}

//1、入数据，往不为空的队列入。如果两个都为空，往哪个队列中push都可以。
//2、出数据，把不为空的队头数据依次导入到空的队列，直到只剩最后一个数据，然后出数据
void myStackPush(MyStack* obj, int x)
{
	assert(obj);
	if (!QueueEmpty(&obj->q1))
	{
		QueuePush(&obj->q1,x);
	}
	else//这里是q1为空，q2可能为空，可能不为空。
	{//q2为空，入q1、q2都可以，q2不为空，入q2
		QueuePush(&obj->q2, x);
	}
}

//移出并返回栈顶元素
int myStackPop(MyStack* obj)
{
	assert(obj);
	//假设q1为空，q2不为空
	Queue* emptyQ = &obj->q1;
	Queue* noneemptyQ = &obj->q2;
	//如果q1不为空，纠正
	if (!QueueEmpty(&obj->q1))
	{
		emptyQ = &obj->q2;
		noneemptyQ = &obj->q1;
	}
	//2、出数据，把不为空的队头数据依次导入到空的队列，直到只剩最后一个数据，然后出数据
	while (QueueSize(noneemptyQ) > 1)
	{
		QueuePush(emptyQ, QueueFront(noneemptyQ));
		QueuePop(noneemptyQ);
	}
	//注意：如果不为空的队列只有一个元素。不进入循环直接pop掉。
	
	int top = QueueFront(noneemptyQ);//如果两个队列都为空，则QueueFront函数断言，报错
	//最后一个数据top需要pop
	QueuePop(noneemptyQ);

	return top;
}

//返回栈顶元素，取不为空的队列中的队尾数据。
int myStackTop(MyStack* obj)
{
	assert(obj);
	//如果两个队列都为空，则QueueBack函数断言，报错
	
	if (!QueueEmpty(&obj->q1))
	{
		return QueueBack(&obj->q1);
	}
	else//这里是q1为空，q2可能为空，可能不为空。
	{//q2为空，入q1、q2都可以，q2不为空，入q2
		return QueueBack(&obj->q2);
	}
}

bool myStackEmpty(MyStack* obj)
{
	assert(obj);
	//两个队列都为空，则栈为空
	return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

void myStackFree(MyStack* obj)
{
	assert(obj);
	//注意：栈的结构
	QueueDestroy(&obj->q1);
	QueueDestroy(&obj->q2);
	free(obj);
}
//队列是先进先出
//栈  是后进先出
//核心思路：
//1、入数据，往不为空的队列入，保持另一个队列为空
//2、出数据的时候，依次出对头的数据，转移到另一个队列保存，只剩最后一个数据Pop掉
//就能实现后进先出的规则

#if 0
int main()
{
	MyStack* st = myStackCreate();

	myStackPush(st, 1);
	myStackPush(st, 2);
	myStackPush(st, 3);
	myStackPush(st, 4);

	while (!myStackEmpty(st))
	{
		int top = myStackTop(st);
		printf("%d ", top);
		myStackPop(st);
	}

	myStackFree(st);
	return 0;
}
#endif