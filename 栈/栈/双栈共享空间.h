#pragma once
#include<iostream>
using namespace std;
template <class T, int MaxSize>
class BothStack
{
public:
    BothStack();
    void Push(int i, T x);
    T Pop(int i);
    T GetTop(int i);
    bool Empty(int i);
private:
    T data[MaxSize];
    int top1, top2;
};
template <class T,int MaxSize>
BothStack<T, MaxSize>::BothStack()
{
    top1 = -1;
    top2 = MaxSize;
}

template <class T, int MaxSize>
void BothStack<T, MaxSize>::Push(int i, T x)
{
    if (i == 1)
    {
        top1++;
        data[top1] = x;
    }
    if (i == 2)
    {
        top2--;
        data[top2] = x;
    }
}

template <class T, int MaxSize>
T BothStack<T, MaxSize>::Pop(int i)
{
    if (i == 1)
    {
        if (top1 == -1)//ÅÐ¶ÏÕ»ÊÇ·ñÎª¿Õ
        {
            cerr << "ÏÂÒç";
            exit(1);
        }
        T x = data[top1];
        top1--;
        return x;
    }
    if (i == 2)
    {
        if (top2 == MaxSize)//ÅÐ¶ÏÕ»ÊÇ·ñÎª¿Õ
        {
            cerr << "ÏÂÒç";
            exit(1);
        }
        T x = data[top2];
        top2++;
        return x;
    }
}

template <class T, int MaxSize>
T BothStack<T, MaxSize>::GetTop(int i)
{
    if (i == 1)
    {
        if (top1 == -1)//ÅÐ¶ÏÕ»ÊÇ·ñÎª¿Õ
        {
            cerr << "ÏÂÒç";
            exit(1);
        }
        
        return data[top1];
    }
    if (i == 2)
    {
        if (top2 == MaxSize)//ÅÐ¶ÏÕ»ÊÇ·ñÎª¿Õ
        {
            cerr << "ÏÂÒç";
            exit(1);
        }
        
        return data[top2];
    }
}

template <class T, int MaxSize>
bool BothStack<T, MaxSize>::Empty(int i)
{
    if (i == 1)
        return top1 == -1;
    if (i == 2)
        return top2 == MaxSize;
}