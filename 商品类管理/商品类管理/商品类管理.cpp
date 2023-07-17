/*实验题 2.2：用顺序表实现一个简易的商品管理系统，完成报告。
用线性表来管理一个商品库存表。对商品库存表的管理就是首先把它读入到线性表中，
接着对它进行必要的处理，然后再把处理后的结果写回到文件中。对商品库存表的处理假定
包括以下选项：
（1）打印（遍历）库存表；
（2）按商品代号修改记录的当前库存量，若查找到对应的记录，则从键盘上输入其修
正量，把它累加到当前库存量域后，再把该记录写回原有位置，若没有查找到对应的记录，
则表明是一条新记录，应接着从键盘上输入该记录的商品名称、最低库存量和当前库存量的
值，然后把该记录追加到库存表中；
（3）按商品代号删除指定记录；
（4）按商品代号对库存表中的记录排序。*/
#include <iostream>
#include"顺序表.h"
#include <fstream>
using namespace std;
 
int main()
{
    ifstream ifs("Goods_list.txt");//创建文件流
   
    Goods a[4];
   
    for (int i = 0; i < 4; i++)
    {
        ifs >> a[i];
    }
    SeqList<Goods, 10> GoodsList(a,4);
    GoodsList.Delete1(2);
    GoodsList.PrintSeqList();
    int n;
    cout << "请输入您要查找的商品货号" << endl;
    cin >> n;
    GoodsList.Get(n);
    GoodsList.PrintSeqList();
    
}

