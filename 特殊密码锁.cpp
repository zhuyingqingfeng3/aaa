#include<iostream>
#include<cstring>
#include<string.h>
using namespace std;
const int N=50;
bool a[N];
int n;

int main(){
    string s1,s2;
    cin>>s1>>s2;
    n=s1.length();
    for(int i=1;i<=n;i++){
        if(s1[i-1]==s2[i-1]){
           a[i]=1;
        }
        else{
            a[i]=0;
        }
    }
    // 储存是否相同
    a[0]=0;
    a[n+1]=0;
    // for(int i=0;i<=n+1;i++){
    //     cout<<a[i]<<" ";
    // }
    // cout<<endl;
    int res1=0;
    int res;
    int res2=0;
    a[1]=!a[1];
    a[2]=!a[2];
    res1++;
    for(int i=2;i<=n;i++){
        if(a[i-1]==0){
            a[i-1]=!a[i-1];
            a[i]=!a[i];
            a[i+1]=!a[i+1];
            res1++;
        }
    }
    
    for(int i=1;i<=n;i++){
        if(s1[i-1]==s2[i-1]){
           a[i]=1;
        }
        else{
            a[i]=0;
        }
    }
    for(int i=2;i<=n;i++){
        if(a[i-1]==0){
            a[i-1]=!a[i-1];
            a[i]=!a[i];
            a[i+1]=!a[i+1];
            res2++;
        }
    }
    int flag=1;
    
    for(int i=1;i<=n;i++){
        if(a[i]!=1){
            flag=0;
            break;
        }
    }
    if(flag){
        cout<<min(res1,res2);
    }
    else{
        cout<<"impossible";
    }
    return 0;

}