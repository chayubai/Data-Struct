#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"
//写一个模块测试一个模块
//测试头尾插入删除
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
	//SeqListPopBack(&s);
	//调试，发现size越界，为-1，ps[size] = x非法访问
	
	//打印
	SeqListPrint(&s);

	SeqListDestory(&s);
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

	SeqListDestory(&s);
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
	//删除下标为3位置的数据
	SeqListErase(&s, 3);
	//打印
	SeqListPrint(&s);

	//查找5，然后删除5，如果有多个5，可以使用循环删除
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

/*
void Test()
{
	SeqList s;
	SeqListInit(&s);
	//测试SeqListInit(s)
	//第八行，F9打断点，F5直接运行到断点处，F11进入函数内部
	//当如果不能进入函数，强制进入，可以在函数内部打一个断点，再进入

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
	//当如果不能进入函数，强制进入，可以在函数内部打一个断点，再进入
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
	//测试SeqListPushFront()
	//第八行，F9打断点，F5直接运行到断点处，F11进入函数内部
	//当如果不能进入函数，强制进入，可以在函数内部打一个断点，再进入
	//发现size > capacity，越界访问了

	//头删两个数据
	SeqListPopFront(&s);
	SeqListPopFront(&s);
	//打印
	SeqListPrint(&s);

	//在下标为3位置插入1
	SeqListInsert(&s, 3, 1);
	//删除下标为3位置的数据
	SeqListErase(&s, 3);

	//查找5的下标，然后删除5
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
	Test();
	return 0;
}
*/

//----------------------------------------------------------------------------

//尽量先不要写菜单，一上来写菜单，不便测试每个接口。等所有接口都实现完且测试没问题后，再写菜单。
/*
void menu()
{
	printf("***************************************\n");
	printf("****** 1、尾插数据   2、尾删数据 ******\n");
	printf("****** 3、头插数据   4、头删数据 ******\n");
	printf("****** 5、打印数据  -1、退出     ******\n");
	printf("***************************************\n");
	printf("请选择你的操作：");
}
int main()
{
	SeqList s;
	SeqListInit(&s);
	int option = 0;
	int x = 0;
	while(option != -1)
	{
		menu();
		scanf("%d",&option);//优化：屏蔽非法输入
		switch(option)
		{
			case 1:
				printf("请输入数据，以-1结束：");
				do
				{
					scanf("%d",&x);//注意：多组输入后，一次只能接收一个数据，遇到-1结束接收
					if(x != -1)
					{
						SeqListPushBack(&s,x);//有缺陷 不能插入-1
					}
				}while(x != -1);
				break;
			case 2:
				SeqListPopBack(&s);
				break;
			case 3:
				printf("请输入数据，以-1结束：");
				scanf("%d",&x);
				while(x != -1)
				{
					if(x != -1)
					{
						SeqListPushBack(&s,x);//有缺陷 不能插入-1
						scanf("%d",&x);//注意：多组输入后，一次只能接收一个数据，遇到-1结束接收
					}
				}
				break;
			case 4:
				SeqListPopFront(&s);
				break;
			case 5:
				SeqListPrint(&s);
				break;
		}
	}
	SeqListDestory(&s);
	return 0;
}
*/