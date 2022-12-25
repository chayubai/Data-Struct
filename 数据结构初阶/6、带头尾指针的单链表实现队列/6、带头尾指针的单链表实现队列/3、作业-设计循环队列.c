#define _CRT_SECURE_NO_WARNINGS 1
//������ѭ������ʵ�֡�ѭ��������һ���������ݽṹ��
//��������ֻ���FIFO(�Ƚ��ȳ�)ԭ���Ҷ�β�������ڶ���֮�����γ�һ��ѭ����
//��Ҳ����Ϊ�����λ���������

//ѭ�����е�һ���ô������ǿ��������������֮ǰ�ù��Ŀռ䡣
//��һ����ͨ�����һ��һ���������ˣ����ǾͲ��ܲ�����һ��Ԫ�أ���ʹ�ڶ���ǰ�����пռ䡣
//����ʹ��ѭ������, ������ʹ����Щ�ռ�ȥ�洢�µ�ֵ��

//���ʵ��Ӧ��֧�����²���:
//MyCircularQueue(k) :������, ���ö��г���Ϊk��
//Front:�Ӷ��׻�ȡԪ�ء��������Ϊ�գ�����-1��
//Rear:��ȡ��βԪ�ء��������Ϊ��,����-1��
//enQueue(value):��ѭ�����в���һ��Ԫ�ء�����ɹ������򷵻��档
//deQueue() :��ѭ��������ɾ��һ��Ԫ�ء� ����ɹ�ɾ���򷵻��档
//isEmpty() :���ѭ�������Ƿ�Ϊ�ա�
//isFul1() :���ѭ�������Ƿ�������

//ѭ�����е����ԣ�1�������Ƚ��ȳ�	2���ռ��С�ǹ̶���
//�ص�:ѭ�����У�����ʹ������ʵ�ֻ�������ʵ�֣���Ҫ�࿪һ���ռ䣬
//���������Ҳ����ζ�ţ�Ҫ��һ����k�����ݵ�ѭ������, Ҫ��k + 1���ռ�����޷�ʵ���пպ�������
//���������Ҳ����ζ�ţ�Ҫ��һ����k�����ݵ�ѭ������, Ҫ��k + 1���������޷�ʵ���пպ�������(��������뿪�ٺ�)
//��Ϊ��ʼʱfront == tail����ȷ��Ϊ�գ�����һ�ε�front == tailʱ�����ǿջ������������塣

//ѭ�����У�����������ʵ�֣�ͨ���±���ơ�
//Ҳ����������ʵ�֣���ѭ������
//1����������ʵ��ʱ���±�front == tail��ʾ�գ�(tail+1)%(K+1) == front��ʾ��
//2����������ʵ��ʱ��ָ��front == tail��ʾ�գ�tail->next == front��ʾ��

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef struct {
	int* a;//����ָ��ά�����������
	int front;//��ͷ�±�
	int tail;//��β�±�
	int k;//��������
}MyCircularQueue;

bool myCircularQueueIsEmpty(MyCircularQueue* obj);

bool myCircularQueueIsFull(MyCircularQueue* obj);

MyCircularQueue* myCircularQueueCreate(int k)
{
	MyCircularQueue* cq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	if (cq == NULL)
		return NULL;
	cq->a = (int*)malloc(sizeof(int) * (k + 1));//�࿪һ���ռ䣬���ֿպ���
	cq->front = cq->tail = 0;
	cq->k = k;

	return cq;
}

//�����
//����гɹ��������棬û�гɹ�(��������)�����ؼ�
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value)
{
	if (myCircularQueueIsFull(obj))
	{
		return false;
	}

	obj->a[obj->tail] = value;
	++obj->tail;
	obj->tail %= (obj->k + 1);//������Ĵ�������4�Σ�Ҳ�����±����k,�±����Ҫ���»ع�
	//ע�⣺���Բ���Ҫif�ж�
	return true;
}

//������
//�����гɹ��������棬û�гɹ�(����Ϊ��)�����ؼ�
bool myCircularQueueDeQueue(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
	{
		return false;
	}

	++obj->front;
	obj->front %= (obj->k + 1);//��ɾ���Ĵ�������4�Σ�Ҳ�����±����k,�±����Ҫ���»ع�
	//ע�⣺���Բ���Ҫif�ж�
	return true;
}

//���ض�ͷԪ��
//������Ϊ�գ�����-1�����򷵻ض�ͷ���ݡ�
int myCircularQueueFront(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
	{
		return -1;
	}
	return obj->a[obj->front];
}

//���ض�βԪ��
//������Ϊ�գ�����-1�����򷵻ض�β���ݡ�
int myCircularQueueRear(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
	{
		return -1;
	}
	//ע�⣺���ض�β�±��ǰһ������

	//����1
	/*
	if (obj->tail == 0)//����β�±�Ϊ0����ǰһ���������±�Ϊk��ֵ
	{
		return obj->a[obj->k];
	}
	else
	{
		return obj->a[obj->tail - 1];
	}
	*/

	//����2
	int i = (obj->tail + obj->k) % (obj->k + 1);//��ȡ��ʵ�±�
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

#if 0
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
#endif