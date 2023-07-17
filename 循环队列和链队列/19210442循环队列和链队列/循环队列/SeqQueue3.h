#pragma once
#ifndef _SEQQUEUE3_H_
#define _SEQQUEUE3_H_
template <class T, int MaxSize >        //定义类模板SeqQueue
class SeqQueue
{
public:
    T data[MaxSize];           //存放队列元素的数组
    int front, rear;           //队头和队尾指针
    bool flag;               //队列上一次操作状态,0表示出队,1表示入队
public:
    SeqQueue();              //构造函数，置空队
    void EnQueue(T x);        //将元素x入队
    T DeQueue();            //将队头元素出队
    T GetQueue();            //取队头元素（并不删除）
    bool Empty();            //判断队列是否为空
    bool Full();             //判断队列是否为满
};
#endif