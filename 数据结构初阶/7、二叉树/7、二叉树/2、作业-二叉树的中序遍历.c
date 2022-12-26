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

int TreeSize(struct TreeNode* root)
{
	return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}

//˼·���������
void _prevOrder(struct TreeNode* root, int* a, int* pi)//i��Ϊַ����
{
	if (root == NULL)
		return;
	//������
	_prevOrder(root->left, a, pi);
	//��
	a[*pi] = root->data;
	++(*pi);
	//������
	_prevOrder(root->right, a, pi);
}
int* preorderTraversal(struct TreeNode* root, int* returnSize)//root�����Ͳ�����returnSize����Ͳ���
{
	int size = TreeSize(root);
	int* a = (int*)malloc(sizeof(int) * size);
	int i = 0;
	_prevOrder(root, a, &i);

	*returnSize = size;//*returnSize����������ߵ�size��ʹ��size��ֵ�ܹ��ı�
	return a;
}

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