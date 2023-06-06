// Hamilton 路径的定义是从 0到n−1不重不漏地经过每个点恰好一次。
// f[i,j]中的i表示的是一种状态，是用二进制压缩状态
// 每一位数上为1就是该点走过，不过题目要求点的序号从0开始，导致
// 相差1 eg：0号走过其他都没走过 i=0001
// j代表最后一位是走到了序号为j的点
// 所以状态转移方程为j点的上一个点是谁，进行取最小值就行0-k(除了j点的状态)+w[k,j]

#include<iostream>
#include<cstring>
using namespace std;
const int N=20,M=1<<N;
int n;
int w[N][N];
int f[M][N];
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>w[i][j];
        }
    }
    // 初始化f为最大值服务于min
    memset(f,0x3f,sizeof(f));
    // 0点出发距离为0
    f[1][0]=0;
    // 遍历各种状态
    for(int i=0;i<1<<n;i++){
        // 遍历状态下经过最后一个点,此时j代表的是序号
        for(int j=0;j<n;j++){
            // 判断状态中是否含有j点
            if(i>>j&1){
                // 遍历上一个点k以及判断是否含有k点
                for(int k=0;k<n;k++){
                    if(i>>k&1){
                        f[i][j]=min(f[i][j],f[i-(1<<j)][k]+w[k][j]);
                    }
                }
            }
        }
    }
    // 注意运算优先级并且知道答案是经过所有点并且达到最远的n-1点
    cout<<f[(1<<n)-1][n-1];
    return 0;

}