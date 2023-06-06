// 关于树的储存这样理解好一点
// 1、idx是序号，是所有边的按照出现的次序的序号
// 2、h[i]储存的是第i点的最新的边的序号
// 3、ne[i]储存的是序号为i的边的上一个同一个顶点的边的序号位置
// 4、所以添加时候，先添加e[idx],随后更新一下ne[idx]指向前一个最新的
// 也就是h[a],既然有了新边，h[a]也要更新一下，并且idx+1
// 遍历的时候肯定是找源头，找最新的边，然后根据ne逆着找，直到指向-1
// 表示结束
#include<iostream>
#include<vector>
using namespace std;
const int N=1e8;
int e[N],ne[N],h[N],idx;
bool flag[N];
void add(int a,int b){
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
    e[idx]=a;
    ne[idx]=h[b];
    h[b]=idx++;
}
int sum=0;
int dfs(int n){
    flag[n]=1;
    sum++;
    for(int i=h[n];i!=-1;i=ne[i]){
        if(flag[e[i]]==0){
           dfs(e[i]);
        }
    }
    return sum;

}
int main(){
    for(int i=0;i<N;i++){
        h[i]=-1;
    }
    int n,m,s;
    cin>>n>>m>>s;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        add(a,b);

    }
    int res=dfs(s);
    cout<<res;
    return 0;


}