//利用了贪心的思想，按左端点排序，随后记录最大右端点
#include<iostream>
#include<algorithm>
using namespace std;
const int N=100010;
struct qujian{
    int l;
    int r;
    bool operator <(const qujian x) const{
        return l<x.l;
    }
}e[N];
const int INF=0x3f3f3f3f;
int n;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int l,r;
        cin>>l>>r;
        e[i].l=l;
        e[i].r=r;
    }
    sort(e,e+n);
    // for(int i=0;i<n;i++){
    //     cout<<e[i].l<<" "<<e[i].r<<endl;
    // }
    int res=0;
    int cnt=-INF;
    for(int i=0;i<n;i++){
        if(e[i].l>cnt){
            res++;
            //cout<<"***"<<e[i].l<<" "<<e[i].r<<" "<<cnt<<endl;
            cnt=max(cnt,e[i].r);
        }
        else{
            cnt=max(cnt,e[i].r);
        }
    }
    cout<<res;
    return 0;
}