#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//#include "Queue.h"//ͷ�ļ�չ������ʱQueue.hͷ�ļ��Ҳ���BTNode�Ķ���
//�������Ĳ��������Ҳ�й�����ȱ��������Ӹ��ڵ㿪ʼһ��һ��ı���

typedef char BTDataType;
typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;//�ڵ��������
	struct BinaryTreeNode* right;//�ڵ��������
	BTDataType data;//�ڵ��ֵ
}BTNode;

#include "Queue.h"//����ͷ�ļ���Ҫ�������չ��ʱ��Queue.h�����ҵ�BTNode�Ķ���

//3�����������ʹ�ö���ʵ�ֱ���
//     A
//   B   C
// D  E
//�ʼ��A��ӣ�A���ӡ��ٰ���һ���B��C��ӡ�B���ӣ��ٰ���һ���D��E���...������Ϊ�գ�����������
//���е����ݱ仯��
//A
//  B C
//    C D E
//      D E
//        E
//
//ע�⣺�������������Ƕ������Ľڵ�ָ��
void LevelOrder(BTNode* root)//ע�⣺root����ָ���ڵ�
{
	//����˼·���Ӹ��ڵ㿪ʼ��ӣ�ÿ�ε���һ�����(����)��ʱ�򣬽���һ��ڵ����
	Queue q;
	QueueInit(&q);
	if (root != NULL)
	{
		QueuePush(&q, root);
	}
	//����
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);//�Ӷ�����ȡ��ָ��(�������ڵ�)Ԫ�أ���û��ɾ��Ԫ�أ�ɾ�����Ƕ��еĽڵ�
		printf("%c ", front->data);

		if (front->left != NULL)
		{
			QueuePush(&q, front->left);
		}
		if (front->right != NULL)
		{
			QueuePush(&q, front->right);
		}
	}
	printf("\n");
	QueueDestroy(&q);
}
#if 0
int main()
{
	BTNode* A = (BTNode*)malloc(sizeof(BTNode));
	A->data = 'A';
	A->left = NULL;
	A->right = NULL;

	BTNode* B = (BTNode*)malloc(sizeof(BTNode));
	B->data = 'B';
	B->left = NULL;
	B->right = NULL;

	BTNode* C = (BTNode*)malloc(sizeof(BTNode));
	C->data = 'C';
	C->left = NULL;
	C->right = NULL;

	BTNode* D = (BTNode*)malloc(sizeof(BTNode));
	D->data = 'D';
	D->left = NULL;
	D->right = NULL;

	BTNode* E = (BTNode*)malloc(sizeof(BTNode));
	E->data = 'E';
	E->left = NULL;
	E->right = NULL;

	A->left = B;
	A->right = C;
	B->left = D;
	B->right = E;

	LevelOrder(A);
	return 0;
}
#endif