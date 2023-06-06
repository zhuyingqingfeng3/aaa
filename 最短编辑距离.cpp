// 采用二维来储存，f[i,j]表示把1-i改成1-j用的最少操作数
// 状态转化方程分别从三个方向考虑
// 1、删掉变一样，=f[i-1,j]+1;
// 2、增加变一样，=f[i,j-1]+1;
// 3、替换变一样 如果a[i]==b[j]那么不用修改=f[i-1,j-1]
// 否则=f[i-1,j-1]+1
// 三者取最小值
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1010;
int n,m;
char a[N],b[N];
int f[N][N];
int main(){
    scanf("%d%s",&n,a+1);
    scanf("%d%s",&m,b+1);
    // 初始化
    for(int i=0;i<=m;i++){
        f[0][i]=i;
    }
    for(int i=0;i<=n;i++){
        f[i][0]=i;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f[i][j]=min(f[i-1][j]+1,f[i][j-1]+1);
            if(a[i]==b[j]){
                f[i][j]=min(f[i][j],f[i-1][j-1]);
            }
            else{
                f[i][j]=min(f[i][j],f[i-1][j-1]+1);

            }
        }
    }
    cout<<f[n][m]<<endl;
    return 0;

}