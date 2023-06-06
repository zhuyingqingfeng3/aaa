// 典型的并查集加set去重
#include<iostream>
#include<set>
using namespace std;
const int N=1e6+10;
int p[N];
int find(int x){
    if(p[x]!=x){
        p[x]=find(p[x]);
    }
    return p[x];
}
int main(){
    int n,m,q;
    cin>>n>>m>>q;
    n=n*m;
    for(int i=1;i<=n;i++){
        p[i]=i;
    }
    while(q--){
        int a,b;
        cin>>a>>b;
        a=find(a);
        b=find(b);
        if(a==b){

        }
        else{
            p[a]=b;
        }
    }
    set<int> s;
    for(int i=1;i<=n;i++){
        s.insert(find(i));
    }
    cout<<s.size();
    return 0;
}