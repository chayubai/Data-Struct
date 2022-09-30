//����ͷ�����ѭ������
#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//�������ɽ����ɣ��������������͵�ַ�򹹳ɡ����һ�����ĵ�ַ��ΪNULL
typedef int SLDataType;

typedef struct SListNode
{
	//������
	SLDataType data;
	//��ַ�򣺱�������һ���ṹ��(���)�ĵ�ַ
	struct SListNode* next;

}SListNode;

//������ӡ����
void SListPrint(SListNode* phead);

//β��
void SListPushBack(SListNode** pphead, SLDataType x);
//βɾ
void SListPopBack(SListNode** phead);

//ͷ��
void SListPushFront(SListNode** pphead, SLDataType x);
//ͷɾ
void SListPopFront(SListNode** pphead);

//���������
SListNode* SListFind(SListNode* phead, SLDataType x);

//��posָ���ǰ�����x
void SListInsertBefore(SListNode** pphead, SListNode* pos, SLDataType x);

//ɾ��posָ��λ�õ�ֵ
void SListErase(SListNode** pphead, SListNode* pos);


//��posָ��ĺ������x
void SListInsertAfter(SListNode* pos, SLDataType x);

//ɾ��posָ������ֵ
void SListEraseAfter(SListNode* pos);

//�ͷ�����
void SListDestory(SListNode** pphead);
