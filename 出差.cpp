// 这是一个比较躶体的最短路径问题，就是把无向边转为两个有向边
// 就是把观察的权重加到路径上
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
const int N=2e4;
int n,m;
int h[N],e[N],ne[N],w[N],idx;
int dist[N];
bool st[N];
int t[N];
typedef pair<int,int>PII;
void add(int a,int b,int c){
  e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}
int get(){
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    priority_queue<PII,vector<PII>,greater<PII>> q;
    q.push({0,1});
    while(q.size()){
      PII k=q.top();
      q.pop();
      int distance=k.first;
      int ver=k.second;
      for(int i=h[ver];i!=-1;i=ne[i]){
        int j=e[i];
        if(dist[j]>dist[ver]+w[i]){
          dist[j]=dist[ver]+w[i];
          q.push({dist[j],j});
        }
      }
    }
    return dist[n];
}
int main(){
   memset(h,-1,sizeof h);
   cin>>n>>m;
   for(int i=1;i<=n;i++){
     cin>>t[i];
   }
   t[1]=0;
   while(m--){
     int a,b,c;
     cin>>a>>b>>c;
     add(a,b,c+t[a]);
     add(b,a,c+t[b]);
   }
   int res=get();
   cout<<res;
   return 0;

}