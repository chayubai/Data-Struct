#define _CRT_SECURE_NO_WARNINGS 1

/**********************************************************************************************
С������һ�첻С��������һ�������Թ�,С����ϣ�����Լ���ʣ������ֵP������������Թ���
Ϊ���������,��������һ��n*m�ĸ����Թ�,�Թ�ÿ��λ��Ϊ0����1,0�������λ�����ϰ���,С���ܴﵽ�������λ��;1����С���ܿ��Դﵽ��λ�á�
С���ܳ�ʼ��(0,0)λ��,�����Թ��ĳ�����(0,m-1)(��֤������λ�ö���1,���ұ�֤һ������㵽�յ�ɴ��·��),
С�������Թ���ˮƽ�ƶ�һ����λ������Ҫ����1������ֵ,������һ����λ������Ҫ����3����λ������ֵ,�����ƶ�����������ֵ,
��С���ܵ�����ֵ����0��ʱ��û�е������,С���ܽ��޷������Թ���
������Ҫ�����С���ܼ�����ܷ��ý�ʣ������ֵ�����Թ�(���ﵽ(0,m-1)λ��)��

//����ڵ�(0,0)�����ڵ�(0,m-1)��0�����ϰ��1������Դﵽ��λ�á�

�������� :
	�������n + 1�� :
	��һ��Ϊ��������n, m  (3 <= m, n <= 10), P(1 <= P <= 100)
	��������n�� : 
	ÿ��m��0����1,�Կո�ָ�

������� :
	����������Թ�, �����һ������������С��·��, �����ʽ��������ʾ; ������������Թ�, �����"Can not escape!"��
	�������ݱ�֤��Ψһ

ʾ��1
����
4 4 10 1 0 0 1 1 1 0 1 0 1 1 1 0 0 1 1
���
[0,0],[1,0],[1,1],[2,1],[2,2],[2,3],[1,3],[0,3]

ע�⣺��������һ����Ļ����ϼ���������ֵ�ĸ�����Ǳ��⻹��һ����������������Ҫ�ҳ��Թ������·����
���²�����������Ҫ�ҳ����·��������ͨ��ȫ������������
4 4 10
1 0 0 1
1 1 0 1
0 1 1 1
0 0 1 1

��������[0,0],[1,0],[1,1],[2,1],[2,2],[3,2],[3,3],[2,3],[1,3],[0,3]
�������[0,0],[1,0],[1,1],[2,1],[2,2],[2,3],[1,3],[0,3]
�����·�����ҳ����е�ͨ·��Ȼ��ȡ���·����ͨ·
***********************************************************************************************/

//����ҵ����·����
//˼·���ҳ����е�ͨ·���ٱȽ�
//1�����ڵ�һ��Ļ����ϣ�ֻҪ�ҵ���ͨ·��ֱ�ӷ����ˣ�����Ͳ����ٵݹ��ˡ��Ͳ���������һ��ͨ·��
//�����������ԭ���Ļ����ϣ�����ֵ���Ϊvoid�������е�if�ж�ȥ��������ֵȥ����
//2�����ڵ�һ��Ļ����ϣ������һ��·���ҵ����Ȼ��ݵ�ĳһ��λ�ú󣬵�������һ��ͨ·ʱ��
//��ʱ������֮ǰ�߹���λ�ñ���Ϊ��2���Ͳ������ߡ����޷�������ڵ㡣
//�����������ԭ���Ļ����ϣ���Ҫ�ڻ��ݵ�ʱ�򽫵�ǰλ�øĻ�0�����ָ�����·����
//3����ÿ�ҵ�һ��ͨ··��ʱ���ͽ���·������ջ��Ԫ�ظ����Ƚ�һ�£������ǰ·�������٣�����¡�
//ע�⣺���²����Ǽ򵥵�minpath = path��ֵ��
//���ȣ����ݵ�ʱ�򣬻�pop�����·��ջ�е����ݣ����·�������仯������������̡�
//��Σ�������������ͷſռ�ʱ��minpathԭʼ�Ŀռ䶪ʧ�ˣ������ڴ�й©��
//���free(path)��free(minPath)���¶�ͬһ���ռ��ͷ����Σ����������
//����ԭ����path��minPathָ��Ŀռ���ͬһ��ռ䡣
//�ⷨ����������·��ǰ����minPathԭ�ռ��ͷŵ���minPath���ٺ�path��ͬ�Ŀռ䣬Ȼ��path�ռ��ֵ������minPath��
#include "Stack.h"

