#pragma once
#ifndef _LINKQUEUE_H_
#define _LINKQUEUE_H_
template <class T>
struct Node
{
    T data;
    Node* next;
};
template <class T>
class LinkQueue
{
public:
    LinkQueue();       //构造函数，初始化一个空的链队列
    ~LinkQueue();      //析构函数，释放链队列中各结点的存储空间
    void EnQueue(T x);  //将元素x入队
    T DeQueue();       //将队头元素出队
    T GetQueue();      //取链队列的队头元素
    bool Empty();      //判断链队列是否为空
private:
    Node<T>* front, * rear;
    //队头和队尾指针，分别指向头结点和终端结点
};

#endif // !_LINKQUEUE_H_
