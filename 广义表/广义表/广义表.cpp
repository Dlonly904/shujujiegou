/*1. 广义表类的实现及应用。
基本要求：
（1）采用链式存储结构实现；
（2）以形式如“((a, b), (c, d), e, f)”的字符串作为参数，构造对象；
（3）以菜单选择各项功能，例如：遍历输出广义表；计算广义表的深度、长度；
*/
#include <iostream>
using namespace std;
enum GListNodeType{ATOM, LIST};
template <class T>
struct GListNode
{
    GListNodeType type;
    union
    {
        T data;
        GListNode* sublist;
    };
    GListNode<T>* next;
  
};

template <class T>
class GList
{
    GListNode<T>* head;
    GListNode<T>* DoCreate(char s[], int& i);//与广义表构造函数相关
    GlistNode<T>* Copy(GListNode<T>* p);//与拷贝构造函数相关
    void Traverse(GListNode<T>* p);
    void Free(GListNode<T>* p);//析构相关
    int Depth(GListNode<T>* p);//与计算广义表的Depth函数相关
public:
    GList();
    GList(char s[]);
    GList(GList<T> head, GList<T> tail); // 利用表头、表尾构造对象
    GList(GList<T>& gl);             // 拷贝构造函数
    ~GList();
    void Traverse(); // 遍历算法
    int Length();   // 计算表的长度
    int Depth();    // 计算表的深度 
    
};
template <class T>
GList<T>::GList()
{
    head = new GListNode<T>;
    head->type = LIST;
    head->sublist = head->next = NULL;

}
template <class T>
GListNode<T>* GList<T>::DoCreate(char s[], int& i)
{
    GListNode<T>* p;
    while (s[i] == '' || s[i] == ',')
        i++;
    char e = s[i];
    if (e == '(')
    {
        p = new GListNode<T>;
        p->type = LIST;
        p->sublist = DoCreate(s, i);
        p->next = DoCreate(s, i);
        return p;
    }
    if (e == ')' || e == "\0")
    {
        return NULL;
    }
    p = new GListNode<T>;
    p->type = ATOM;
    p->data = e;
    p->next = DoCreate(s, i);
    return p;

}

template <class T>
GList<T>::GList(char s[]) 
{
    int i = 0;
    head = DoCreate(s, i);
}



int main()
{
    
}

