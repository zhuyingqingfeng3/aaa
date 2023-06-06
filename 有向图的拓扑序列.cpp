// 拓扑排序是建立在无环的情况下
// 利用bfs做，并且是只要入度为0的才能进去，进去一个，他的终点入度-1更新
// 所以需要另外两个数组，一个数组储存入度数，一个储存压入的顺序
// 因为queue要不断的pop，而本题需要记忆
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int N=100010;
int n,m;
int h[N],ne[N],e[N],idx;
int d[N];//记录入度
int res[N];//记录顺序
int cnt;//记录答案压入顺序
void add(int a,int b){
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}
bool topsort(){
    int flag=0;
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(d[i]==0){
            flag=1;
            res[cnt++]=i;
            q.push(i);
        }
    }
    while(q.size()){
        int t=q.front();
        q.pop();
        for(int i=h[t];i!=-1;i=ne[i]){
            int j=e[i];
            if(--d[j]==0){
                q.push(j);
                res[cnt++]=j;
            }
        }
    }
    // 这个点很关键，判断一个图有没有环可以先进行拓扑排序
    // 然后看压入的数量是否是全部的点的数量
    return cnt==n;
}
int main(){
    scanf("%d%d",&n,&m);
    memset(h,-1,sizeof(h));
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b);
        d[b]++;
    }
    if(!topsort()){
        puts("-1");
    }
    else{
        for(int i=0;i<cnt;i++){
            printf("%d ",res[i]);
        }
        puts("");
    }
    return 0;
}