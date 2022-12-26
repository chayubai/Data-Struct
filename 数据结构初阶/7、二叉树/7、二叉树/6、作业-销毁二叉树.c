#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
struct A
{
	int a;
	int b;
};
//�ṹ���������ָ������ĳ�Ա
struct A sa;
sa.a = 10;
sa.b = 20;
printf("%d %d\n", sa.a, sa.b);

//�ṹ��ָ�����ָ������ĳ�Ա
struct P
{
	int a;
	int b;
};
struct P p = { 10,20 };
struct P* sp = &p;
(*sp).a = 30;
(*sp).b = 40;
printf("%d %d", sp->a, sp->b);
*/

struct TreeNode
{
	struct TreeNode* left;//�ڵ��������
	struct TreeNode* right;//�ڵ��������
	int data;//�ڵ��ֵ
};

//���������ٸ��ڵ㣬���޷������������������������������һ���������ú������

//˼�룺����
//1����ǰ���ĸ��ڵ�Ϊ�գ�ֱ�ӷ���
//2����ǰ���ĸ��ڵ�ǿգ����ͷ��������������ͷŸ��ڵ㣨�������������ֽ������������
//		�����ֽ�ɣ��жϵ�ǰ���ĸ��Ƿ�Ϊ�գ��ͷ��������������ͷŸ��ڵ�
/*
void DestroyTree(struct TreeNode* root)//���ڴ������struct TreeNode* node1,root��node1����ʱ����
{//ע�⣺root��ʾ�ڵ�ָ�룬������ָ���ڵ�
	if (root == NULL)
	{
		return;
	}
	DestroyTree(root->left);
	DestroyTree(root->right);
	free(root);
	root = NULL;//�����ÿգ��������á�
}
*/
void DestroyTree(struct TreeNode* *proot)//����C++��Ϊ����DestroyTree(struct TreeNode*& root)
{//ע�⣺root��ʾ�ڵ�ָ��ĵ�ַ��������ָ���ڵ�ĵ�ַ
	if (*proot == NULL)
	{
		return;
	}
	DestroyTree(&((*proot)->left));
	DestroyTree(&((*proot)->right));
	free(*proot);
	*proot = NULL;//�ı���ߵ�root������*root���ı�*root������**root
}

#if 0
int main()
{
	//���Թ���
	struct TreeNode* node1 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	struct TreeNode* node2 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	struct TreeNode* node3 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	node1->data = 1;
	node1->left = node2;
	node1->right = node3;

	node2->data = 2;
	node2->left = NULL;
	node2->right = NULL;

	node3->data = 3;
	node3->left = NULL;
	node3->right = NULL;

	DestroyTree(&node1);//����Ҫ��һ��ָ��ĵ�ַ���ö���ָ�����
	
	return 0;
}
#endif