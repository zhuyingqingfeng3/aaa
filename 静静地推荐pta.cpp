#include<iostream>
using namespace std;
int dp[292][2]={0};
int main(){
    int n,k,s;
    cin>>n>>k>>s;
    int res=0;
    for(int i=0;i<n;i++){
       int a,b;
       cin>>a>>b;
       if(a>=175){
         if(b>=s){
            dp[a][1]++;
         }
         else{
            dp[a][0]++;
         }
       }
    }
    
    for(int i=0;i<k;i++){
       for(int p=0;p<291;p++){
          if(dp[p][0]>0){
            res++;
            dp[p][0]--;
          }
          res=res+dp[p][1];
          dp[p][1]=0;
       }
    }
    cout<<res;

}