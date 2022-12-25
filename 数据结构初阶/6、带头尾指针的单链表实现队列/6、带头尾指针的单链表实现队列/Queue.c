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
	while (cur != NULL)//注意：不是while (cur != pq->tail)否则最后一个结点没有删除
	{
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = NULL;
	pq->tail = NULL;
}

//尾插
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode == NULL)
		return;
	newnode->data = x;
	newnode->next = NULL;
	//没有结点时,空队列
	if (pq->head == NULL)
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;//更新尾节点
	}
}

//头删
/*
void QueuePop(Queue* pq)
{
	assert(pq);
	//判断队列是否为空，队列为空时，再删队尾的数据，NULL指针访问
	assert(!QueueEmpty(pq));//!QueueEmpty(pq)为假，则QueueEmpty(pq)为真，相当于assert(pq->head);
	//方法1：
	QueueNode* next = pq->head->next;//注意pq->head为空，则解引用报错
	free(pq->head);
	pq->head = next;//当删除最后一个结点的时候，head被置为NULL，但tail并没有置NULL
	//方法2：
	//QueueNode* del = pq->head;
	//pq->head = pq->head->next;//当删除最后一个结点的时候，head被置为NULL，但tail并没有置NULL
	//free(del);

	//即当只有一个元素的时候，调用QueuePop后，head被置为NULL了。但tail并不没有置空，tail为野指针。
	//故需要这里再判断，当head为空时，将tail也置空。
	if (pq->head == NULL)
		pq->tail = NULL;
	//通过调试观察现象。
}
*/
void QueuePop(Queue* pq)
{
	assert(pq);
	//队列为空时，再删队尾的数据，NULL指针访问
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
	//队列为空时，再取队尾的数据，NULL指针访问
	assert(!QueueEmpty(pq));//注意pq->head为空，队列为空，解引用报错
	return pq->head->data;
}

QDataType QueueBack(Queue* pq)
{
	assert(pq);
	//队列为空时，再取队尾的数据，NULL指针访问
	assert(!QueueEmpty(pq));//注意pq->tail为空，队列为空，解引用报错
	return pq->tail->data;
}

int QueueSize(Queue* pq)
{
	assert(pq);
	int n = 0;
	QueueNode* cur = pq->head;
	while (cur != NULL)//注意：不是while (cur != pq->tail)否则少算了一个
	{
		++n;
		cur = cur->next;
	}
	return n;

	//或者在Queue结构体加一个size成员变量，在Push或者Pop函数中，++或--
	//那么这里就可以直接使用下面代码
	//return pq->size;
}

bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL;
}