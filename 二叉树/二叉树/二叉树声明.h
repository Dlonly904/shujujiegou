#pragma once
#include<iostream>
using namespace std;
template<class T>
struct BiNode
{
	T data;
	BiNode<T>* lchild;//左孩子指针
	BiNode<T>* rchild;//右孩子指针

};

template <class T>
class BiTree
{
private:
	BiNode<T>* root;//根指针
public:
	BiTree() { root = NULL; }                     //无参构造
	BiTree(vector<T>& pre);						//先序序列构造
	BiTree(vector<T>& pre, vector<T>& mid);		//先序，中序序列构造
	BiTree(BiTree <T> tree);						//拷贝构造
	~BiTree();									//析构
	.............																																																																																																																																																																																																																																																																		

};