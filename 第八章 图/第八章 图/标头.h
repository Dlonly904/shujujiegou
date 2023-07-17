#pragma once
#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include <stack>
#include <algorithm>
const int INF = 0x3f3f3f3f;
using namespace std;
enum GraphType { UNDIRGRAPH, DIRGRAPH, UNDIRNETWORK, DIRNETWORK };

template<class T>
struct EdgeType {
	T head, tail;
	int cost;
	EdgeType() {}
	EdgeType(T h, T t, int c) { head = h; tail = t; cost = c; }
};

template<class T>
struct Edge {
	T adjvex;
	int lowcost;
};

template<class T>
class MGraph {
private:
	int vexnum, edgenum;
	GraphType kind;
	vector<vector<int> >edges;
	vector<T>vexs;
	void DFS(int v, bool* visited);
public:
	MGraph(GraphType t, T v[],int n, int e);
	~MGraph() {};
	T GetVexValue(int v);
	int GetEdgeValue(int v, int i);
	int MiniNum(Edge<T>* p);
	static bool cmp(EdgeType<T>e1, EdgeType<T>e2) {
		return e1.cost < e2.cost;
	}
	void GetGraph(vector<EdgeType<T> >& graph);
	void DFSTraverse();
	void BFSTraverse();
	void Prim(int v);
	void Kruskal(vector<EdgeType<T> >& tree);
	void PrintPath(int path[], int dist[], int v);
	void Dijkstra(int v, int path[], int dist[]);
};

template<class T>
MGraph<T>::MGraph(GraphType t, T v[], int n, int e) :vexnum{ n }, edgenum{ e }, kind{ t }{
	vexs.resize(vexnum);
	edges.resize(vexnum);
	for (int i = 0; i < n; i++) {
		vexs[i] = v[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				edges[i].push_back(0);
			}
			else {
				edges[i].push_back(INF);
			}
		}
	}
	for (int i = 0; i < e; i++) {//!
		int va, vb, w;
		cin >> va >> vb;
		cin >> w;
		if (kind == 0) edges[va][vb] = edges[vb][va] = w;
		else edges[va][vb] = w;
	}
}

template<class T>
void MGraph<T>::DFS(int v, bool* visited) {
	cout << vexs[v];
	visited[v] = true;
	for (int i = 0; i < vexnum; i++)
	{
		if (edges[v][i] == 1 && !visited[i])
		{
			DFS(i, visited);
		}
	}
}

template<class T>
void MGraph<T>::DFSTraverse() {
	bool* visited = new bool[vexnum];
	memset(visited, 0, sizeof(bool) * vexnum);
	for (int v = 0; v < vexnum; v++) {
		if (!visited[v]) {
			DFS(v, visited);
		}
	}
	delete[]visited;
}

template<class T>
void MGraph<T>::BFSTraverse() {
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
	delete[]visited;
}

template<class T>
T MGraph<T>::GetVexValue(int v) {
	return vexs[v];
}

template<class T>
int MGraph<T>::GetEdgeValue(int v, int i) {
	return edges[v][i];
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
	for (int i = 0; i < vexnum; i++) {
		miniedges[i].adjvex = GetVexValue(v);
		miniedges[i].lowcost = GetEdgeValue(v, i);
	}
	miniedges[v].lowcost = 0;
	for (int i = 1; i < vexnum; i++) {
		int k = MiniNum(miniedges);
		cout << miniedges[k].adjvex << "<->" << GetVexValue(k) << endl;
		miniedges[k].lowcost = 0;
		for (int j = 0; j < vexnum; j++) {
			if (GetEdgeValue(k, j) < miniedges[j].lowcost) {
				miniedges[j].adjvex = GetVexValue(k);
				miniedges[j].lowcost = GetEdgeValue(k, j);
			}
		}
	}
	delete[]miniedges;
}

template<class T>
void MGraph<T>::GetGraph(vector<EdgeType<T> >& graph) {
	for (int i = 0; i < vexnum; i++) {
		for (int j = i + 1; j < vexnum; j++) {
			if (edges[i][j] != INF) {
				int head = GetVexValue(i);
				int tail = GetVexValue(j);
				int cost = edges[i][j];
				EdgeType<T> temp(head, tail, cost);
				graph.push_back(temp);
			}
		}
	}
	sort(graph.begin(), graph.end(), cmp);
}

template<class T>
void PrintSubTree(MGraph<T>& g, vector<EdgeType<T> >tree) {
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
void MGraph<T>::Kruskal(vector<EdgeType<T> >& tree) {
	vector<EdgeType<T> > graph;
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