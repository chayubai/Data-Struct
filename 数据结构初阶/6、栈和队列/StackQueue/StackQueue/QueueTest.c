#define _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h"
void TestQueue()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QDataType front = QueueFront(&q);
	printf("%d ", front);
	QueuePop(&q);
	QueuePush(&q, 5);

	while (!QueueEmpty(&q))
	{
		QDataType front = QueueFront(&q);
		printf("%d ", front);
		QueuePop(&q);
	}
	printf("\n");

	QueueDestroy(&q);
}
int main()
{
	TestQueue();
	return 0;
}