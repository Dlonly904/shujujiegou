#pragma once
#include <algorithm>
#include <iostream>
#include"Student.h"
using namespace std;


template <class T>//结点
struct Node
{
    T data;
    Node<T>* next;
};


template <class T>
class LinkList
{
public:
    LinkList();
    LinkList(T a[], int n);
    ~LinkList();
    int Length();
    T Get(int pos);//按位查找
    void Change(int id);
    int Locate(T x);//按值查找
    void Insert(int i, T item);//插入
    T Delete(int i);//删除
    void PrintList();//打印
    void Invert();//逆置
    friend void Merge(LinkList<T>& L1, LinkList<T>& L2);//归并
    friend class Student;
private:
    Node<T>* head;
};

template <class T>
LinkList<T> ::LinkList()
{
    head = new Node<T>;
    head->next = NULL;
}

template <class T>
LinkList<T> ::LinkList(T a[], int n)
{
    head = new Node<T>;     Node<T>* rear = head;
    for (int i = 0; i < n; i++)
    {
        Node<T>* s = new Node<T>;      s->data = a[i];
        rear->next = s;        rear = s;
    }
    rear->next = NULL;

    /*头插法
    head = new Node<T>;

    for (int i = 0; i < n; i++)
    {
        Node<T> *p = new Node<T>;
        p->data = a[i];
        p->next = head->next;
        head->next = p;

    }*/
}
template <class T>
LinkList<T>:: ~LinkList()
{
    Node<T>* p = head;
    while (p)
    {
        Node<T>* q = p;
        p = p->next;
        delete q;
    }
    head = NULL;
}


template <class T>
int LinkList<T>::Length()
{
    int length = 0;
    Node<T>* p = head->next;
    while (p)
    {
        p = p->next;
        length++;

    }
    return length;
}

void LinkList<Student>::Change(int id)
{
    Node<Student>* p = head->next;

    while (p)
    {
        if (p->data == id)
        {
            
            p->data.InMajor();
            break;
        }
        else
            p = p->next;

    }
}
template <class T>
T LinkList<T> ::Get(int pos)
{
    Node<T>* p = head->next;
    
    while (p)
    {
        if (p->data == pos)
        {
            cout << p->data << endl;
            return p->data;
        }
    else
        p = p->next;
        
    }
        
}
template<class T>
int LinkList<T>::Locate(T x)
{
    Node<T>* p = head->next;
    int pos = 1;
    while (p && p->data != x)
    {
        p = p->next;
        pos++;
    }
    if (p)
        return pos;
    else
        return -1;
}
template<class T>
void LinkList<T>::PrintList()
{
    Node<T>* p = head->next;
    while (p)
    {
        cout << p->data << endl;
        p = p->next;

    }

}
template<class T>
void LinkList<T>::Insert(int i, T item)
{
    Node<T>* p = head;
    int j = 0;
    while (p && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (!p)
    {
        cerr << "插入位置非法";
        exit(1);
    }
    else
    {
        Node<T>* s = new Node<T>;
        s->data = item;
        s->next = p->next;
        p->next = s;
    }


}
template <class T>
T LinkList<T>::Delete(int i)
{
    Node<T>* p = head;
    
    while (p)
    {
        if (p->next->data == i)
        {
             Node<T>* q = p->next;
        T x = q->data;
        p->next = q->next;
        delete q;
        return x;
        }
        else
        p = p->next;
       
    }
   
}
template<class T>
void LinkList<T>::Invert()
{
    Node<T>* p = head->next;
    Node<T>* q = new Node<T>;
    head->next = NULL;
    while (p != NULL)
    {
        q = p;
        p = p->next;
        q->next = head->next;//将节点插入到逆置后单链表的表头
        head->next = q;
    }
}

//template<class T>
void Merge(LinkList<int>& L1, LinkList<int>& L2)
{
    Node<int>* p1 = L1.head->next;
    Node<int>* p2 = L2.head->next;
    Node<int>* p3 = L1.head;
    while ((p1 != NULL) && (p2 != NULL))
    {   //处理两个表非空时的情况。p1，p2指向当前需比较的结点，
        //p3指向结果有序单链表的表尾
        if ((p1->data) < (p2->data))
        {
            p3->next = p1;	p1 = p1->next;
            p3 = p3->next;
        }
        else
        {
            p3->next = p2;   p2 = p2->next;
            p3 = p3->next;
        }
    }
    if (p1 != NULL)  p3->next = p1;
    if (p2 != NULL)  p3->next = p2;
    delete L2.head;     L2.head = NULL;

}