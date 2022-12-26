#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

typedef char BTDataType;
typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;//�ڵ��������
	struct BinaryTreeNode* right;//�ڵ��������
	BTDataType data;//�ڵ��ֵ
}BTNode;

#include "Queue.h"//����ͷ�ļ���Ҫ�������չ��ʱ�������Ҳ���Queue.h�Ҳ���BTNode

//1����������ڵ�ĸ���
//����һ����������
//��size����Ϊȫ�ֱ���
/*
int size = 0;
void  BinaryTreeSize(BTNode* root)//ע�⣺root��ʾ�ڵ�ָ�룬������ָ���ڵ�
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		++size;
	}
	BinaryTreeSize(root->left);
	BinaryTreeSize(root->right);
}
*/

//����������������
//��size����Ϊ��̬����
/*
int BinaryTreeSize(BTNode* root)//ע�⣺root��ʾ�ڵ�ָ�룬������ָ���ڵ�
{
	if (root == NULL)
	{
		return;
	}
	static int size = 0;
	++size;

	BinaryTreeSize(root->left);
	BinaryTreeSize(root->right);

	return size;
}
*/
//ע�⣺�������ַ������ڶ��̲߳���ִ��ʱ������ȥ����������������ָ���
//����������������������̰߳�ȫ�ġ�

//������������
/*
void  BinaryTreeSize(BTNode* root, int size)//ע�⣺root��ʾ�ڵ�ָ�룬������ָ���ڵ�
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		++size;
	}
	BinaryTreeSize(root->left, size);
	BinaryTreeSize(root->right, size);
}
*/
/*
void  BinaryTreeSize(BTNode* root,int *psize)//ע�⣺root��ʾ�ڵ�ָ�룬������ָ���ڵ�
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		++(*psize);//��������++,�൱��++size
	}
	BinaryTreeSize(root->left,psize);
	BinaryTreeSize(root->right,psize);
}
*/

//�����ģ������㷨
//��һ�����ֳɸ�����������������
//�����Ľڵ���Լ���Ϊ���������Ľڵ����+�������Ľڵ����+1��
//�������ֿ��Լ����ٷֳɸ�����������������������(�������Ľڵ����+�������Ľڵ����+1)......ֱ�������ٷ֣�����0
int BinaryTreeSize(BTNode* root)//ע�⣺root��ʾ�ڵ�ָ�룬������ָ���ڵ�
{
	return root == NULL ? 0 : BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}

//2����Ҷ�ӽڵ�ĸ���
//����1�������������������������ΪNULL����size++
//����2�������㷨
//��һ�����ֳɸ�����������������
//�����Ľڵ���Լ���Ϊ����������Ҷ�ӽڵ����+��������Ҷ�ӽڵ������
//�������ֿ��Լ����ٷֳɸ�����������������������(��������Ҷ�ӽڵ����+��������Ҷ�ӽڵ����)......ֱ�������ٷ֣�����0
int BinaryTreeLeafSize(BTNode* root)//ע�⣺root��ʾ�ڵ�ָ�룬������ָ���ڵ�
{
	if (root == NULL)//�ڵ�Ϊ��
	{
		return 0;
	}
	if (root->left == NULL && root->right == NULL)
		return 1;
	//�����������������㣬Ҳ���ǵ�ǰ�ڵ㻹���ӽڵ㣬�Ȳ��ǿգ�Ҳ����Ҷ�ӽڵ�
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}
#if 0
int main()
{
	BTNode* A = (BTNode*)malloc(sizeof(BTNode));
	A->data = 'A';
	A->left = NULL;
	A->right = NULL;

	BTNode* B = (BTNode*)malloc(sizeof(BTNode));
	B->data = 'B';
	B->left = NULL;
	B->right = NULL;

	BTNode* C = (BTNode*)malloc(sizeof(BTNode));
	C->data = 'C';
	C->left = NULL;
	C->right = NULL;

	BTNode* D = (BTNode*)malloc(sizeof(BTNode));
	D->data = 'D';
	D->left = NULL;
	D->right = NULL;

	BTNode* E = (BTNode*)malloc(sizeof(BTNode));
	E->data = 'E';
	E->left = NULL;
	E->right = NULL;

	A->left = B;
	A->right = C;
	B->left = D;
	B->right = E;

	BinaryTreeSize(A);

	BinaryTreeLeafSize(A);
	return 0;
}
#endif