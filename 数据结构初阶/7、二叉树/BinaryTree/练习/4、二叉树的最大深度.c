#define _CRT_SECURE_NO_WARNINGS 1
//给定一个二叉树，找出其最大深度
//二叉树的深度为根节点到最远叶子节点的最长路径上的节点数
//叶子节点是指没有子节点的节点

#include <stdio.h>
#include <stdlib.h>
struct TreeNode
{
	struct BinaryTreeNode* left;//根节点的左子树
	struct BinaryTreeNode* right;//根节点的右子树
	int data;//根节点的值
};
//由于不知道定义多大的数组，且不能返回局部变量的地址，所以采用动态内存开辟数组
//由于二叉树节点个数，就无法确定开多大的空间，因此需要先求二叉树的节点个数

//思路：分治
//1、树为空，高度为0
//2、树非空，分解子问题
//		先求左，右子树的深度，再取深度大的+1（左右子树继续分解成以上两步）
//错误答案：maxDepth(root->left)和maxDepth(root->left) + 1递归调用导致死循环
//int maxDepth(struct TreeNode* root)
//{
//	if (root == NULL)
//	{
//		return 0;
//	}
//	return maxDepth(root->left) > maxDepth(root->right) ? maxDepth(root->left) + 1 : maxDepth(root->right) + 1;
//}

//正确答案：
//int maxDepth(struct TreeNode* root)
//{
//	if (root == NULL)
//	{
//		return 0;
//	}
//	int leftDepth = maxDepth(root->left);
//	int rightDepth = maxDepth(root->right);
//	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
//}
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
//
//	int  MaxDepth = maxDepth(&node1);
//	printf("%d ", MaxDepth);
//
//	return 0;
//}