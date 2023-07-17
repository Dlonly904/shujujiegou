#include <iostream>
#include"LinkList.h"
#include"Student.h"
using namespace std;


int main()
{

    LinkList<Student> hkust;

    Student qz(19210405, "qz", "rmbi");
    Student qs(19210404, "qs", "rmbi");
    qz.SetCourse("math", 60);
    qz.SetCourse("sex education", 100);
    qs.SetCourse("math", 100);
    hkust.Insert(1, qz);
    hkust.Insert(2, qs);
    int num = 3;
   
    while (1)
    {cout << "请输入选项：1.增加学生  2.查找学生  3.打印学生信息  4.删除学生  5.修改学生信息 6.退出" << endl;
        int sel;
        cin >> sel;
        
        switch (sel)
        {
        case 1:
        {
            Student who;
            who.InID(); who.InName(); who.InMajor(); who.InCourse();
            hkust.Insert(num, who);
            num++;
        }break;
        case 2:
        {   
            int n;
            cout << "请输入要查找的学生学号" << endl;
            cin >> n;
            hkust.Get(n);
        }
        break;
        case 3:
        {
            hkust.PrintList();
        }break;
        case 4:
        {
            int i;
            cout << "请输入要删除学生的学号" << endl;
            cin >> i;
            cout << "要删除的学生为："; hkust.Get(i);
            hkust.Delete(i);
            
        }break;
        case 5:
        {
            int i;
            cout << "请输入要修改学生的学号" << endl;
            cin >> i;
            hkust.Change(i);
                
        }break;
        case 6:
        {
            exit(1);
        }break;
        
        }

    }
}