/*【编程 1】SeqList 类模板的实现与测试
实验内容：
（1）完成 SeqList 类模板的基本功能。
（2）扩展顺序表的功能：
1）排序
2）归并两个有序顺序表
3）2.2~2.6
4）移位操作
（3）编写 main()函数对 SeqList 类模板进行实例化测试，要求：
从键盘输入原始顺序表的个数以及每个元素的值。*/


#include <iostream>
#include<algorithm>
using namespace std;
template<class T, int MaxSize>
class SeqList
{
    T data[MaxSize];
    int length;
public:
    SeqList();//午餐构造
    SeqList(T a[], int n);
    int ListLength();      //求线性表的长度
    T Get(int pos);        //按位查找，取顺序表的第pos个元素
    int Locate(T item); //按值查找，求顺序表中值为item的元素序号
    void PrintSeqList(); //遍历顺序表，按序号依次输出各元素
    void Insert(int i, T item);  //在顺序表第i个位置插入值为item的元素
    T Delete1(int i);
    T Delete();          //2.2删除最小
    void Delete2(T x);//2.3课后习题
    void DeleteBetween(T x, T y);//2.4课后习题
    void Sort();  //排序
    void Merge(SeqList list2);//归并有序顺序表
    void DeleteSame();//2.5
    void Sort2();
    void Move();
     
};
template<class T,int MaxSize>
SeqList<T, MaxSize>::SeqList(T a[], int n)
{
    if (n > MaxSize) { cerr << "参数非法"; exit(1); }
    for (int i = 0; i < n; i++)
        data[i] = a[i];
    length = n;
}

template<class T, int MaxSize>
int SeqList<T, MaxSize>::ListLength()
{
    return length;
}

template<class T, int MaxSize>
T SeqList<T, MaxSize>::Get(int pos)
{
    if (pos<1 || pos>length) { cerr << "查找位置非法"; exit(1); }
    else return data[pos - 1];
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
        cout << data[i]<<" ";
    }
    cout << endl;
}
template <class T, int MaxSize>
void SeqList<T, MaxSize>::Insert(int i, T item)
{
    if (length >= MaxSize) { cerr << "上溢"; exit(1); }
    if (i<1 || i>length + 1) { cerr << "插入位置非法"; exit(1); }
    for (int j = length - 1; j >= i - 1; j--)
        data[j + 1] = data[j];
    data[i - 1] = item;
    length++;
}

