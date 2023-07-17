#pragma once
#include <iostream>

using namespace std;
template <class T, int MaxSize >
class SeqStack
{
    T data[MaxSize];      	//���ջԪ�ص�����
    int top;  //ջ��ָ�룬ָʾջ��Ԫ���������е��±�
public:
    SeqStack();            	//���캯��
    void Push(T x);          	//��ջ
    T Pop();               	//��ջ
    T Top();	            	//ȡջ��Ԫ�أ�Ԫ�ز�����ջ��
    bool Empty();          	//�ж�ջ�Ƿ�Ϊ��
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

        cerr << "����";
        exit(1);
    }
    top++;
    data[top] = x;
}
template <class T, int MaxSize >
T SeqStack<T, MaxSize>::Pop()
{
    if (top == -1)//�ж�ջ�Ƿ�Ϊ��
    {
        cerr << "����";
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
        cerr << "����";
        exit(1);
    }
    return data[top];
}
template <class T, int MaxSize>
bool SeqStack<T, MaxSize>::Empty()
{
    return top == -1;
}
