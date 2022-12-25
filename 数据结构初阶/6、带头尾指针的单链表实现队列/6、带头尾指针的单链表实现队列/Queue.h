#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int QDataType;
typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;

}QueueNode;

typedef struct Queue
{
	QueueNode* head;//头指针
	QueueNode* tail;//尾指针
	//注意：利用头尾指针维护队列。所以通过Queue变量的地址就能操作里面的内容，也就能操作队列。
}Queue;

void QueueInit(Queue* pq);
//如果不定义Queue结构体，则Queue* pq的head和tail由QueueNode** pphead, QueueNode** pptail实现
//void QueueInit(QueueNode** pphead, QueueNode** pptail);
//注意：如果形参是结构体，则实参传结构体地址。如果形参是二级指针，则实参传一级指针的地址。

void QueueDestroy(Queue* pq);

//1、头作队头，尾作队尾 头删出队尾插入队，头删时间复杂度为O(1)，尾插时间复杂度为O(1)，适合
//2、头做队尾，尾作对头 尾删出队头插入队，尾删时间复杂度为O(1)，头插时间复杂度为O(1)，适合
//注意：这里使用第一种方式。且不需要哨兵位结点。

//队尾入
void QueuePush(Queue* pq, QDataType x);
//队头出
void QueuePop(Queue* pq);
//获取队头数据
QDataType QueueFront(Queue* pq);
//获取队尾数据
QDataType QueueBack(Queue* pq);

int QueueSize(Queue* pq);

bool QueueEmpty(Queue* pq);