#define _CRT_SECURE_NO_WARNINGS 1
//����һ�����������ҳ���������
//�����������Ϊ���ڵ㵽��ԶҶ�ӽڵ���·���ϵĽڵ���
//Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ�

#include <stdio.h>
#include <stdlib.h>
struct TreeNode
{
	struct BinaryTreeNode* left;//���ڵ��������
	struct BinaryTreeNode* right;//���ڵ��������
	int data;//���ڵ��ֵ
};
//���ڲ�֪������������飬�Ҳ��ܷ��ؾֲ������ĵ�ַ�����Բ��ö�̬�ڴ濪������
//���ڶ������ڵ���������޷�ȷ�������Ŀռ䣬�����Ҫ����������Ľڵ����

//˼·������
//1����Ϊ�գ��߶�Ϊ0
//2�����ǿգ��ֽ�������
//		����������������ȣ���ȡ��ȴ��+1���������������ֽ������������
//����𰸣�maxDepth(root->left)��maxDepth(root->left) + 1�ݹ���õ�����ѭ��
//int maxDepth(struct TreeNode* root)
//{
//	if (root == NULL)
//	{
//		return 0;
//	}
//	return maxDepth(root->left) > maxDepth(root->right) ? maxDepth(root->left) + 1 : maxDepth(root->right) + 1;
//}

//��ȷ�𰸣�
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
//	//���Թ���
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