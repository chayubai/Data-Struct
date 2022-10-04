#define _CRT_SECURE_NO_WARNINGS 1
//������ѭ������ʵ�֡�ѭ��������һ���������ݽṹ��
//��������ֻ���FIFO(�Ƚ��ȳ�)ԭ���Ҷ�β�������ڶ���֮�����γ�һ��ѭ����
//��Ҳ����Ϊ�����λ���������

//ѭ�����е�һ���ô������ǿ��������������֮ǰ�ù��Ŀռ䡣
//��һ����ͨ�����һ��һ���������ˣ����ǾͲ��ܲ�����һ��Ԫ�أ���ʹ�ڶ���ǰ�����пռ䡣
//����ʹ��ѭ������, ������ʹ����Щ�ռ�ȥ�洢�µ�ֵ��


//1�������Ƚ��ȳ�	2���ռ��С�ǹ̶���
//���ʵ��Ӧ��֧�����²���:
//MyCircularQueue(k) :������, ���ö��г���Ϊk��
//Front:�Ӷ��׻�ȡԪ�ء��������Ϊ�գ�����-1��
//Rear:��ȡ��βԪ�ء��������Ϊ��,����-1��
//enQueue(value):��ѭ�����в���һ��Ԫ�ء�����ɹ������򷵻��档
//deQueue() :��ѭ��������ɾ��һ��Ԫ�ء� ����ɹ�ɾ���򷵻��档
//isEmpty() :���ѭ�������Ƿ�Ϊ�ա�
//isFul1() :���ѭ�������Ƿ�������
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
typedef struct {
	int* a;
	int front;
	int tail;
	int k;
}MyCircularQueue;
bool myCircularQueueIsEmpty(MyCircularQueue* obj);
bool myCircularQueueIsFull(MyCircularQueue* obj);
MyCircularQueue* myCircularQueueCreate(int k)
{
	MyCircularQueue* cq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	cq->a = (int*)malloc(sizeof(int) * (k + 1));
	cq->front = cq->tail = 0;
	cq->k = k;

	return cq;
}
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value)
{
	if (myCircularQueueIsFull(obj))
	{
		return false;
	}
	obj->a[obj->tail] = value;
	++obj->tail;
	obj->tail %= (obj->k + 1);

	return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
	{
		return false;
	}

	++obj->front;
	obj->front %= (obj->k + 1);

	return true;
}

int myCircularQueueFront(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
	{
		return -1;
	}
	return obj->a[obj->front];
}
int myCircularQueueRear(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
	{
		return -1;
	}

	//����1
	/*if (obj->tail == 0)
	{
		return obj->a[obj->k];
	}
	else
	{
		return obj->a[obj->tail - 1];
	}*/
	//����2
	int i = (obj->tail + obj->k) % (obj->k + 1);
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