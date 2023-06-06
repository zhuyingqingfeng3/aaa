#include<iostream>
#include<unordered_map>
using namespace std;
typedef long long LL;
const int N=1e9+7;
int main(){
    int n;
    cin>>n;
    unordered_map<int,int>res;
    while(n--){
        int x;
        cin>>x;
        for(int i=2;i<=x/i;i++){
            while(x%i==0){
                x/=i;
                res[i]++;
            }
            
        }
        if(x>1){
            res[x]++;
        }
        
    }
    LL k=1;
    for(auto p:res){
        int di=p.first;
        int zhi=p.second;
        LL t=1;
        // t储存的是每一个因式的结果
        while(zhi--){
            t=(t*di+1)%N;
        }
        // t的求法
        k=(k*t)%N;
        // 最终结果是怎样由每一个因式得到的。
    }
    cout<<k;
    return 0;
}