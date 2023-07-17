#pragma once
#include<iostream>
#include"LinkList.h"
#include<string>
using namespace std;

/*失败品class Course
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
		cout << "请输入课程名" << endl;
		cin >> CourseName;
	}
	void InGrade()
	{
		cout << "请输入成绩：" << endl;
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
		cout << "请输入学生姓名" << endl;
		cin >> Name;
	}
	void InID()
	{
		cout << "请输入学号：" << endl;
		cin >> ID;
	}
	void InMajor()
	{
		cout<< "请输入专业：" << endl;
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
		cout << "请输入课程名" << endl;
		cin>>p->CourseName;
		if (!cin.good())
			cerr << "输入的格式有误" << endl;
		cout << "请输入成绩" << endl;
		cin>>p->grade;
		if (!cin.good())
			cerr << "输入的格式有误" << endl;
		p->next = head->next;
		head->next = p;
	}
	void Print()
	{
		cout << "学号：" <<ID<< endl;
		cout << "姓名:" << Name << endl;
		cout << "专业" << Major << endl;
		cout << "所选课程：";
	
		Course* p = head->next;
		while (p)
		{
			cout << p->CourseName << endl;
			cout <<"成绩:" << p->grade << endl;
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
	out << "学号：" << student.ID << endl;
	out << "姓名:" << student.Name << endl;
	out << "专业" << student.Major << endl;
	out << "所选课程：";

	Course* p = student.head->next;
	while (p)
	{
		out << p->CourseName << endl;
		out << "成绩:" << p->grade << endl;
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
