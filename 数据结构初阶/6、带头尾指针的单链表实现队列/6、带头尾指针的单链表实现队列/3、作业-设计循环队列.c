#define _CRT_SECURE_NO_WARNINGS 1
//设计你的循环队列实现。循环队列是一种线性数据结构，
//其操作表现基于FIFO(先进先出)原则并且队尾被连接在队首之后以形成一个循环。
//它也被称为“环形缓冲器”。

//循环队列的一个好处是我们可以利用这个队列之前用过的空间。
//在一个普通队列里，一旦一个队列满了，我们就不能插入下一个元素，即使在队列前面仍有空间。
//但是使用循环队列, 我们能使用这些空间去存储新的值。

//你的实现应该支持如下操作:
//MyCircularQueue(k) :构造器, 设置队列长度为k。
//Front:从队首获取元素。如果队列为空，返回-1。
//Rear:获取队尾元素。如果队列为空,返回-1。
//enQueue(value):向循环队列插入一个元素。如果成功插入则返回真。
//deQueue() :从循环队列中删除一个元素。 如果成功删除则返回真。
//isEmpty() :检查循环队列是否为空。
//isFul1() :检查循环队列是否已满。

//循环队列的特性：1、符合先进先出	2、空间大小是固定的
//重点:循环队列，无论使用数组实现还是链表实现，都要多开一个空间，
//如果是数组也就意味着，要是一个存k个数据的循环队列, 要开k + 1个空间否则无法实现判空和判满。
//如果是链表也就意味着，要是一个存k个数据的循环队列, 要开k + 1个结点否则无法实现判空和判满。(链表结点必须开辟好)
//因为初始时front == tail可以确定为空，但下一次当front == tail时到底是空还是满，有歧义。

//循环队列，可以用数组实现，通过下标控制。
//也可以用链表实现，即循环链表。
//1、当用数组实现时，下标front == tail表示空，(tail+1)%(K+1) == front表示满
//2、当用数组实现时，指针front == tail表示空，tail->next == front表示满

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef struct {
	int* a;//利用指针维护的数组队列
	int front;//队头下标
	int tail;//队尾下标
	int k;//队列容量
}MyCircularQueue;

bool myCircularQueueIsEmpty(MyCircularQueue* obj);

bool myCircularQueueIsFull(MyCircularQueue* obj);

MyCircularQueue* myCircularQueueCreate(int k)
{
	MyCircularQueue* cq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	if (cq == NULL)
		return NULL;
	cq->a = (int*)malloc(sizeof(int) * (k + 1));//多开一个空间，区分空和满
	cq->front = cq->tail = 0;
	cq->k = k;

	return cq;
}

//入队列
//入队列成功，返回真，没有成功(队列满了)，返回假
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value)
{
	if (myCircularQueueIsFull(obj))
	{
		return false;
	}

	obj->a[obj->tail] = value;
	++obj->tail;
	obj->tail %= (obj->k + 1);//当插入的次数超过4次，也就是下标大于k,下标就需要重新回归
	//注意：可以不需要if判断
	return true;
}

//出队列
//出队列成功，返回真，没有成功(队列为空)，返回假
bool myCircularQueueDeQueue(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
	{
		return false;
	}

	++obj->front;
	obj->front %= (obj->k + 1);//当删除的次数超过4次，也就是下标大于k,下标就需要重新回归
	//注意：可以不需要if判断
	return true;
}

//返回队头元素
//当队列为空，返回-1。否则返回队头数据。
int myCircularQueueFront(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
	{
		return -1;
	}
	return obj->a[obj->front];
}

//返回队尾元素
//当队列为空，返回-1。否则返回队尾数据。
int myCircularQueueRear(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
	{
		return -1;
	}
	//注意：返回队尾下标的前一个数据

	//方法1
	/*
	if (obj->tail == 0)//当队尾下标为0，则前一个数据是下标为k的值
	{
		return obj->a[obj->k];
	}
	else
	{
		return obj->a[obj->tail - 1];
	}
	*/

	//方法2
	int i = (obj->tail + obj->k) % (obj->k + 1);//获取真实下标
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

#if 0
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
#endif