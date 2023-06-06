#include<iostream>
#include<string>
using namespace std;
int main(){
    int a[26] = {0};
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<s.size();j++){
            a[s[j]-'A']++;
        }
        for(int j=0;j<s.size();j++){
            if(a[s[j]-'A']==1){
                cout<<s[j];
            }
            if(a[s[j]-'A']>1){
                cout<<a[s[j]-'A']<<s[j];
                a[s[j]-'A']=0;
            }
        }
        cout<<endl;
        for(int j=0;j<26;j++){
            a[j]=0;
        }
    }
    
}