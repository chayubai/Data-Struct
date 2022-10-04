#define _CRT_SECURE_NO_WARNINGS 1
//设计你的循环队列实现。循环队列是一种线性数据结构，
//其操作表现基于FIFO(先进先出)原则并且队尾被连接在队首之后以形成一个循环。
//它也被称为“环形缓冲器”。

//循环队列的一个好处是我们可以利用这个队列之前用过的空间。
//在一个普通队列里，一旦一个队列满了，我们就不能插入下一个元素，即使在队列前面仍有空间。
//但是使用循环队列, 我们能使用这些空间去存储新的值。


//1、符合先进先出	2、空间大小是固定的
//你的实现应该支持如下操作:
//MyCircularQueue(k) :构造器, 设置队列长度为k。
//Front:从队首获取元素。如果队列为空，返回-1。
//Rear:获取队尾元素。如果队列为空,返回-1。
//enQueue(value):向循环队列插入一个元素。如果成功插入则返回真。
//deQueue() :从循环队列中删除一个元素。 如果成功删除则返回真。
//isEmpty() :检查循环队列是否为空。
//isFul1() :检查循环队列是否已满。
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
typedef struct {
	int* a;
	int front;
	int tail;
	int k;
}MyCircularQueue;
bool myCircularQueueIsEmpty(MyCircularQueue* obj);
bool myCircularQueueIsFull(MyCircularQueue* obj);
MyCircularQueue* myCircularQueueCreate(int k)
{
	MyCircularQueue* cq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	cq->a = (int*)malloc(sizeof(int) * (k + 1));
	cq->front = cq->tail = 0;
	cq->k = k;

	return cq;
}
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value)
{
	if (myCircularQueueIsFull(obj))
	{
		return false;
	}
	obj->a[obj->tail] = value;
	++obj->tail;
	obj->tail %= (obj->k + 1);

	return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
	{
		return false;
	}

	++obj->front;
	obj->front %= (obj->k + 1);

	return true;
}

int myCircularQueueFront(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
	{
		return -1;
	}
	return obj->a[obj->front];
}
int myCircularQueueRear(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
	{
		return -1;
	}

	//方法1
	/*if (obj->tail == 0)
	{
		return obj->a[obj->k];
	}
	else
	{
		return obj->a[obj->tail - 1];
	}*/
	//方法2
	int i = (obj->tail + obj->k) % (obj->k + 1);
	return obj->a[i];
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj)
{
	return obj->front == obj->tail;
}

bool myCircularQueueIsFull(MyCircularQueue* obj)
{
	return (obj->tail + 1) % (obj->k + 1) == obj->front;
}

void myCircularQueueFree(MyCircularQueue* obj)
{
	free(obj->a);
	free(obj);
}

int main()
{
	MyCircularQueue* cq = myCircularQueueCreate(4);
	
	myCircularQueueEnQueue(cq, 1);
	myCircularQueueEnQueue(cq, 2);
	myCircularQueueEnQueue(cq, 3);
	myCircularQueueEnQueue(cq, 4);
	
	while (!myCircularQueueIsEmpty(cq))
	{
		int front = myCircularQueueFront(cq);
		printf("%d ", front);
		myCircularQueueDeQueue(cq);
	}
	
	myCircularQueueFree(cq);
	return 0;
}