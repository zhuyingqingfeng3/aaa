#include<iostream>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int N=100010;
int a[N],b[N];
int j[N],res[N];
int lena,lenb;
int jmax;
int main(){
    
    cin>>jmax;
    
    cin>>lena;
    for(int i=1;i<=lena;i++){
        scanf("%d",&a[i]);
        j[i]=a[i]+1;
    }
    cin>>lenb;
    for(int i=lena-lenb+1;i<=lena;i++){
        scanf("%d",&b[i]);
        j[i]=max(j[i],b[i]+1);
    }
    if(j[lena]<=2){
        j[lena]=2;
    }
    
    // for(int i=lena;i>=1;i--){
    //     if(a[i]>=b[i]){
    //         res[i]=a[i]-b[i];
    //     }
    //     else{
    //         a[i]+=j[i];
    //         a[i-1]--;
    //         res[i]=a[i]-b[i];
    //     }
    // }
    
    // double s1=a[1];
    // for(int i=1;i<=lena-1;i++){
    //     s1=s1*j[i+1]+a[i+1];
    // }
    // double s2=b[lena-lenb+1];
    // for(int i=lena-lenb+1;i<=lena-1;i++){
    //     s2=s2*j[i+1]+b[i+1];
    // }
    // ll ans=ll((s1-s2))%mod;
    // cout<<ans;
    ll s=a[1]-b[1];
    for(int i=1;i<=lena-1;i++){
       s=(s*j[i+1]+a[i+1]-b[i+1])%mod;
    }
    cout<<s;
    return 0;

}