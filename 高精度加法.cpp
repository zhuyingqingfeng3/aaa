#include<iostream>
#include<vector>
using namespace std;
vector<int> add(vector<int>&a,vector<int>&b){
    vector<int>c;
    int t=0;
    for(int i=0;i<a.size()||i<b.size();i++){
        if(i<a.size()){
            t=t+a[i];
        }
        if(i<b.size()){
            t=t+b[i];
        }
        c.push_back(t%10);
        t=t/10;
    }
    if(t!=0){
        c.push_back(t);
    }
    return c;
}
int main(){
    string m,n;
    cin>>m>>n;
    vector<int>a,b;
    for(int i=m.size()-1;i>=0;i--){
        a.push_back(m[i]-'0');
    }
    for(int i=n.size()-1;i>=0;i--){
        b.push_back(n[i]-'0');
    }
    vector<int>c;
    c=add(a,b);
    for(int i=c.size()-1;i>=0;i--){
        cout<<c[i];
    }
}