// 题目：小蓝最近在学习二进制。他想知道 
// 1 到 N 中有多少个数满足其二进制表示中恰好有 K 个 1。你能帮助他吗？


// 本题是动态规划题目，还是典型的数字逐位分析采用dfs还是经典的
// 一个参数表示遍历的位置，其他参数表示现在的状态这样就不用现场恢复了
// 具体分析来说，假如最高位是1 那么如果这个位置我们未来选择这个位置为0
// 那么最后的结果就是在n-1中选出k个1，即c(n-1.k)
// 如果这个选为1那么接下来的部分只需要承担k-1个任务继续遍历下去就好
// 一个方案数成功了那么就是1 不成功就是0临界值就是遍历完了或者出现的状态不对
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const int N=55;
ll f[N][N];
void init(){
    for(int i=0;i<N;i++){
        for(int j=0;j<=i;j++){
            if(!j){
                f[i][j]=1;
            }
            else{
                f[i][j]=f[i-1][j]+f[i-1][j-1];
            }
        }
    }
}


ll num;
int k;
vector<ll> vec;

ll dfs(int pos,int last){
    // 出口
    if(last==k){
        return 1;
    }
    if(pos<0||last>k){
        return 0;//匹配失败
    }
    ll res=0;
    if(vec[pos]==1){
        res+=f[pos][k-last];//这个位置取0的情况
        res+=dfs(pos-1,last+1);//这个位置取1的情况
    }
    else{
        res+=dfs(pos-1,last);
    }
    return res;
}

int main(){
    init();
    cin>>num>>k;
    // 这是一个求一个数二进制数的好方法，不断地%2再除以2，再添加到
    // vector中，只不过分解出来的是倒着的
    while(num){
        vec.emplace_back(num%2);
        num/=2;
    }
    ll ans=dfs(vec.size()-1,0);
    cout<<ans;
    return 0;
}