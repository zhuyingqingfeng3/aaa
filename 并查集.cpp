// 并查集的应用：1、合并两个集合
// 2、查找两个元素是否在一个集合中
#include<iostream>
using namespace std;
const int N=100010;
int n,m;
int p[N];
int find(int x){
    if(p[x]!=x){
        p[x]=find(p[x]);
    }
    return p[x];
}
// 这个是核心 采用了路径压缩，返回的是x的根节点的编号
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        p[i]=i;
    }
    // 需要进行的初始化，是p[x]=x；
    while(m--){
        char op;
        int a,b;
        cin>>op>>a>>b;
        if(op=='M'){
           p[find(a)]=find(b);
        }
        // 两个集合合并，说白了就是让其中一个集合的跟节点认另一个根节点当父亲
        else{
            if(find(a)==find(b)){
                cout<<"Yes"<<endl;
            }
            else{
                cout<<"No"<<endl;
            }
        }
    }
    return 0;

}
