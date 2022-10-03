#define _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h"
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
	//没有结点时
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

//void QueuePop(Queue* pq)
//{
//	assert(pq);
//	//相当于assert(pq->head);
//	assert(!QueueEmpty(pq));//注意pq->head为空，解引用
//	QueueNode* next = pq->head->next;
//	free(pq->head);
//	pq->head = next;
//	//当pop最后一个结点时，此时head为空时，但tail并不为空，此时tail为野指针
//	if (pq->head == NULL)
//		pq->tail = NULL;
//}

void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	//只有一个结点
	if (pq->head->next == NULL)
	{
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	else
	{
		QueueNode* next = pq->head->next;
		free(pq->head);
		pq->head = next;
	}	
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