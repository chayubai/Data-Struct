#define _CRT_SECURE_NO_WARNINGS 1

/**********************************************************************************************
小青蛙有一天不小心落入了一个地下迷宫,小青蛙希望用自己仅剩的体力值P跳出这个地下迷宫。
为了让问题简单,假设这是一个n*m的格子迷宫,迷宫每个位置为0或者1,0代表这个位置有障碍物,小青蛙达到不了这个位置;1代表小青蛙可以达到的位置。
小青蛙初始在(0,0)位置,地下迷宫的出口在(0,m-1)(保证这两个位置都是1,并且保证一定有起点到终点可达的路径),
小青蛙在迷宫中水平移动一个单位距离需要消耗1点体力值,向上爬一个单位距离需要消耗3个单位的体力值,向下移动不消耗体力值,
当小青蛙的体力值等于0的时候还没有到达出口,小青蛙将无法逃离迷宫。
现在需要你帮助小青蛙计算出能否用仅剩的体力值跳出迷宫(即达到(0,m-1)位置)。

//即入口点(0,0)，出口点(0,m-1)，0代表障碍物，1代表可以达到的位置。

输入描述 :
	输入包括n + 1行 :
	第一行为三个整数n, m  (3 <= m, n <= 10), P(1 <= P <= 100)
	接下来的n行 : 
	每行m个0或者1,以空格分隔

输出描述 :
	如果能逃离迷宫, 则输出一行体力消耗最小的路径, 输出格式见样例所示; 如果不能逃离迷宫, 则输出"Can not escape!"。
	测试数据保证答案唯一

示例1
输入
4 4 10 1 0 0 1 1 1 0 1 0 1 1 1 0 0 1 1
输出
[0,0],[1,0],[1,1],[2,1],[2,2],[2,3],[1,3],[0,3]

注意：本题在上一个题的基础上计入了体力值的概念，但是本题还有一个隐藏条件，就是要找出迷宫的最短路径，
如下测试用例，需要找出最短路径，才能通过全部测试用例。
4 4 10
1 0 0 1
1 1 0 1
0 1 1 1
0 0 1 1

你的输出：[0,0],[1,0],[1,1],[2,1],[2,2],[3,2],[3,3],[2,3],[1,3],[0,3]
答案输出：[0,0],[1,0],[1,1],[2,1],[2,2],[2,3],[1,3],[0,3]
找最短路径：找出所有的通路，然后取最短路径的通路
***********************************************************************************************/

//如何找到最短路径？
//思路：找出所有的通路，再比较
//1、由于第一题的基础上，只要找到了通路就直接返回了，后面就不会再递归了。就不会再找下一条通路。
//解决方法：在原来的基础上，返回值设计为void，把所有的if判断去掉，返回值去掉。
//2、由于第一题的基础上，如果第一条路径找到后，先回溯到某一个位置后，当再找下一条通路时，
//此时，由于之前走过的位置被置为了2，就不会再走。就无法到达出口点。
//解决方法：在原来的基础上，需要在回溯的时候将当前位置改回0。即恢复公共路径。
//3、当每找到一条通路路径时，就将该路径所在栈中元素个数比较一下，如果当前路径个数少，则更新。
//注意：更新并不是简单的minpath = path赋值，
//首先，回溯的时候，会pop掉最短路径栈中的数据，最短路径发生变化，而不再是最短。
//其次，当程序结束，释放空间时，minpath原始的空间丢失了，导致内存泄漏，
//最后，free(path)和free(minPath)导致对同一个空间释放两次，程序崩溃。
//归其原因还是path和minPath指向的空间是同一块空间。
//解法方法：更新路径前，将minPath原空间释放掉，minPath开辟和path相同的空间，然后将path空间的值拷贝给minPath。
#include "Stack.h"

//定义一个结构体，保存当前位置的行列
/*
typedef struct Postion
{
	int row;//行
	int col;//列
}PT;

typedef PT STDataType;
*/

ST path;//通路
ST minPath;//最短通路

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

//输出栈里面的坐标路径
void PrintPath(ST* ps)
{
	//用另一个栈，将path栈中的数据导入到该栈中
	ST rPath;
	StackInit(&rPath);
	while (!StackEmpty(ps))
	{
		StackPush(&rPath, StackTop(ps));
		StackPop(ps);
	}

	while (StackSize(&rPath) > 1)//打印前n-1个
	{
		PT top = StackTop(&rPath);
		printf("[%d,%d],", top.row, top.col);
		StackPop(&rPath);
	}
	//打印最后一个，最后一个数没有逗号
	PT top = StackTop(&rPath);
	printf("[%d,%d]", top.row, top.col);//输出格式
	StackPop(&rPath);

	StackDestroy(&rPath);
}

