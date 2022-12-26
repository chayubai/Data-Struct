#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//��������ǰ�����򡢺������Ҳ��������ȱ������������Ҳ�й�����ȱ�����

typedef char BTDataType;
//����������Ľڵ�
typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;//�ڵ��������
	struct BinaryTreeNode* right;//�ڵ��������
	BTDataType data;//�ڵ��ֵ
}BTNode;

//ǰ��������� ������ ������
void PrevOrder(BTNode* root)//ע�⣺root��ʾ�ڵ�ָ�룬������ָ���ڵ�
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%c ", root->data);
	PrevOrder(root->left);
	PrevOrder(root->right);
}

//��������������� �� ������
void InOrder(BTNode* root)//ע�⣺root��ʾ�ڵ�ָ�룬������ָ���ڵ�
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	InOrder(root->left);
	printf("%c ", root->data);
	InOrder(root->right);
}

//��������������� ������ ��
void PostOrder(BTNode* root)//ע�⣺root��ʾ�ڵ�ָ�룬������ָ���ڵ�
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	PostOrder(root->left);
	PostOrder(root->right);
	printf("%c ", root->data);
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

	PrevOrder(A);
	printf("\n");
	InOrder(A);
	printf("\n");
	PostOrder(A);
	printf("\n");

	return 0;
}
#endif