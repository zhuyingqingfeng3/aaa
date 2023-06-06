// 属于贪心算法，贪心算法适合用于有单调性的不适用于其他
// 找到当前的最优解然后更新状态再找最优解知道答案
// 本题的贪心目标是让一个点尽可能多的被多个区间共享
// 先按照右端点排序，再遍历每一个区间是否包含上一个标注的点
// 如果包含直接pass，不包含，新增一个点并更新
// 这个题目代码与区间选点的思路是一模一样，因为本质也一样就是合并有交集
// 的区间同时最后统计有几个区间
#include<iostream>
#include<algorithm>
using namespace std;
const int N=100010;
struct Range
{
    int l;
    int r;
    /* data */
}range[N];
bool cmd(Range a,Range b){
    return a.r<b.r;
}
int n;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&range[i].l,&range[i].r);
    }
    sort(range,range+n,cmd);
    int res=0,ed=-2e9;//初始点最够小
    for(int i=0;i<n;i++){
        if(range[i].l>ed){
            res++;
            ed=range[i].r;
        }
        
    }
    cout<<res;
    return 0;

}
