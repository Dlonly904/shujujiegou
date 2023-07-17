#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
#include"SeqQueue2.h"
using namespace std;

template <class T, int MaxSize >
SeqQueue<T, MaxSize>::SeqQueue()
{
	front = rear = MaxSize-1;
	num = 0;
}
template <class T, int MaxSize >
void SeqQueue<T, MaxSize>::EnQueue(T x)
{
	if (Full()) { cerr << "����";exit(1); }
	rear = (rear + 1) % MaxSize;
	data[rear] = x;
	num++;
}
template <class T, int MaxSize >
T SeqQueue<T, MaxSize>::DeQueue()
{
	if (Empty()) { cerr << "����";exit(1); }
	front = (front + 1) % MaxSize;
	num--;
	return data[front];
}
template <class T, int MaxSize >
T SeqQueue<T, MaxSize>::GetQueue()
{
	if (Empty()) { cerr << "�ӿ�";exit(1); }
	return data[(front + 1) % MaxSize];
}
template <class T, int MaxSize >
bool SeqQueue<T, MaxSize>::Empty()
{
	if (num == 0) return 1;
	return 0;
}
template <class T, int MaxSize >
bool SeqQueue<T, MaxSize>::Full()
{
	if (num == MaxSize) return 1;
	return 0;
}
