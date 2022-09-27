#define _CRT_SECURE_NO_WARNINGS 1
//#pragma once	//防止被重复包含

#ifndef __SEQLIST__H__
#define __SEQLIST__H__

//顺序表

//顺序表，有效数据在数组中必须是连续的
//静态顺序表设计（固定大小）
//问题：给少了不够用，给多了用不完浪费，不能灵活控制
//struct SeqList
//{
//	int a[10];//定长的数组
//	int size;//有效数据的个数
//};

//typedef int SLDataType;	//便于修改数据的类型int，从而达到存储不同类型的数
//#define N 10	//便于修改a数组的大小
//struct SeqList
//{
//	SLDataType a[N];
//	int size;
//};

//--------------------------------------------------------------

//动态顺序表设计（大小可变）
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int SLDataType;	//便于修改数据的类型int，从而达到存储不同类型的数
typedef struct SeqList
{
	SLDataType* a;//指针变量a指向动态开辟的数组(空间)，用来动态存放SLDataType类型的数据
	int size;//有效数据的个数
	int capacity;//容量空间的大小
}SL,SeqList;

//1、初始化
void SeqListInit(SL* ps);
//空间销毁
void SeqListDestory(SL* ps);
//3、打印
void SeqListPrint(SL* ps);
//6、检查容量
void SeqListCheckCapacity(SL* ps);

//2、尾插
void SeqListPushBack(SL* ps, SLDataType x);
//4、尾删
void SeqListPopBack(SL* ps);
//5、头插
void SeqListPushFront(SL* ps, SLDataType x);
//7、头删
void SeqListPopFront(SL* ps);

/8、任意位置插入
void SeqListInsert(SL* ps, int pos, SLDataType x);

//9、任意位置删除
void SeqListErase(SL* ps, int pos);

//10、顺序表查找
int SeqListFind(SL* psl, SLDataType x);//返回找到的数的下标
//...
//int SeqListSort(SL* psl, SLDataType x);
//int SeqListBinaryFind(SL* psl, SLDataType x);

#endif