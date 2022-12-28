#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
typedef int STDataType;
//���ڴ�������䣬���±�����±꣬���Կ��Զ���һ���ṹ�塣Ҳ���Բ���

typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;

void StackInit(ST* ps);
void StackDestroy(ST* ps);
// ��ջ
void StackPush(ST* ps, STDataType x);
// ��ջ
void StackPop(ST* ps);
STDataType StackTop(ST* ps);

int StackSize(ST* ps);
bool StackEmpty(ST* ps);