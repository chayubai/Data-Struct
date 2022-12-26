#define _CRT_SECURE_NO_WARNINGS 1
//给定一个二叉树，判断它是否是高度平衡的二叉树
//高度平衡二叉树：一个二叉树 每个节点 的左右两个子树的高度差的绝对值不超过1
//思想：分治算法
//1、当前树的根节点，所在的树不满足平衡二叉树的条件，返回false，后续不要判断
//2、当前树的根节点，所在的树满足平衡二叉树的条件，再检查左，右子树是否满足，（左右子树继续分解成以上两步）
//		继续分解成，判断当前树的根节点是否满足二叉树的条件，再检查左，右子树是否满足
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
struct TreeNode
{
	struct TreeNode* left;//节点的左子树
	struct TreeNode* right;//节点的右子树
	int data;//节点的值
};
int maxDepth(struct TreeNode* root)//注意：root表示节点指针，不仅仅指根节点
{
	if (root == NULL)
	{
		return 0;
	}
	int leftDepth = maxDepth(root->left);
	int rightDepth = maxDepth(root->right);
	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}
bool isBalancedTree(struct TreeNode* root)//注意：root表示节点指针，不仅仅指根节点
{
	//空树满足
	if (root == NULL)
		return true;
	int leftDepth = maxDepth(root->left);//计算左子树深度
	int rightDepth = maxDepth(root->right);//计算右子树深度

	return abs(leftDepth - rightDepth) < 2 
		&& isBalancedTree(root->left) && isBalancedTree(root->right);

	//abs(leftDepth - rightDepth)是检查当前节点是否满足搜索二叉树的要求，当满足继续递归左子树和右子树...直到所有的子树都检查了一遍满足要求。
}
//注意：画递归展开图进行理解。

#if 0
int main()
{
	//测试功能
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

	if (isBalancedTree(&node1))
		printf("Yes");
	else
		printf("No");
	return 0;
}
#endif