#include<iostream>
#include<string>

using namespace std;
int main(){
    string s[27];
    int n;

    cin>>n;
    s[1]="A";
    for(int i=2;i<=n;i++){
        char a='A'+i-1;
        s[i]=s[i-1]+a+s[i-1];
    }
    
    cout<<s[n];
}