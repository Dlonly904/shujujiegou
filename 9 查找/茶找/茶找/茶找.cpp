// 茶找.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stdlib.h>
#include <time.h> 
#include"二叉排序树.h"
using namespace std;
struct Record
{
	int key;
};
int SeqSearch(Record r[], int n, int k)//顺序查找无监视哨
{
	int i = 0;
	while (i < n && r[i].key != k) 
		i++;
	if (i < n) 
		return i;
	else return -1;
}
int SeqSearch2(Record r[], int n, int k)//有监视哨
{
	int i = 0;
	r[n-1].key = k;
	while (r[i].key != k)
		i++;
	if (i < n)
		return i;
	else return -1;
}
int BiSearch(Record r[], int n, int k)//折半查找非递归
{
	int low = 0, high = n - 1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (r[mid].key == k) 
			return mid;
		else if (r[mid].key < k)
			low = mid + 1;
		else 
			high = mid - 1;
	}
	return -1;
}

int Bisearch2(Record r[], int low, int high, int k)//折半递归
{
	if (low > high)
		return -1;
	else
	{
		int mid = (low + high) / 2;
		if (r[mid].key == k)
			return mid;
		else
			if (r[mid].key < k)
				return Bisearch2(r, mid + 1, high, k);
			else
				return Bisearch2(r, low, mid - 1, k);
	}
}
int HashSearch1(int hash[], int m, int k)
{
	int pos = k % m;
	int t = pos;
	while (hash[pos] != NULL)
	{
		if (hash[pos] == k)
			return pos;
		else
			pos = (pos + 1) % m;
		if (pos == t)
			return -1;
	}
	return -1;
}
int main()
{
	int a[10] = { 1,2,4,5,6,7,8,9,11,14 };
	BiSortTree tree(a, 10);
	tree.Insert(3);
	if (tree.Search(3))
		cout << "查找成功" << endl;
	tree.Delete(3);
	if (!tree.Search(3))
		cout << "查找失败" << endl;
	Record r[10];
	srand((unsigned)time(NULL));

	for (int i = 0; i < 10; i++) {

		r[i].key = 8 + rand() % 50;
		r[6].key = 7;
		cout << r[i].key << endl;
	}


	cout << SeqSearch(r, 10, 7) << endl;
	cout << SeqSearch2(r, 10, 7)
		<< endl;

	for (int i = 0; i < 10; i++) {

		r[i].key = i + 1;
	}

	cout << BiSearch(r, 10, 7) << endl;
	cout << Bisearch2(r, 0, 10, 7) << endl;
	cout << HashSearch1(a, 10, 4) << endl;
}

