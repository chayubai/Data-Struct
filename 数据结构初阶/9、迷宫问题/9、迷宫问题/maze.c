#define _CRT_SECURE_NO_WARNINGS 1

//迷宫问题本质就是一个图的遍历问题，
//从起点开始不断四个方向探索，直到走到出口，走的过程中我们借助栈记录走过路径的坐标，
//栈记录坐标有两方面的作用，一方面是记录走过的路径，一方面方便走到死路时进行回溯找其他的通路。

/**********************************************************************************************
https://www.nowcoder.com/practice/cf24906056f4488c9ddb132f317e03bc?tpId=37&tqId=21266&ru=/exam/oj
描述：
定义一个二维数组 N*M(其中2 <= n <= 10,2 <= m <= 10 ) ，如 5 × 5 数组下所示：

int maze[5][5] = {
					0, 1, 0, 0, 0,
					0, 1, 1, 1, 0,
					0, 0, 0, 0, 0,
					0, 1, 1, 1, 0,
					0, 0, 0, 1, 0,
					};

它表示一个迷宫，其中的1表示墙壁，0表示可以走的路，只能横着走或竖着走，不能斜着走，
要求编程序找出从【左上角】到【右下角】的路线。入口点为[0,0],即第一格是可以走的路。出口点[n-,m-]

数据范围：2 <= n,m <= 10 ， 输入的内容只包含 0 <= val <=1

输入描述：
输入两个整数，分别表示二维数组的行数，列数。再输入相应的数组，其中的1表示墙壁，0表示可以走的路。
数据保证有唯一解,不考虑有多解的情况，即迷宫只有一条通道。

输出描述：
左上角到右下角的最短路径，格式如样例所示。

示例1
输入：5 5
0 1 0 0 0
0 1 1 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0

输出：  (0,0)
		(1,0)
		(2,0)
		(2,1)
		(2,2)
		(2,3)
		(2,4)
		(3,4)
		(4,4)

示例2
输入：5 5
0 1 0 0 0
0 1 0 1 0
0 0 0 0 1
0 1 1 1 0
0 0 0 0 0

输出：	(0,0)
		(1,0)
		(2,0)
		(3,0)
		(4,0)
		(4,1)
		(4,2)
		(4,3)
		(4,4)
说明：注意：不能斜着走！！
***********************************************************************************************/

//思路：深度优先遍历(前序、中序、后序遍历) 或 广度优先遍历(层序遍历)

//深度优先遍历法：
//从当前位置开始，上下左右去探测，如果为0则该位置(方向)是通路，就往这个位置(方向)继续上下左右试探。
//如果当这个位置的上下左右都走不通，则往回退。这里往回走，即迷宫回溯，类似于二叉树递归返回（二叉树是左右两个方向，迷宫是四个方向）

//注意：由于下一个位置为通路，则下一个位置的上下左右必有一个是0通路，也就是往回走的那个位置。
//为了防止走回头路，将走过的位置0标记为2。从而，当下一个位置探测上下左右，遇到2就不走，避免了往回走。

//注意：如果上下左右都不通，不需要将该位置的值改回0，因为不通时，会一直返回。下一次探测不会走该方向。

//那么输出的是通路的坐标，该如何实现？
//利用一个栈特性：后进先出。这样后进入位置的即使是死路，后面也能通过后进先出来弹出栈。直到栈里面保存的全是通路的位置。
//先将当前位置入栈，再判断当前位置的上下左右是否有通路，有通路，则递归把下一个位置(当前位置)继续入栈...
//直到当前位置上下左右都没有通路，则把当前位置出栈。

#if 0
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

ST path;

//1、打印迷宫，用于测试迷宫的逻辑是否正确
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

//4、输出栈里面的坐标路径
//由于栈是后进先出，所以，栈中路径的顺序打印出来是反的。
//解法方法：先将栈中的数据依次弹出，并保存到另一个新栈中。再遍历新栈就可以了。
void PrintPath(ST* ps)
{
	//用另一个栈，将path栈中的数据导入到该栈rPath中
	ST rPath;
	StackInit(&rPath);
	while (!StackEmpty(ps))
	{
		StackPush(&rPath, StackTop(ps));//将ps栈顶数据，入rPath栈
		StackPop(ps);//出ps栈顶的数据
	}
	//遍历rPath栈
	while(!StackEmpty(&rPath))
	{
		PT top = StackTop(&rPath);
		printf("(%d,%d)\n", top.row, top.col);
		StackPop(&rPath);
	}
	StackDestroy(&rPath);
}