bool IsPass(int** maze, int N, int M, PT pos)
{
	if (pos.row >= 0 && pos.row < N && pos.col >= 0 && pos.col < M
		&& maze[pos.row][pos.col] == 1)//1代表通路
	{
		return true;
	}
	else
		return false;
}

//拷贝一个栈
void StackCopy(ST* ppath, ST* pcopy)
{
	pcopy->a = (STDataType*)malloc(sizeof(STDataType*) * ppath->capacity);//capacity栈的容量
	if (pcopy->a == NULL)
		return;
	memcpy(pcopy->a, ppath->a, sizeof(STDataType) * ppath->top);//top栈的元素个数
	pcopy->top = ppath->top;
	pcopy->capacity = ppath->capacity;
}

void GetMazePath(int** maze, int N, int M, PT cur, int P)
{
	StackPush(&path, cur);

	//如果走到出口，每次都要更新最短的路径
	if (cur.row == 0 && cur.col == M - 1)//出口点
	{
		//前提P >= 0，如果体力值为0但是找到了通路，或者体力值最后有剩余，且找到了通路，才更新路径。
		//也就是，体力值还没有消耗完，并且找到通路，则更新。

		//如果迷宫只要一条路径，则StackEmpty(&minPath) == NULL，结束。
		//如果迷宫有多条路径，每次比较当前栈元素个数和最短路径栈元素个数，则更新最短路径，更新minPath
		if (P >= 0 && StackEmpty(&minPath) || StackSize(&path) < StackSize(&minPath))
		{
			//minPath = path;//浅拷贝，1、free(path)和free(minPath)导致多次释放同一块空间，2、minPath的原始空间丢失了，导致内存泄露

			//深拷贝
			StackDestroy(&minPath);

			StackCopy(&path, &minPath);
		}
	}

	maze[cur.row][cur.col] = 2;
	//探测当前坐标cur位置的上下左右四个方向
	PT next;

	//假设按上下左右顺序探测
	//上
	next = cur;
	next.row -= 1;
	if (IsPass(maze, N, M, next))
	{
		GetMazePath(maze, N, M, next, P - 3);//体力值-3
	}
	//下
	next = cur;
	next.row += 1;
	if (IsPass(maze, N, M, next))
	{
		GetMazePath(maze, N, M, next, P);//体力值不变
	}
	//左
	next = cur;
	next.col -= 1;
	if (IsPass(maze, N, M, next))
	{
		GetMazePath(maze, N, M, next, P - 1);//体力值-1
	}
	//右
	next = cur;
	next.col += 1;
	if (IsPass(maze, N, M, next))
	{
		GetMazePath(maze, N, M, next, P - 1);//体力值-1
	}
	
	//回溯的时候，将当前位置恢复。
	maze[cur.row][cur.col] = 1;//恢复标记的2为1
	StackPop(&path);//如果minPath = path;这里就会出栈，改path的同时，会把minPath的数据也改了。
	//当下一次找最短路径时，发现当前路径并不是最短的，
	//不需要进入if (P >= 0 && StackEmpty(&minPath) || StackSize(&path) < StackSize(&minPath))这个判断
	//也就是说最短路径还是minPath上一次的path，但是这一次minPath因为path的改变而发生了修改，就不再是上一次的path
}

int main()
{
	//1、解决输入问题
	int N = 0, M = 0, P = 0;//P体力值
	while (scanf("%d%d%d", &N, &M, &P) != EOF)
	{
		//int a[N][M]变长数组，vs2013不支持

		//动态开辟二维数组
		//由于开辟的数组需要保存一维数组的地址，因此需要二级指针
		int** maze = (int**)malloc(sizeof(int*) * N);
		for (int i = 0; i < N; i++)
		{
			maze[i] = (int*)malloc(sizeof(int) * M);
		}

		//2、二维数组的输入
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				scanf("%d", &maze[i][j]);
			}
		}

		//PrintMaze(maze, N, M);

		//3、迷宫求出路径
		StackInit(&path);
		StackInit(&minPath);

		PT entry = { 0,0 };
		GetMazePath(maze, N, M, entry, P);

		if (!StackEmpty(&minPath))//如果存在最短路径，minPath栈就不为空，否则就为空
		{
			PrintPath(&minPath);
		}
		else
		{
			printf("Can not escape! \n");
		}

		StackDestroy(&path);
		StackDestroy(&minPath);

		//释放空间
		for (int i = 0; i < N; i++)
		{
			free(maze[i]);
		}
		free(maze);
		maze = NULL;
	}
	return 0;
}