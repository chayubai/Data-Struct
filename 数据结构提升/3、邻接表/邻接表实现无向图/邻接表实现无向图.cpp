#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

#if 1
#define MaxVertex 100
// 邻接点的结构体
struct edgeNode
{
	// 当前顶点在顶点数组中的位置
	int position;
	// 指向后继节点的指针
	struct edgeNode* next;
	// 节点相关的信息 - info
	int weight;//权值
};

// 顶点数组的结构体
struct Vertex
{
	// 顶点的名字
	char name[9];
	// 指向临接点结构体指针
	struct edgeNode* first;
};
// 邻接表图结构
struct GraphList
{
	// 顶点数组
	Vertex head[MaxVertex];
	// 顶点的个数
	int vertexNum;
	// 边的条数
	int edgeNum;
};

int LocalVertex(GraphList& g, char* name)
{
	for (int i = 0; i < g.vertexNum; ++i)
	{
		if (strcmp(name, g.head[i].name) == 0)
		{
			return i;
		}
	}
	return -1;	// 没找到
}

// 创建一个图
void CreateGraph(GraphList& g)
{
	cout << "请输入图的顶点数和边数: 顶点 边" << endl;
	cin >> g.vertexNum >> g.edgeNum;
	//顶点的命名
	cout << "请输入" << g.vertexNum << "个顶点的值" << endl;
	for (int i = 0; i < g.vertexNum; ++i)
	{
		cin >> g.head[i].name;
		g.head[i].first = NULL;	// 初始化，目前没有邻接点
	}

	cout << "请输入" << g.edgeNum << "条边, 顶点1 顶点2" << endl;
	char v1[9], v2[9];
	for (int i = 0; i < g.edgeNum; ++i)
	{
		cin >> v1 >> v2;
		// 以M为头结点的链表, n是m的;邻接点
		// 求用户输入的顶点在顶点数组中的位置
		int m = LocalVertex(g, v1);
		int n = LocalVertex(g, v2);

		// 链表中添加邻接点
		edgeNode* pNew = new edgeNode;
		// init pNew
		pNew->position = n;	// 当前的节点在顶点数组中的位置
		// pNew添加到头结点数组第m个元素 对应的链表中
		// 头插法  尾插法需要遍历到尾部 ，麻烦，因此用头插法
		pNew->next = g.head[m].first;
		g.head[m].first = pNew;

#if 1//当if 0时，是有向图，当if 1时，是无向图
		// 以N为头结点的链表, m是n的邻接点
		edgeNode* pNew1 = new edgeNode;
		// init pNew1
		pNew1->position = m;	// 当前的节点在顶点数组中的位置
		// pNew添加到头结点数组第n个元素 对应的链表中
		// 头插法
		pNew1->next = g.head[n].first;
		g.head[n].first = pNew1;
#endif

	}
}
// 打印图
void PrintGraphList(GraphList& g)
{
	for (int i = 0; i < g.vertexNum; ++i)
	{
		edgeNode* pNode = g.head[i].first;
		cout << g.head[i].name << ": ";
		while (pNode != NULL)
		{
			int index = pNode->position;
			cout << g.head[index].name << " ,";
			pNode = pNode->next;
		}
		cout << endl;
	}
	cout << endl;
}

// 深度优先搜索
void DFS(GraphList& g)
{
	// 保证顶点不被重复遍历
	bool* visited = new bool[g.vertexNum];
	// init
	for (int i = 0; i < g.vertexNum; ++i)
	{
		visited[i] = false;
	}
	// 从顶点数组中找一个顶点, 开始遍历 - 0
	stack<int> st;	// int - 顶点在顶点数组中的下标
	st.push(0);
	// 访问
	visited[0] = true;
	cout << g.head[0].name << " ";

	// 当栈为空, 遍历完成
	while (!st.empty())
	{
		// 顶点在顶点数组中的下标取出来
		int top = st.top();
		// 找下标对应的顶点的邻接点
		edgeNode* pNode = g.head[top].first;
		while (pNode)
		{
			// 如果节点被遍历过了
			while (pNode && visited[pNode->position])
			{
				// 指针后移
				pNode = pNode->next;
			}
			// 找到了没有被访问的
			if (pNode)
			{
				// 访问
				visited[pNode->position] = true;
				cout << g.head[pNode->position].name << " ";
				// 找新的顶点pNode->position的邻接点
				// 链表和链表直接做跳转
				pNode = g.head[pNode->position].first;
				st.push(pNode->position);
			}
		}
		st.pop();
	}
	delete[] visited;
}

void BFS(GraphList& g)
{
	// 保证顶点不被重复遍历
	bool* visited = new bool[g.vertexNum];
	// init
	for (int i = 0; i < g.vertexNum; ++i)
	{
		visited[i] = false;
	}
	// 从顶点数组中找一个顶点, 开始遍历 - 0
	queue<int> q;	// int - 顶点在顶点数组中的下标
	q.push(0);
	// 访问
	visited[0] = true;
	cout << g.head[0].name << " ";

	// 队列为空,遍历完成
	while (!q.empty())
	{
		// 取出队头元素值, 顶点在顶点数组中的下标
		int front = q.front();
		// 找队头元素对应的定点的所有的邻接点
		edgeNode* pNode = g.head[front].first;
		while (pNode)
		{
			// 如果没有被访问
			if (!visited[pNode->position])
			{
				visited[pNode->position] = true;
				cout << g.head[pNode->position].name << " ";
				// 邻接点入队列
				q.push(pNode->position);
			}
			pNode = pNode->next;
		}
		// 所有的临界点发全部被访问
		q.pop();
	}
	delete[] visited;
}

int main()
{
	GraphList g;
	CreateGraph(g);
	PrintGraphList(g);

	system("pause");
	return 0;
}

#endif