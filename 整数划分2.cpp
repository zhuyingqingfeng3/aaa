// 这次的是状态表示的不同f[i,j]表示的是总数为i，并且i是由j个数相加得来
// 的全部选法
// f[i,j]=f[i-1,j-1]+f[i-j,j]
// 划分依据是j个数种的最小值=1或者大于1 =1是前者 大于1，所有数都减一是后者
#include<iostream>
using namespace std;
const int N=1010,M=1e9+7;
int n;
int f[N][N];
int main(){
    cin>>n;
    f[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            f[i][j]=(f[i-1][j-1]+f[i-j][j])%M;
        }
    }
    int res=0;
    for(int i=1;i<=n;i++){
        res=(res+f[n][i])%M;
    }
    cout<<res<<endl;
    return 0;
}