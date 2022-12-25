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
	//QueuePop(&q);//����Ϊ�գ�����ɾ��������
	//QueuePopɾ�����һ��Ԫ�أ�û�н�tail�ÿգ������Է���tailΪҰָ��

	//printf("%d\n", QueueBack(&q));//ע�͵���QueueBack�е�assert(!QueueEmpty(pq));���ӡ���ֵ

	QueuePush(&q, 5);
	QueuePush(&q, 6);

	QueueDestroy(&q);
}
//�Ƚ��ȳ�
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

	//��������
	while (!QueueEmpty(&q))
	{
		QDataType front = QueueFront(&q);
		printf("%d ", front);
		QueuePop(&q);
	}
	printf("\n");//1 2 3 4 5
	//���е������Ǿ���λ��

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