//����һ���ṹ�壬���浱ǰλ�õ�����
/*
typedef struct Postion
{
	int row;//��
	int col;//��
}PT;

typedef PT STDataType;
*/

ST path;//ͨ·
ST minPath;//���ͨ·

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

	while (StackSize(&rPath) > 1)//��ӡǰn-1��
	{
		PT top = StackTop(&rPath);
		printf("[%d,%d],", top.row, top.col);
		StackPop(&rPath);
	}
	//��ӡ���һ�������һ����û�ж���
	PT top = StackTop(&rPath);
	printf("[%d,%d]", top.row, top.col);//�����ʽ
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

//����һ��ջ
void StackCopy(ST* ppath, ST* pcopy)
{
	pcopy->a = (STDataType*)malloc(sizeof(STDataType*) * ppath->capacity);//capacityջ������
	if (pcopy->a == NULL)
		return;
	memcpy(pcopy->a, ppath->a, sizeof(STDataType) * ppath->top);//topջ��Ԫ�ظ���
	pcopy->top = ppath->top;
	pcopy->capacity = ppath->capacity;
}

void GetMazePath(int** maze, int N, int M, PT cur, int P)
{
	StackPush(&path, cur);

	//����ߵ����ڣ�ÿ�ζ�Ҫ������̵�·��
	if (cur.row == 0 && cur.col == M - 1)//���ڵ�
	{
		//ǰ��P >= 0���������ֵΪ0�����ҵ���ͨ·����������ֵ�����ʣ�࣬���ҵ���ͨ·���Ÿ���·����
		//Ҳ���ǣ�����ֵ��û�������꣬�����ҵ�ͨ·������¡�

		//����Թ�ֻҪһ��·������StackEmpty(&minPath) == NULL��������
		//����Թ��ж���·����ÿ�αȽϵ�ǰջԪ�ظ��������·��ջԪ�ظ�������������·��������minPath
		if (P >= 0 && StackEmpty(&minPath) || StackSize(&path) < StackSize(&minPath))
		{
			//minPath = path;//ǳ������1��free(path)��free(minPath)���¶���ͷ�ͬһ��ռ䣬2��minPath��ԭʼ�ռ䶪ʧ�ˣ������ڴ�й¶

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
		GetMazePath(maze, N, M, next, P - 3);//����ֵ-3
	}
	//��
	next = cur;
	next.row += 1;
	if (IsPass(maze, N, M, next))
	{
		GetMazePath(maze, N, M, next, P);//����ֵ����
	}
	//��
	next = cur;
	next.col -= 1;
	if (IsPass(maze, N, M, next))
	{
		GetMazePath(maze, N, M, next, P - 1);//����ֵ-1
	}
	//��
	next = cur;
	next.col += 1;
	if (IsPass(maze, N, M, next))
	{
		GetMazePath(maze, N, M, next, P - 1);//����ֵ-1
	}
	
	//���ݵ�ʱ�򣬽���ǰλ�ûָ���
	maze[cur.row][cur.col] = 1;//�ָ���ǵ�2Ϊ1
	StackPop(&path);//���minPath = path;����ͻ��ջ����path��ͬʱ�����minPath������Ҳ���ˡ�
	//����һ�������·��ʱ�����ֵ�ǰ·����������̵ģ�
	//����Ҫ����if (P >= 0 && StackEmpty(&minPath) || StackSize(&path) < StackSize(&minPath))����ж�
	//Ҳ����˵���·������minPath��һ�ε�path��������һ��minPath��Ϊpath�ĸı���������޸ģ��Ͳ�������һ�ε�path
}

int main()
{
	//1�������������
	int N = 0, M = 0, P = 0;//P����ֵ
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

		if (!StackEmpty(&minPath))//����������·����minPathջ�Ͳ�Ϊ�գ������Ϊ��
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