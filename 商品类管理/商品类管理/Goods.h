#pragma once
using namespace std;

class Goods 
{
private:
	int ID;
	string name;
	double price;
	int inventory;
public:
	Goods(void);
	void ChangeInventory();
	void updateID(int id);
	bool operator == (Goods good);
	bool operator == (int n);
	bool operator != (Goods good);
	friend istream& operator >> (istream& in, Goods& good);
	friend ostream& operator << (ostream& out, Goods& good);
	
};
Goods::Goods(void)
{

}
void Goods::ChangeInventory()
{
	
	cin>>inventory;
	cout << "�޸ĳɹ�" << endl;
}
void Goods::updateID(int id)
{
	ID = id;
}
bool Goods::operator==(Goods good)
{
	return ID == good.ID;
}
bool Goods::operator == (int n)
{
	return ID == n;
}
bool Goods::operator!=(Goods good)
{
	return ID != good.ID;
}
istream& operator >> (istream& in, Goods& good)
{
	cout << "��Ʒ���룺" << endl;
	in >> good.ID;
	cout << "��Ʒ����" << endl;
	in >> good.name;
	cout << "��Ʒ�۸�" << endl;
	in >> good.price;
	cout << "��Ʒ���" << endl;
	in >> good.inventory;
	return in;
}
ostream& operator <<(ostream& out, Goods& good)
{
	out << "��Ʒ�Ĵ���Ϊ" << good.ID << "����Ʒ����Ϊ" << good.name << "���۸�Ϊ" << good.price << "�������Ϊ" << good.inventory;
	return out;
}












