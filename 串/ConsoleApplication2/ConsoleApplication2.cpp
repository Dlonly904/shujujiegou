/*串的基本操作，用C基本语句实现。

（1）串的链接
（2）串的比较
（3）串的复制
（4~6）习题p73  4.4、4.5、4.6
4.4  编写输入两个字符串s和t，统计串s包含串t个数的算法
4.5  编写从串s中删除所有与串t相同的子串的算法
4.6  编写求串s和串t的最大公共子串的算法

（7~8）习题4.7、4.8。【《程序员面试攻略(第2版)》p81】

2. BF模式匹配算法实现

3. KMP模式匹配算法实现*/


#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
#define MaxSize 50
void StrCat(char* s1, char* s2)//串链接
{
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    if (len1 + len2 > MaxSize - 1)//为什么maxisize-1，因为要给'\0'留一格
    {
        cerr << "超长";

    }
    int i = 0;
    while (s2[i] != 0)
    {
        s1[i + len1] = s2[i];
        i++;
    }
    s1[i + len1] = '\0';



}
int StrCmp(char* s1, char* s2)//串比较
{
    int i = 0;
    while (s1[i] == s2[i] && s1[i] != '\0')
    {
        i++;
    }
    return(s1[i] - s2[i]);//返回不同字母的差值


}
void StrCpy(char* s1, char* s2)//串复制
{
    int len = strlen(s2);
    if (len > MaxSize) { cerr << "超长"; }
    while (*s1++ = *s2++);
 }

bool in(char a, char* s)//removechars第一部分
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (a == s[i])
            return true;

    }
    return false;
}
void Deletel(int i,char *s)//removechars第二部分
{
    for (int j = i; j < strlen(s); j++)
    {
        s[j] = s[j + 1];
    }
}
void RemoveChars(char* str, char* remove)//主体
{
    int i = 0;
    while (str[i] != 0)
    {
        if (in(str[i], remove))
        {
            Deletel(i, str);
            i--;
        }
        i++;
    }
}
void Delete(char* s, char* t)
{
    int i = 0, j = 0;
    int n = strlen(s), m = strlen(t);
    int count = 0;
    while (i < n)
    {
        if (s[i] == t[j])
        {
            i++;
            j++;

        }
        else
        {
            i = i - j + 1;
            j = 0;
        }
        if (j >= m)
        {

            for (int a = i - j; a < n ; a++)
            {
                s[a] = s[a + j];
            }
            i = i - j;//回溯

        }
    }

}
int StrSame(char* s, char* t)
{
    int i = 0, j = 0;
    int n = strlen(s), m = strlen(t);
    int count = 0;
    while (i < n)
    {
        if (s[i] == t[j])
        {
            i++;
            j++;
            
        }
        else
        {
            i = i - j + 1;
            j = 0;
        }
        if (j >= m)
            count++;

    }
    return count;
}
int BFmatching(char* s, char* t)
{
    int i = 0, j = 0;
    int n = strlen(s),m=strlen(t);
    while (i < n && j < m)
    {
        if (s[i] == t[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 1;
            j = 0;
        }


    }
    if (j >= m)
        return i - j;
    else
        return -1;
}

int KMP(int start, char S[], char T[])
{
    int j = 0, k = -1;
    int m = strlen(T);
    int next[MaxSize];
    next[0] = -1;
    while (j < m - 1)
    {
        if ((k == -1) || T[j] == T[k])
        {
            j++;
            k++;
            next[j] = k;
        }
        else
            k = next[k];
    }
    int i = start;
    j = 0;
    
    while (S[i] != '\0' && T[j] != '\0')
    {
        if (j == -1 || S[i] == T[j])
        {
            i++;         //继续对下一个字符比较 
            j++;         //模式串向右滑动 
        }
        else j = next[j];
    }
    if (T[j] == '\0') return (i - j+1);    //匹配成功返回下标 
    else return -1;                 //匹配失败返回-1 
}

char* Reverse(char* str)
{
    int k = 0;
    int len = strlen(str);
    char* res = new char[len + 1];
    bool flag = 0;
    int index = len - 1;
    for (int i = len - 1; i >= 0; i--)
    {
        if (str[i] == ' ')  //读到空格
        {
            for (int j = i + 1; j <= index; j++)
            {
                res[k++] = str[j];
            }
            res[k++] = ' ';
            index = i - 1;    //更新单词尾
            i = index - 1;    //跳过空格
            if (i == 0)
                flag = 1;
        }
        if (i == 0)   //读完句子
        {
            for (int j = i; j <= index; j++)
            {
                res[k++] = str[j];
            }
        }
    }
    res[k] = '\0';
    return res;
}




int main()
{
    char s1[50] = { "wts" };
    char s2[50] = { "usaiw tswts wt" };
    StrCat(s1, s2);
    
}