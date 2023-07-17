#include"标头.h"
using namespace std;
void print(const vector<vector<int>> vec)
{
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec[0].size(); j++) {
			cout << vec[i][j] << "\t";
			if (j == vec[0].size() - 1)
				cout << endl;
		}
	}
}

int main()
{
	int a[] = { 0,1,2,3,4,5 };
	MGraph<int> g(UNDIRNETWORK, a, 6, 10);
	//cout << "深度优先：" << endl;
	//g.DFSTraverse();
	//cout << endl;
	cout << "广度优先" << endl;
	g.BFSTraverse();
	cout << endl << "Prim:"<<endl;
	g.Prim(0);
	vector< EdgeType<int> > tree;
	g.Kruskal(tree);
	cout << "Kruskal:" << endl;
	PrintSubTree(g, tree);
	int* path = new int[100];
	int* dist = new int[100];
	g.Dijkstra(0, path, dist);
	cout << "Dijkstra:" << endl;
	g.PrintPath(path, dist, 0);
}
//0 1 1 2 2 0 0 3 2 3 3 4 2 4
//0 1 2 0 3 4 1 2 4 0 2 5 2 3 6 2 4 3 1 4 5 2 5 3 3 5 7 4 5 1
