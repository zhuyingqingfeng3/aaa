// next[n]储存是1-n最大相同前后缀长度
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e6+10,M=1e5+10;
char s[N],p[M];
int n,m;
int ne[M];
int main(){
    // 下标从1开始
    cin>>m>>p+1>>n>>s+1;
    // 求next数组
    for(int i=2,j=0;i<=m;i++){
        while(j&&p[i]!=p[j+1]){
            j=ne[j];
        }
        if(p[i]==p[j+1]){
            j++;
        }
        ne[i]=j;
    }
    // 匹配操作
    for(int i=1,j=0;i<=n;i++){
        while(j&&s[i]!=p[j+1]){
            j=ne[j];
        }
        if(s[i]==p[j+1]){
            j++;
        }
        if(j==m){
            cout<<i-m<<" ";//下标从1开始就是i-m+1了
            j=ne[j];//继续匹配
        }
    }
    return 0;
}