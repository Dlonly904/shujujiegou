#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
#include "SeqQueue3.cpp"
using namespace std;

void test1()
{
	SeqQueue<int,3> sq;
	sq.EnQueue(1);
	sq.EnQueue(2);
	//sq.EnQueue(3);
	//sq.EnQueue(4);
	cout << sq.GetQueue() << endl;
	sq.DeQueue();
	sq.DeQueue();
	//sq.DeQueue();
	cout << sq.GetQueue() << endl;
}
int main()
{
	test1();
	return 0;
}
