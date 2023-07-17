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
	cout << "修改成功" << endl;
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
	cout << "商品代码：" << endl;
	in >> good.ID;
	cout << "商品名称" << endl;
	in >> good.name;
	cout << "商品价格" << endl;
	in >> good.price;
	cout << "商品库存" << endl;
	in >> good.inventory;
	return in;
}
ostream& operator <<(ostream& out, Goods& good)
{
	out << "商品的代码为" << good.ID << "，商品名称为" << good.name << "，价格为" << good.price << "，库存量为" << good.inventory;
	return out;
}












