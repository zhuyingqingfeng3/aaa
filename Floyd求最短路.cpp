// 最优美的算法之一，三重循环加上一定的初始值就可以求多元最短路径
// 不过是o（n3）导致点的数量不能很多
// 核心思想就是i->j  和i->v->j一段和两段和比较取最小值，找中转站
#include<iostream>
#include<cstring>
using namespace std;
const int N=210,INF=1e9;
int n,m,Q;
int d[N][N];
void floyd(){
    // 第一重循环是遍历中转点
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
}
int main(){
    scanf("%d%d%d",&n,&m,&Q);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            // 初始值
            if(i==j){
                d[i][j]=0;
            }
            else{
                d[i][j]=INF;
            }
        }
    }
    while(m--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        d[a][b]=min(d[a][b],c);//对抗重边
    }
    floyd();
    while(Q--){
        int a,b;
        scanf("%d%d",&a,&b);
        int t=d[a][b];
        if(t>INF/2){//有负回路
            puts("impossible");
        }
        else{
            cout<<t<<endl;
        }

    }
    return 0;
}