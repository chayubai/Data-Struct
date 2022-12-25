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
	while (cur != NULL)//ע�⣺����while (cur != pq->tail)�������һ�����û��ɾ��
	{
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = NULL;
	pq->tail = NULL;
}

//β��
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode == NULL)
		return;
	newnode->data = x;
	newnode->next = NULL;
	//û�н��ʱ,�ն���
	if (pq->head == NULL)
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;//����β�ڵ�
	}
}

//ͷɾ
/*
void QueuePop(Queue* pq)
{
	assert(pq);
	//�ж϶����Ƿ�Ϊ�գ�����Ϊ��ʱ����ɾ��β�����ݣ�NULLָ�����
	assert(!QueueEmpty(pq));//!QueueEmpty(pq)Ϊ�٣���QueueEmpty(pq)Ϊ�棬�൱��assert(pq->head);
	//����1��
	QueueNode* next = pq->head->next;//ע��pq->headΪ�գ�������ñ���
	free(pq->head);
	pq->head = next;//��ɾ�����һ������ʱ��head����ΪNULL����tail��û����NULL
	//����2��
	//QueueNode* del = pq->head;
	//pq->head = pq->head->next;//��ɾ�����һ������ʱ��head����ΪNULL����tail��û����NULL
	//free(del);

	//����ֻ��һ��Ԫ�ص�ʱ�򣬵���QueuePop��head����ΪNULL�ˡ���tail����û���ÿգ�tailΪҰָ�롣
	//����Ҫ�������жϣ���headΪ��ʱ����tailҲ�ÿա�
	if (pq->head == NULL)
		pq->tail = NULL;
	//ͨ�����Թ۲�����
}
*/
void QueuePop(Queue* pq)
{
	assert(pq);
	//����Ϊ��ʱ����ɾ��β�����ݣ�NULLָ�����
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
	//����Ϊ��ʱ����ȡ��β�����ݣ�NULLָ�����
	assert(!QueueEmpty(pq));//ע��pq->headΪ�գ�����Ϊ�գ������ñ���
	return pq->head->data;
}

QDataType QueueBack(Queue* pq)
{
	assert(pq);
	//����Ϊ��ʱ����ȡ��β�����ݣ�NULLָ�����
	assert(!QueueEmpty(pq));//ע��pq->tailΪ�գ�����Ϊ�գ������ñ���
	return pq->tail->data;
}

int QueueSize(Queue* pq)
{
	assert(pq);
	int n = 0;
	QueueNode* cur = pq->head;
	while (cur != NULL)//ע�⣺����while (cur != pq->tail)����������һ��
	{
		++n;
		cur = cur->next;
	}
	return n;

	//������Queue�ṹ���һ��size��Ա��������Push����Pop�����У�++��--
	//��ô����Ϳ���ֱ��ʹ���������
	//return pq->size;
}

bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL;
}