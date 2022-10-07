#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//typedef struct Postion
//{
//	int row;//行
//	int col;//列
//}PT;
//////////////////////////////////////////
//typedef PT STDataType;
////typedef struct Stack
////{
////	STDataType a[MAX];//数组，静态栈
////	int top;//栈顶的位置，即栈顶的下标
////}ST;
//typedef struct Stack
//{
//	STDataType* a;//指针a，用来维护数组栈
//	int top;//栈顶的位置，即栈顶的下标
//	int capacity;//数组栈的容量
//}ST;
//
////数组栈初始化
//void StackInit(ST* ps);
////数组栈销毁
//void StackDestroy(ST* ps);
////数组栈（顶）的插入
//void StackPush(ST* ps, STDataType x);
////数组栈（顶）的删除
//void StackPop(ST* ps);
////栈顶的数据
//STDataType StackTop(ST* ps);
////数组栈的大小
//int StackSize(ST* ps);
////判断栈是否为空
//bool StackEmpty(ST* ps);
//
////数组栈初始化
////void StackInit(ST* ps)//形参不会影响实参，传实参的地址，形参就能改变实参
////{
////	assert(ps);
////	ps->a = NULL;
////	ps->top = 0;//初始top = 0，表示top指向栈顶数据的下一个，即先放数据再++。初始top = -1.表示top指向栈顶数据，即先++再放数据
////	ps->capacity = 0;
////}
//
//void StackInit(ST* ps)//形参不会影响实参，传实参的地址，形参就能改变实参
//{
//	assert(ps);
//	ps->a = (STDataType*)malloc(sizeof(STDataType) * 4);
//	if (ps->a == NULL)
//	{
//		printf("malloc failed\n");
//		exit(-1);
//	}
//	ps->top = 0;//top = 0，表示top指向栈顶数据的下一个，即先放数据再++。top = -1.表示top指向栈顶数据，即先++再放数据
//	ps->capacity = 4;
//}
////数组栈的插入
////void StackPush(ST* ps, STDataType x)
////{
////	assert(ps);
////	if (ps->top == ps->capacity)
////	{
////		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
////		STDataType* tmp = realloc(ps->a, sizeof(STDataType) * newCapacity);
////		if (tmp == NULL)
////		{
////			printf("realloc failed\n");
////			exit(-1);
////		}
////		ps->a = tmp;
////		ps->capacity = newCapacity;
////	}
////	ps->a[ps->top] = x;
////	ps->top++;
////}
//
//void StackPush(ST* ps, STDataType x)
//{
//	assert(ps);
//	if (ps->top == ps->capacity)
//	{
//		STDataType* tmp = realloc(ps->a, sizeof(STDataType) * (ps->capacity * 2));
//		if (tmp == NULL)
//		{
//			printf("realloc failed\n");
//			exit(-1);
//		}
//		ps->a = tmp;
//		ps->capacity = ps->capacity * 2;
//	}
//	ps->a[ps->top] = x;
//	ps->top++;
//}
//
////数组栈销毁
//void StackDestroy(ST* ps)
//{
//	assert(ps);
//	free(ps->a);
//	ps->a = NULL;
//	ps->capacity = ps->top = 0;
//}
//
////数组栈的删除
//void StackPop(ST* ps)
//{
//	assert(ps);
//	//栈空了，调用pop直接中止程序报错
//	//assert(ps->top > 0);相当于assert(!StackEmpty(ps));
//	assert(!StackEmpty(ps));
//	ps->top--;
//}
//
////栈顶的数据
//STDataType StackTop(ST* ps)
//{
//	assert(ps);
//	//assert(ps->top > 0);相当于assert(!StackEmpty(ps));
//	assert(!StackEmpty(ps));
//	return ps->a[ps->top - 1];
//}
//
////数组栈的大小
//int StackSize(ST* ps)
//{
//	assert(ps);
//	return ps->top;//top既是栈的栈顶的下标的前一个，也是栈的大小
//}
////判断栈是否为空
//bool StackEmpty(ST* ps)
//{
//	assert(ps);
//	/*if (ps->top == 0)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}*/
//	return ps->top == 0;
//}
//
//ST path;
////////////////////////////////////////
//void PrintMaze(int** maze, int N, int M)
//{
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < M; j++)
//		{
//			printf("%d ", maze[i][j]);
//		}
//		printf("\n");
//	}
//}
//
////输出栈里面的坐标路径
//void PrintPath(ST* ps)
//{
//	//用另一个栈，将path栈中的数据导入到该栈中
//	ST rPath;
//	StackInit(&rPath);
//	while (!StackEmpty(ps))
//	{
//		StackPush(&rPath, StackTop(ps));
//		StackPop(ps);
//
//	}
//
//	while(!StackEmpty(&rPath))
//	{
//		PT top = StackTop(&rPath);
//		printf("(%d,%d)\n", top.row, top.col);
//		StackPop(&rPath);
//	}
//	StackDestroy(&rPath);
//}
//
//bool IsPass(int** maze, int N, int M, PT pos)
//{
//	if (pos.row >= 0 && pos.row < N && pos.col >= 0 && pos.col < M
//		&& maze[pos.row][pos.col] == 0)
//	{
//		return true;
//	}
//	else
//		return false;
//}
//
//bool GetMazePath(int** maze, int N, int M, PT cur)
//{
//	StackPush(&path, cur);
//
//	//如果走到出口
//	if (cur.row == N - 1 && cur.col == M - 1)
//	{
//		return true;
//	}
//	//探测当前坐标cur位置的上下左右四个方向
//	maze[cur.row][cur.col] = 2;
//	PT next;
//
//	//假设按上下左右顺序探测
//	//上
//	next = cur;
//	next.row -= 1;
//	if (IsPass(maze, N, M, next))
//	{
//		if (GetMazePath(maze, N, M, next))
//			return true;
//	}
//	//下
//	next = cur;
//	next.row += 1;
//	if (IsPass(maze, N, M, next))
//	{
//		if (GetMazePath(maze, N, M, next))
//			return true;
//	}
//	//左
//	next = cur;
//	next.col -= 1;
//	if (IsPass(maze, N, M, next))
//	{
//		if (GetMazePath(maze, N, M, next))
//			return true;
//	}
//	//右
//	next = cur;
//	next.col += 1;
//	if (IsPass(maze, N, M, next))
//	{
//		if (GetMazePath(maze, N, M, next))
//			return true;
//	}
//
//	StackPop(&path);
//	return false;
//}
//int main()
//{
//	//1、解决输入问题
//	int N = 0, M = 0;
//	while (scanf("%d%d", &N, &M) != EOF)
//	{
//		//int a[N][M]变长数组，vs2013不支持
//
//	//动态开辟二维数组
//	//由于开辟的数组需要保存一维数组的地址，因此需要二级指针
//		int** maze = (int**)malloc(sizeof(int*) * N);
//		for (int i = 0; i < N; i++)
//		{
//			maze[i] = (int*)malloc(sizeof(int) * M);
//		}
//
//		//2、二维数组的输入
//		for (int i = 0; i < N; i++)
//		{
//			for (int j = 0; j < M; j++)
//			{
//				scanf("%d", &maze[i][j]);
//			}
//		}
//
//		PrintMaze(maze, N, M);
//
//		//3、迷宫求出路径
//		StackInit(&path);
//
//		PT entry = { 0,0 };
//		if (GetMazePath(maze, N, M, entry))
//		{
//			printf("找到通路\n");
//			PrintPath(&path);
//		}
//		else
//		{
//			printf("没有找到通路\n");
//		}
//
//		StackDestroy(&path);
//
//		//释放空间
//		for (int i = 0; i < N; i++)
//		{
//			free(maze[i]);
//		}
//		free(maze);
//		maze = NULL;
//	}
//	return 0;
//}
//迷宫：
//5 5
//0 1 0 0 0
//0 1 0 1 0
//0 0 0 0 1
//0 1 1 1 0
//0 0 0 0 0