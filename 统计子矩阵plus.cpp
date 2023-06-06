// 这个最简单的思路是提前计算好矩阵前缀和然后枚举四个变量
// 复杂度为n的四次方
// 采用列的前缀和加双指针可以减少到n的三次方
#include<iostream>
using namespace std;
typedef long long ll;
int a[510][510];
int main(){
    int n,m,k;
    ll ans=0;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j],a[i][j]+=a[i-1][j];
        }
    }//a[i][j]储存的是1-i行j列的前缀和

    // i控制的是矩阵的上边界，j是矩阵的下边界，i j都是行数
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            // l,r是双指针，从1开始，然后一列一列的加（通过r++）
            // 当发现超出限制了，就l++抛弃最左边的一列
            // l,r控制的是列的下标 当确定r找到最左边的l时候时
            // 答案方案就有r-l+1（仅限本题）
            for(int l=1,r=1,sum=0;r<=m;r++){
                sum+=a[j][r]-a[i-1][r];
                while(sum>k){
                    sum-=a[j][l]-a[i-1][l];
                    l+=1;
                }
                ans+=r-l+1;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}