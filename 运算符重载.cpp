// 重载<是固定格式，它的作用就是把你想要的排在前面
// 注意是前面而不是小或者大，sort只是一种顺序而已
// 经过重载，sort调用时是我们想要的结果，而priority_queue的默认是
// 从大到小输出，也就是说自定义的<经过优先队列排序top返回的与sort最后一个
// 是一样的，二者是反着来的。如果默认有排序的话，自己调用greater与less就好
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
struct node
{
    int a;
    int b;
    bool operator <(const node x) const{
        return a>x.a;
    }
    /* data */
}a[3];

int main(){
    a[0].a=1;
    a[1].a=2;
    a[2].a=3;
    sort(a,a+3);
    cout<<a[0].a<<endl;
    priority_queue<node,vector<node>>q;
    q.push(a[0]);
    q.push(a[1]);
    q.push(a[2]);
    cout<<q.top().a;

}