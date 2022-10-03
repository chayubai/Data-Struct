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
	//û�н��ʱ
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
//	//�൱��assert(pq->head);
//	assert(!QueueEmpty(pq));//ע��pq->headΪ�գ�������
//	QueueNode* next = pq->head->next;
//	free(pq->head);
//	pq->head = next;
//	//��pop���һ�����ʱ����ʱheadΪ��ʱ����tail����Ϊ�գ���ʱtailΪҰָ��
//	if (pq->head == NULL)
//		pq->tail = NULL;
//}

void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	//ֻ��һ�����
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
	assert(!QueueEmpty(pq));//ע��pq->headΪ�գ�������
	return pq->head->data;
}

QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));//ע��pq->tailΪ�գ�������
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

	//������Queue�ṹ���һ��size��������Push����Pop�����У�++��--
	//return pq->size;
}

bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL;
}