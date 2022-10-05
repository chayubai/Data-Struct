#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//typedef BTNode* QDataType;
//ǰ����������typedef BTNode* QDataType;������������
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
//���������Queue�ṹ�壬��Queue* pq����QueueNode** pphead, QueueNode** pptailʵ��
//����β��ǽṹ�壬��ʵ�δ��ṹ���ַ������β��Ƕ���ָ�룬��ʵ�δ�һ��ָ��
//void QueueInit(QueueNode** pphead, QueueNode** pptail);

void QueueDestroy(Queue* pq);

//��β��
void QueuePush(Queue* pq, QDataType x);
//��ͷ��
void QueuePop(Queue* pq);
//��ͷ����
QDataType QueueFront(Queue* pq);
//��β����
QDataType QueueBack(Queue* pq);
int QueueSize(Queue* pq);
bool QueueEmpty(Queue* pq);