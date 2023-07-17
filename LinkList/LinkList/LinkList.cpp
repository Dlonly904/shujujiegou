/*二、单链表上机作业
【编程 3】LinkList 类模板的实现与测试
实验内容：
（1）完成 LinkList 类模板的基本功能。
（2）扩展链表的功能：
 1）原地逆置
 2）分段
 3）归并两个有序单链表
（3）编写 main()函数对 LinkList 类模板进行实例化测试，要求使用菜单选择各项功能。*/
#include<algorithm>
#include <iostream>
#include"实现.h"
using namespace std;

int main()
{   
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int b[10] = { 11,12,13,14,15,16,17,18,19,20 };
	LinkList<int> L1(a, 10);
	LinkList<int> L2(b, 10);
	int sel = 0;//选择按键
	while (1)
	{
		cout << "输入选择（1.按位查找 2.按值查找 3.插入 4.删除 5.打印 6.逆置 7.归并 0.exit）：";
		cin >> sel;
		switch (sel)
		{
		case 1:
		{
			cout << "你要查找表1的第几个元素" << endl;
			int n;
			cin >> n;
			cout << L1.Get(n) << endl;
			
		}break;
		case 2:
		{
			cout << "你要查找的元素的值" << endl;
			int n;
			cin >> n;
			cout <<"你要查找的元素在第" << L1.Locate(n) << "个"<<endl;
		}break;
		case 3:
		{
			cout << "请输入你要插入的元素"<<endl;
			int x;
			cin >> x;
			cout << "请输入你要插入的位置"<<endl;
			int n;
			cin >> n;
			L1.Insert(n, x);
			cout << "插入后的链表为：" << endl;
			L1.PrintList();
		}break;
		case 4:
		{
			cout << "请输入你要删除第几个元素" << endl;
			int n;
			cin >> n;
			L1.Delete(n);
			cout << "删除后的链表为：" << endl;
			L1.PrintList();

		}break;
		case 5:
		{
			cout << "打印链表";
			L1.PrintList();

		}break;
		case 6:
		{
			cout << "逆置链表";
			L1.Invert();
		}break;
		case 7:
		{
			Merge(L1, L2);
			L1.PrintList();
		}break;
		}
	}
	return 0;
}


