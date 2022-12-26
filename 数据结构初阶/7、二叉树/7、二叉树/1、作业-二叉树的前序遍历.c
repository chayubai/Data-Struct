#define _CRT_SECURE_NO_WARNINGS 1
//����������ĸ��ڵ�root���������ڵ�ֵ��ǰ����������ѷ��صĽڵ�ֵ����������

#include <stdio.h>
#include <stdlib.h>
struct TreeNode
{
	struct TreeNode* left;//�ڵ��������
	struct TreeNode* right;//�ڵ��������
	int data;//�ڵ��ֵ
};

//���ڲ�֪������������飬�Ҳ��ܷ��ؾֲ������ĵ�ַ�����Բ��ܲ��þ�̬���飬Ӧ�ò��ö�̬�ڴ濪�����顣
//���ڶ������ڵ���������޷�ȷ�������Ŀռ䣬�����Ҫ����������Ľڵ������
int TreeSize(struct TreeNode* root)
{
	return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}

//˼·���������
/*
void _prevOrder(struct TreeNode* root, int* a, int i)//i��Ϊֵ����,ע�⣺root��ʾ�ڵ�ָ�룬������ָ���ڵ�
{
	if (root == NULL)
		return;

	//��
	a[i] = root->data;//�ѽڵ��ֵ����������
	++i;
	//������
	_prevOrder(root->left, a, i);
	//������
	_prevOrder(root->right, a, i);
}
*/
//���ݹ�չ��ͼ�����������1 3 ���ֵ��
//��һ�ε���_prevOrder(root, a, i)��i = 0��
//���뺯���壬����i = 0ʱ, ��1�ŵ�a[0]����++i��i = 1��ִ��_prevOrder(root->left, a, i)���
//�ڶ��ε���_prevOrder(root, a, i)��i = 1��
//���뺯���壬����i = 1ʱ, ��2�ŵ�a[1]����++i��i = 2��ִ��_prevOrder(root->left, a, i)��䣬���ء�
//����i��ֵ���ݣ�i��ֵ������Ӱ�죬��ִ��_prevOrder(root->right, a, i)��䣬��ʱi��Ϊ1��
//���뺯���壬����i = 1ʱ, ��3�ŵ�a[1]����++i��i = 2��ִ��_prevOrder(root->left, a, i)��䣬���ء�

//����1��
/*
void _prevOrder(struct TreeNode* root, int* a, int* pi)//i��Ϊַ����,ע�⣺root��ʾ�ڵ�ָ�룬������ָ���ڵ�
{
	if (root == NULL)
		return;

	a[*pi] = root->data;
	++(*pi);

	_prevOrder(root->left, a, pi);
	_prevOrder(root->right, a, pi);
}
int* preorderTraversal(struct TreeNode* root, int* returnSize)//root�����Ͳ�����returnSize����Ͳ���,ע�⣺root��ʾ�ڵ�ָ�룬������ָ���ڵ�
{
	int size = TreeSize(root);
	int* a = (int*)malloc(sizeof(int) * size);
	int i = 0;
	_prevOrder(root, a, &i);

	*returnSize = size;//*returnSize����������ߵ�size��ʹ��size��ֵ�ܹ��ı�
	return a;
}
*/

//����2��
//��i����Ϊȫ�ֱ����Ƿ���У�
int i = 0;
void _prevOrder(struct TreeNode* root, int* a)//ע�⣺root��ʾ�ڵ�ָ�룬������ָ���ڵ�
{
	if (root == NULL)
		return;

	a[i] = root->data;
	++i;

	_prevOrder(root->left, a);
	_prevOrder(root->right, a);
}
int* preorderTraversal(struct TreeNode* root, int* returnSize)//ע�⣺root����ָ���ڵ�
{
	i = 0;//������Ҫע�⣬����preorderTraversal֮ǰi��Ҫ����
	//������Leetcode�ϣ��ж�������������ᵼ��iһֱ�ۼӣ������ͨ�����еĲ���������
	int size = TreeSize(root);
	int* a = (int*)malloc(sizeof(int) * size);

	_prevOrder(root, a);

	*returnSize = size;//*returnSize����������ߵ�size��ʹ��size��ֵ�ܹ��ı�
	return a;
}
//ע�⣺ȫ�ֱ��������ж���߳�ͬʱ����preorderTraversal�������̰߳�ȫ���⡣

#if 0
int main()
{
	//���Թ���
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