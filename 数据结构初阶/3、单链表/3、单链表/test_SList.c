#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"
void TestSList1()
{
	//存放头指针,第一个结点为空链表
	SListNode* pList = NULL;//NULL = 0x00000000

	//SListPushBack(pList, 1);//传值调用，即传了NULL，导致pList内的数据没有改变

	SListPushBack(&pList, 1);
	SListPushBack(&pList, 2);//此之后的&pList不再等于NULL
	SListPushBack(&pList, 3);
	SListPushBack(&pList, 4);
	SListPrint(pList);

	SListPopBack(&pList);
	SListPopBack(&pList);
	SListPopBack(&pList);
	SListPopBack(&pList);
	SListPopBack(&pList);
	SListPrint(pList);

	SListPushFront(&pList, 0);
	SListPushFront(&pList, -1);
	SListPushFront(&pList, -2);
	SListPushFront(&pList, -3);
	SListPrint(pList);

	SListPopFront(&pList);
	SListPopFront(&pList);
	SListPopFront(&pList);
	SListPopFront(&pList);
	SListPopFront(&pList);
	SListPrint(pList);
}

void TestSList2()
{
	SListNode* pList = NULL;

	SListPushBack(&pList, 1);
	SListPushBack(&pList, 2);
	SListPushBack(&pList, 3);
	SListPushBack(&pList, 4);
	SListPrint(pList);

	SListNode* cur = SListFind(pList, 3);
	//不为空指针，则找到了
	if (cur)
	{
		cur->data = 30;//修改当前pos指针处的值
	}
	SListPrint(pList);
}

void TestSList3()
{
	SListNode* pList = NULL;

	SListPushBack(&pList, 1);
	SListPushBack(&pList, 2);
	SListPushBack(&pList, 3);
	SListPushBack(&pList, 4);
	SListPrint(pList);

	//找到了，返回该值的指针
	SListNode* pos = SListFind(pList, 3);
	//不为空指针，则找到了
	if (pos)
	{
		SListInsertBefore(&pList,pos,30);
	}
	SListPrint(pList);

	pos = SListFind(pList, 3);
	//不为空指针，则找到了
	if (pos)
	{
		SListErase(&pList,pos);
	}
	SListPrint(pList);
}

void TestSList4()
{
	SListNode* pList = NULL;

	SListPushBack(&pList, 1);
	SListPushBack(&pList, 2);
	SListPushBack(&pList, 3);
	SListPushBack(&pList, 4);
	SListPrint(pList);

	//找到了，返回该值的指针
	SListNode* pos = SListFind(pList, 4);
	if(pos)
        		SListInsertAfter(pos, 9);//在数据为4的结点后插入数据9
	SListPrint(pList);

	//找到了，返回该值的指针
	pos = SListFind(pList, 3);
	if(pos)
        SListEraseAfter(pos);//删除数据为3的结点后的数据
	SListPrint(pList);

}

void TestSList5()
{
	SListNode* pList = NULL;

	SListPushBack(&pList, 1);
	SListPushBack(&pList, 2);
	SListPushBack(&pList, 3);
	SListPushBack(&pList, 2);
	SListPushBack(&pList, 4);
	SListPushBack(&pList, 2);
	SListPrint(pList);

	//找到了，返回该值的指针
	SListNode* pos = SListFind(pList, 2);
	int count = 1;
	while(pos)
   	 {
       	pos->data = 10;//修改
       	printf("第%d个pos结点:%p: %d\n",count++,pos,pos->data);
        pos = SListFind(pos->next,2);
   	 }
	SListPrint(pList);
}
/*
int main()
{
	//TestSList1();
	//TestSList2();
	//TestSList3();
    //TestSList4();
   	TestSList5();
	return 0;
}
*/
