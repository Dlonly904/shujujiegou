#pragma once
#ifndef _SEQQUEUE1_H_
#define _SEQQUEUE1_H_
template <class T, int MaxSize >        //定义类模板SeqQueue
class SeqQueue
{
    T data[MaxSize];           //存放队列元素的数组
    int front, rear;              //队头和队尾指针
public:
    SeqQueue();              //构造函数，置空队
    void EnQueue(T x);        //将元素x入队
    T DeQueue();            //将队头元素出队
    T GetQueue();            //取队头元素（并不删除）
    bool Empty();            //判断队列是否为空
};


#endif // !_SEQQUEUE_H_
