#include<iostream>
using namespace std;
const int N=100010;
int p[N],cnt[N];
// 升级版本体现在可以查找一个元素所在集合的元素个数
// 原理为每次两个不在同一个集合的元素连在一起时，让其中当父亲的数量加上新来的
// 每次查询只看父亲的元素数量就好
int n,m;
int find(int x){
    if(p[x]!=x){
        p[x]=find(p[x]);
    }
    return p[x];
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        p[i]=i;
        cnt[i]=1;
        // 初始化要赋值数量都为1
    }
    while(m--){
        string op;
        int a,b;
        cin>>op;
        if(op=="C"){
            cin>>a>>b;
            a=find(a);
            b=find(b);
            if(a!=b){
                p[a]=b;
                cnt[b]+=cnt[a];
            }
            // 注意，不在同一个集合再相连
        }
        else if(op=="Q1"){
            cin>>a>>b;
            if(find(a)==find(b)){
                cout<<"Yes"<<endl;
            }
            else{
                cout<<"No"<<endl;
            }
        }
        else{
            cin>>a;
            cout<<cnt[find(a)]<<endl;
        }

    }
    return 0;

}
