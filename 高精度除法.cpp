#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> div(vector<int> &a,int b,int &r){
    vector<int> c;
    r=0;
    for(int i=a.size()-1;i>=0;i--){
        r=r*10+a[i];
        c.push_back(r/b);
        r=r%b;
    }
    reverse(c.begin(),c.end());
    while(c.size()>1&&c.back()==0){
        c.pop_back();
    }
    return c;
}
int main(){
    string m;
    int b;
    int r;
    cin>>m>>b;
    vector<int> a,c;
    for(int i=m.size()-1;i>=0;i--){
        a.push_back(m[i]-'0');
    }
    c=div(a,b,r);
    for(int i=c.size()-1;i>=0;i--){
        cout<<c[i];
    }
    cout<<endl;
    cout<<r;
    return 0;
    
}