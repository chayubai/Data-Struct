#define _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h"

void TestQueue1()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);

	QueuePop(&q);
	QueuePop(&q);
	QueuePop(&q);
	QueuePop(&q);
	//QueuePop(&q);//队列为空，继续删除，报错
	//QueuePop删除最后一个元素，没有将tail置空，当调试发现tail为野指针

	//printf("%d\n", QueueBack(&q));//注释掉：QueueBack中的assert(!QueueEmpty(pq));会打印随机值

	QueuePush(&q, 5);
	QueuePush(&q, 6);

	QueueDestroy(&q);
}
//先进先出
void TestQueue2()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QDataType front = QueueFront(&q);
	printf("%d ", front);
	QDataType front = QueueFront(&q);
	printf("%d ", front);
	QueuePop(&q);
	QueuePush(&q, 5);

	//遍历队列
	while (!QueueEmpty(&q))
	{
		QDataType front = QueueFront(&q);
		printf("%d ", front);
		QueuePop(&q);
	}
	printf("\n");//1 2 3 4 5
	//队列的数据是绝对位置

	QueueDestroy(&q);
}
/*
int main()
{
	//TestQueue1();
	TestQueue2();
	return 0;
}
*/