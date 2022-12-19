#define _CRT_SECURE_NO_WARNINGS 1
//#pragma once	//��ֹ���ظ�����

//˳�����Ч�����������еĴ洢������������

#ifndef __SEQLIST__H__
#define __SEQLIST__H__

//��̬˳�����ƣ��̶���С��
//���⣺�����˲����ã��������ò����˷ѣ�����������
//struct SeqList
//{
//	int a[10];//����������
//	int size;//��Ч���ݵĸ���
//};

//typedef int SLDataType;	//�����޸����ݵ�����int���Ӷ��ﵽ�洢��ͬ���͵���
//#define MAX_SIZE 10	//�����޸�a����Ĵ�С
//struct SeqList
//{
//	SLDataType a[MAX_SIZE];
//	int size;
//};

//void SeqListInit(SL s)//��ֵ���ã�Ӧ���ô�ַ
//{
//	memset(s.a, 0, sizeof(SLDataType)*MAX_SIZE);//�Թ̶���С�ĸ�Ԫ�ص������ʼ��
//	s.size = 0;
//}

//void SeqListPushBack(SL* ps, SLDataType x)
//{
//	if (ps->size == MAX_SIZE)
//	{
//		printf("SeqList is Full\n");
//		return;
//	}
//	ps->a[ps->size] = x;
//	ps->size++;
//}

//--------------------------------------------------------------

//��̬˳�����ƣ���С�ɱ䣩
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLDataType;	//�����޸����ݵ�����int���Ӷ��ﵽ�洢��ͬ���͵���
typedef struct SeqList
{
	SLDataType* a;//ָ�����aָ��̬���ٵ�����(�ռ�)��������̬���SLDataType���͵�����
	int size;//��Ч���ݵĸ���
	int capacity;//�����ռ�Ĵ�С
}SL,SeqList;

//1����ʼ��
void SeqListInit(SL* ps);
//�ռ�����
void SeqListDestory(SL* ps);
//3����ӡ
void SeqListPrint(SL* ps);
//6���������
void SeqListCheckCapacity(SL* ps);

//2��β��
void SeqListPushBack(SL* ps, SLDataType x);
//4��βɾ
void SeqListPopBack(SL* ps);
//5��ͷ��
void SeqListPushFront(SL* ps, SLDataType x);
//7��ͷɾ
void SeqListPopFront(SL* ps);

//8������λ�ò���
void SeqListInsert(SL* ps, int pos, SLDataType x);

//9������λ��ɾ��
void SeqListErase(SL* ps, int pos);

//10��˳������
int SeqListFind(SL* ps, SLDataType x);//�����ҵ��������±�
//...
//int SeqListSort(SL* ps, SLDataType x);
//int SeqListBinaryFind(SL* psl, SLDataType x);

//11��˳����޸�
void SeqListModify(SL* ps, int pos, SLDataType x);

#endif