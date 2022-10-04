#define _CRT_SECURE_NO_WARNINGS 1
//请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部操作（push、top、pop、empty）
//实现MyStack类：
//void push(int x)将元素x压入栈顶
//int pop()移出并返回栈顶元素
//int top()返回栈顶元素
//boolean empty()如果栈是空的，返回true，否则返回false

//思路：
//队列A: 1 2 3 4
//队列B: 空

//队列A: 4    ---pop
//队列B: 1 2 3

//队列A:     
//队列B: 1 2 3

//队列A: 1 2     
//队列B: 3    ---pop

//队列A: 1 2     
//队列B: 
//即：来回倒，出最后一个数
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef int QDataType;
typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;

}QueueNode;

typedef struct Queue
{
	QueueNode* head;
	QueueNode* tail;

}Queue;

void QueueInit(Queue* pq);
//如果不定义Queue结构体，则Queue* pq的由QueueNode** pphead, QueueNode** pptail实现
//void QueueInit(QueueNode** pphead, QueueNode** pptail);

void QueueDestroy(Queue* pq);
void QueuePush(Queue* pq, QDataType x);
void QueuePop(Queue* pq);
QDataType QueueFront(Queue* pq);
QDataType QueueBack(Queue* pq);
int QueueSize(Queue* pq);
bool QueueEmpty(Queue* pq);

void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = NULL;
	pq->tail = NULL;
}

void QueueDestroy(Queue* pq)
{
	assert(pq);
	QueueNode* cur = pq->head;
	while (cur != NULL)
	{
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = NULL;
	pq->tail = NULL;
}

void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	newnode->data = x;
	newnode->next = NULL;
	if (pq->head == NULL)
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
}

void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));//注意pq->head为空，解引用
	QueueNode* next = pq->head->next;
	free(pq->head);
	pq->head = next;
	if (pq->head == NULL)
		pq->tail = NULL;
}

QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));//注意pq->head为空，解引用
	return pq->head->data;
}

QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));//注意pq->tail为空，解引用
	return pq->tail->data;
}

int QueueSize(Queue* pq)
{
	assert(pq);
	int n = 0;
	QueueNode* cur = pq->head;
	while (cur != NULL)
	{
		++n;
		cur = cur->next;
	}
	return n;

	//或者在Queue结构体加一个size变量，在Push或者Pop函数中，++或--
	//return pq->size;
}

bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL;
}

//匿名结构体名称为MyStack
typedef struct {
	Queue q1;
	Queue q2;
}MyStack;

//匿名结构体的变量为MyStack
//struct {
//
//}MyStack;

MyStack* myStackCreate()
{
	/*MyStack st;
	return &st;
	//st为局部变量，出了作用域，&st变成野指针
	*/

	MyStack* st = (MyStack*)malloc(sizeof(MyStack));

	//栈由两个队列q1和q2组成，q1和q2是由链表组成
	QueueInit(&st->q1);
	QueueInit(&st->q2);

	return st;
}

//1、入数据，往不为空的队列入
//2、出数据，把不为空的数据倒入到空的队列，直到只剩最后一个数据，然后出数据
void myStackPush(MyStack* obj, int x)
{
	if (!QueueEmpty(&obj->q1))
	{
		QueuePush(&obj->q1,x);
	}
	else
	{
		QueuePush(&obj->q2, x);
	}
}
int myStackPop(MyStack* obj)
{
	//假设q1为空，q2不为空
	Queue* emptyQ = &obj->q1;
	Queue* noneemptyQ = &obj->q2;
	//如果q1不为空，纠正
	if (!QueueEmpty(&obj->q1))
	{
		emptyQ = &obj->q2;
		noneemptyQ = &obj->q1;
	}
	//2、出数据，把不为空的数据倒入到空的队列，直到只剩最后一个数据，然后出数据
	while (QueueSize(noneemptyQ) > 1)
	{
		QueuePush(emptyQ, QueueFront(noneemptyQ));
		QueuePop(noneemptyQ);
	}
	int top = QueueFront(noneemptyQ);
	//最后一个数据top需要pop
	QueuePop(noneemptyQ);

	return top;
}
int myStackTop(MyStack* obj)
{
	if (!QueueEmpty(&obj->q1))
	{
		return QueueBack(&obj->q1);
	}
	else
		return QueueBack(&obj->q2);
}
bool myStackEmpty(MyStack* obj)
{
	return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

void myStackFree(MyStack* obj)
{
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
//int main()
//{
//	MyStack* st = myStackCreate();
//
//	myStackPush(st, 1);
//	myStackPush(st, 2);
//	myStackPush(st, 3);
//	myStackPush(st, 4);
//
//	while (!myStackEmpty(st))
//	{
//		int top = myStackTop(st);
//		printf("%d ", top);
//		myStackPop(st);
//	}
//
//	myStackFree(st);
//	return 0;
//}

