#include<iostream>
#include<string>
using namespace std;
//生成一个函数判断一个字符是不是字母
bool isLetter(char c)
{
    if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
        return true;
    else
        return false;
}
//生成一个函数判断一个字符是不是数字
bool isDigit(char c)
{
    if(c>='0'&&c<='9')
        return true;
    else
        return false;
}
//生成一个函数判断一个字符是不是空格
bool isSpace(char c)
{
    if(c==' '||c=='\t'||c=='\n'||c=='\r')
        return true;
    else
        return false;
}
int main(){
    int zimu=0,num=0,qita=0,kong=0;
    string s;
    getline(cin,s);
    for(int i=0;i<s.length();i++)
    {
        if(isLetter(s[i]))
            zimu++;
        else if(isDigit(s[i]))
            num++;
        else if(isSpace(s[i]))
            kong++;
        else
            qita++;
    }
    cout<<zimu<<" "<<num<<" "<<kong<<" "<<qita;
    
}