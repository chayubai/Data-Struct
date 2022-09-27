
#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"
//写一个测试一个
//测试头尾插入删除
void TestSeqList1()
{
	SeqList s;
	SeqListInit(&s);
	//测试SeqListInit(s)
	//第八行，F9打断点，F5直接运行到断点处，F11进入函数内部
	//当如果不能进入函数，强制进入，可以在函数内部打一个断点，在进入

	//尾插1，2，3，4四个数据
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	//当插入第五个以及更多的数据，造成越界访问 - 扩容
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);
	SeqListPushBack(&s, 7);
	SeqListPushBack(&s, 8);
	//打印 - 尽管打印函数不会影响值的大小，但是传结构体浪费空间
	SeqListPrint(&s);
	//测试SeqListPushBack()
	//第八行，F9打断点，F5直接运行到断点处，F11进入函数内部
	//当如果不能进入函数，强制进入，可以在函数内部打一个断点，在进入
	//发现size > capacity，越界访问了
	
	//尾删两个数据
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	//打印
	SeqListPrint(&s);

	//头插-1，-2，-3三个数据，造成越界访问 - 扩容
	SeqListPushFront(&s, -1);
	SeqListPushFront(&s, -2);
	SeqListPushFront(&s, -3);
	//打印
	SeqListPrint(&s);
	//测试SeqListPushBack()
	//第八行，F9打断点，F5直接运行到断点处，F11进入函数内部
	//当如果不能进入函数，强制进入，可以在函数内部打一个断点，在进入
	//发现size > capacity，越界访问了

	SeqListPopFront(&s);
	SeqListPopFront(&s);
	//打印
	SeqListPrint(&s);

	//在第三个位置后面插入1
	SeqListInsert(&s, 3, 1);
	//在第三个位置后面删除一个数据
	SeqListErase(&s, 3);
	
	SeqListDestory(&s);

	//查找5，然后删除5
	int pos = SeqListFind(&s, 5);
	if (pos != -1)
	{
		SeqListErase(&s, pos);
	}
	//打印
	SeqListPrint(&s);
}
//int main()
//{
//	TestSeqList1();
//	return 0;
//}