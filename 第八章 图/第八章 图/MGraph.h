#pragma once
#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include <stack>
#include <algorithm>
const int INF = 0x3f3f3f3f;
using namespace std;
enum Graphtype { UNDIRGRAPH, DIRGRAPH, UNDIRNETWORK, DIRNETWORK };	//无向图 有向图 无向网 有向网
template<class T>
struct Edge
{
	T adjvex;
	int lowcost;
};
template<class T>
struct Edgetype
{
	T head, tail;
	int cost;
	Edgetype() {}
	Edgetype(T h, T t, int c) { head = h; tail = t; cost = c; }
};

template<class T>
class MGraph
{
private:
    int vexnum, edgenum;
    Graphtype kind;
    vector<vector <int>>edges;//邻接矩阵
    vector<T>vexs;//顶点表
    void DFS(int v, bool* visited);//深度优先遍历
	int MiniNum(Edge<T>* p);
	void GetGraph(vector<Edgetype<T> >& graph);
public:
    MGraph(Graphtype t, T v[], int n, int e);
    ~MGraph() {};
	static bool cmp(Edgetype<T>e1, Edgetype<T>e2) {
		return e1.cost < e2.cost;
	}
    int VexterNum();//返回图中顶点数量
    int EdgeNum();//返回图中边数量
    T GetVexValue(int i);//返回顶点表中第i个顶点的值
    int GetVexValueNum(T v);//返回顶点表中值的序号
    int GetEdgeValue(int i, int j);//返回邻接矩阵中第i个顶点到第j个顶点的权值
    void DFSTraverse();//深度优先遍历
    void BFSTraverse();//广度优先遍历
    void Prim(int v);
	void Kruskal(vector<Edgetype<T> >& tree);
	void PrintPath(int path[], int dist[], int v);
	void Dijkstra(int v, int path[], int dist[]);
	void Floyd(int path[][10], int D[][10]);
};

template <class T>
MGraph<T>::MGraph(Graphtype t, T v[], int n, int e) :vexnum(n), edgenum(e), kind(t)
{
	vexs.resize(vexnum);
	edges.resize(vexnum);
	for (int i = 0; i < n; i++)
	{
		vexs[i] = v[i];
	}
	for (int i = 0; i < n; i++)
		edges[i].resize(vexnum);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			if (i == j)
				edges[i][j] = 0;
			else edges[i][j] = INF;
	}
	for (int i = 0; i < e; i++)
	{
		int va, vb, w;
		cin >> va >> vb;
		cin >> w;
		edges[va][vb] = edges[vb][va] = w;//无向网图
	}
}
template <class T>
void MGraph<T>::DFS(int v, bool* visited)
{
	cout << vexs[v];
	visited[v] = true;//访问顶点v
	for (int i = 0; i < vexnum; i++)
	{
		if (edges[v][i] == 1 && !visited[i])//从顶点v没有被访问的邻接点中选取一个
			DFS(i, visited);//开始递龟
	}

}
template <class T>
void MGraph<T>::DFSTraverse()//深度优先遍历递归算法
{
	bool* visited = new bool[vexnum];//建立访问标记数组
	for (int v = 0; v < vexnum; v++)
	{
		visited[v] = false;//初始化

	}
	for (int v = 0; v < vexnum; v++)
	{
		if (!visited[v])
			DFS(v, visited);
		
	}
}

template <class T>
void MGraph<T>::BFSTraverse()//广度优先遍历算法
{
	queue<int>q;
	bool* visited = new bool[vexnum];
	memset(visited, 0, sizeof(bool) * vexnum);
	for (int i = 0; i < vexnum; i++) {
		if (!visited[i]) {
			cout << vexs[i];
			visited[i] = true;
			q.push(i);
			while (!q.empty()) {
				int u = q.front();
				q.pop();
				for (int j = 0; j < vexnum; j++) {
					if (edges[u][j] == 1 && !visited[j]) {
						cout << vexs[j];
						visited[j] = true;
						q.push(j);
					}
				}
			}
		}
	}

}
template<class T>
int MGraph<T>::VexterNum()
{
	return vexnum;
}
template<class T>
int MGraph<T>::EdgeNum()
{
	return edgenum;
}
template<class T>
T MGraph<T>::GetVexValue(int i)
{
	return vexs[i];
}
template<class T>
int  MGraph<T>::GetVexValueNum(T v)
{
	for (int i = 0; i < vexnum; i++)
		if (vexs[i] == v)
			return i;
}
template<class T>
int MGraph<T>::GetEdgeValue(int i, int j)
{
	return edges[i][j];
}
template<class T>
int MGraph<T>::MiniNum(Edge<T>* p) {
	int i = 0;
	while (!p[i].lowcost) i++;
	int min = p[i].lowcost;
	int minIndex = i;
	for (int j = i; j < vexnum; j++) {
		if (p[j].lowcost && p[j].lowcost < min) {
			min = p[j].lowcost;
			minIndex = j;
		}
	}
	return minIndex;
}

template<class T>
void MGraph<T>::Prim(int v) {
	Edge<T>* miniedges = new Edge<T>[vexnum];
	for (int i = 0; i < vexnum; i++) 
	{
		miniedges[i].adjvex = GetVexValue(v);
		miniedges[i].lowcost = GetEdgeValue(v, i);
	}
	miniedges[v].lowcost = 0;
	for (int i = 1; i < vexnum; i++)
	{
		int k = MiniNum(miniedges);
		cout << miniedges[k].adjvex << "<->" << GetVexValue(k) << endl;
		miniedges[k].lowcost = 0;
		for (int j = 0; j < vexnum; j++)
		{
			if (GetEdgeValue(k, j) < miniedges[j].lowcost) 
			{
				miniedges[j].adjvex = GetVexValue(k);
				miniedges[j].lowcost = GetEdgeValue(k, j);
			}
		}
	}
	delete[]miniedges;
}

