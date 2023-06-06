// 典型的dp问题
// 首先想暴力的解法，发现可以枚举左右数量然后发现需要求更小的
// 自然引发了dp的想法，从小到大
// 记得求得是最小值，所以是初始设置好最大值，另外初始条件f[0]=0得利用好
#include<iostream>
#include<cstring>
using namespace std;
const int N=2050;
long long f[N];
int main(){
    memset(f,0x3f,sizeof f);
    f[0]=0;
    for(int i=1;i<=2021;i++){
        for(int j=0;j<i;j++){
            f[i]=min(f[i],1+2*f[j]+3*f[i-1-j]+j*j*(i-1-j));
        }
    }
    cout<<f[2021];
    return 0;
}
