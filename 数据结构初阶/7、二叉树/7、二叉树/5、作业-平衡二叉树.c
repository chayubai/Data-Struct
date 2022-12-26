#define _CRT_SECURE_NO_WARNINGS 1
//����һ�����������ж����Ƿ��Ǹ߶�ƽ��Ķ�����
//�߶�ƽ���������һ�������� ÿ���ڵ� ���������������ĸ߶Ȳ�ľ���ֵ������1
//˼�룺�����㷨
//1����ǰ���ĸ��ڵ㣬���ڵ���������ƽ�������������������false��������Ҫ�ж�
//2����ǰ���ĸ��ڵ㣬���ڵ�������ƽ����������������ټ�����������Ƿ����㣬���������������ֽ������������
//		�����ֽ�ɣ��жϵ�ǰ���ĸ��ڵ��Ƿ�������������������ټ�����������Ƿ�����
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
struct TreeNode
{
	struct TreeNode* left;//�ڵ��������
	struct TreeNode* right;//�ڵ��������
	int data;//�ڵ��ֵ
};
int maxDepth(struct TreeNode* root)//ע�⣺root��ʾ�ڵ�ָ�룬������ָ���ڵ�
{
	if (root == NULL)
	{
		return 0;
	}
	int leftDepth = maxDepth(root->left);
	int rightDepth = maxDepth(root->right);
	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}
bool isBalancedTree(struct TreeNode* root)//ע�⣺root��ʾ�ڵ�ָ�룬������ָ���ڵ�
{
	//��������
	if (root == NULL)
		return true;
	int leftDepth = maxDepth(root->left);//�������������
	int rightDepth = maxDepth(root->right);//�������������

	return abs(leftDepth - rightDepth) < 2 
		&& isBalancedTree(root->left) && isBalancedTree(root->right);

	//abs(leftDepth - rightDepth)�Ǽ�鵱ǰ�ڵ��Ƿ�����������������Ҫ�󣬵���������ݹ���������������...ֱ�����е������������һ������Ҫ��
}
//ע�⣺���ݹ�չ��ͼ������⡣

#if 0
int main()
{
	//���Թ���
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