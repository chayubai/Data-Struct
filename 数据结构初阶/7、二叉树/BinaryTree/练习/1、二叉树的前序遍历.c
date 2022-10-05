#define _CRT_SECURE_NO_WARNINGS 1
//给你二叉树的根节点root，返回它节点值的前序遍历，即把返回的节点值放入数组中

#include <stdio.h>
#include <stdlib.h>
struct TreeNode
{
	struct TreeNode* left;//根节点的左子树
	struct TreeNode* right;//根节点的右子树
	int data;//根节点的值
};
//由于不知道定义多大的数组，且不能返回局部变量的地址，所以采用动态内存开辟数组
//由于二叉树节点个数，就无法确定开多大的空间，因此需要先求二叉树的节点个数
int TreeSize(struct TreeNode* root)
{
	return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}

//思路：先序遍历的进行中，同时把节点的值存入数组中
//void _prevOrder(struct TreeNode* root, int* a, int i)
//{
//	if (root == NULL)
//		return;
//
//	a[i] = root->data;
//	++i;
//
//	_prevOrder(root->left, a, i);
//	_prevOrder(root->right, a, i);
//}
//由于i = 0时, ++i后，_prevOrder(root->left, a, i)中的i = 1
//再调用_prevOrder(struct TreeNode* root, int* a, int i)时，int i为新的独立空间，与前一个i无关，
//此时i = 1传入函数，++i后，i = 2,但调用_prevOrder(root->right, a, i)时
//不会影响_prevOrder(root->right, a, i)的i，此时的_prevOrder(root->right, a, i)的i仍为1
//void _prevOrder(struct TreeNode* root, int* a, int* pi)
//{
//	if (root == NULL)
//		return;
//
//	a[*pi] = root->data;
//	++(*pi);
//
//	_prevOrder(root->left, a, pi);
//	_prevOrder(root->right, a, pi);
//}
//int* preorderTraversal(struct TreeNode* root, int* returnSize)
//{
//	int size = TreeSize(root);
//	int* a = (int*)malloc(sizeof(int) * size);
//	int i = 0;
//	_prevOrder(root, a, &i);
//
//	*returnSize = size;//*returnSize操作的是外边的size，使得size的值能够改变
//	return a;
//}

//将i定义为全局变量是否可行？
int i = 0;
void _prevOrder(struct TreeNode* root, int* a)
{
	if (root == NULL)
		return;

	a[i] = root->data;
	++i;

	_prevOrder(root->left, a);
	_prevOrder(root->right, a);
}
int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
	i = 0;//这里需要注意，Leetcode上，由于有多个测试用例，会导致i一直累加，最后不能通过，需要置零
	int size = TreeSize(root);
	int* a = (int*)malloc(sizeof(int) * size);

	_prevOrder(root, a);

	*returnSize = size;//*returnSize操作的是外边的size，使得size的值能够改变
	return a;
}

//int main()
//{
//	//测试功能
//	struct TreeNode node1;
//	struct TreeNode node2;
//	struct TreeNode node3;
//	node1.data = 1;
//	node1.left = &node2;
//	node1.right = &node3;
//
//	node2.data = 2;
//	node2.left = NULL;
//	node2.right = NULL;
//
//	node3.data = 3;
//	node3.left = NULL;
//	node3.right = NULL;
//	int size = 0;
//	int* a = preorderTraversal(&node1, &size);
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	return 0;
//}