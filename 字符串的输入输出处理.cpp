#include<iostream>
#include<string>
using namespace std;
int main(){
    int n;
    cin>>n;
    
    getchar();
    for(int i=0;i<n;i++){
        string s;
        getline(cin,s);
        cout<<s<<endl;
    }
    string s;
    while(cin>>s){
        cout<<s<<endl;
    }
}