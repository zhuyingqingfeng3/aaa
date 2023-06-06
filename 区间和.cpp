// 本题就是明显的离散化。把所有的用到的大下标存在一个地方排序
// 关键算法是离散化的对应关系
// 注意放到一起后把重复的去掉
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,int>PII;
const int N=300010;
int n,m;
int a[N],s[N];
vector<int> alls;
vector<PII> add,query;
int find(int x){
    int l=0,r=alls.size()-1;
    
    while(l<r){
        // 注意是r+l
        int mid=r+l>>1;
        if(alls[mid]>=x){
            r=mid;
        }
        else{
            l=mid+1;
        }
    }
    //让数组变相的从1开始，因为用到前缀和
    return r+1;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int x,c;
        cin>>x>>c;
        add.push_back({x,c});
        alls.push_back(x);
    }
    for(int i=0;i<m;i++){
        int l,r;
        cin>>l>>r;
        query.push_back({l,r});
        alls.push_back(l);
        alls.push_back(r);
    }
    sort(alls.begin(),alls.end());
// 这段代码的作用是去除vector<int> alls中的重复元素。
// 其中unique()函数会将所有相邻的重复元素去掉，只保留一个，
// 然后返回去重后的vector的尾部迭代器，
// erase()函数会将这个迭代器到vector的末尾的所有元素删除。
// 因此，这段代码可以保留vector<int> alls中的所有不同元素
// ，而且不改变它们在vector中的顺序。
    
    alls.erase(unique(alls.begin(),alls.end()),alls.end());
    // 处理插入
    // auto 用法
    for(auto item:add){
        int x=find(item.first);
        a[x]+=item.second;
    }
    //预处理前缀和
    // 注意范围
    for(int i=1;i<=alls.size();i++){
        s[i]=s[i-1]+a[i];
    }
    // 处理询问
    for(auto item:query){
        int l=find(item.first),r=find(item.second);
        cout<<s[r]-s[l-1]<<endl;
    }
    return 0;
}