#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

typedef struct Postion
{
	int row;//��
	int col;//��
}PT;
////////////////////////////////////////
typedef PT STDataType;

//typedef struct Stack
//{
//	STDataType a[MAX];//���飬��̬ջ
//	int top;//ջ����λ�ã���ջ�����±�
//}ST;
typedef struct Stack
{
	STDataType* a;//ָ��a������ά������ջ
	int top;//ջ����λ�ã���ջ�����±�
	int capacity;//����ջ������
}ST;

//����ջ��ʼ��
void StackInit(ST* ps);
//����ջ����
void StackDestroy(ST* ps);
//����ջ�������Ĳ���
void StackPush(ST* ps, STDataType x);
//����ջ��������ɾ��
void StackPop(ST* ps);
//ջ��������
STDataType StackTop(ST* ps);
//����ջ�Ĵ�С
int StackSize(ST* ps);
//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(ST* ps);

//����ջ��ʼ��
//void StackInit(ST* ps)//�ββ���Ӱ��ʵ�Σ���ʵ�εĵ�ַ���βξ��ܸı�ʵ��
//{
//	assert(ps);
//	ps->a = NULL;
//	ps->top = 0;//��ʼtop = 0����ʾtopָ��ջ�����ݵ���һ�������ȷ�������++����ʼtop = -1.��ʾtopָ��ջ�����ݣ�����++�ٷ�����
//	ps->capacity = 0;
//}

void StackInit(ST* ps)//�ββ���Ӱ��ʵ�Σ���ʵ�εĵ�ַ���βξ��ܸı�ʵ��
{
	assert(ps);
	ps->a = (STDataType*)malloc(sizeof(STDataType) * 4);
	if (ps->a == NULL)
	{
		printf("malloc failed\n");
		exit(-1);
	}
	ps->top = 0;//top = 0����ʾtopָ��ջ�����ݵ���һ�������ȷ�������++��top = -1.��ʾtopָ��ջ�����ݣ�����++�ٷ�����
	ps->capacity = 4;
}
//����ջ�Ĳ���
//void StackPush(ST* ps, STDataType x)
//{
//	assert(ps);
//	if (ps->top == ps->capacity)
//	{
//		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
//		STDataType* tmp = realloc(ps->a, sizeof(STDataType) * newCapacity);
//		if (tmp == NULL)
//		{
//			printf("realloc failed\n");
//			exit(-1);
//		}
//		ps->a = tmp;
//		ps->capacity = newCapacity;
//	}
//	ps->a[ps->top] = x;
//	ps->top++;
//}

void StackPush(ST* ps, STDataType x)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		STDataType* tmp = (STDataType*)realloc(ps->a, sizeof(STDataType) * (ps->capacity * 2));
		if (tmp == NULL)
		{
			printf("realloc failed\n");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = ps->capacity * 2;
	}
	ps->a[ps->top] = x;
	ps->top++;
}

//����ջ����
void StackDestroy(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}

//����ջ��ɾ��
void StackPop(ST* ps)
{
	assert(ps);
	//ջ���ˣ�����popֱ����ֹ���򱨴�
	//assert(ps->top > 0);�൱��assert(!StackEmpty(ps));
	assert(!StackEmpty(ps));
	ps->top--;
}

//ջ��������
STDataType StackTop(ST* ps)
{
	assert(ps);
	assert(ps->top > 0);//�൱��assert(!StackEmpty(ps));

	return ps->a[ps->top - 1];
}

//����ջ�Ĵ�С
int StackSize(ST* ps)
{
	assert(ps);
	return ps->top;//top����ջ��ջ�����±��ǰһ����Ҳ��ջ�Ĵ�С
}
//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(ST* ps)
{
	assert(ps);
	/*if (ps->top == 0)
	{
		return true;
	}
	else
	{
		return false;
	}*/
	return ps->top == 0;
}

ST path;//ͨ·
ST minPath;//���ͨ·
////////////////////////////////////////
void PrintMaze(int** maze, int N, int M)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			printf("%d ", maze[i][j]);
		}
		printf("\n");
	}
}

//���ջ���������·��
void PrintPath(ST* ps)
{
	//����һ��ջ����pathջ�е����ݵ��뵽��ջ��
	ST rPath;
	StackInit(&rPath);
	while (!StackEmpty(ps))
	{
		StackPush(&rPath, StackTop(ps));
		StackPop(ps);
	}

	while (StackSize(&rPath) > 1)
	{
		PT top = StackTop(&rPath);
		printf("[%d,%d],", top.row, top.col);
		StackPop(&rPath);
	}
	//���һ����,û�ж���
	PT top = StackTop(&rPath);
	printf("[%d,%d]", top.row, top.col);
	StackPop(&rPath);

	StackDestroy(&rPath);
}

