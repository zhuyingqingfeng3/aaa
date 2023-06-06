#include<iostream>
#include<algorithm>
using namespace std;
const int N=100010;
int n,m;
int h[N],sizes;
// 首先，堆是完全二叉树，最后一排从左到右。利用这个特点，堆用一维数组来储存
// 下标为u，则u*2是他的左子树，u*2+1是又子树。并且初始下标为1开始的
// 核心函数为down函数与up函数 down函数是比较根，左，又三个的最小值放到根。不断的交换递归
void down(int u){
    int t=u;
    // t储存的是最小数的下标
    if(u*2<=sizes&&h[u*2]<h[t]){
        t=u*2;
    }
    if(u*2+1<=sizes&&h[u*2+1]<h[t]){
        t=u*2+1;
    }
    if(u!=t){
        swap(h[u],h[t]);
        down(t);
    }
    // 判断出需要交换并且继续递归下去
}
void up(int u){
    while(u/2&&h[u/2]>h[u]){
        swap(h[u/2],h[u]);
        u/=2;
    }
}
// 只要有父节点，并且父节点比它大，那就一直交换
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>h[i];
    }
    sizes=n;
    // 初始化，储存原始数据以及设置好size
    for(int i=n/2;i;i--){
        down(i);
    }
    // 这是对初始化的排序。从n/2开始到i=0结束，接近o（1）的速度
    while(m--){
        cout<<h[1]<<" ";
        h[1]=h[sizes];
        sizes--;
        down(1);
        // 删除根节点的操作，首先用最后一位替掉，size--，重新排序
    }
    return 0;

}
