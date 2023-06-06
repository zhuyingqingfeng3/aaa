#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N=1e6+10;
LL a[N];
int main(){
    int n;
    cin>>n;
    if(n==0){
        cout<<0;
        exit(0);
    }
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    LL w;
    cin>>w;
    
    if(w==0){
        cout<<0;
        exit(0);
    }
    if(w>=a[0]&&w<a[1]){
        cout<<1;
        exit(0);
    }
    if(w<a[0]){
        cout<<0;
        exit(0);
    }
    int idx;
    for(int i=0;i<n;i++){
        if(w<a[i]){
           idx=i-1;
           break;
        }
        if(i==n-1){
            idx=n-1;
        }
    }
    LL s=a[idx];
    LL sum=0;
    for(int i=0;i<=idx;i++){
         sum+=a[i];
         if(sum>s){
            cout<<i;
            break;
         }
         if(i==idx){
            cout<<idx;
         }
    }
    

}
