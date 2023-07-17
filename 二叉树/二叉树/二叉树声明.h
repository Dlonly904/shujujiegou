#pragma once
#include<iostream>
using namespace std;
template<class T>
struct BiNode
{
	T data;
	BiNode<T>* lchild;//����ָ��
	BiNode<T>* rchild;//�Һ���ָ��

};

template <class T>
class BiTree
{
private:
	BiNode<T>* root;//��ָ��
public:
	BiTree() { root = NULL; }                     //�޲ι���
	BiTree(vector<T>& pre);						//�������й���
	BiTree(vector<T>& pre, vector<T>& mid);		//�����������й���
	BiTree(BiTree <T> tree);						//��������
	~BiTree();									//����
	.............																																																																																																																																																																																																																																																																		

};