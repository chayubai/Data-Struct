#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"
//����ջ��ʼ��
/*
//��ʽ1��
void StackInit(ST* ps)//�ββ���Ӱ��ʵ�Σ���ʵ�εĵ�ַ���βξ��ܸı�ʵ��
{
	assert(ps);
	ps->a = NULL;
	ps->top = 0;//��ʼtop = 0����ʾtopָ��ջ�����ݵ���һ�������ȷ�������++����ʼtop = -1.��ʾtopָ��ջ�����ݣ�����++�ٷ�����
	ps->capacity = 0;
}
*/
//��ʽ2��
void StackInit(ST* ps)//�ββ���Ӱ��ʵ�Σ���ʵ�εĵ�ַ���βξ��ܸı�ʵ��
{
	assert(ps);
	ps->a = (STDataType*)malloc(sizeof(STDataType)*4);
	if (ps->a == NULL)
	{
		printf("malloc failed\n");
		exit(-1);
	}
	ps->top = 0;//top = 0����ʾtopָ��ջ�����ݵ���һ�������ȷ�������++��top = -1.��ʾtopָ��ջ�����ݣ�����++�ٷ�����
	ps->capacity = 4;
}

//����ջ�Ĳ���
/*
//��ʽ1��
void StackPush(ST* ps, STDataType x)
{
	assert(ps);
	if (ps->top == ps->capacity)//���ˣ�����
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
*/
//��ʽ2��
void StackPush(ST* ps, STDataType x)
{
	assert(ps);
	if (ps->top == ps->capacity)//���ˣ�����
	{
		STDataType* tmp = realloc(ps->a, sizeof(STDataType) * (ps->capacity * 2));
		if (tmp == NULL)
		{
			printf("realloc failed\n");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = ps->capacity * 2;
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
	//��ջ��û�����ݣ�ջ���ˣ�������ɾ��ջ�������ݣ��±�Խ��
	//assert(ps->top > 0);�൱��assert(!StackEmpty(ps));
	assert(!StackEmpty(ps));
	ps->top--;
}

//��ȡջ��������
STDataType StackTop(ST* ps)
{
	assert(ps);
	//��ջ��û�����ݣ�ջ���ˣ������ٻ�ȡջ�������ݣ�����Ƿ�����
	//assert(ps->top > 0);�൱��assert(!StackEmpty(ps));
	assert(!StackEmpty(ps));
	return ps->a[ps->top - 1];
	//��top��ʼ��Ϊ0����return ps->a[ps->top - 1];
	//��top��ʼ��Ϊ-1����return ps->a[ps->top];
}

//����ջ�Ĵ�С
int StackSize(ST* ps)
{
	assert(ps);
	return ps->top;//top����ջ��ջ���±��ǰһ����Ҳ��ջ�Ĵ�С
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