#define _CRT_SECURE_NO_WARNINGS 1
//��ͷ��˫��ѭ������
#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int LTDataType;

typedef struct ListNode
{
	struct ListNode* next;//����һ�����ĵ�ַ
	struct ListNode* prev;//����һ�����ĵ�ַ
	LTDataType data;
}ListNode;

//��ʼ����ͷ���
//1��
//void ListInit(ListNode** pphead);
//2��
ListNode* ListInit();

//��ӡ
void ListPrint(ListNode* phead);

//�������
ListNode* BuyListNode(LTDataType x);

//β�� - ������β����Բ���β������һ��βָ��
void ListPushBack(ListNode* phead, LTDataType x);

//βɾ
void ListPopBack(ListNode* phead);

//ͷ��
void ListPushFront(ListNode* phead, LTDataType x);

//ͷɾ
void ListPopFront(ListNode* phead);

//����λ�ò���
void ListInsert(ListNode* pos, LTDataType x);

//����λ��ɾ��
void ListErase(ListNode* pos);

//����
ListNode* ListFind(ListNode* phead, LTDataType x);//�����ҵ��������±�
//...
//int SeqListSort(SL* psl, SLDataType x);
//int SeqListBinaryFind(SL* psl, SLDataType x);

//�ռ�����
//void ListDestory(ListNode* phead);
void ListDestory(ListNode** phead);

//�������� - �������е����ݽڵ㣬����headͷ��㣬���Լ���ʹ��
void ListClear(ListNode* phead);

#include <stdbool.h>
//�ж������Ƿ�Ϊ�� - �ж�phead->next�Ƿ����phead
bool ListEmpty(ListNode* phead);

//��������ĳ���
int ListSize(ListNode* phead);
