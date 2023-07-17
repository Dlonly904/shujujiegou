#pragma once
#include<iostream>
#include"LinkList.h"
#include<string>
using namespace std;

/*ʧ��Ʒclass Course
{
	string CourseName;
	int grade;
public:
	Course();
	Course(string n=NULL, int s=0) :CourseName(n), grade(s){}
	void AddName(string n)
	{
		CourseName = n;
	}
	void InName()
	{
		cout << "������γ���" << endl;
		cin >> CourseName;
	}
	void InGrade()
	{
		cout << "������ɼ���" << endl;
		cin >> grade;
	}
	void AddGrade(int s)
	{
		grade = s;
	}
	int SearchGrade()
	{
		return grade;
	}
};*/
struct Course
{
	string CourseName;
	int grade;
	Course* next;
};
class Student
{
	int ID;
	string Name;
	string Major;
	Course* head;
public:
	Student();
	Student(int id, string n, string m);
	bool operator ==(Student student);
	bool operator ==(int n);
	bool operator !=(Student student);
	void InName()
	{
		cout << "������ѧ������" << endl;
		cin >> Name;
	}
	void InID()
	{
		cout << "������ѧ�ţ�" << endl;
		cin >> ID;
	}
	void InMajor()
	{
		cout<< "������רҵ��" << endl;
		getline(cin, Major);
	}
	void ChangeID(int id)
	{
		ID = id;
	}
	void AddName(string n) 
	{
		Name = n;
	}
	void AddMajor(int m)
	{
		Major = m;

	}
	void SetCourse(string n,int score) 
	{
		Course* p = new Course;
		p->CourseName = n;
		p->grade = score;
		p->next = head->next;
		head->next = p;
	}
	void InCourse()
	{   
		Course* p = new Course;
		cout << "������γ���" << endl;
		cin>>p->CourseName;
		if (!cin.good())
			cerr << "����ĸ�ʽ����" << endl;
		cout << "������ɼ�" << endl;
		cin>>p->grade;
		if (!cin.good())
			cerr << "����ĸ�ʽ����" << endl;
		p->next = head->next;
		head->next = p;
	}
	void Print()
	{
		cout << "ѧ�ţ�" <<ID<< endl;
		cout << "����:" << Name << endl;
		cout << "רҵ" << Major << endl;
		cout << "��ѡ�γ̣�";
	
		Course* p = head->next;
		while (p)
		{
			cout << p->CourseName << endl;
			cout <<"�ɼ�:" << p->grade << endl;
			p = p->next;

		}
	}
	friend ostream& operator << (ostream& out, Student& student);
	

};
Student::Student()
{
	head = new Course;
	head->next = NULL;
}
Student::Student(int id, string n, string m)
{
	ID = id;
	Name = n;
	Major = m;
		head = new Course;
		head->next = NULL;
		head->grade = 0;
		head->CourseName = "noname";
	
}
ostream& operator <<(ostream& out, Student& student)
{
	out << "ѧ�ţ�" << student.ID << endl;
	out << "����:" << student.Name << endl;
	out << "רҵ" << student.Major << endl;
	out << "��ѡ�γ̣�";

	Course* p = student.head->next;
	while (p)
	{
		out << p->CourseName << endl;
		out << "�ɼ�:" << p->grade << endl;
		p = p->next;

	}
	return out;
}
bool Student::operator==(Student student)
{
	return ID == student.ID;
}
bool Student::operator==(int n)
{
	return ID == n;
}
bool Student::operator!=(Student student)
{
	return ID != student.ID;
}
