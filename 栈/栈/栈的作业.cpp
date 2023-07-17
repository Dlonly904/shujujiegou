/*（1）把十进制整数转换为二至十六之间的任一进制数输出。
（2）括号匹配问题。试编写一个算法，用来检查一个C++语言程序中的花括号、方括号和圆括号是否配对，若能够全部配对则返回1，否则返回0。
（3）判回文。
（4）表达式求值。
*/
#include <iostream>
#include"栈.h"

using namespace std;

void Change()
{
    SeqStack<int,10000> Zhan;
    cout << "请输入你要转换的十进制数：" << endl;
    int n;
    cin >> n;
    cout << "请输入你要转换的进制：" << endl;
    int m;
    cin >> m;
    int remain = 0;
    while (n > 0)
    {
        remain = n % m;
       
        Zhan.Push(remain);
        n = n / m;
    }
    while (!Zhan.Empty())
    {
        int t= Zhan.Pop();
        if (t < 10)
        {
            cout << t;
        }
        else if (t > 10 && t < 16)
        {
            cout << (char)(t - 10 + 'A');
        }
        

    }
}

/* 对字符数组str中所有的字符进行括号配对 */
int bracketsCheck(char str[], int n) {
	SeqStack<char,1000> st;// 定义一个栈
		/* 必须初始化栈 */
	int i = 0;// 定义一个变量，记录数组下标
	while (i < n) 
	{
		if (str[i] == 39) 
		{// 判断字符是否是单引号
			i++;// 跳过第一个单引号
			while (str[i] != 39) 
			{
				i++;// 跳过单引号中的内容
			}
			i++;// 跳过最后一个单引号
		}
		else if (str[i] == 34) 
		{// 判断字符是否是双引号
			i++;// 跳过第一个双引号
			while (str[i] != 34) 
			{
				i++;// 跳过双引号中的内容
			}
			i++;// 跳过最后一个双引号
		}
		else {// 跳过单引号和双引号后进行括号配对
			if (str[i] == '(' || str[i] == '[' || str[i] == '{') 
			{
				st.Push(str[i]);// 将符合上述情况的字符压入栈中
			}
			else if (str[i] == ')') 
			{// 判断是否配对括号"()"
				char x=st.Top();
				// 获取栈顶元素
				if (x == '(') 
				{
					st.Pop();// 如果配对成功，则将该字符出栈
				}
				else 
				{
					return 0;
				}
			}
			else if (str[i] == ']') 
			{// 判断是否配对括号"[]"
				
				char x = st.Top();
				if (x == '[') 
				{
					st.Pop();
				}
				else 
				{
					return 0;
				}
			}
			else if (str[i] == '}') 
			{// 判断是否配对括号"{}"
				
				char x = st.Top();
				if (x == '{') 
				{
					st.Pop();
				}
				else 
				{
					return 0;
				}
			}

			i++;
		}
	}
	/* 判断最后结果，如果为空则全部配对正确，否则未配对成功 */
	if (st.Empty() == 1) 
	{
		return 1;// 配对成功返回1
	}
	else 
	{
		return 0;// 配对失败返回0
	}
}

int Judgehuiwen(int a)
{
	SeqStack<int, 100> Zhan1;
	SeqStack<int, 100> Zhan2;
	SeqStack<int, 100> Zhan3;
	int remain = 0;
	int n = 0;
	while (a > 0)
	{
		remain = a % 10;
		Zhan1.Push(remain);
		Zhan3.Push(remain);
		a = a / 10;
		n++;
	}
	while (!Zhan1.Empty())
	{
		Zhan2.Push(Zhan1.Pop());
	}
	while (!Zhan2.Empty() && !Zhan3.Empty())
	{
		if (Zhan2.Pop() != Zhan3.Pop())
			return 0;
		
	}
	return 1;
}
//表达式求值
bool Judge(char ch)
{
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/' ||
		ch == '(' || ch == ')' || ch == '\n')
		return true;
	return false;
}

int Trans(char c)
{
	switch (c)
	{
	case'+':return 0;
	case'-':return 1;
	case'*':return 2;
	case'/':return 3;
	case'(':return 4;
	case')':return 5;
	case'\n':return 6;
	}
}

int Operate(int a, char op, int b)
{
	switch (op)
	{
	case'+':return a + b;
	case'-':return a - b;
	case'*':return a * b;
	case'/':return a / b;
	default: { cerr << "op运算符错误" << endl; exit(1); }
	}
}

void Evaluation()
{
	char Prior[7][7] =
	{
		{'>','>','<','<','<','>','>'},
		{'>','>','<','<','<','>','>'},
		{'>','>','>','>','<','>','>'},
		{'>','>','>','>','<','>','>'},
		{'<','<','<','<','<','=','0'},
		{'>','>','>','>','0','>','>'},
		{'<','<','<','<','<','0','='}
	};
	SeqStack<int, 100> OPND;   //运算数栈
	SeqStack<char, 100> OPTR;  //运算操符栈
	OPTR.Push('\n');
	char ch, op;
	int a, b, num = 0;
	cout << "输入表达式" << endl;
	ch = getchar();
	while (ch != '\n' || OPTR.Top() != '\n')
	{
		if (ch >= '0' && ch <= '9')
		{
			num = num * 10 + (ch - '0');
			ch = getchar();
			if (Judge(ch))
			{
				OPND.Push(num);
				num = 0;
			}

		}
		if (Judge(ch))
		{
			switch (Prior[Trans(OPTR.Top())][Trans(ch)])
			{
			case'<':
				OPTR.Push(ch);
				ch = getchar();
				break;
			case'>':
				op = OPTR.Pop();
				b = OPND.Pop();
				a = OPND.Pop();
				OPND.Push(Operate(a, op, b));
				break;
			case'=':
				OPTR.Pop();     //弹出括号
				ch = getchar();
				break;
			default: { cerr << "Prior运算符错误" << endl; exit(1); }

			}
		}
		//else { cerr << "非法输入" << endl; exit(1); }
	}
	cout << "表达式结果是:" << OPND.Top() << endl;
}

int main()
{

  
    /*SeqStack<int, 20> Zhan1;
    if (Zhan1.Empty())
        cout << "脑袋空空"<< endl;
    else
        cout << "非空"  << endl;
    for (int i = 0; i < 10; i++)
    {
        Zhan1.Push(i);
    }
    if (Zhan1.Empty())
        cout << "脑袋空空" << endl;
    else
        cout << "非空" << endl;
    cout << "栈顶元素为：" << Zhan1.Top() << endl;
    for (int i = 0; i < 10; i++)
    {
        cout<<Zhan1.Pop()<<endl;
    }
    if (Zhan1.Empty())
        cout << "脑袋空空" << endl;
    else
        cout <<"非空"  << endl;
	if(Judgehuiwen(12138))
	{
		cout << "12138是回文数" << endl;
	}
	else { cout << "12138不是回文数" << endl; }
	if (Judgehuiwen(121383121))
	{
		cout << "121383121是回文数" << endl;
	}
	else { cout << "121383121不是回文数" << endl; }

	Evaluation();*/
	char a[200] = { "if (Judgehuiwen(121383121)){cout << 121383121是回文数 << endl};else{ cout << 121383121不是回文数 << endl; }" };
	if(bracketsCheck(a, strlen(a)))
	{cout<<"没有遗漏" <<endl;}
	else{cout<<"有遗漏"<<endl; }
    Change();
	
}


