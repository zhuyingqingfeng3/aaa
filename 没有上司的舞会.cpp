// 这个属于树形dp大致要想到树形dp用f[u,0]和f[u,1]表示，0代表不选，1代表选
// 同时还要常规的图的储存，遍历等基本内容
// 本题首先找到根，然后dfs根取二者中最大值。注意，如果选了u那么下属一定不能选
// 不选u，那么要下属二者中的最大值
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=6010;
int n;
int h[N],ne[N],e[N],idx;
int happy[N];
int f[N][2];
bool has_fa[N];
void add(int a,int b){
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}
void dfs(int u){
    f[u][1]=happy[u];
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        dfs(j);
        f[u][1]+=f[j][0];
        f[u][0]+=max(f[j][0],f[j][1]);
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&happy[i]);
    }
    memset(h,-1,sizeof(h));
    for(int i=0;i<n-1;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        add(b,a);
        has_fa[a]=true;
    }
    int root=1;
    while(has_fa[root]){
        root++;
    }
    dfs(root);
    printf("%d",max(f[root][0],f[root][1]));
    return 0;

}
