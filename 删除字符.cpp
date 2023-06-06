// 贪心思想，直接暴力枚举
// 注意字符串的用法，s.erase(a,num)代表从a开始删除长度为num的字符子串
// 不仅返回删除后的结果，而且对字符串本身也产生了变化，如果想保留原来的
// 就要做好之前的储存
#include<iostream>
using namespace std;
int main(){
    string s,s1,s2,s3;
    int n;
    cin>>s;
    s1=s;s2=s;s3=s;
    cin>>n;
    while(n--){
        
        for(int i=0;i<s.size();i++){
            s3=s;
             s1=s3.erase(i,1);
             if(s1<s2){
                s2=s1;
             }
        }
        s=s2;
    }
    cout<<s2;
    return 0;
    
}