// 这个题直接哈希加set查重即可
#include<iostream>
#include<set>
using namespace std;
typedef long long ll;
const int p=131;
set<ll> s;
int pn[1010];

int n;
int main(){
    cin>>n;
    pn[0]=1;
    for(int i=1;i<1010;i++){
        pn[i]=pn[i-1]*p;
    }
    while(n--){
        string m;
        cin>>m;
        ll res=0;
        for(int i=0;i<m.size();i++){
             res=res*p+m[i];
        }
        if(s.count(res)){
            cout<<1;
            return 0;
        }
        s.insert(res);
    }
    cout<<0;
    return 0;

}