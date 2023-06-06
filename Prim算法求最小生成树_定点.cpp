/*
S:当前已经在联通块中的所有点的集合
1. dist[i] = inf
2. for n 次
    t<-S外离S最近的点
    利用t更新S外点到S的距离
    st[t] = true
n次迭代之后所有点都已加入到S中
联系：Dijkstra算法是更新到起始点的距离，Prim是更新到集合S的距离
*/
#include<iostream>
#include<cstring>
using namespace std;
const int N=550;
const int INF=0x3f3f3f3f;
int n,m;
int g[N][N];//储存边
int dist[N];//储存到集合的距离
bool st[N];//判断是否收到集合里了
int prim(){
    int res=0;//储存最小数的权值
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;//定点出发也不用特判两个
    // 因为有n个点所以要迭代n次
    for(int i=0;i<n;i++){
        int t=-1;//储存离集合最近的点的编号以及初始判断
        for(int j=1;j<=n;j++){
            if(!st[j]&&(t==-1||dist[t]>dist[j])){
                t=j;
            }
        }
        if(dist[t]==INF){
            return INF;
        }
        res+=dist[t];
        // 吸收进来t要更新st[t]
        st[t]=1;
        // 更新其他的距离,集合里面的被更新了也无所谓因为接下来也用不到了
        // 用min来更新是比较由新点更新的还是以前的点更新的，记录路径就在这里做文章了
        for(int j=1;j<=n;j++){
            dist[j]=min(dist[j],g[t][j]);
        }
    }
    return res;
}
int main(){
    cin>>n>>m;
    memset(g,0x3f,sizeof g);//初始化图
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        g[a][b]=g[b][a]=min(g[a][b],c);//防止重边取最小值,并且是无向边
        // 所以同时更新两个边
    }
    int t=prim();
    if(t==INF){
        cout<<"impossible";
    }
    else{
        cout<<t;
    }
    return 0;
}