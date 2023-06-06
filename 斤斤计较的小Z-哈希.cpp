// 典型的字符串匹配用kmp和哈希都可以
// kmp就不说了，哈希的话就是先求出子串的哈希值，在从母串第一个开始匹配
// 哈希值，一样说明出现了
#include<iostream>
#include<cstring>
#include<string>
#include<math.h>
using namespace std;
const int N=1e6+10;
char s[N];
typedef unsigned long long ull;
ull p[N],h[N];
char k[N];
ull t;
ull get(int l,int r){
    return h[r]-h[l-1]*p[r-l+1];
}
int pp=131;
int main(){
    cin>>k+1>>s+1;
    p[0]=1;
    int Len=0;
    for(int i=1;s[i];i++){
        p[i]=p[i-1]*pp;
        h[i]=h[i-1]*pp+s[i];
        Len++;
    }
    t=0;
    int len=0;
    for(int i=1;k[i];i++){
        t=t*pp+k[i];
        len++;
    }
    int res=0;
    for(int i=1;i+len-1<=Len;i++){
         if(get(i,i+len-1)==t){
            res++;
         }
    }
    cout<<res;
    return 0;
}