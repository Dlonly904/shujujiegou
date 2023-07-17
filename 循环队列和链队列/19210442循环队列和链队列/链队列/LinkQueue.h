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
    LinkQueue();       //���캯������ʼ��һ���յ�������
    ~LinkQueue();      //�����������ͷ��������и����Ĵ洢�ռ�
    void EnQueue(T x);  //��Ԫ��x���
    T DeQueue();       //����ͷԪ�س���
    T GetQueue();      //ȡ�����еĶ�ͷԪ��
    bool Empty();      //�ж��������Ƿ�Ϊ��
private:
    Node<T>* front, * rear;
    //��ͷ�Ͷ�βָ�룬�ֱ�ָ��ͷ�����ն˽��
};

#endif // !_LINKQUEUE_H_
