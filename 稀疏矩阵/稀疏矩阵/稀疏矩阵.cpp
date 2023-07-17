/*1. 实现稀疏矩阵转置的朴素方法和快速方法。

2. 实现稀疏矩阵的加法和乘法。*/

#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
template <class T>
struct Triple
{
	int r, c;//该元素的行下标和列下标
	T elem;//该元素的值
};
template <class T>
class SparseMatrix
{
	vector< Triple<T> >triList; //储存矩阵中非零元素的三元组表
	int rows, cols, num;
public:
	SparseMatrix();
	SparseMatrix(Triple <T>* tlist, int rs, int cs ,int n);
	void trans1(SparseMatrix<T>& B); //矩阵的朴素转置运算
	void trans2(SparseMatrix<T>& B); //矩阵的快速转置运算
	SparseMatrix operator +(SparseMatrix<T>& B); //矩阵加法运算
	SparseMatrix operator *(SparseMatrix<T>& B); //矩阵乘法运算

	void print(); //打印

};
template <class T>
SparseMatrix<T>::SparseMatrix()
{
	
	rows=0, cols=0, num=0;
}
template <class T>
SparseMatrix<T>::SparseMatrix(Triple<T>* tlist, int rs, int cs, int n) :rows(rs), cols(cs), num(n)
{
	Triple<T>* tag = tlist;
	for (int i = 0; i < num; i++)
	{
		triList.push_back(*tag++);
	}
}
template <class T>
void SparseMatrix<T>::trans1(SparseMatrix<T>& B)//朴素转置
{
	B.rows = cols;
	B.cols = rows;
	B.num = num;
	B.triList.resize(num);/*用于改变容器大小并创建对象，调用此函数后，就可以引用容器
	内对象了，如通过下标运算符[]来引用元素对象*/
	if (num == 0)
		return;
	int q = 0;
	for (int col = 0; col < cols; ++col)
	{
		for (int p = 0; p < num; ++p)
		{
			if (triList[p].c == col) 
			{
				B.triList[q].r = triList[p].c;
				B.triList[q].c = triList[p].r;
				B.triList[q].elem = triList[p].elem;
				++q;
			} 
		}
			
	}
}

template <class T>
void SparseMatrix<T> ::trans2(SparseMatrix<T>& B)//快速转置
{
	B.rows = cols;
	B.cols = rows;
	B.num = num;
	B.triList.resize(num);
	if (num == 0)
		return;
	int* cnum = new int[cols];
	int* cpot = new int[cols];
	for (int col = 0; col < cols; ++col)
		cnum[col] = 0;
	for (int t = 0; t < num; ++t)
		++cnum[triList[t].c];
	cpot[0] = 0;
	for (int col = 1; col < cols; ++col)
		cpot[col] = cpot[col - 1] + cnum[col + 1];
	for (int p = 0; p < num; ++p)
	{
		int col = triList[p].c;
		int q = cpot[col];
		B.triList[q].r = triList[p].c;
		B.triList[q].c = triList[p].r;
		B.triList[q].elem = triList[p].elem;
		++cpot[col];
	}
	delete[]cnum;
	delete[]cpot;
}

template<class T>
SparseMatrix<T> SparseMatrix<T>::operator + (SparseMatrix& B)
{
	if (rows != B.rows || cols != B.cols)
	{
		cerr << "参数非法" << endl;
		exit(1);
	}
	int i = 0, j = 0;
	int k = 0;
	Triple<T>* tl = new Triple<T>[triList.size() + B.triList.size()];
	while (i < triList.size() && j < B.triList.size())
	{
		if ((triList[i].r == B.triList[j].r) && (triList[i].c == B.triList[j].c))
		{
			Triple<T> m;
			m.r = triList[i].r;
			m.c = triList[i].c;
			m.elem = triList[i].elem + B.triList[j].elem;
			tl[k++] = m;
			i++;
			j++;
		}
		else if (triList[i].r < B.triList[j].r ||
			(triList[i].r == B.triList[j].r && triList[i].c < B.triList[j].c))
		{
			tl[k++] = triList[i++];
		}
		else
		{
			tl[k++] = B.triList[j++];
		}
	}
	while (i < triList.size())
	{
		tl[k++] = triList[i++];
	}
	while (j < B.triList.size())
	{
		tl[k++] = B.triList[j++];
	}
	SparseMatrix<T> res(tl, rows, cols, k);
	delete[]tl;
	return res;
}
template<class T>
SparseMatrix<T> SparseMatrix<T>::operator *(SparseMatrix& B)
{
	if (cols != B.rows)
	{
		cerr << "参数非法" << endl;
		exit(1);
	}
	SparseMatrix<T> C;//C存放B的转置
	B.trans2(C);

	int* rpot1 = new int[rows];
	int* rpot2 = new int[C.rows];
	Getrpot(rpot1);
	C.Getrpot(rpot2);

	SparseMatrix<T> res;
	res.rows = rows;
	res.cols = C.cols;

	for (int i = 1; i <= rows; i++)
	{
		int end1 = (i < rows) ? rpot1[i] : num;//end
		for (int j = 1; j <= C.rows; j++)
		{
			int end2 = (j < C.rows) ? rpot2[j] : C.num;//end
			T tmp = 0;                 //用于累加
			int p = rpot1[i - 1];    //start
			int q = rpot2[j - 1];    //start
			while (p < end1 && q < end2)
			{
				if (triList[p].c < C.triList[q].c)
					p++;
				else if (triList[p].c > C.triList[q].c)
					q++;
				else
					tmp += triList[p++].elem * C.triList[q++].elem;
			}
			if (tmp != 0)
			{
				Triple<T> temp;
				temp.r = i - 1; temp.c = j - 1; temp.elem = tmp;
				res.triList.push_back(temp);
			}
		}
	}
	res.num = res.triList.size();
	return res;
}

template<class T>
void SparseMatrix<T>::print()
{
	auto it = triList.begin();
	for (; it != triList.end(); it++)
	{
		cout << it->r << " " << it->c << " " << it->elem << endl;
	}
}

int main()
{
	Triple<int> a[6] = { {0,0,12},{0,1,8},{0,2,7},{1,1,8},{2,1,6} };
	Triple<int> b[6] = { {0,0,-4},{0,1,-8},{0,2,-1},{1,2,8},{2,2,4} };

	SparseMatrix<int> sm(a, 3, 3, 5);
	SparseMatrix<int> sm2(b, 3, 3, 5);
	sm2.print();
	sm.trans1(sm2);
	sm.print();
    sm2.print();
}

