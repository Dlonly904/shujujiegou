#pragma once
#ifndef _SEQQUEUE1_H_
#define _SEQQUEUE1_H_
template <class T, int MaxSize >        //������ģ��SeqQueue
class SeqQueue
{
    T data[MaxSize];           //��Ŷ���Ԫ�ص�����
    int front, rear;              //��ͷ�Ͷ�βָ��
public:
    SeqQueue();              //���캯�����ÿն�
    void EnQueue(T x);        //��Ԫ��x���
    T DeQueue();            //����ͷԪ�س���
    T GetQueue();            //ȡ��ͷԪ�أ�����ɾ����
    bool Empty();            //�ж϶����Ƿ�Ϊ��
};


#endif // !_SEQQUEUE_H_
