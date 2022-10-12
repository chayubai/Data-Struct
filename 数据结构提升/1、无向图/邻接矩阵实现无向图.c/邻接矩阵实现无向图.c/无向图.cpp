#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <stack>
#include <queue>

//最大的顶点数
#define MaxVertex 50 
//存放顶点名称的数组，名称为char*类型
typedef char VertexInfo[9];

//技巧：按Ctrl + 点击函数名，可以跳转到函数实现位置

// 定义图的结构
struct Graph
{
	// 顶点数组 - 存储顶点的名字  等价于  vertex[MaxVertex][9]  最多存放MaxVertex个顶点
	VertexInfo vertex[MaxVertex];
	// 边的数组  二维矩阵 - 存储顶点和边的关系
	int edge[MaxVertex][MaxVertex];
	// 顶点的个数
	int vertexNum;
	// 边的条数
	int edgeNum;
};

// 求用户输入的顶点在顶点数组中的位置
int LocalVertex(Graph& g, VertexInfo v)
{
	// 遍历顶点数组
	for (int i = 0; i < g.vertexNum; ++i)
	{
		if (strcmp(v, g.vertex[i]) == 0)
		{
			// 找到了,返回元素的下标
			return i;
		}
	}
	// 没找到
	return -1;
}

// 构建一个图
void CreateGraph(Graph& g)
{
	//1、输入顶点个数和边条数
	cout << "请输入图的顶点数和边数: 顶点 边" << endl;
	cin >> g.vertexNum >> g.edgeNum;

	//2、给顶点命名
	cout << "请输入" << g.vertexNum << "个顶点的值" << endl;
	for (int i = 0; i < g.vertexNum; ++i)
	{
		cin >> g.vertex[i]; //初始化每个顶点的名字
	}

	//3、初始化所有边都不存在
	for (int i = 0; i < g.vertexNum; ++i)
	{
		for (int j = 0; j < g.vertexNum; ++j)
		{
			g.edge[i][j] = 0;
		}
	}

	//4、设置边
	cout << "请输入" << g.edgeNum << "条边, 顶点1 顶点2" << endl;
	VertexInfo v1, v2;
	for (int i = 0; i < g.edgeNum; ++i)
	{
		cin >> v1 >> v2;
		// 求用户输入的顶点在顶点数组中的坐标位置
		int m = LocalVertex(g, v1); //获取v1在二维数组中的位置
		int n = LocalVertex(g, v2); //获取v2在二维数组中的位置

		// 边对应的二维数组赋值
		g.edge[m][n] = 1;
		g.edge[n][m] = 1;	// 无向图 对称关系
	}
}

// 打印图 - 
void PrintGraph(Graph& g)
{
	// 水平表头
	cout << "\t";
	for (int i = 0; i < g.vertexNum; ++i)
	{
		cout << g.vertex[i] << "\t";
	}
	for (int i = 0; i < g.vertexNum; ++i)
	{
		cout << endl;
		// 垂直的
		cout << g.vertex[i] << "\t";
		for (int j = 0; j < g.vertexNum; ++j)
		{
			cout << g.edge[i][j] << "\t";
		}
	}
	cout << endl;
}

// 深度优先搜索
void DFS(Graph& g)
{
	bool* visited = new bool[g.vertexNum];//该数组用来标记顶点是否被访问过
	// init
	for (int i = 0; i < g.vertexNum; ++i)
	{
		visited[i] = false;
	}

	// 从顶点数组中的第一个开始访问
	stack<int> st;	// int - 顶点数组的下标
	visited[0] = true;//标记第一个顶点被访问
	cout << g.vertex[0] << " ";
	st.push(0);

	while (!st.empty())
	{
		// 遍历所有的顶点, 找邻接点 - 栈顶元素对应的邻接点
		//二维矩阵找邻接点，使用双循环遍历
		for (int i = 0; i < g.vertexNum; ++i)
		{
			// 栈顶元素在顶点数组中的位置
			int top = st.top();
			if (!visited[i] && g.edge[top][i] > 0)
			{
				// 遍历该顶点
				visited[i] = true;
				cout << g.vertex[i] << " ";
				// 邻接点压栈
				st.push(i);
			}
		}
		// 栈顶的顶点与其余的顶点组成的边全部判断了一遍
		st.pop();
	}
	delete[] visited;
}

// 广度优先搜索
void BFS(Graph& g)
{
	// 保证顶点不被重复遍历
	bool* visited = new bool[g.vertexNum];
	// init
	for (int i = 0; i < g.vertexNum; ++i)
	{
		visited[i] = false;
	}

	// 找一个顶点, 开始访问 - 0
	queue<int> q;	// 存储顶点的下标
	visited[0] = true;
	cout << g.vertex[0] << " ";
	q.push(0);

	// 如果队列为空, 遍历完成
	while (!q.empty())
	{
		// 队头顶点的下标值拿出来
		int front = q.front();
		// 遍历所有的顶点, 找邻接点
		// 二维矩阵找邻接点，使用双循环遍历
		for (int i = 0; i < g.vertexNum; ++i)
		{
			// 如果没被访问, 并且两顶点互为邻接点
			if (!visited[i] && g.edge[front][i] > 0)
			{
				// 访问,并且入队列
				visited[i] = true;
				cout << g.vertex[i] << " ";
				q.push(i);
			}
		}
		// 所有的邻接点都访问完成,出队列
		q.pop();
	}
	delete[] visited;
}

//构建图
void test01()
{
	Graph graph;
	CreateGraph(graph);
	PrintGraph(graph);
}

//深度优先搜索
void test02()
{
	Graph graph;
	CreateGraph(graph);
	PrintGraph(graph);

	DFS(graph);
}

//广度优先搜索
void test03()
{
	Graph graph;
	CreateGraph(graph);
	PrintGraph(graph);

	BFS(graph);
}

int main() {

	//test01();
	//test02();
	test03();

	system("pause");
	return EXIT_SUCCESS;
}