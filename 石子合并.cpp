// 这个属于区间dp问题，区间dp的话肯定用二维来储存
// 并且遍历顺序不是按照从左往右，从上至下，而是按照区间长度
// 本题的状态转移是按照i j 之间从哪里分开来求最小值的思路
#include<iostream>
#include<algorithm>
using namespace std;
const int N=310;
int n;
int f[N][N];
int s[N];//储存前缀和
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    for(int i=2;i<=n;i++){
        s[i]+=s[i-1];
    }
    // 大循环是按照len 小循环是按照起点 最小循环是各个分割集合比较
    // f[i,j]=min(f[i,j],f[i,k]+f[k+1,j]+s[j]-s[i-1])
    for(int len=2;len<=n;len++){
        for(int i=1;i+len-1<=n;i++){
            int l=i;
            int r=i+len-1;
            // 用到min，所以f[l,r]=无穷大
            f[l][r]=1e8;
            for(int k=l;k<r;k++){
                f[l][r]=min(f[l][r],f[l][k]+f[k+1][r]+s[r]-s[l-1]);
            }
        }
    }
    cout<<f[1][n]<<endl;
    return 0;
}