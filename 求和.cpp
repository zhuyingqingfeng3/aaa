#include<iostream>
using namespace std;
typedef long long ll;
const int N=200010;
int a[N];
ll dp[N];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(i==0){
            dp[i]=a[i];
        }
        else{
            dp[i]=dp[i-1]+a[i];
        }
    }
    ll res=0;
    for(int i=0;i<n;i++){
        res+=a[i]*(dp[n-1]-dp[i]);
    }
    cout<<res;
    return 0;

}