#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//#include "Queue.h"//头文件展开，此时Queue.h头文件找不到BTNode的定义
//二叉树的层序遍历，也叫广度优先遍历。即从根节点开始一层一层的遍历

typedef char BTDataType;
typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;//节点的左子树
	struct BinaryTreeNode* right;//节点的右子树
	BTDataType data;//节点的值
}BTNode;

#include "Queue.h"//包含头文件，要放在这里，展开时，Queue.h才能找到BTNode的定义

//3、层序遍历：使用队列实现遍历
//     A
//   B   C
// D  E
//最开始先A入队，A出队。再把下一层的B、C入队。B出队，再把下一层的D、E入队...当队列为空，结束遍历。
//队列的数据变化：
//A
//  B C
//    C D E
//      D E
//        E
//
//注意：队列数据域存的是二叉树的节点指针
void LevelOrder(BTNode* root)//注意：root仅仅指根节点
{
	//核心思路：从根节点开始入队，每次当上一层出队(数据)的时候，将下一层节点入队
	Queue q;
	QueueInit(&q);
	if (root != NULL)
	{
		QueuePush(&q, root);
	}
	//遍历
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);//从队列中取出指针(二叉树节点)元素，并没有删除元素，删除的是队列的节点
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