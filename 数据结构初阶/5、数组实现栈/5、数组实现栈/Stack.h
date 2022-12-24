#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int STDataType;
//#define MAX 10
//typedef struct Stack
//{
//	STDataType a[MAX];//���飬��̬ջ
//	int top;//ջ����λ�ã���ջ�����±�
//}ST;
typedef struct Stack
{
	STDataType* a;//ָ��a������ά����̬����ջ
	int top;//�ȱ�ʾջ�ĵ�ǰԪ�ظ������ֱ�ʾ��ǰջ����λ�ã���ջ�����±�
	//����ʾջ��Ԫ�ظ���ʱ����Χ��top >= 0����top>0��ʾջ��Ϊ��
	//����ʾջ����λ��ʱ����Χ��[0,top-1] 
	int capacity;//��̬����ջ������
}ST;

//����ջ��ʼ��
void StackInit(ST* ps);
//����ջ����
void StackDestroy(ST* ps);
//����ջ�������Ĳ���
void StackPush(ST* ps, STDataType x);
//����ջ��������ɾ��
void StackPop(ST* ps);
//��ȡջ��������
STDataType StackTop(ST* ps);
//����ջ�Ĵ�С
int StackSize(ST* ps);
//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(ST* ps);