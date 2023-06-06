// 本题精髓在于dp的记忆化以及dp的递归做法
// f[i,j]表示以i，j为起点的能走过的最多格子数
// f[i,j]=max(上下左右)+1 同时要满足不能出边界和严格向下滑动
// 记忆化的做法是给f赋值初值，判断是否已经算过了
#include<cstring>
#include<iostream>
using namespace std;
const int N=310;
int n,m;
int g[N][N];//储存高度
int f[N][N];
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};//上下左右的顺序对应的xy变化值
int dp(int x,int y){
    // 返回f[x,y]的值
    int &v=f[x][y];
    // 记忆化
    if(v!=-1){
        return v;
    }
    // 自己至少占据一个格子
    v=1;
    for(int i=0;i<4;i++){
        // 四个方向
        int a=x+dx[i];
        int b=y+dy[i];
        if(a>=1&&a<=n&&b>=1&&b<=m&&g[x][y]>g[a][b]){
            v=max(v,dp(a,b)+1);
        }
    }
    return v;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>g[i][j];
        }
    }
    memset(f,-1,sizeof(f));
    int res=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            res=max(res,dp(i,j));
        }
    }
    cout<<res;
    return 0;


}