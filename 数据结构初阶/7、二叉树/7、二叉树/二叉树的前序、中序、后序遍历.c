#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//二叉树的前序、中序、后序遍历也叫深度优先遍历。层序遍历也叫广度优先遍历。

typedef char BTDataType;
//定义二叉树的节点
typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;//节点的左子树
	struct BinaryTreeNode* right;//节点的右子树
	BTDataType data;//节点的值
}BTNode;

//前序遍历：根 左子树 右子树
void PrevOrder(BTNode* root)//注意：root表示节点指针，不仅仅指根节点
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
void InOrder(BTNode* root)//注意：root表示节点指针，不仅仅指根节点
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
void PostOrder(BTNode* root)//注意：root表示节点指针，不仅仅指根节点
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

	PrevOrder(A);
	printf("\n");
	InOrder(A);
	printf("\n");
	PostOrder(A);
	printf("\n");

	return 0;
}
#endif