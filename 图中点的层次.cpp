// 本题的思想就是用bfs的路径代表距离，因为距离都为1
// 思路很简单用bfs并且用合适的状态能够储存距离就够了
// bfs需要用到模拟队列
// 队列的循环是由while(hh<=tt)来控制的，同时注意取的时候时q[hh++]
// 先取后挪 而添加入新的时候时q[++tt]先挪后加，这是对的
// 直接用队列，是q.size()控制循环队列，取出来记得pop一下
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int N=100010;
int n,m;
int h[N],ne[N],e[N],idx;
int d[N];//储存状态如果是-1代表是没有遍历过，其他的是距离
void add(int a,int b){
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}
int bfs(){
    memset(d,-1,sizeof(d));
    d[1]=0;
    queue<int> q;
    q.push(1);
    while(q.size()){
        int j=q.front();
        q.pop();
        for(int i=h[j];i!=-1;i=ne[i]){
            int t=e[i];
            if(d[t]==-1){
                d[t]=d[j]+1;
                q.push(t);
            }
        }
    }
    return d[n];
}
int main(){
    scanf("%d%d",&n,&m);
    memset(h,-1,sizeof(h));
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b);
    }
    cout<<bfs();
    return 0;
}