//3、判断当前位置是否是通路
bool IsPass(int** maze, int N, int M, PT pos)
{
	if (pos.row >= 0 && pos.row < N && pos.col >= 0 && pos.col < M
		&& maze[pos.row][pos.col] == 0)//先判断行列的合法性，再判断是否是通路
	{
		return true;
	}
	else
		return false;
}

//2、获得通路的位置，保存到栈中。
//返回值：如果递归过程中，即使没有递归完，提前找到了某条通路路径就直接返回真，就无需再递归。否则递归完没有找到路径，则返回假。
bool GetMazePath(int** maze, int N, int M, PT cur)
{
	StackPush(&path, cur);//先将当前位置入栈，再判断上下左右是否有通路

	//如果走到出口(n-1,m-1)
	if (cur.row == N - 1 && cur.col == M - 1)
	{
		return true;
	}
	//探测当前坐标cur位置的上下左右四个方向。
	maze[cur.row][cur.col] = 2;//探测之前，需要将当前位置置为2，作为走过的标记

	PT next;//记录当前位置的下一个位置的上下左右的情况

	//假设按上下左右顺序探测。如果上不通，则继续探测下，下不通，则继续探测左，左不通，继续探测右
	//上
	next = cur;
	next.row -= 1;//上方向位置：当前位置行-1，列不变
	if (IsPass(maze, N, M, next))
	{
		if (GetMazePath(maze, N, M, next))
			return true;
	}
	//下
	next = cur;
	next.row += 1;//下方向位置：当前位置行+1，列不变
	if (IsPass(maze, N, M, next))
	{
		if (GetMazePath(maze, N, M, next))
			return true;
	}
	//左
	next = cur;
	next.col -= 1;//左方向位置：当前位置列-1，行不变
	if (IsPass(maze, N, M, next))
	{
		if (GetMazePath(maze, N, M, next))
			return true;
	}
	//右
	next = cur;
	next.col += 1;//右方向位置：当前位置列+1，行不变
	if (IsPass(maze, N, M, next))
	{
		if (GetMazePath(maze, N, M, next))
			return true;
	}

	StackPop(&path); //当前位置上下左右都没有通路，则return前，把当前位置出栈。
	return false;
}

int main()
{
	//1、解决输入问题
	int N = 0, M = 0;
	while (scanf("%d%d", &N, &M) != EOF)//多组输入
	{
		//int a[N][M]变长数组，vs2013不支持

		//动态开辟二维数组
		//先开辟一个存储int*类型的数组，然后在每个元素又去开辟(指向)int类型的数组
		//malloc开辟int*元素的空间，则会返回首元素的地址即&(int*)，因此需要二级指针接收。
		int** maze = (int**)malloc(sizeof(int*) * N);
		if (maze == NULL)
			return -1;
		for (int i = 0; i < N; i++)
		{
			maze[i] = (int*)malloc(sizeof(int) * M);
			if (maze == NULL)
				return -1;
		}

		//2、二维数组的输入
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				scanf("%d", &maze[i][j]);
			}
		}

		PrintMaze(maze, N, M);

		//3、迷宫求出路径
		StackInit(&path);

		PT entry = { 0,0 };//迷宫入口
		if (GetMazePath(maze, N, M, entry))
		{
			//printf("找到通路\n");//测试GetMazePath逻辑是否正确
			PrintPath(&path);
		}
		else
		{
			//printf("没有找到通路\n");//测试GetMazePath逻辑是否正确
		}

		StackDestroy(&path);

		//释放二维的空间。
		//先释放里面的元素为int的数组，再释放外面的元素为int*的数组。
		for (int i = 0; i < N; i++)
		{
			free(maze[i]);
		}
		free(maze);
		maze = NULL;
	}
	return 0;
}

#endif