template <class T, int MaxSize>
T SeqList<T, MaxSize>::Delete1(int i)
{
    if (length == 0) { cerr << "下溢"; exit(1); }
    if (i<1 || i>length) { cerr << "删除位置非法"; exit(1); }
    T x = data[i - 1];
    for (int j = i; j < length; j++)
        data[j - 1] = data[j];
    length--;
    return x;
}
template <class T, int MaxSize>
T SeqList<T, MaxSize>::Delete()
{
    if (length == 0) { cerr << "下溢"; exit(1); }
    
    int count=0;
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

template <class T, int MaxSize>
void SeqList<T, MaxSize>::Delete2(T x)//2.3
{
    for (int i = 0; i < length; i++)//遍历
    {
        if (data[i] == x)//如果检测到和x值一样的
        {
            int j = i + 1, count = 1;//开始检测后面是否有连着等于x的
            while (j)
            {
                if (data[j] == x)
                {
                    j++;
                    count++;
                }
                else
                    break;
            }
            
            for (int k = i; k < length; k++)//删除操作
            {
                data[k] = data[k+count];
            }
            length -= count;
        }
    }
    
}

template <class T, int MaxSize>
void SeqList<T, MaxSize>::DeleteBetween(T x, T y)
{
    if (x >= y) { cerr << "x必须小于y"; exit(1); }
    for (int i = 0; i < length; i++)
    {
        if (data[i]>x && data[i]<y)//如果检测到比x大比y小的
        {
            int j = i + 1, count = 1;//开始检测后面有几个在区间内的
            while (j)
            {
                if (data[j]<y)
                {
                    j++;
                    count++;
                }
                else
                    break;
            }

            for (int k = i; k < length; k++)//删除操作
            {
                data[k] = data[k + count];
            }
            length -= count;
        }
            
    }
    
}

template<class T, int MaxSize>
void SeqList<T, MaxSize> ::DeleteSame()
{
    for (int i = 0; i < length; i++)//双重循环
    {
        for (int j = i+1; j < length; j++)
        {
            if (data[j] == data[i])
            {
                Delete1(j + 1);//删除第j个元素并且再检测一遍j元素是否还等于datai
                j--;
            }
        }
    }
}
template <class T, int MaxSize>
void SeqList<T, MaxSize>::Sort()
{
    sort(data, data + length);
}

template <class T, int MaxSize>
void SeqList<T, MaxSize> ::Sort2()
{
    T x[MaxSize];
    int num = 0;
    for (int i = 1; i <length; i++)
    {
        if (data[i] <data[0])
        {
            x[num] = data[i];
            num++;
        }
    }
    x[num] =data[0];
    num++;
    for (int i = 1; i <length; i++)
    {
        if (data[i] > data[0])
        {
            x[num] = data[i];
            num++;
        }
    }
    for (int i = 0; i <length; i++)
    {
        int index = data[i];
        data[i]=x[i];
        x[i] = index;
        
    }
   
}

template <class T, int MaxSize>
void SeqList<T, MaxSize> ::Move()
{

    int  n;
   
    cin >> n;
    if ( n < length - 1)//左移
    {
        T x[MaxSize];
        for (int i = 0; i <= n; i++)
        {
            x[i] = data[i];
        }

        for (int i = 0; i < length - n; i++)
        {
            data[i] = data[i + n];
        }
        for (int i = length - n,j=0; i <= length - 1; i++)
        {
            
            data[i] = x[j];
            j++;
        }
    

    
    }
}
template <class T, int MaxSize>
void SeqList<T, MaxSize>::Merge(SeqList list2) 
{
    int i = 0, j = 0, k = 0;
    T x[MaxSize];//用于存储的数组x
    while (i < length && j < list2.length)//归并
    {
        if (data[i] <= list2.data[j])
            x[k++] = data[i++];
        else
            x[k++] = list2.data[j++];
    }
    if (i < length)
        while (i < length)
            x[k++] = data[i++];
    else
        while (j < list2.length)
            x[k++] = list2.data[j++];
    length += list2.length;
    for (int a = 0; a < length+list2.length; a++)
    {
        data[a] = x[a];
    }
   
        
        
   
    
}

int main()
{
    int a[50];
    int b[50];
    int m, n;

    cout << "请输入第一个顺序表的元素个数" << endl;
    cin >> n;
    cout << "请输入第一个顺序表的元素";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    SeqList<int, 50> list1(a, n);

    cout << "请输入第二个顺序表的元素个数" << endl;
    cin >> m;
    cout << "请输入第二个顺序表的元素";
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    SeqList<int, 50> list2(b, m);

    
    
    int sel;
    cin >> sel;
    switch (sel) 
    {
    case 1: 
    {
        list1.Sort();
        list2.Sort();
        list1.PrintSeqList();
        list2.PrintSeqList();
        system("pause");//暂停观察结果
        system("cls");//清屏
    }break;
    case 2: 
    {   list1.Sort();
    list2.Sort();
        list1.Merge(list2);

        list1.PrintSeqList();
        system("pause");
        system("cls");
    }
          break;
    case 3:
    {
        int a=list1.Delete();
        list1.PrintSeqList();
        cout << "最小的是" << a << endl;
        system("pause");
        system("cls");
    }
    case 4:
    {   
        int x;
        cin >> x;
        list1.Delete2(x);
        list1.PrintSeqList();
        system("pause");
        system("cls");
    }
    case 5:
    {
        list1.Sort();
        list1.DeleteBetween(3, 8);
        list1.PrintSeqList();
        system("pause");
        system("cls");
    }
    case 6:
    {list1.DeleteSame();
    list1.PrintSeqList();
    system("pause");
    system("cls");
    }
    case 7:
    {
        list2.Sort2();
        list2.PrintSeqList();
        system("pause");
        system("cls");
    }
    case 8:
    {
        list1.Move();
        list1.PrintSeqList();
        system("pause");
        system("cls");
    }
    }
  
}

