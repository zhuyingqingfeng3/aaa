#include<iostream>
#include<unordered_map>
using namespace std;
typedef long long LL;
// 数据比较大，用这个存
const int N=1e9+7;
int main(){
    int n;
    cin>>n;
    unordered_map<int,int>res;
    // 储存分解的结果first储存的是底，second储存的是底对应的指数
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
        // 进行了分解与储存
        
    }
    LL k=1;
    for(auto p:res){
        k=k*(p.second+1)%N;
    }
    // 求约数个数的公式，即所有（指数+1）相乘
    cout<<k;
    return 0;
}