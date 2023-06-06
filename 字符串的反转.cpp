#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
//生成一个可以输出字符串反转的函数
void reverse(string &s)
{
    int i=0,j=s.length()-1;
    while(i<j)
    {
        char temp=s[i];
        s[i]=s[j];
        s[j]=temp;
        i++;
        j--;
    }
}
int main(){
    string s;
    cin>>s;
    reverse(s);
    cout<<s;
}