#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
#include "LinkQueue.h"
using namespace std;

template <class T>
LinkQueue<T>::LinkQueue()
{
    Node<T>*s = new Node<T>;
    s->next = NULL;
    front = rear = s;
}
template <class T>
LinkQueue<T>::~LinkQueue()
{
    Node<T>* p = front;
    while (p)
    {
        Node<T>* q = p;
        p = p->next;
        delete q;
    }
    front = NULL;
    rear = NULL;
}
template <class T>
void LinkQueue<T>::EnQueue(T x)
{
    Node<T>* s = new Node<T>;
    s->data = x;
    s->next = NULL;
    rear->next = s;
    rear = s;
}
template <class T>
T LinkQueue<T>::DeQueue()
{
    if (Empty()) { cerr << "下溢"; exit(1); }
    Node<T>* p = front->next;
    T x = p->data;
    front->next = p->next;
    if (p->next == NULL) rear = front;  //修改队尾指针 
    delete p;
    return x;
}
template <class T>
T LinkQueue<T>::GetQueue()
{
    if (Empty()) { cerr << "队空"; exit(1); }
    T x = front->next->data;
    return x;
}
template <class T>
bool LinkQueue<T>::Empty()
{
    return rear == front;
}