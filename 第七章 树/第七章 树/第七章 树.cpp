/*1. 编写程序，实现二叉树类模板及若干应用算法。
要求采用二叉链表结构，实现以下功能：
（1）构造函数：根据带空指针标记的先序遍历序列构造对象；根据先序和中序遍历序列构造对象。
（2）析构函数：释放所有结点空间。
（3）先序、中序、后序、层次遍历算法。
（4）统计结点的个数。
（5）计算二叉树的高度。

2. 编程程序，实现线索二叉树类模板及若干应用算法。

3. 编写程序，实现Huffman树构造、编码、译码等基本算法。*/
#include"声明.h"
#include <iostream>
using namespace std;
int main()
{
	vector<char> pre = { 'A','B','H','F','D','E','C','K','G' };
	vector<char> mid = { 'H','B','D','F','A','E','K','C','G' };
	BiTree<char> T(pre, mid);
	T.PreOrder();
	cout << endl;
	T.InOrder();
	cout << endl;
	T.PostOrder();
	cout << endl;
	T.LevelOrder();
	cout << endl;
	cout << T.Count() << endl<<T.Height()<<endl;


}

