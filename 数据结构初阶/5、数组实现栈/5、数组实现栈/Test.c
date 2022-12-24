#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"

void TestStack()
{
	ST st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);

	StackPop(&st);
	StackPop(&st);
	StackPop(&st);
	StackPop(&st);
	//StackPop(&st);//栈为空，继续删除，报错
	
	StackDestroy(&st);
}
//后进先出
void TestStack()
{
	ST st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);

	printf("%d ", StackTop(&st));
	StackPop(&st);
	printf("%d ", StackTop(&st));
	StackPop(&st);

	StackPush(&st, 5);
	StackPush(&st, 6);

	//栈的遍历
	//先打印当前栈顶的数据，再删除栈顶的数据。
	while (!StackEmpty(&st))
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}
	printf("\n");//4 3 6 5 2 1
	//队列的数据是相对位置
	
	StackDestroy(&st);
}
//int main()
//{
//	TestStack();
//	return 0;
//}