#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    int*a=new int[n];
    if(n%2==1){
        for(int i=0;i<=n/2;i++){
            a[i]=2*(n-1)-i*2;
        }
        for(int i=n/2+1;i<n;i++){
            a[i]=a[i-1]+2;
        }
    }
    else{
        for(int i=0;i<n/2;i++){
            a[i]=2*(n-1)-2*i;
        }
        for(int i=n/2;i<n;i++){
            if(i==n/2){
                a[i]=a[i-1];
            }
            else{
                a[i]=a[i-1]+2;
            }
            
            
        }
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    
    }
    return 0;
}