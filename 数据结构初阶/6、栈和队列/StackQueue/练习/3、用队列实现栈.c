#define _CRT_SECURE_NO_WARNINGS 1
//�����ʹ����������ʵ��һ�������ȳ���LIFO����ջ����֧����ͨջ��ȫ��������push��top��pop��empty��
//ʵ��MyStack�ࣺ
//void push(int x)��Ԫ��xѹ��ջ��
//int pop()�Ƴ�������ջ��Ԫ��
//int top()����ջ��Ԫ��
//boolean empty()���ջ�ǿյģ�����true�����򷵻�false

//˼·��
//����A: 1 2 3 4
//����B: ��

//����A: 4    ---pop
//����B: 1 2 3

//����A:     
//����B: 1 2 3

//����A: 1 2     
//����B: 3    ---pop

//����A: 1 2     
//����B: 
//�������ص��������һ����
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
//���������Queue�ṹ�壬��Queue* pq����QueueNode** pphead, QueueNode** pptailʵ��
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
	assert(!QueueEmpty(pq));//ע��pq->headΪ�գ�������
	QueueNode* next = pq->head->next;
	free(pq->head);
	pq->head = next;
	if (pq->head == NULL)
		pq->tail = NULL;
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

//�����ṹ������ΪMyStack
typedef struct {
	Queue q1;
	Queue q2;
}MyStack;

//�����ṹ��ı���ΪMyStack
//struct {
//
//}MyStack;

MyStack* myStackCreate()
{
	/*MyStack st;
	return &st;
	//stΪ�ֲ�����������������&st���Ұָ��
	*/

	MyStack* st = (MyStack*)malloc(sizeof(MyStack));

	//ջ����������q1��q2��ɣ�q1��q2�����������
	QueueInit(&st->q1);
	QueueInit(&st->q2);

	return st;
}

//1�������ݣ�����Ϊ�յĶ�����
//2�������ݣ��Ѳ�Ϊ�յ����ݵ��뵽�յĶ��У�ֱ��ֻʣ���һ�����ݣ�Ȼ�������
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
	//����q1Ϊ�գ�q2��Ϊ��
	Queue* emptyQ = &obj->q1;
	Queue* noneemptyQ = &obj->q2;
	//���q1��Ϊ�գ�����
	if (!QueueEmpty(&obj->q1))
	{
		emptyQ = &obj->q2;
		noneemptyQ = &obj->q1;
	}
	//2�������ݣ��Ѳ�Ϊ�յ����ݵ��뵽�յĶ��У�ֱ��ֻʣ���һ�����ݣ�Ȼ�������
	while (QueueSize(noneemptyQ) > 1)
	{
		QueuePush(emptyQ, QueueFront(noneemptyQ));
		QueuePop(noneemptyQ);
	}
	int top = QueueFront(noneemptyQ);
	//���һ������top��Ҫpop
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
	//ע�⣺ջ�Ľṹ
	QueueDestroy(&obj->q1);
	QueueDestroy(&obj->q2);
	free(obj);
}
//�������Ƚ��ȳ�
//ջ  �Ǻ���ȳ�
//����˼·��
//1�������ݣ�����Ϊ�յĶ����룬������һ������Ϊ��
//2�������ݵ�ʱ�����γ���ͷ�����ݣ�ת�Ƶ���һ�����б��棬ֻʣ���һ������Pop��
//����ʵ�ֺ���ȳ��Ĺ���
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

