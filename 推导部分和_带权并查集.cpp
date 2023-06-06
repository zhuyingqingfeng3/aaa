// 首先知道并查集带权的操作，需要p，d数组
// d数组储存的是到父节点的距离，不过经过find函数后，父节点变成根节点
// d储存的就是到根节点的距离了，所以a,b如果在一个并查集中
// a与b之间的距离就是d[b]-d[a]（可能会产生负值因为有方向性）
// find函数首先记录旧的父亲，然后寻找根节点，再更新自己的距离为到根节点的距离
// 合并操作时候，除了让父节点pl认pr为父亲，关键更新为
// !d[pl]=d[r]-d[l]-距离


// !另外本题让我对数组的理解更深一层，数组中的值可以看做数字之间的距离
// 比如告诉a[3]=5代表2号点到3号点距离为5
// a[3]+a[4]=5代表2号到4号距离为5 本题就可转化为告诉m条边问是否在
// 一个连通集，在的话距离为多少
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=1e5+10;
// 并查集
int p[N];
// 到根距离
ll d[N];
int n,m,q;
int find(int x){
    if(p[x]!=x){
        int t=p[x];//t储存旧的父亲
        p[x]=find(p[x]);//找到父亲
        d[x]+=d[t];//更新d[x]
    }
    return p[x];
}
int main(){
    cin>>n>>m>>q;
    // 初始化并查集
    for(int i=1;i<=n;i++){
        p[i]=i;
    }
    while(m--){
        ll l,r,s;
        cin>>l>>r>>s;
        // 找根节点 前缀和 s=sum[r]-sum[l-1]抽象为l-1到r的距离为s
        int pl=find(l-1),pr=find(r);
        // 合并
        p[pl]=pr;
        // !合并时候操作 d[r]-d[l]-（l与r之间的距离）
        d[pl]=d[r]-d[l-1]-s;
    }
    // 查询
    // 在一个联通集，就输出距离l---r =d[r]-d[l]
    while(q--){
        int l,r;
        cin>>l>>r;
        int pl=find(l-1),pr=find(r);
        if(pl!=pr){
            cout<<"UNKNOWN"<<endl;
        }
        else{
            cout<<d[r]-d[l-1]<<endl;
        }
    }
    return 0;
}