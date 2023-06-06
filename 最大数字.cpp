// dp用深搜来解决，尤其是遍历一个数字的每一位时候，i表示第几位，其余变量
// 表示状态
// 其中给我们的启发是，如果不想在dfs中还原现场的话，可以直接把
// 变化后的状态当做参数传到函数中，直接用最新的参数，就不用还原现场了
#include<iostream>
using namespace std;
typedef long long ll;
string s;
ll ans=0;
void dfs(int i,ll sum,int a,int b){
    if(i==s.size()){
        ans=max(ans,sum);
        return;
    }
    int x=s[i]-'0';
    int t=min(a,9-x);
    dfs(i+1,sum*10+x+t,a-t,b);
    if(b>=x+1){
        dfs(i+1,sum*10+9,a,b-(x+1));
    }
    else{
        dfs(i+1,sum*10+x,a,b);
    }
}
int main(){
    int A,B;
    cin>>s>>A>>B;
    dfs(0,0,A,B);
    cout<<ans<<endl;
    return 0;
}