#include<iostream>
using namespace std;
typedef unsigned long long ULL;
const int N=100010;
const int pp=131;
// 一般情况下采用p=131进制下以及直接采用ULL作为模（自动溢出）是不会发生冲突的
ULL h[N],p[N];
// h[k]储存的是前k个字母组成的字符串的哈希值，p[k]储存的是p的k次方
int n,m;
char str[N];
ULL get(int l,int r){
    return h[r]-h[l-1]*p[r-l+1];
}
// 此函数是求的字字符串的哈希值，计算方法就是上面的算法
int main(){
    cin>>n>>m;
    cin>>str+1;
    p[0]=1;
    for(int i=1;i<=n;i++){
        p[i]=p[i-1]*pp;
        h[i]=h[i-1]*pp+str[i];
    }
    // 进行初始化，求的p的k次方以及h数组
    while(m--){
        int l1,r1,l2,r2;
        cin>>l1>>r1>>l2>>r2;
        if(get(l1,r1)==get(l2,r2)){
            cout<<"Yes"<<endl;

        }
        else{
            cout<<"No"<<endl;
        }
    }
    return 0;



}