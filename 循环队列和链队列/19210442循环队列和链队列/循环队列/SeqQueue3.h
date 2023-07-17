#pragma once
#ifndef _SEQQUEUE3_H_
#define _SEQQUEUE3_H_
template <class T, int MaxSize >        //������ģ��SeqQueue
class SeqQueue
{
public:
    T data[MaxSize];           //��Ŷ���Ԫ�ص�����
    int front, rear;           //��ͷ�Ͷ�βָ��
    bool flag;               //������һ�β���״̬,0��ʾ����,1��ʾ���
public:
    SeqQueue();              //���캯�����ÿն�
    void EnQueue(T x);        //��Ԫ��x���
    T DeQueue();            //����ͷԪ�س���
    T GetQueue();            //ȡ��ͷԪ�أ�����ɾ����
    bool Empty();            //�ж϶����Ƿ�Ϊ��
    bool Full();             //�ж϶����Ƿ�Ϊ��
};
#endif