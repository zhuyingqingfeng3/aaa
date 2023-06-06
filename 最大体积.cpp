// 有用的知识：n个数如果最大公因数为1的话，那么无限个物品不能组成的体积是
// 无限多个的，而为1的，不能组成的体积种类是有限的，用硬币dp可以找到
#include<iostream>
using namespace std;
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
const int N=3e5;
int dp[N];
int v[600];
int n;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int g=gcd(v[0],v[1]);
    for(int i=2;i<n;i++){
        g=gcd(g,v[i]);
    }
    if(g!=1){
        cout<<0;
        return 0;
    }
    else{
        dp[0]=1;
        int m=0;
        for(int i=1;i<N;i++){
            for(int j=0;j<n;j++){
                if(i>=v[j]){
                    if(dp[i-v[j]]){
                        dp[i]=1;
                    }
                }
            }
            if(dp[i]){

            }
            else{
                m=i;
            }
        }
        cout<<m;
    }
    return 0;
}