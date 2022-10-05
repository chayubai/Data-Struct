#define _CRT_SECURE_NO_WARNINGS 1
//编一个程序，读入用户输入的一串先序遍历字符串，根据此字符串建立一个二叉树(以指针方式存储)。
//例如，如下的先序遍历字符串: ABC##DE#G##F###其中"#"表示的是空格，空格字符代表空树。
//建立起此二叉树以后，再对二叉树进行中序遍历，输出遍历结果。

//输入描述：输入包括1行字符串，长度不超过100。
//输出描述：可能有多组测试数据，
//对于每组数据，输出将输入字符串建立二叉树后中序遍历的序列，每个字符后面都有一个空格。每个输出结果占一行。

//如：
//输入：abc##de#g##f###
//输出：c b e g d f a

//二叉树：
//		   a
//      b     #
//  c      d 
//#   #  e   f
//     #  g #  #
//       # #  
#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode
{
	struct TreeNode* left;//父节点的左子树
	struct TreeNode* right;//父节点的右子树
	char data;//父节点的值
}TNode;

//思想：类似前序遍历
TNode* CreateTree(char* a,int* pi)
{
	if (a[*pi] == '#')
	{
		++(*pi);
		return NULL;
	}
	TNode* root = (TNode*)malloc(sizeof(TNode));//根
	if (root == NULL)
	{
		printf("malloc failed\n");
		exit(-1);
	}
	root->data = a[*pi];
	++(*pi);
	root->left = CreateTree(a,pi);//左子树
	root->right = CreateTree(a,pi);//右子树

	return root;
}
void InOrder(TNode* root)
{
	if (root == NULL)
		return;
	InOrder(root->left);
	printf("%c ", root->data);
	InOrder(root->right);
}
int main()
{
	//测试功能
	char str[100];
	scanf("%s", str);
	int i = 0;
	TNode* root = CreateTree(str, &i);//由于下一层的i不会影响上一层的i，i需要取地址

	InOrder(root);
	return 0;
}