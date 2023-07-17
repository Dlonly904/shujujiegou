#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
#include "LinkQueue.cpp"
using namespace std;

int main()
{
	LinkQueue<int> lq;
	lq.EnQueue(1);
	lq.EnQueue(2);
	lq.EnQueue(3);
	cout << lq.DeQueue() << endl;
	cout << lq.DeQueue() << endl;
	cout << lq.GetQueue() << endl;

	return 0;
}
