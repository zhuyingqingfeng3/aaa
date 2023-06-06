// 总体来说，本题是二分加贪心的思路
// 二分负责不断找更小的范围，贪心是负责查看二分找的那个数是否能行
// 总结规律，加入机器人清理的长度为n，那么不要管机器人是怎么走的
// 不要管机器人的出生点在哪，所花费的时间为(n-1)*2
// 这样就可以把长度和时间（答案）挂上钩
// 要想答案最小，那么久要求某一个机器人清扫的最长长度最短
// （木桶的最长边越短越好）
// 怎么检查能不能行得通呢，就假设所有机器人都清扫最长长度，然后
// 利用贪心思想，尽可能先清扫左边，再清扫右边，累加起来，看清扫的
// 的长度有没有超过n即可
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+10;
int n,k;
int pos[N];
bool check(int x){
    // x代表的是一次性清扫x长的路
    int s=0;//表示一共扫了多少地
    for(int i=0;i<k;i++){
        if(pos[i]-x>s){
            return false;
        }
        if(pos[i]<=s){
            s=max(s,pos[i]+x-1);
        }
        else{
            s+=x;
        }
    }
    return s>=n;
}
int main(){
    cin>>n>>k;
    for(int i=0;i<k;i++){
        cin>>pos[i];
    }
    sort(pos,pos+k);
    int left=0,right=n;
    while(left<right){
        int mid=left+right>>1;
        if(check(mid)){
            right=mid;
        }
        else{
            left=mid+1;
        }
    }
    cout<<(left-1)*2<<endl;
    return 0;
    
}