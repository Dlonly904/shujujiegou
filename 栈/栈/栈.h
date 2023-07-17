#pragma once
#include <iostream>

using namespace std;
template <class T, int MaxSize >
class SeqStack
{
    T data[MaxSize];      	//存放栈元素的数组
    int top;  //栈顶指针，指示栈顶元素在数组中的下标
public:
    SeqStack();            	//构造函数
    void Push(T x);          	//入栈
    T Pop();               	//出栈
    T Top();	            	//取栈顶元素（元素并不出栈）
    bool Empty();          	//判断栈是否为空
};
template <class T, int MaxSize >
SeqStack<T, MaxSize>::SeqStack()
{
    top = -1;
}
template <class T, int MaxSize >
void SeqStack<T, MaxSize>::Push(T x)
{
    if (top == MaxSize - 1)
    {

        cerr << "上溢";
        exit(1);
    }
    top++;
    data[top] = x;
}
template <class T, int MaxSize >
T SeqStack<T, MaxSize>::Pop()
{
    if (top == -1)//判断栈是否为空
    {
        cerr << "下溢";
        exit(1);
    }
    T x = data[top];
    top--;
    return x;
}
template <class T,int MaxSize>
T SeqStack<T, MaxSize>::Top()
{
    if (top == -1)
    {
        cerr << "下溢";
        exit(1);
    }
    return data[top];
}
template <class T, int MaxSize>
bool SeqStack<T, MaxSize>::Empty()
{
    return top == -1;
}
