#define _CRT_SECURE_NO_WARNINGS 1
//�����ʹ������ջʵ��һ�������ȳ��Ķ��У�����Ӧ��֧��һ�����֧�ֵ����в�����push��peek��pop��empty��
//ʵ��MyQueue�ࣺ
//void push(int x)��Ԫ��x������е�ĩβ
//int pop()�Ӷ��еĿ�ͷ�Ƴ�������Ԫ��
//int peek()���ض��п�ͷ��Ԫ��
//boolean empty()�������Ϊ�գ�����true�����򷵻�false

//�������Ƚ��ȳ�
//ջ  �Ǻ���ȳ�

//����˼·�������Ƚ��ȳ�
//����pushA��popBջ������1234�����ʹ���ȳ�1��
//1�������ݣ���pushAջ�У�������
//2�������ݵĺ򣬽�pushAջ���δ�ջ�������ݣ�ת��(ջ������)��popBջ�б��棬Ȼ����popBջ�������ݡ�
//ֻ�е�popBջ�����е����ݶ�������ٽ�pushAջ�е�����ת�Ƶ�popBջ�У����������ݡ�

//���裺��1 2 3 4��A�У���pop��4 3 2 1���뵽B�У������pop��1��
//���Ҫ�����ݣ�����A����5 6���ȳ���B�е����ݣ���pop��5 6���뵽B��,�����pop��6��
//ջA: 1 2 3 4  ---push
//ջB: ��

//ջA: �� 
//ջB: 4 3 2 1  ---pop

//ջA: ��    
//ջB: 4 3 2

//ջA: 5 6      ---push
//ջB: 4 3 2    

//ջA: 5 6     
//ջB: 4 3 2    ---pop

//ջA: 5 6      
//ջB: ��

//ջA: ��       
//ջB: 5 6      ---pop

//ջA: ��    
//ջB: 5
//����

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType* a;//ָ��a������ά������ջ
	int top;//ջ����λ�ã���ջ�����±�
	int capacity;//����ջ������
}ST;

//����ջ��ʼ��
void StackInit(ST* ps);
//����ջ����
void StackDestroy(ST* ps);
//����ջ�������Ĳ���
void StackPush(ST* ps, STDataType x);
//����ջ��������ɾ��
void StackPop(ST* ps);
//ջ��������
STDataType StackTop(ST* ps);
//����ջ�Ĵ�С
int StackSize(ST* ps);
//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(ST* ps);

//����ջ��ʼ��
void StackInit(ST* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->top = 0;//top = 0����ʾtopָ��ջ�����ݵ���һ�������ȷ�������++��top = -1.��ʾtopָ��ջ�����ݣ�����++�ٷ�����
	ps->capacity = 0;
}

//����ջ�Ĳ���
void StackPush(ST* ps, STDataType x)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STDataType* tmp = realloc(ps->a, sizeof(STDataType) * newCapacity);
		if (tmp == NULL)
		{
			printf("realloc failed\n");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newCapacity;
	}
	ps->a[ps->top] = x;
	ps->top++;
}

//����ջ����
void StackDestroy(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}

//����ջ��ɾ��
void StackPop(ST* ps)
{
	assert(ps);
	//assert(ps->top > 0);
	assert(!StackEmpty(ps));
	ps->top--;
}

//ջ��������
STDataType StackTop(ST* ps)
{
	assert(ps);
	//assert(ps->top > 0);
	assert(!StackEmpty(ps));
	return ps->a[ps->top - 1];
}

//����ջ�Ĵ�С
int StackSize(ST* ps)
{
	assert(ps);
	return ps->top;
}
//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(ST* ps)
{
	assert(ps);
	/*if (ps->top == 0)
	{
		return true;
	}
	else
	{
		return false;
	}*/
	return ps->top == 0;
}

typedef struct {
	ST pushST;
	ST popST;
}MyQueue;

MyQueue* myQueueCreate()
{
	MyQueue* q = (MyQueue*)malloc(sizeof(MyQueue));
	if (q == NULL)
		return NULL;
	//����������ջpushST��popST��ɣ�pushST��popST�����������
	StackInit(&q->pushST);
	StackInit(&q->popST);

	return q;
}

//1�������ݣ���pushAջ�У�������
//2�������ݵĺ򣬽�pushAջ���δ�ջ�������ݣ�ת��(ջ������)��popBջ�б��棬Ȼ����popBջ�������ݡ�
void myQueuePush(MyQueue* obj, int x)
{
	assert(obj);
	//��pushSTջ��������
	StackPush(&obj->pushST, x);
}

//�Ƴ������ض�ͷԪ��
int myQueuePop(MyQueue* obj)
{
	assert(obj);	//��popSTջ�г����ݣ�������ʱ��ֻ�е�PopSTջû�����ݲŴ�PushST����ȥ���ٳ����ݣ���Ϊֻ�е����������ݲŷ����Ƚ��ȳ���˳�򣬷���ֱ����popST�г����ݣ�
	if (StackEmpty(&obj->popST))
	{
		while (!StackEmpty(&obj->pushST))
		{
			StackPush(&obj->popST, StackTop(&obj->pushST));
			StackPop(&obj->pushST);
		}
	}
	
	//popST��Ϊ�գ�ֱ��ȡ����
	int front = StackTop(&obj->popST);
	StackPop(&obj->popST);

	return front;
}

//���ض�ͷԪ��
int myQueuePeek(MyQueue* obj)
{
	assert(obj);
	//���popST��û�����ݣ���PushST�е����ݵ���ȥ���ٷ���popSTջ������
	if (StackEmpty(&obj->popST))
	{
		while (!StackEmpty(&obj->pushST))
		{
			StackPush(&obj->popST, StackTop(&obj->pushST));
			StackPop(&obj->pushST);
		}
	}

	//���popST��Ϊ�գ�ֱ��ȡջ������
	return StackTop(&obj->popST);
}

bool myQueueEmpty(MyQueue* obj)
{
	assert(obj);
	//����ջ��Ϊ�գ������Ϊ��
	return StackEmpty(&obj->popST) && StackEmpty(&obj->pushST);
}

void myQueueFree(MyQueue* obj)
{
	assert(obj);
	//ע�⣺���еĽṹ
	StackDestroy(&obj->pushST);
	StackDestroy(&obj->popST);
	free(obj);
}
#if 0
int main()
{
	MyQueue* q = myQueueCreate();

	myQueuePush(q, 1);
	myQueuePush(q, 2);
	myQueuePush(q, 3);
	myQueuePush(q, 4);

	while (!myQueueEmpty(q))
	{
		int front = myQueuePeek(q);
		printf("%d ", front);
		myQueuePop(q);
	}

	myQueueFree(q);
	return 0;
}
#endif