bool IsPass(int** maze, int N, int M, PT pos)
{
	if (pos.row >= 0 && pos.row < N && pos.col >= 0 && pos.col < M
		&& maze[pos.row][pos.col] == 1)//1����ͨ·
	{
		return true;
	}
	else
		return false;
}

void StackCopy(ST* ppath, ST* pcopy)
{
	pcopy->a = (STDataType*)malloc(sizeof(STDataType*) * ppath->capacity);
	if (pcopy->a == NULL)
		return;
	memcpy(pcopy->a, ppath->a, sizeof(STDataType) * ppath->top);
	pcopy->top = ppath->top;
	pcopy->capacity = ppath->capacity;
}

void GetMazePath(int** maze, int N, int M, PT cur, int P)
{
	StackPush(&path, cur);

	//����ߵ�����
	if (cur.row == 0 && cur.col == M - 1)
	{
		//ǰ��P >= 0
		//�����һ�ξ��ҵ��˼�StackEmpty(&minPath) == NULL,�����ҵ��˸������·��������minPath
		if (P >= 0 && StackEmpty(&minPath) || StackSize(&path) < StackSize(&minPath))
		{
			//minPath = path;//ǳ������1�����¶���ͷ�ͬһ��ռ䣬2��minPath��ԭʼ�ռ䶪ʧ�ˣ������ڴ�й¶

			//���
			StackDestroy(&minPath);

			StackCopy(&path, &minPath);
		}
	}

	maze[cur.row][cur.col] = 2;
	//̽�⵱ǰ����curλ�õ����������ĸ�����
	PT next;

	//���谴��������˳��̽��
	//��
	next = cur;
	next.row -= 1;
	if (IsPass(maze, N, M, next))
	{
		GetMazePath(maze, N, M, next, P - 3);
	}
	//��
	next = cur;
	next.row += 1;
	if (IsPass(maze, N, M, next))
	{
		GetMazePath(maze, N, M, next, P);
	}
	//��
	next = cur;
	next.col -= 1;
	if (IsPass(maze, N, M, next))
	{
		GetMazePath(maze, N, M, next, P - 1);
	}
	//��
	next = cur;
	next.col += 1;
	if (IsPass(maze, N, M, next))
	{
		GetMazePath(maze, N, M, next, P - 1);
	}

	maze[cur.row][cur.col] = 1;//�ָ���ǵ�2Ϊ1
	StackPop(&path);
}

int main()
{
	//1�������������
	int N = 0, M = 0, P = 0;
	while (scanf("%d%d%d", &N, &M, &P) != EOF)
	{
		//int a[N][M]�䳤���飬vs2013��֧��

		//��̬���ٶ�ά����
		//���ڿ��ٵ�������Ҫ����һά����ĵ�ַ�������Ҫ����ָ��
		int** maze = (int**)malloc(sizeof(int*) * N);
		for (int i = 0; i < N; i++)
		{
			maze[i] = (int*)malloc(sizeof(int) * M);
		}

		//2����ά���������
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				scanf("%d", &maze[i][j]);
			}
		}

		//PrintMaze(maze, N, M);

		//3���Թ����·��
		StackInit(&path);
		StackInit(&minPath);

		PT entry = { 0,0 };
		GetMazePath(maze, N, M, entry, P);
		if (!StackEmpty(&minPath))
		{
			PrintPath(&minPath);
		}
		else
		{
			printf("Can not escape! \n");
		}

		StackDestroy(&path);
		StackDestroy(&minPath);

		//�ͷſռ�
		for (int i = 0; i < N; i++)
		{
			free(maze[i]);
		}
		free(maze);
		maze = NULL;
	}
	return 0;
}
//�Թ���
//4 4 10 
//1 0 0 1 
//1 1 0 1 
//0 1 1 1 
//0 0 1 1

//��������[0,0],[1,0],[1,1],[2,1],[2,2],[3,2],[3,3],[2,3],[1,3],[0,3]
//�������[0,0],[1,0],[1,1],[2,1],[2,2],[2,3],[1,3],[0,3]
//�����·�����ҳ����е�ͨ·��Ȼ��ȡ���·����ͨ·
