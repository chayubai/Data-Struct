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
	//StackPop(&st);//ջΪ�գ�����ɾ��������
	
	StackDestroy(&st);
}
//����ȳ�
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

	//ջ�ı���
	//�ȴ�ӡ��ǰջ�������ݣ���ɾ��ջ�������ݡ�
	while (!StackEmpty(&st))
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}
	printf("\n");//4 3 6 5 2 1
	//���е����������λ��
	
	StackDestroy(&st);
}
//int main()
//{
//	TestStack();
//	return 0;
//}