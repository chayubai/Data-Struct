#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int STDataType;
//typedef struct Stack
//{
//	STDataType a[MAX];//数组，静态栈
//	int top;//栈顶的位置，即栈顶的下标
//}ST;
typedef struct Stack
{
	STDataType* a;//指针a，用来维护数组栈
	int top;//栈顶的位置，即栈顶的下标
	int capacity;//数组栈的容量
}ST;

//数组栈初始化
void StackInit(ST* ps);
//数组栈销毁
void StackDestroy(ST* ps);
//数组栈（顶）的插入
void StackPush(ST* ps, STDataType x);
//数组栈（顶）的删除
void StackPop(ST* ps);
//栈顶的数据
STDataType StackTop(ST* ps);
//数组栈的大小
int StackSize(ST* ps);
//判断栈是否为空
bool StackEmpty(ST* ps);
