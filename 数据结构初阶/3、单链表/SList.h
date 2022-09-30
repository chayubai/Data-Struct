//不带头单向非循环链表
#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//链表是由结点组成，而结点由数据域和地址域构成。最后一个结点的地址域为NULL
typedef int SLDataType;

typedef struct SListNode
{
	//数据域
	SLDataType data;
	//地址域：保存了下一个结构体(结点)的地址
	struct SListNode* next;

}SListNode;

//遍历打印链表
void SListPrint(SListNode* phead);

//尾插
void SListPushBack(SListNode** pphead, SLDataType x);
//尾删
void SListPopBack(SListNode** phead);

//头插
void SListPushFront(SListNode** pphead, SLDataType x);
//头删
void SListPopFront(SListNode** pphead);

//单链表查找
SListNode* SListFind(SListNode* phead, SLDataType x);

//在pos指针的前面插入x
void SListInsertBefore(SListNode** pphead, SListNode* pos, SLDataType x);

//删除pos指针位置的值
void SListErase(SListNode** pphead, SListNode* pos);


//在pos指针的后面插入x
void SListInsertAfter(SListNode* pos, SLDataType x);

//删除pos指针后面的值
void SListEraseAfter(SListNode* pos);

//释放链表
void SListDestory(SListNode** pphead);
