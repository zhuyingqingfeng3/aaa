#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    unsigned long long a,b,n;
    cin>>a>>b>>n;
    int sum=5*a+2*b;
    int zhou=n/sum;
    int res=0;
    res=res+zhou*7;
    int h=n-zhou*sum;
    int tian=1;
    while(h>0){
        if(tian<=5){
            h=h-a;
            res++;
        }
        else{
            h=h-b;
            res++;
        }
    }
    cout<<res;
    return 0;
}