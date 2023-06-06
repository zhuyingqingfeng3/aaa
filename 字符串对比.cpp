#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string a,b;
    cin>>a>>b;
    int n=a.size();
    int m=b.size();
    if(n!=m){
        cout<<1;
        exit(0);
    }
    else if(a==b){
        cout<<2;
        exit(0);
    }
    transform(a.begin(),a.end(),a.begin(),::tolower);
    transform(b.begin(),b.end(),b.begin(),::tolower);
    if(a==b){
        cout<<3;
        exit(0);
    }
    else{
        cout<<4;
        exit(0);
    }
}