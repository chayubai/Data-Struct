#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int STDataType;
//typedef struct Stack
//{
//	STDataType a[MAX];//���飬��̬ջ
//	int top;//ջ����λ�ã���ջ�����±�
//}ST;
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
