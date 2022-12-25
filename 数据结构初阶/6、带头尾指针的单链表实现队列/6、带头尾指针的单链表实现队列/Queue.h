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
	QueueNode* head;//ͷָ��
	QueueNode* tail;//βָ��
	//ע�⣺����ͷβָ��ά�����С�����ͨ��Queue�����ĵ�ַ���ܲ�����������ݣ�Ҳ���ܲ������С�
}Queue;

void QueueInit(Queue* pq);
//���������Queue�ṹ�壬��Queue* pq��head��tail��QueueNode** pphead, QueueNode** pptailʵ��
//void QueueInit(QueueNode** pphead, QueueNode** pptail);
//ע�⣺����β��ǽṹ�壬��ʵ�δ��ṹ���ַ������β��Ƕ���ָ�룬��ʵ�δ�һ��ָ��ĵ�ַ��

void QueueDestroy(Queue* pq);

//1��ͷ����ͷ��β����β ͷɾ����β����ӣ�ͷɾʱ�临�Ӷ�ΪO(1)��β��ʱ�临�Ӷ�ΪO(1)���ʺ�
//2��ͷ����β��β����ͷ βɾ����ͷ����ӣ�βɾʱ�临�Ӷ�ΪO(1)��ͷ��ʱ�临�Ӷ�ΪO(1)���ʺ�
//ע�⣺����ʹ�õ�һ�ַ�ʽ���Ҳ���Ҫ�ڱ�λ��㡣

//��β��
void QueuePush(Queue* pq, QDataType x);
//��ͷ��
void QueuePop(Queue* pq);
//��ȡ��ͷ����
QDataType QueueFront(Queue* pq);
//��ȡ��β����
QDataType QueueBack(Queue* pq);

int QueueSize(Queue* pq);

bool QueueEmpty(Queue* pq);