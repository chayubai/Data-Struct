#define _CRT_SECURE_NO_WARNINGS 1
//给你二叉树的根节点root，返回它节点值的前序遍历，即把返回的节点值放入数组中

#include <stdio.h>
#include <stdlib.h>
struct TreeNode
{
	struct TreeNode* left;//节点的左子树
	struct TreeNode* right;//节点的右子树
	int data;//节点的值
};

int TreeSize(struct TreeNode* root)
{
	return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}

//思路：中序遍历
void _prevOrder(struct TreeNode* root, int* a, int* pi)//i作为址传递
{
	if (root == NULL)
		return;
	//左子树
	_prevOrder(root->left, a, pi);
	//根
	a[*pi] = root->data;
	++(*pi);
	//右子树
	_prevOrder(root->right, a, pi);
}
int* preorderTraversal(struct TreeNode* root, int* returnSize)//root输入型参数，returnSize输出型参数
{
	int size = TreeSize(root);
	int* a = (int*)malloc(sizeof(int) * size);
	int i = 0;
	_prevOrder(root, a, &i);

	*returnSize = size;//*returnSize操作的是外边的size，使得size的值能够改变
	return a;
}

#if 0
int main()
{
	//测试功能
	//    1
	//  2   3
	struct TreeNode node1;
	struct TreeNode node2;
	struct TreeNode node3;
	node1.data = 1;
	node1.left = &node2;
	node1.right = &node3;

	node2.data = 2;
	node2.left = NULL;
	node2.right = NULL;

	node3.data = 3;
	node3.left = NULL;
	node3.right = NULL;

	int size = 0;
	int* a = preorderTraversal(&node1, &size);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}
#endif