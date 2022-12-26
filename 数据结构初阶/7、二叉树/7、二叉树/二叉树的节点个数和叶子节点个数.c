#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

typedef char BTDataType;
typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;//节点的左子树
	struct BinaryTreeNode* right;//节点的右子树
	BTDataType data;//节点的值
}BTNode;

#include "Queue.h"//包含头文件，要放在这里，展开时，否则找不到Queue.h找不到BTNode

//1、求二叉树节点的个数
//方法一：遍历计数
//将size定义为全局变量
/*
int size = 0;
void  BinaryTreeSize(BTNode* root)//注意：root表示节点指针，不仅仅指根节点
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		++size;
	}
	BinaryTreeSize(root->left);
	BinaryTreeSize(root->right);
}
*/

//方法二：遍历计数
//将size定义为静态变量
/*
int BinaryTreeSize(BTNode* root)//注意：root表示节点指针，不仅仅指根节点
{
	if (root == NULL)
	{
		return;
	}
	static int size = 0;
	++size;

	BinaryTreeSize(root->left);
	BinaryTreeSize(root->right);

	return size;
}
*/
//注意：以上两种方法，在多线程并发执行时，并行去计算两棵树，会出现干扰
//因此以上两个方法，不是线程安全的。

//方法三：传参
/*
void  BinaryTreeSize(BTNode* root, int size)//注意：root表示节点指针，不仅仅指根节点
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		++size;
	}
	BinaryTreeSize(root->left, size);
	BinaryTreeSize(root->right, size);
}
*/
/*
void  BinaryTreeSize(BTNode* root,int *psize)//注意：root表示节点指针，不仅仅指根节点
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		++(*psize);//解引用再++,相当于++size
	}
	BinaryTreeSize(root->left,psize);
	BinaryTreeSize(root->right,psize);
}
*/

//方法四：分治算法
//将一棵树分成根，左子树，右子树
//该树的节点可以计算为：左子树的节点个数+右子树的节点个数+1。
//左子树又可以继续再分成根，左子树，右子树，返回(左子树的节点个数+右子树的节点个数+1)......直到不可再分，返回0
int BinaryTreeSize(BTNode* root)//注意：root表示节点指针，不仅仅指根节点
{
	return root == NULL ? 0 : BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}

//2、求叶子节点的个数
//方法1：遍历计数，如果左右子树都为NULL，则size++
//方法2：分治算法
//将一棵树分成根，左子树，右子树
//该树的节点可以计算为：左子树的叶子节点个数+右子树的叶子节点个数。
//左子树又可以继续再分成根，左子树，右子树，返回(左子树的叶子节点个数+右子树的叶子节点个数)......直到不可再分，返回0
int BinaryTreeLeafSize(BTNode* root)//注意：root表示节点指针，不仅仅指根节点
{
	if (root == NULL)//节点为空
	{
		return 0;
	}
	if (root->left == NULL && root->right == NULL)
		return 1;
	//当以上两个都不满足，也就是当前节点还有子节点，既不是空，也不是叶子节点
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
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

	BinaryTreeSize(A);

	BinaryTreeLeafSize(A);
	return 0;
}
#endif