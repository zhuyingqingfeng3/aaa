#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
struct node{
    string sbegin;
    string send;
}s[100005];
bool cmd(node a,node b){
    return a.sbegin<b.sbegin;
}
int main(){
    int n;
    cin>>n;
    string c;
    for(int i=0;i<n;i++){
        cin>>s[i].sbegin>>c>>s[i].send;
    }
    sort(s,s+n,cmd);
    string x="00:00:00";
    string y="23:59:59";
    for(int i=0;i<n;i++){
        if(s[i].sbegin==x){
            x=s[i].send;
        }
        else{
            cout<<x<<" - "<<s[i].sbegin<<endl;
            x=s[i].send;
        }
    }
    if(x!=y){
        cout<<x<<" - "<<y<<endl;
    }
    return 0;
}