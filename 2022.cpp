// 这是一个背包问题，把2022以内的数全部当做一个物品，然后每个物品的
// 体积是1，价值为自身数值，然后用f[i][j]开储存方案数
// 代表用i个数能表达出j的方案数
// 递归方程就是f[i][j]+=f[i-1][j-x]当最后一个数是由x补充的时候
// 特别注意的是，这个时候大循环是遍历以哪个物品垫底，但是里面要从高到低的
// 遍历，否则会前面的会对后面的有影响，记住求方案数一定要从高到低遍历
#include<iostream>
using namespace std;
typedef long long LL;
const int N=3000;
LL f[15][N];
int main()
{
    f[0][0]=1;
    for(int i=1;i<=2022;++i){
        for(int j=10;j>=1;j--){
            for(int k=i;k<=2022;++k){
                 f[j][k]+=f[j-1][k-i];
            }
        }
    }
    cout<<f[10][2022]<<endl;
   return 0;
}