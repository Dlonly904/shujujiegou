#pragma once
#include<iostream>
using namespace std;
struct BiNode
{
	int key;
	BiNode* lchild, *rchild;

};
class BiSortTree
{
	BiNode* root;
	void Insert(BiNode*& ptr, int k);
	BiNode* Search(BiNode* ptr, int k);
	void Delete(BiNode*& ptr, int k);
	void Free(BiNode* ptr);
public:
	BiSortTree(int a[], int n);
	~BiSortTree();
	void Insert(int k);
	bool Search(int k);
	void Delete(int k);
};
void BiSortTree::Insert(BiNode*& ptr, int k)
{
	if (ptr == NULL)
	{
		ptr = new BiNode;
		ptr->key = k;
		ptr->lchild = ptr->rchild = NULL;
	}
	else
	{
		if (k < ptr->key)
			Insert(ptr->lchild, k);//²åÈëµ½×ó×ÓÊ÷
		else if (k > ptr->key)
			Insert(ptr->rchild, k);

	}
	
}
void BiSortTree::Insert(int k)
{
	Insert(root, k);
}
BiSortTree::BiSortTree(int a[], int n)
{
	root = NULL;
	for (int i = 0; i < n; i++)
	{
		Insert(root, a[i]);
	}
}
BiNode* BiSortTree::Search(BiNode* ptr, int k)
{
	if (ptr == NULL)
		return NULL;
	else
		if (ptr->key == k)
			return ptr;
		else if (k < ptr->key)
			return Search(ptr->lchild, k);
		else
			return Search(ptr->rchild, k);
}
bool BiSortTree::Search(int k)
{
	return Search(root, k) != NULL;
}
void BiSortTree::Delete(BiNode*& ptr, int k)
{
	if (ptr != NULL)
	{
		if (k < ptr->key)
			Delete(ptr->lchild, k);
		else if (k > ptr->key)
			Delete(ptr->rchild, k);
		else
		{
			if (ptr->lchild != NULL && ptr->rchild != NULL)
			{
				BiNode* temp = ptr->lchild;
				while (temp->rchild != NULL)
					temp = temp->rchild;
				ptr->key = temp->key;
				Delete(ptr->lchild, temp->key);

			}
			else {
				BiNode* temp = ptr;
				if (ptr->lchild == NULL)
					ptr = ptr->rchild;
				else if (ptr->rchild == NULL)
					ptr = ptr->lchild;
				delete temp;

			}
		}
	}
}
void BiSortTree::Delete(int k)
{
	Delete(root, k);
}
void BiSortTree::Free(BiNode* ptr)
{
	if (ptr == NULL)
		return;
	Free(ptr->lchild);
	Free(ptr->rchild);
	delete ptr;


}
BiSortTree::~BiSortTree()
{
	Free(root);
}

