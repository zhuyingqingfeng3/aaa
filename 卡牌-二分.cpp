// 首先采用暴力的解法，遍历x套能不能凑齐
// 判断a[i]+b[i]是否够x  最后看cnt超过了没有m
// 最多2*n套 然后check 每一个x时候要遍历a[i],b[i]
// 所以时间复杂度为n的平方
// check的复杂度是没法下降的，但是遍历x发现是有单调性的
// 即x行，那么0-x都行 x不行，那么x-2*n都不行，所以可以采用二分
// !背过二分模板
#include<iostream>
using namespace std;
typedef long long ll;
const int N=2e5+50;
ll n,m;
int a[N],b[N];
bool check(int x){
    ll cnt=0;
    for(int i=0;i<n;i++){
        if(a[i]>=x){
            continue;
        }
        else if(a[i]+b[i]<x){
            return false;
        }
        else{
            cnt+=x-a[i];
        }
    }
    if(cnt<=m){
        return true;
    }
    else{
        return false;
    }
}
int main(){
   cin>>n>>m;
   for(int i=0;i<n;i++){
    cin>>a[i];
   }
   for(int i=0;i<n;i++){
    cin>>b[i];
   }
   int l=0,r=2*N;
   while(l<r){
      int mid=(l+r+1)>>1;
      if(check(mid)){
        l=mid;
      }
      else{
        r=mid-1;
      }
   }
   cout<<r<<endl;
   return 0;
}