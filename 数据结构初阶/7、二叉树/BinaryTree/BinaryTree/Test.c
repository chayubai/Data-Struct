#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

typedef char BTDataType;
typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;//根节点的左子树
	struct BinaryTreeNode* right;//根节点的右子树
	BTDataType data;//根节点的值
}BTNode;

#include "Queue.h"//包含头文件，要放在这里，展开时，否则找不到Queue.h找不到BTNode

//前序遍历：根 左子树 右子树
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
//中序遍历：左子树 根 右子树
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
//后序遍历：左子树 右子树 根
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

//求二叉树节点的个数 - 遍历计数
//方法一：将size定义为全局变量
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

//方法二：
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
//以上两种方法，在多线程并发执行时，会出现干扰

//方法三：
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
//		++(*psize);//解引用再++,相当于++size
//	}
//	BinaryTreeSize(root->left,psize);
//	BinaryTreeSize(root->right,psize);
//}

//方法四：分治算法
int  BinaryTreeSize(BTNode* root)
{
	return root == NULL ? 0 : BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}

//求叶子节点的个数
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

//层序遍历 - 使用队列实现遍历
void LevelOrder(BTNode* root)
{
	//核心思路：上一层出数据的时候，带下一层节点进入栈中
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
//	//方法一，方法二的测试
//	//BinaryTreeSize(A);
//	//printf("A：%d ", size);
//	//size = 0;//这里要置零，否则BinaryTreeSize(B);时，会在之前的基础上size继续++
//	//BinaryTreeSize(B);
//	//printf("B：%d ", size);
//
//	//方法三的测试
//	int Asize = 0;
//	BinaryTreeSize(A,&Asize);//这里要传址
//	printf("A：%d ", Asize);
//	int Bsize = 0;
//	BinaryTreeSize(B, &Bsize);//这里要传址
//	printf("B：%d ", Bsize);
//
//	LevelOrder(A);
//	return 0;
//}