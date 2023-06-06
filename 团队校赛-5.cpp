#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef unsigned long long ULL;
ULL er[65];
int main(){
    er[0]=1;
    for(int i=1;i<65;i++){
        er[i]=er[i-1]*2;
    }
    int t;
    cin>>t;
    
    while(t--){
        ULL res=0;
        int n;
        string str;
        cin>>n>>str;
        int cnt=count(str.begin(),str.end(),'1');
        
        for(int i=0;i<cnt;i++){
            res+=er[i];
        }
        cout<<res<<endl;
    }
    

}