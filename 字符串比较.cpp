#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string k[2];
//生成一个可以对k中字符串按照字典大小从小到大排序的函数
bool cmp(string a,string b)
{
    return a<b;
}

int main(){
    string a,b;
    cin>>a>>b;
    if(a<b){
        cout<<-1;
    }
    else if(a>b){
        cout<<1;
    }
    else{
        cout<<0;
    }

}