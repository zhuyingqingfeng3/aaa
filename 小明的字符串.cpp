#include<iostream>
#include<cstring>
#include<string>
using namespace std;
string s,t;
int main(){
   cin>>s>>t;
   int len=0,ans=0;
//    len控制的是长度
   while(len!=t.length()){
    len++;
    string str(t,0,len);//这是调用字符串的初始化表示赋值t的部分
    // 第二个参数是开始的地方，第三个参数是长度
    if(s.find(str)==-1){
        // 如果找不到的话就返回时-1
        cout<<len-1;
        return 0;
    }
   }
   cout<<len;
   return 0;
}