
#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"
//写一个测试一个
//测试头尾插入删除
void TestSeqList1()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);

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

	//头删两个数据
	SeqListPopFront(&s);
	SeqListPopFront(&s);
	//打印
	SeqListPrint(&s);

	//在下标为3位置插入1
	SeqListInsert(&s, 2, 5);
	//打印
	SeqListPrint(&s);

	//在下标为0位置删除一个数据
	SeqListErase(&s, 0);
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

//尽量先不要写菜单，方便测试每个接口
void menu()
{
	printf("***************************************\n");
	printf("*******1、尾插数据  2、尾删数据********\n");
	printf("*******3、头插数据  4、头删数据********\n");
	printf("*******5、打印数据  -1、退出   ********\n");
	printf("***************************************\n");
	printf("请选择你的操作：");
}

void menuTest()
{
    SeqList s;
	SeqListInit(&s);

	int option = 0;
	int x = 0;
	while(option != -1)
	{
		menu();
		scanf("%d",&option);
		switch(option)
		{
			case 1: //尾插
				printf("请输入数据，以-1结束：");
				do
				{
					scanf("%d",&x);
					if(x != -1)
					{
						SeqListPushBack(&s,x);
					}
				}while(x != -1);
				break;
			case 2: //尾删
                SeqListPopBack(&s);
				break;
            case 3: //头插
                printf("请输入数据，以-1结束：");
				do
				{
					scanf("%d",&x);
					if(x != -1)
					{
						SeqListPushFront(&s, x);
					}
				}while(x != -1);
                break;
            case 4: //头删
                SeqListPopFront(&s);
                break;
            case 5: //打印
                SeqListPrint(&s);
                break;
            case -1://退出
                printf("正在退出...\n");
                SeqListDestory(&s);
                break;
            default:
                printf("输入错误，请重新输入！\n");
                break;
		}
	}
}

int main()
{
	//TestSeqList1();
	menuTest();
	return 0;
}
