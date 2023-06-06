// 这是典型的筛式，s[i]储存的是质数想乘的个数，找到一个质数，就用
// 数组储存起来，然后更新所有质数乘以i后的数，这个状态转移s[x*i]=s[i]+1
// 是最关键的最难想到的
#include<iostream>
#include<vector>
using namespace std;
const int L = 2333333, R = 23333333;
int s[R+10],ans;
vector<int> p;
int main(){
    // 遍历所有小于等于R的数
    for(int i=2;i<=R;i++){
        if(!s[i]){
            // 这是一个质数
            s[i]=1;
            p.push_back(i);//把这个质数存进去
        }
        // 判断是否满足条件
        if(i>=L&&s[i]==12){
            ans++;
        }
        for(auto x:p){
            if(x*i>R){
                break;
            }
            else{
                s[x*i]=s[i]+1;
            }
        }
    }
    cout<<ans<<endl;
    return 0;

}