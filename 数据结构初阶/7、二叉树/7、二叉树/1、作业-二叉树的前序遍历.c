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

//由于不知道定义多大的数组，且不能返回局部变量的地址，所以不能采用静态数组，应该采用动态内存开辟数组。
//由于二叉树节点个数，就无法确定开多大的空间，因此需要先求二叉树的节点个数。
int TreeSize(struct TreeNode* root)
{
	return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}

//思路：先序遍历
/*
void _prevOrder(struct TreeNode* root, int* a, int i)//i作为值传递,注意：root表示节点指针，不仅仅指根节点
{
	if (root == NULL)
		return;

	//根
	a[i] = root->data;//把节点的值存入数组中
	++i;
	//左子树
	_prevOrder(root->left, a, i);
	//右子树
	_prevOrder(root->right, a, i);
}
*/
//画递归展开图，分析结果：1 3 随机值。
//第一次调用_prevOrder(root, a, i)，i = 0。
//进入函数体，由于i = 0时, 将1放到a[0]处，++i后i = 1，执行_prevOrder(root->left, a, i)语句
//第二次调用_prevOrder(root, a, i)，i = 1。
//进入函数体，由于i = 1时, 将2放到a[1]处，++i后i = 2，执行_prevOrder(root->left, a, i)语句，返回。
//由于i是值传递，i的值不会受影响，再执行_prevOrder(root->right, a, i)语句，此时i仍为1。
//进入函数体，由于i = 1时, 将3放到a[1]处，++i后i = 2，执行_prevOrder(root->left, a, i)语句，返回。

//方法1：
/*
void _prevOrder(struct TreeNode* root, int* a, int* pi)//i作为址传递,注意：root表示节点指针，不仅仅指根节点
{
	if (root == NULL)
		return;

	a[*pi] = root->data;
	++(*pi);

	_prevOrder(root->left, a, pi);
	_prevOrder(root->right, a, pi);
}
int* preorderTraversal(struct TreeNode* root, int* returnSize)//root输入型参数，returnSize输出型参数,注意：root表示节点指针，不仅仅指根节点
{
	int size = TreeSize(root);
	int* a = (int*)malloc(sizeof(int) * size);
	int i = 0;
	_prevOrder(root, a, &i);

	*returnSize = size;//*returnSize操作的是外边的size，使得size的值能够改变
	return a;
}
*/

//方法2：
//将i定义为全局变量是否可行？
int i = 0;
void _prevOrder(struct TreeNode* root, int* a)//注意：root表示节点指针，不仅仅指根节点
{
	if (root == NULL)
		return;

	a[i] = root->data;
	++i;

	_prevOrder(root->left, a);
	_prevOrder(root->right, a);
}
int* preorderTraversal(struct TreeNode* root, int* returnSize)//注意：root仅仅指根节点
{
	i = 0;//这里需要注意，调用preorderTraversal之前i需要置零
	//由于在Leetcode上，有多个测试用例，会导致i一直累加，最后不能通过所有的测试用例，
	int size = TreeSize(root);
	int* a = (int*)malloc(sizeof(int) * size);

	_prevOrder(root, a);

	*returnSize = size;//*returnSize操作的是外边的size，使得size的值能够改变
	return a;
}
//注意：全局变量，当有多个线程同时调用preorderTraversal，存在线程安全问题。

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