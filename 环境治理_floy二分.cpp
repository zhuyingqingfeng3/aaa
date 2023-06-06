// 觉得巧妙的是察觉到天数是符合二段性的用二分查找
// 注意每次查看天的时候，f都要恢复成g数组
// 技巧，一般需要三个数组，一个保持原来样子，一个是要求，一个用于储存变化后的
// !当不能低于要求时用max来保持
#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
const int N=110;
int g[N][N];
int f[N][N];
int m[N][N];
ll n,q;
// 求出返回治理后的总和
ll floy(){
    ll a=0;
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            a+=f[i][j];
        }
    }
    return a;
}
// 检查经过x天是否能行
bool check(int x){
    int h=x/n;//经历h轮
    int s=x%n;//额外多的几天
    memcpy(f,g,sizeof(g));
    // 开始治理
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j){
                continue;
            }
            if(i<=s){//多一次的城市
                f[i][j]=max(m[i][j],f[i][j]-h-1);
            }
            else{
                f[i][j]=max(m[i][j],f[i][j]-h);
            }
            // 共同道路，也要更新
            f[j][i]=f[i][j];
        }
    }
    return floy()<=q;
    
}
void solve(){
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>g[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>m[i][j];
            // 进行初始判断，因为floy里用的是f数组，这里进行赋值
            f[i][j]=m[i][j];
        }
    }
    if(floy()>q){
        cout<<"-1";
        return;
    }
    ll l=0,r=10000010;
    // 采用二分进行查找天数，如果20天能够满足，那么最少天数一定在20天内
    // 符合二段性
    while(l<r){
        int mid=l+r>>1;
        if(check(mid)){
            r=mid;
        }
        else{
            l=mid+1;
        }
    }
    cout<<l;
    
}
int main(){
    solve();
    return 0;

}