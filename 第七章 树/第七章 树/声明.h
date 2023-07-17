#pragma once
#include<iostream>
#include<vector>
#include"����.h"
using namespace std;
template<class T>
struct BiNode
{
	T data;//�������
	BiNode<T>* lchild;//����ָ��
	BiNode<T>* rchild;//�Һ���ָ��

};
template <class T>
class BiTree
{
    BiNode<T>* root;   // ��ָ��
    //�漰����˽�г�Ա����
    void PreOrder(BiNode<T>* p);
    void InOrder(BiNode<T>* p);
    void PostOrder(BiNode<T>* p);
	BiNode<T>* CreateByPre(vector<T>& pre, int& i);
	BiNode<T>* Copy(BiNode<T>* p);
	BiNode<T>* CreateByPreMid(vector<T>& pre, vector<T>& mid, int ipre,int imid,int n);
	void Free(BiNode<T>* p);
	int Count(BiNode<T>* p);
	int Height(BiNode<T>* p);
	BiNode<T>* Search(BiNode<T>* p, T e);
	BiNode<T>* SearchParent(BiNode<T>* p, BiNode<T>* child);
public:
    BiTree() { root = NULL; }
    BiTree(vector<T>& pre);  // �ɵ����������й������
	BiTree(vector<T>& pre, vector<T>& mid); // �ɶ����������й������
    BiTree(BiTree<T>& tree);              // �����������
    ~BiTree();                             // ��������  
    void PreOrder();                        // �������
    void InOrder();                         // �������
    void PostOrder();                       // �������
    void LevelOrder();                      // ��α���
    int Count();                            // ͳ�ƽ�����
    int Height();                            // ����������ĸ߶�
    BiNode<T>* Search(T e);                 // ����ֵe���ҽ��
    BiNode<T>* SearchParent(BiNode<T>* child); // ����ָ�����ĸ����
};


template <class T>
void BiTree<T>::PreOrder(BiNode<T>* p)
{
	if (p == NULL)
		return;
	cout << p->data;
	PreOrder(p->lchild);
	PreOrder(p->rchild);
}
template <class T>
void BiTree<T>::PreOrder()
{
	PreOrder(root);
}
template<class T>
void BiTree<T>::InOrder(BiNode<T>* p)
{
	if (p == NULL)
		return;
	InOrder(p->lchild);
	cout << p->data;
	InOrder(p->rchild);
}
template<class T>
void BiTree<T>::InOrder()
{
	InOrder(root);
}
template<class T>
void BiTree<T>::PostOrder(BiNode<T>* p)
{
	if (p == NULL)
		return;
	PostOrder(p->lchild);
	PostOrder(p->rchild);
	cout << p->data;
}
template<class T>
void BiTree<T>::PostOrder()
{
	PostOrder(root);
}
template<class T>
void BiTree<T>::LevelOrder()
{
	if (root == NULL)
		return;
	LinkQueue<BiNode <T>*> Q;
	Q.EnQueue(root);
	while (!Q.Empty())
	{
		BiNode<T>* p = Q.DeQueue();
		cout << p->data;
		if (p->lchild != NULL)
			Q.EnQueue(p->lchild);
		if (p->rchild != NULL)
			Q.EnQueue(p->rchild);
	}
}
template<class T>
BiNode<T>* BiTree<T>::CreateByPre(vector<T>& pre, int& i)
{
	T e = pre[i];
	i++;
	if (e == '*')
		return NULL;
	BiNode<T>* p = new BiNode<T>;
	p->data = e;
	p->lchild = CreateByPre(pre, i);
	p->rchild = CreateByPre(pre, i);
	return p;
}
template<class T>
BiTree<T>::BiTree(vector<T>& pre)
{
	int i = 0;
	root = CreateByPre(pre, i);
}
template<class T> 
BiNode<T>* BiTree<T>::CreateByPreMid(vector<T>& pre, vector<T>& mid, int ipre, int imid, int n)
{
	if (n == 0)
		return NULL;
	BiNode<T>* p = new BiNode<T>;
	p->data = pre[ipre];
	int i;
	for (i = 0; i < n; i++)
		if (pre[ipre] == mid[imid + i])
			break;
	p->lchild = CreateByPreMid(pre, mid, ipre + 1, imid, i);
	p->rchild = CreateByPreMid(pre, mid, ipre + i + 1, imid + i + 1, n - i - 1);
	return p;
}
template<class T>
BiTree<T>::BiTree(vector<T>& pre, vector<T>& mid)
{
	int n = pre.size();
	root = CreateByPreMid(pre, mid, 0, 0, n);
}
template<class T>
BiNode<T>* BiTree<T>::Copy(BiNode<T>* p)
{
	if (p == NULL)
		return NULL;
	BiNode<T>* newp = new BiNode<T>;
	newp->data = p->data;
	newp->lchild = Copy(p->lchild);
	newp->rchild = Copy(p->rchild);
	return newp;
}
template<class T>
BiTree<T>::BiTree(BiTree<T>& tree)
{
	root = Copy(tree.root);
}
template<class T>
void BiTree<T>::Free(BiNode<T>* p)
{
	if (p == NULL)
		return;
	Free(p->lchild);
	Free(p->rchild);
	delete p;


}
template<class T>
BiTree<T>::~BiTree()
{
	Free(root);
}
template<class T>
int BiTree<T>::Count(BiNode<T>* p)
{
	if (p == NULL)
		return 0;
	int left = Count(p->lchild);
	int right = Count(p->rchild);
	return 1 + left + right;

}
template<class T>
int BiTree<T>::Count()
{
	return Count(root);
}
template<class T>
int BiTree<T>::Height(BiNode<T>* p)
{
	if (p == NULL)
		return 0;
	int left = Height(p->lchild);
	int right = Height(p->rchild);
	if (left > right)
		return left + 1;
	else
		return right + 1;

}
template<class T>
int BiTree<T>::Height()
{
	return Height(root);
}
template<class T>
BiNode<T>* BiTree<T>::Search(BiNode<T>* p, T e) 
{
	if (p == NULL)
		return NULL;
	if (p->data == e)
		return p;
	BiNode<T>* q = Search(p->lchild, e);
	if (q != NULL)
		return q;//������������в��ҳɹ��򷵻ز��ҽ��
	return Search(p->rchild, e);//�������������в��ҽ��
}
template<class T>
BiNode<T>* BiTree<T>::Search(T e)
{
	return Search(root, e);
}
template<class T>
BiNode<T>* BiTree<T>::SearchParent(BiNode<T>* p, BiNode<T>* child)
{
	if (p == NULL || child == NULL)
		return NULL;//����ʧ��
	if (p->lchild == child || p->rchild == child)
		return p;
	BiNode<T>* q = SearchParent(p->lchild, child);
	if (q != NULL)
		return q;//�����������в��ҳɹ��򷵻ز��ҽ��
	return SearchParent(p->rchild, child);
}
template<class T>
BiNode<T>* BiTree<T>::SearchParent(BiNode<T>* child)
{
	return SearchParent(root, child);
}