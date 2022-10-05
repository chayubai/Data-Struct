#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//typedef BTNode* QDataType;
//前置声明：将typedef BTNode* QDataType;换成以下两句
struct BinaryTreeNode;
typedef struct BinaryTreeNode* QDataType;

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
//如果形参是结构体，则实参传结构体地址。如果形参是二级指针，则实参传一级指针
//void QueueInit(QueueNode** pphead, QueueNode** pptail);

void QueueDestroy(Queue* pq);

//队尾入
void QueuePush(Queue* pq, QDataType x);
//对头出
void QueuePop(Queue* pq);
//队头数据
QDataType QueueFront(Queue* pq);
//队尾数据
QDataType QueueBack(Queue* pq);
int QueueSize(Queue* pq);
bool QueueEmpty(Queue* pq);