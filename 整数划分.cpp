// 整数划分与完全背包是一个背景，只不过一个是容量为n，能装的最大价值
// 一个求得是能装到n有几种装法，各个物品数量不限制
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1010,M=1e9+7;
int n;
int f[N];
int main(){
    cin>>n;
    // f[0]=1,代表装0的选法只有一种即全都不选
    f[0]=1;
    // 遍历每一个数
    for(int i=1;i<=n;i++){
        // 关键点理解：f[j]=原来的选法+j去掉i后的选法（j去掉i的选法情况下再选i）
        for(int j=i;j<=n;j++){
            f[j]=(f[j]+f[j-i])%M;
        }
    }
    cout<<f[n]<<endl;
    return 0;

}