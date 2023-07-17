#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
#include"SeqQueue1.h"
using namespace std;

template <class T, int MaxSize >
SeqQueue<T, MaxSize>::SeqQueue()
{
	front = rear = 0;
}
template <class T, int MaxSize >
void SeqQueue<T, MaxSize>::EnQueue(T x)
{
	if ((rear + 1) % MaxSize == front) { cerr << "ÉÏÒç";exit(1); }
	rear = (rear + 1) % MaxSize;
	data[rear] = x;
}
template <class T, int MaxSize >
T SeqQueue<T, MaxSize>::DeQueue()
{
	if(rear==front) { cerr << "ÏÂÒç";exit(1); }
	front = (front + 1) % MaxSize;
	return data[front];
}
template <class T, int MaxSize >
T SeqQueue<T, MaxSize>::GetQueue()
{
	if (rear == front) { cerr << "¶Ó¿Õ";exit(1); }
	return data[(front + 1) % MaxSize];
}
template <class T, int MaxSize >
bool SeqQueue<T, MaxSize>::Empty()
{
	return rear == front;
}