#define _CRT_SECURE_NO_WARNINGS 1
//带头的双向循环链表
#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int LTDataType;

typedef struct ListNode
{
	struct ListNode* next;//存下一个结点的地址
	struct ListNode* prev;//存上一个结点的地址
	LTDataType data;
}ListNode;

//初始化带头结点
//1、
//void ListInit(ListNode** pphead);
//2、
ListNode* ListInit();

//打印
void ListPrint(ListNode* phead);

//创建结点
ListNode* BuyListNode(LTDataType x);

//尾插 - 单链表尾插可以不找尾，定义一个尾指针
void ListPushBack(ListNode* phead, LTDataType x);

//尾删
void ListPopBack(ListNode* phead);

//头插
void ListPushFront(ListNode* phead, LTDataType x);

//头删
void ListPopFront(ListNode* phead);

//任意位置插入
void ListInsert(ListNode* pos, LTDataType x);

//任意位置删除
void ListErase(ListNode* pos);

//查找
ListNode* ListFind(ListNode* phead, LTDataType x);//返回找到的数的下标
//...
//int SeqListSort(SL* psl, SLDataType x);
//int SeqListBinaryFind(SL* psl, SLDataType x);

//空间销毁
//void ListDestory(ListNode* phead);
void ListDestory(ListNode** phead);

//数据清理 - 清理所有的数据节点，保留head头结点，可以继续使用
void ListClear(ListNode* phead);

#include <stdbool.h>
//判断链表是否为空 - 判断phead->next是否等于phead
bool ListEmpty(ListNode* phead);

//计算链表的长度
int ListSize(ListNode* phead);