template<class T>
void MGraph<T>::GetGraph(vector<Edgetype<T> >& graph)
{
	for (int i = 0; i < vexnum; i++) {//遍历edges矩阵
		for (int j = i + 1; j < vexnum; j++) {
			if (edges[i][j] != INF) {//如果非空
				int head = GetVexValue(i);
				int tail = GetVexValue(j);
				int cost = edges[i][j];
				Edgetype<T> temp(head, tail, cost);//建立一个边类型temp来储存数据
				graph.push_back(temp);//把temp压入graph数组中
			}
		}
	}
	sort(graph.begin(), graph.end(), cmp);//排序
}

template<class T>
void PrintSubTree(MGraph<T>& g, vector<Edgetype<T> >tree) {
	int i = 0;
	while (i < tree.size()) {
		cout << g.GetVexValue(tree[i].head) << "<->" << g.GetVexValue(tree[i].tail) << endl;
		i++;
	}
}

int find(int* p, int x)
{
	if (p[x] != x) p[x] = find(p, p[x]);
	return p[x];
}
template<class T>
void MGraph<T>::Kruskal(vector<Edgetype<T> >& tree) {
	vector<Edgetype<T> > graph;
	GetGraph(graph);
	tree.resize(vexnum - 1);
	int* components = new int[edgenum];
	for (int i = 0; i < vexnum; i++) {
		components[i] = i;
	}
	int k = 0, j = 0;
	while (k < vexnum - 1) {
		T h1 = graph[j].head;
		T t1 = graph[j].tail;
		int h2 = components[h1];//有不合法的可能
		int t2 = components[t1];
		if (find(components, h2) != find(components, t2)) {
			tree[k].head = h1;
			tree[k].tail = t1;
			tree[k].cost = graph[j].cost;
			k++;
			components[find(components, t2)] = find(components, h2);
		}
		j++;
	}
	delete[]components;
}
template<class T>
void MGraph<T>::PrintPath(int path[], int dist[], int v) {
	T target = GetVexValue(v);
	for (int i = 0; i < vexnum; i++) {
		T temp = GetVexValue(i);
		cout << target << "->" << temp << ":\tdist:" << dist[i] << "\tpath:" << target;
		stack<T> st;
		int k = i;
		st.push(temp);
		while (path[k] != target) {
			st.push(path[k]);
			k = path[k];
		}
		while (!st.empty()) {
			cout << "->" << st.top();
			st.pop();
		}
		cout << endl;
	}
}
template<class T>
void MGraph<T>::Dijkstra(int v, int path[], int dist[]) {
	bool* s = new bool[vexnum];
	for (int i = 0; i < vexnum; i++) {
		s[i] = false;
		dist[i] = GetEdgeValue(v, i);
		if (dist[i] < INF || i == v) {
			path[i] = v;
		}
		else {
			path[i] = -1;
		}
	}
	dist[v] = 0;
	s[v] = true;
	for (int i = 1; i < vexnum; i++) {
		int min = INF;
		int k;
		for (int j = 0; j < vexnum; j++) {
			if (!s[j] && dist[j] < min) {
				k = j;
				min = dist[j];
			}
		}
		s[k] = true;
		for (int w = 0; w < vexnum; w++) {
			if (!s[w] && dist[w] > dist[k] + GetEdgeValue(k, w)) {
				dist[w] = dist[k] + GetEdgeValue(k, w);
				path[w] = k;
			}
		}
	}
	delete[]s;
}
template<class T>
void MGraph<T>::Floyd(int path[][10],int D[][10])
{
	for (int i = 0; i < vexnum; i++)
	{
		for (int j = 0; j < vexnum; j++)
		{
			if (i == j)
				D[i][j] = 0;
			else
				D[i][j] = GetEdgeValue(i, j);
			if (D[i][j] < INF)
				path[i][j] = j;
			else
				path[i][j] = -1;

		}
		for (int k = 0; k < vexnum; k++)
			for(int i=0;i<vexnum;i++)
				for (int j = 0; j < vexnum; j++)
					if (D[i][k] + D[k][j] < D[i][j])
					{
						D[i][j] = D[i][k] + D[k][j];//修改最短路径长度
						path[i][j] = path[i][k];//修改最短路经
				}
	}
}
template <class T>
int len(T& array)
{
	return (sizeof(array) / sizeof(array[0]));
}
template <class T>
void OutPutPath(MGraph<T>& g, int path[][10], int D[][10])
{
	//	for (int i = 0; i < path1.size(); i++)	Output(path1.at(i));
	//	for (int i = 0; i < D.size(); i++)		Output(D.at(i));;
	for (int k = 0; k <len(path); k++)
	{
		for (int i = 0; i <len(path); i++)
		{
			cout << k << "—>" << i << ":";
			string fpath = string(1, i + '0');
			if (path[k][i] == -1)
			{
				cout << "不存在路径" << endl;	continue;
			}
			else if (path[k][i] != i)		fpath = string(1, path[k][i] + '0') + fpath;
			fpath = string(1, k + '0') + fpath;
			cout << fpath << "	距离：" << D[k][i] << endl;
		}
	}
}