// 判断是否是二分图用染色法来判断
// 做法是对每一个新的集合都深度遍历，相邻之间的关系是不能染同样的颜色
// 或者不能出现同样的颜色，所以先for所有点保证不是连通图也能全部遍历
// 再判断是否这个集合能够染色成功，如果一直成功下去，那么就是二分图
#include<iostream>
#include<cstring>
using namespace std;
const int N=1e5+10,M=2*N;//因为是无向图，add（a,b) add(b,a)边的数量是点的两倍
int h[N],e[M],ne[M],idx;
int color[N];//储存颜色状态，0表示没有涂色，1,2表示两种颜色
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
bool dfs(int u,int c){//返回的是把u点染成c颜色能否成功
    color[u]=c;
    for(int i=h[u];i!=-1;i=ne[i]){
        int j=e[i];
        if(!color[j]){//相邻的边没有染色的情况
            if(!dfs(j,3-c)){//相邻的点染成另一种颜色能否成功
                return false;
            }
        }
        else{
            if(color[j]==c){
                return false;
            }
        }
    }
    return true;
}
int n,m;
int main(){
    scanf("%d%d",&n,&m);
    memset(h,-1,sizeof h);
    while(m--){
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b);
        add(b,a);
    }
    bool flag=true;//判断能否全部成功的
    for(int i=1;i<=n;i++){
        if(!color[i]){
            if(!dfs(i,1)){
                flag=false;
                break;
            }
        }
    }
    if(flag){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
    return 0;
    
}