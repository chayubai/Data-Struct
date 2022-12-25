#define _CRT_SECURE_NO_WARNINGS 1
//�����ʹ����������ʵ��һ�������ȳ���LIFO����ջ����֧����ͨջ��ȫ��������push��top��pop��empty��
//ʵ��MyStack�ࣺ
//void push(int x)��Ԫ��xѹ��ջ��
//int pop()�Ƴ�������ջ��Ԫ��
//int top()����ջ��Ԫ��
//boolean empty()���ջ�ǿյģ�����true�����򷵻�false

//�������Ƚ��ȳ�
//ջ  �Ǻ���ȳ�

//����˼·˼·�����Ϻ���ȳ�
//����A��B���У�����1234�����ʹ���ȳ�4��
//1�������ݣ�����Ϊ�յĶ����У������ݣ�������һ������Ϊ��
//2�������ݵ�ʱ�����γ���ͷ�����ݣ�ת��(����������)����һ�������б��档ֻʣ���һ������ʱ��pop����
//Ҳ����˵�������ݵ�ʱ�򣬽�ǰn-1������ת�Ƶ�Ϊ�յĶ����С�
//����ʵ�ֺ���ȳ��Ĺ���

//���裺��1 2 3 4��A�У���pop��1 2 3���뵽B�С������pop��4��
//���Ҫ�����ݣ�����Ϊ�յ�B����5 6����pop��1 2 3 5���뵽A��,�����pop��6��
//����A: 1 2 3 4  ---push
//����B: ��

//����A: 4    ---pop
//����B: 1 2 3

//����A: ��    
//����B: 1 2 3

//����A: 1 2     
//����B: 3    ---pop

//����A: 1 2     
//����B: ��

//����A: 1 2 5 6   ---push
//����B: ��

//����A: 6    ---pop
//����B: 1 2 5
//�������ص��������һ����

#include "Queue.h"

//�����ṹ������ΪMyStack
typedef struct {
	Queue q1;
	Queue q2;
}MyStack;

//�����ṹ��ı���ΪMyStack
//struct {
//
//}MyStack;

//����ջ��ָ��
MyStack* myStackCreate()
{
	/*
	MyStack st;
	return &st;//���ܷ��ؾֲ������ĵ�ַ
	//stΪ�ֲ�����������������&st���Ұָ��
	*/

	MyStack* st = (MyStack*)malloc(sizeof(MyStack));
	if (st == NULL)
		return NULL;
	//ջ����������q1��q2��ɣ�q1��q2�����������
	QueueInit(&st->q1);//->���ȼ�����&
	QueueInit(&st->q2);

	return st;
}

//1�������ݣ�����Ϊ�յĶ����롣���������Ϊ�գ����ĸ�������push�����ԡ�
//2�������ݣ��Ѳ�Ϊ�յĶ�ͷ�������ε��뵽�յĶ��У�ֱ��ֻʣ���һ�����ݣ�Ȼ�������
void myStackPush(MyStack* obj, int x)
{
	assert(obj);
	if (!QueueEmpty(&obj->q1))
	{
		QueuePush(&obj->q1,x);
	}
	else//������q1Ϊ�գ�q2����Ϊ�գ����ܲ�Ϊ�ա�
	{//q2Ϊ�գ���q1��q2�����ԣ�q2��Ϊ�գ���q2
		QueuePush(&obj->q2, x);
	}
}

//�Ƴ�������ջ��Ԫ��
int myStackPop(MyStack* obj)
{
	assert(obj);
	//����q1Ϊ�գ�q2��Ϊ��
	Queue* emptyQ = &obj->q1;
	Queue* noneemptyQ = &obj->q2;
	//���q1��Ϊ�գ�����
	if (!QueueEmpty(&obj->q1))
	{
		emptyQ = &obj->q2;
		noneemptyQ = &obj->q1;
	}
	//2�������ݣ��Ѳ�Ϊ�յĶ�ͷ�������ε��뵽�յĶ��У�ֱ��ֻʣ���һ�����ݣ�Ȼ�������
	while (QueueSize(noneemptyQ) > 1)
	{
		QueuePush(emptyQ, QueueFront(noneemptyQ));
		QueuePop(noneemptyQ);
	}
	//ע�⣺�����Ϊ�յĶ���ֻ��һ��Ԫ�ء�������ѭ��ֱ��pop����
	
	int top = QueueFront(noneemptyQ);//����������ж�Ϊ�գ���QueueFront�������ԣ�����
	//���һ������top��Ҫpop
	QueuePop(noneemptyQ);

	return top;
}

//����ջ��Ԫ�أ�ȡ��Ϊ�յĶ����еĶ�β���ݡ�
int myStackTop(MyStack* obj)
{
	assert(obj);
	//����������ж�Ϊ�գ���QueueBack�������ԣ�����
	
	if (!QueueEmpty(&obj->q1))
	{
		return QueueBack(&obj->q1);
	}
	else//������q1Ϊ�գ�q2����Ϊ�գ����ܲ�Ϊ�ա�
	{//q2Ϊ�գ���q1��q2�����ԣ�q2��Ϊ�գ���q2
		return QueueBack(&obj->q2);
	}
}

bool myStackEmpty(MyStack* obj)
{
	assert(obj);
	//�������ж�Ϊ�գ���ջΪ��
	return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

void myStackFree(MyStack* obj)
{
	assert(obj);
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

#if 0
int main()
{
	MyStack* st = myStackCreate();

	myStackPush(st, 1);
	myStackPush(st, 2);
	myStackPush(st, 3);
	myStackPush(st, 4);

	while (!myStackEmpty(st))
	{
		int top = myStackTop(st);
		printf("%d ", top);
		myStackPop(st);
	}

	myStackFree(st);
	return 0;
}
#endif