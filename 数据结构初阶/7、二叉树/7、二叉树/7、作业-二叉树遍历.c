#define _CRT_SECURE_NO_WARNINGS 1
//��һ�����򣬶����û������һ����������ַ��������ݴ��ַ�������һ��������(��ָ�뷽ʽ�洢)��
//���磬���µ���������ַ���: ABC##DE#G##F###����"#"��ʾ���ǿո񣬿ո��ַ����������
//������˶������Ժ��ٶԶ������������������������������

//�����������������1���ַ��������Ȳ�����100��
//��������������ж���������ݣ�
//����ÿ�����ݣ�����������ַ���������������������������У�ÿ���ַ����涼��һ���ո�ÿ��������ռһ�С�

//�磺
//���룺abc##de#g##f###
//�����c b e g d f a

//��������
//		   a
//      b     #
//  c      d 
//#   #  e   f
//     #  g #  #
//       # # 

//ע�⣺һ������£�ǰ��+��������+���򣬿���ȷ��Ψһ��һ�Ŷ����������ǰ������������п�����ʾ��Ҳ��ȷ����������
//��ȷ�����ڵ㣬��ȷ���������ĸ���ֱ�������ڵ�Ϊ�գ����ء���ȷ���������ĸ���ֱ�������ڵ�Ϊ�ա�
//����������������������ȷ���ˣ���ԭһ��������
#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode
{
	struct TreeNode* left;//�ڵ��������
	struct TreeNode* right;//�ڵ��������
	char data;//�ڵ��ֵ
}TNode;

//˼�룺����ǰ�����
TNode* CreateTree(char* a,int* pi)
{
	if (a[*pi] == '#')
	{
		++(*pi);
		return NULL;
	}

	//������
	TNode* root = (TNode*)malloc(sizeof(TNode));//�ڵ�
	if (root == NULL)
	{
		printf("malloc failed\n");
		exit(-1);
	}
	//��
	root->data = a[*pi];
	++(*pi);
	//������
	root->left = CreateTree(a,pi);
	//������
	root->right = CreateTree(a,pi);

	return root;
}
//ע�⣺���ݹ�չ��ͼ

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
	//���Թ���
	char str[100];//���ڸ������ַ������ᳬ��100���ֽڣ�����ֱ�ӿ��ٹ̶���С�����顣
	scanf("%s", str);
	int i = 0;
	TNode* root = CreateTree(str, &i);//������һ���i����Ӱ����һ���i��i��Ҫȡ��ַ

	InOrder(root);
	return 0;
}