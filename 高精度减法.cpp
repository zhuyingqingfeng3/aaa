#include<iostream>
#include<vector>
using namespace std;
bool cmd(string&m,string&n){
    if(m.size()>n.size()){
        return true;
    }
    if(m.size()<n.size()){
        return false;
    }
    for(int i=0;i<m.size();i++){
        if(m[i]>n[i]){
            return true;
        }
        if(m[i]<n[i]){
            return false;
        }
    }
    return true;
}
vector<int> sub(vector<int>&a,vector<int>&b){
    vector<int>c;
    int t=0;
    for(int i=0;i<a.size();i++){
        t=a[i]-t;
        if(i<b.size()){
            t=t-b[i];
        }
        if(t<0){
            c.push_back(t+10);
            t=1;
        }
        else{
            c.push_back(t);
            t=0;
        }
    }
    while(c.size()>1&&c.back()==0){
        c.pop_back();
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
    if(cmd(m,n)){
        c=sub(a,b);
        for(int i=c.size()-1;i>=0;i--){
            cout<<c[i];
        }
    }
    else{
        c=sub(b,a);
        cout<<"-";
        for(int i=c.size()-1;i>=0;i--){
            cout<<c[i];
        }
    }
}