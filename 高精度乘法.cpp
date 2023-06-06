#include<iostream>
#include<vector>
using namespace std;
vector<int> mul(vector<int>&a,int b){
    vector<int> c;
    int t=0;
    for(int i=0;i<a.size()||t;i++){
        if(i<a.size()){
            int t=a[i]*b+t;
        }
        
        c.push_back(t%10);
        t/=10;
    }
    return c;
}
int main(){
    string m;
    int b;
    cin>>m>>b;
    vector<int> a,c;
    for(int i=m.size()-1;i>=0;i--){
        a.push_back(m[i]-'0');
    }
    c=mul(a,b);
    for(int i=c.size()-1;i>=0;i--){
        cout<<c[i];
    }

}