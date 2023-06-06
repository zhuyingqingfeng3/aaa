#include<iostream>
using namespace std;
const int N=1000010;
int prim[N],cnt;
bool st[N];
int oula[N];
// prim数组是质数数组，从小到大储存着质数
// st储存的是否为合数，cnt储存有几个质数
// oula[n]储存的是1-n-1与n互质的个数即欧拉函数的数组
void get_oula(int n){
    oula[1]=1;
    // 特别注意这里要有一定的初始化
    for(int i=2;i<=n;i++){
        if(!st[i]){
            prim[cnt++]=i;
            oula[i]=i-1;
            // 质数的互质个数为质数减一
        }
        for(int j=0;prim[j]<=n/i;j++){
            int t=prim[j]*i;
            st[t]=1;
            if(i%prim[j]==0){
                oula[t]=oula[i]*prim[j];
                break;
                // 注意这里有break
            }
            oula[t]=oula[i]*(prim[j]-1);
        }
        // 不同的情况i%质数，oula的推导公式不一样
    }
    
}
int main(){
    int n;
    cin>>n;
    get_oula(n);
    long long res=0;
    for(int i=1;i<=n;i++){
        res+=oula[i];
        
    }
    cout<<res<<endl;
    return 0;

}