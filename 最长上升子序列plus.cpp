// 这个用模拟栈和贪心是小端更小的思想来求得长度
// 时间复杂度为nlogn
// lower_bound是二分，最后栈中储存的不是原本顺序的上升子序列
// 只不过长相同
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
const int N=1e5+10;
int a[N];
vector<int> stk;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    stk.push_back(a[0]);
    for(int i=1;i<=n;i++){
        if(a[i]>stk.back()){
            stk.push_back(a[i]);
        }
        else{
            *lower_bound(stk.begin(),stk.end(),a[i])=a[i];
        }
    }
    cout<<stk.size();
    return 0;
    
}