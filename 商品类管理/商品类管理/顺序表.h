#pragma once

#include"Goods.h"
using namespace std;
template<class T, int MaxSize>
class SeqList
{
    T data[MaxSize];
    int length;
public:
    SeqList();//��͹���
    SeqList(T a[], int n);
    int ListLength();      //�����Ա�ĳ���
    void Get(int pos);        //����Ų��Ҳ��Ҹı����Ŀ��
    int Locate(T item); //��ֵ���ң���˳�����ֵΪitem��Ԫ�����
    void PrintSeqList(); //����˳�����������������Ԫ��
    void Insert(int i, T item);  //��˳����i��λ�ò���ֵΪitem��Ԫ��
    T Delete1(int i);
    T Delete();          //2.2ɾ����С
   

};



template<class T, int MaxSize>
SeqList<T, MaxSize>::SeqList(T a[], int n)
{
    if (n > MaxSize) { cerr << "�����Ƿ�"; exit(1); }
    for (int i = 0; i < n; i++)
        data[i] = a[i];
    length = n;
}

template<class T, int MaxSize>
int SeqList<T, MaxSize>::ListLength()
{
    return length;
}

template<class Goods, int MaxSize>
void SeqList<Goods, MaxSize>::Get(int pos)
{
    if (pos<1 || pos>length) { cerr << "����λ�÷Ƿ�"; exit(1); }
    for(int i=0;i<length;i++)
    {
        if(data[i]==pos)
        {
            cout << data[i] << endl;
            cout << "������Ϊ��";
            data[i].ChangeInventory();
        }
    }
    
}

template <class T, int MaxSize>
int SeqList<T, MaxSize>::Locate(T item)
{
    for (int i = 0; i < length; i++)
        if (data[i] == item)
            return i + 1;
    return 0;
}

template<class T, int MaxSize>
void SeqList<T, MaxSize>::PrintSeqList()
{
    for (int i = 0; i < length; i++)
    {
        cout << data[i] <<endl;
    }
    cout << endl;
}
template <class T, int MaxSize>
void SeqList<T, MaxSize>::Insert(int i, T item)
{
    if (length >= MaxSize) { cerr << "����"; exit(1); }
    if (i<1 || i>length + 1) { cerr << "����λ�÷Ƿ�"; exit(1); }
    for (int j = length - 1; j >= i - 1; j--)
        data[j + 1] = data[j];
    data[i - 1] = item;
    length++;
}

template <class T, int MaxSize>
T SeqList<T, MaxSize>::Delete1(int i)
{
    if (length == 0) { cerr << "����"; exit(1); }
    if (i<1 || i>length) { cerr << "ɾ��λ�÷Ƿ�"; exit(1); }
    T x = data[i - 1];
    for (int j = i; j < length; j++)
        data[j - 1] = data[j];
    length--;
    return x;
}
template <class T, int MaxSize>
T SeqList<T, MaxSize>::Delete()
{
    if (length == 0) { cerr << "����"; exit(1); }

    int count = 0;
    for (int j = 0; j < length; j++) {
        for (int i = 0; i < length; i++)
        {
            if (data[j] < data[i] && data[j] < data[count])
                count = j;

        }
    }
    T x = data[count];
    data[count] = data[length - 1];

    return x;
}






