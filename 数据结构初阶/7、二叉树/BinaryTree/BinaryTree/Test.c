#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

typedef char BTDataType;
typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;//���ڵ��������
	struct BinaryTreeNode* right;//���ڵ��������
	BTDataType data;//���ڵ��ֵ
}BTNode;

#include "Queue.h"//����ͷ�ļ���Ҫ�������չ��ʱ�������Ҳ���Queue.h�Ҳ���BTNode

//ǰ��������� ������ ������
void PrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%c ", root->data);
	PrevOrder(root->left);
	PrevOrder(root->right);
}
//��������������� �� ������
void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	InOrder(root->left);
	printf("%c ", root->data);
	InOrder(root->right);
}
//��������������� ������ ��
void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	PostOrder(root->left);
	PostOrder(root->right);
	printf("%c ", root->data);
}

//��������ڵ�ĸ��� - ��������
//����һ����size����Ϊȫ�ֱ���
//int size = 0;
//void  BinaryTreeSize(BTNode* root)
//{
//	if (root == NULL)
//	{
//		return;
//	}
//	else
//	{
//		++size;
//	}
//	BinaryTreeSize(root->left);
//	BinaryTreeSize(root->right);
//}

//��������
//int BinaryTreeSize(BTNode* root)
//{
//	if (root == NULL)
//	{
//		return;
//	}
//	static int size = 0;
//	++size;
//
//	BinaryTreeSize(root->left);
//	BinaryTreeSize(root->right);
//
//	return size;
//}
//�������ַ������ڶ��̲߳���ִ��ʱ������ָ���

//��������
//void  BinaryTreeSize(BTNode* root, int size)
//{
//	if (root == NULL)
//	{
//		return;
//	}
//	else
//	{
//		++size;
//	}
//	BinaryTreeSize(root->left, size);
//	BinaryTreeSize(root->right, size);
//}
//void  BinaryTreeSize(BTNode* root,int *psize)
//{
//	if (root == NULL)
//	{
//		return;
//	}
//	else
//	{
//		++(*psize);//��������++,�൱��++size
//	}
//	BinaryTreeSize(root->left,psize);
//	BinaryTreeSize(root->right,psize);
//}

//�����ģ������㷨
int  BinaryTreeSize(BTNode* root)
{
	return root == NULL ? 0 : BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}

//��Ҷ�ӽڵ�ĸ���
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL && root->right == NULL)
		return 1;
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}

//������� - ʹ�ö���ʵ�ֱ���
void LevelOrder(BTNode* root)
{
	//����˼·����һ������ݵ�ʱ�򣬴���һ��ڵ����ջ��
	Queue q;
	QueueInit(&q);
	if (root != NULL)
	{
		QueuePush(&q, root);
	}
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
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
//
//int main()
//{
//	BTNode* A = (BTNode*)malloc(sizeof(BTNode));
//	A->data = 'A';
//	A->left = NULL;
//	A->right = NULL;
//
//	BTNode* B = (BTNode*)malloc(sizeof(BTNode));
//	B->data = 'B';
//	B->left = NULL;
//	B->right = NULL;
//
//	BTNode* C = (BTNode*)malloc(sizeof(BTNode));
//	C->data = 'C';
//	C->left = NULL;
//	C->right = NULL;
//
//	BTNode* D = (BTNode*)malloc(sizeof(BTNode));
//	D->data = 'D';
//	D->left = NULL;
//	D->right = NULL;
//
//	BTNode* E = (BTNode*)malloc(sizeof(BTNode));
//	E->data = 'E';
//	E->left = NULL;
//	E->right = NULL;
//
//	A->left = B;
//	A->right = C;
//	B->left = D;
//	B->right = E;
//
//	PrevOrder(A);
//	printf("\n");
//	InOrder(A);
//	printf("\n");
//	PostOrder(A);
//	printf("\n");
//
//	//����һ���������Ĳ���
//	//BinaryTreeSize(A);
//	//printf("A��%d ", size);
//	//size = 0;//����Ҫ���㣬����BinaryTreeSize(B);ʱ������֮ǰ�Ļ�����size����++
//	//BinaryTreeSize(B);
//	//printf("B��%d ", size);
//
//	//�������Ĳ���
//	int Asize = 0;
//	BinaryTreeSize(A,&Asize);//����Ҫ��ַ
//	printf("A��%d ", Asize);
//	int Bsize = 0;
//	BinaryTreeSize(B, &Bsize);//����Ҫ��ַ
//	printf("B��%d ", Bsize);
//
//	LevelOrder(A);
//	return 0;
//}