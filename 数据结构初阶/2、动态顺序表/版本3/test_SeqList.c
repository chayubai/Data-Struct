
#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

void TestSeqList1()
{
	SeqList s;
	SeqListInit(&s);

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

	//尾删
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	//打印
	SeqListPrint(&s);
}
void TestSeqList2()
{
    SeqList s;
	SeqListInit(&s);
    //尾插1，2，3，4四个数据
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
    //打印
	SeqListPrint(&s);

	//头插-1，-2，-3三个数据，造成越界访问 - 扩容
	SeqListPushFront(&s, -1);
	SeqListPushFront(&s, -2);
	SeqListPushFront(&s, -3);
	SeqListPushFront(&s, -1);
	SeqListPushFront(&s, -2);
	SeqListPushFront(&s, -3);
	//打印
	SeqListPrint(&s);

	SeqListPopFront(&s);
	SeqListPopFront(&s);
	//打印
	SeqListPrint(&s);

}

void TestSeqList3()
{
    SeqList s;
	SeqListInit(&s);
    //尾插1，2，3，4四个数据
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
    //打印
	SeqListPrint(&s);

	//在下标为3的位置插入1
	SeqListInsert(&s, 3, 1);
	//打印
	SeqListPrint(&s);
	//在第三个位置后面删除一个数据
	SeqListErase(&s, 3);
    //打印
	SeqListPrint(&s);

	//查找5，然后删除5
	int pos = SeqListFind(&s, 5);
	if (pos != -1)
	{
		SeqListErase(&s, pos);
	}
	//打印
	SeqListPrint(&s);

	SeqListDestory(&s);
}
int main()
{
	//TestSeqList1();
	//TestSeqList2();
	TestSeqList3();
	return 0;
}
