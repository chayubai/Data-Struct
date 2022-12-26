#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
struct A
{
	int a;
	int b;
};
//结构体变量访问指向变量的成员
struct A sa;
sa.a = 10;
sa.b = 20;
printf("%d %d\n", sa.a, sa.b);

//结构体指针访问指向变量的成员
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
	struct TreeNode* left;//节点的左子树
	struct TreeNode* right;//节点的右子树
	int data;//节点的值
};

//由于先销毁根节点，就无法销毁左子树，和右子树，因此消除一个树，采用后序遍历

//思想：分治
//1、当前树的根节点为空，直接返回
//2、当前树的根节点非空，先释放左，右子树，再释放根节点（左右子树继续分解成以上两步）
//		继续分解成，判断当前树的根是否为空，释放左，右子树，再释放根节点
/*
void DestroyTree(struct TreeNode* root)//由于传入的是struct TreeNode* node1,root是node1的临时拷贝
{//注意：root表示节点指针，不仅仅指根节点
	if (root == NULL)
	{
		return;
	}
	DestroyTree(root->left);
	DestroyTree(root->right);
	free(root);
	root = NULL;//这里置空，不起作用。
}
*/
void DestroyTree(struct TreeNode* *proot)//或者C++改为引用DestroyTree(struct TreeNode*& root)
{//注意：root表示节点指针的地址，不仅仅指根节点的地址
	if (*proot == NULL)
	{
		return;
	}
	DestroyTree(&((*proot)->left));
	DestroyTree(&((*proot)->right));
	free(*proot);
	*proot = NULL;//改变外边的root，则用*root，改变*root，则用**root
}

#if 0
int main()
{
	//测试功能
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

	DestroyTree(&node1);//这里要传一级指针的地址，用二级指针接受
	
	return 0;
}
#endif