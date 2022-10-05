#define _CRT_SECURE_NO_WARNINGS 1
//����������ĸ��ڵ�root���������ڵ�ֵ��ǰ����������ѷ��صĽڵ�ֵ����������

#include <stdio.h>
#include <stdlib.h>
struct TreeNode
{
	struct TreeNode* left;//���ڵ��������
	struct TreeNode* right;//���ڵ��������
	int data;//���ڵ��ֵ
};
//���ڲ�֪������������飬�Ҳ��ܷ��ؾֲ������ĵ�ַ�����Բ��ö�̬�ڴ濪������
//���ڶ������ڵ���������޷�ȷ�������Ŀռ䣬�����Ҫ����������Ľڵ����
int TreeSize(struct TreeNode* root)
{
	return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}

//˼·����������Ľ����У�ͬʱ�ѽڵ��ֵ����������
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
//����i = 0ʱ, ++i��_prevOrder(root->left, a, i)�е�i = 1
//�ٵ���_prevOrder(struct TreeNode* root, int* a, int i)ʱ��int iΪ�µĶ����ռ䣬��ǰһ��i�޹أ�
//��ʱi = 1���뺯����++i��i = 2,������_prevOrder(root->right, a, i)ʱ
//����Ӱ��_prevOrder(root->right, a, i)��i����ʱ��_prevOrder(root->right, a, i)��i��Ϊ1
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
//	*returnSize = size;//*returnSize����������ߵ�size��ʹ��size��ֵ�ܹ��ı�
//	return a;
//}

//��i����Ϊȫ�ֱ����Ƿ���У�
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
	i = 0;//������Ҫע�⣬Leetcode�ϣ������ж�������������ᵼ��iһֱ�ۼӣ������ͨ������Ҫ����
	int size = TreeSize(root);
	int* a = (int*)malloc(sizeof(int) * size);

	_prevOrder(root, a);

	*returnSize = size;//*returnSize����������ߵ�size��ʹ��size��ֵ�ܹ��ı�
	return a;
}

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
//	int size = 0;
//	int* a = preorderTraversal(&node1, &size);
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	return 0;
//}