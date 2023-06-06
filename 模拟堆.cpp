// #include<iostream>
// #include<algorithm>
// using namespace std;
// const int N=100010;
// int h[N],ph[N],hp[N],cnt;
// // h[x]储存堆中下标为x的数值 ph[k]储存的是第k个插入的数在堆中的下标
// // hp[j]储存的是堆中下标为j的数是第几个插进来的。所以hp[j]=k ph[k]=j
// void heap_swap(int a,int b){
//     swap(ph[hp[a]],ph[hp[b]]);
//     // 先交换ph，ph[]中需要获得是第几个插入的，所以为hp[a]
//     swap(hp[a],hp[b]);
//     swap(h[a],h[b]);
// }
// // heap的专属交换 参数为堆中的下标
// void down(int u){
//     int t=u;
//     if(u*2<=cnt&&h[u*2]<h[t]){
//         t=u*2;
//     }
//     if(u*2+1<=cnt&&h[u*2+1]<h[t]){
//         t=u*2+1;
//     }
//     if(u!=t){
//         heap_swap(t,u);
//         down(t);
//     }
// }
// void up(int u){
//     while(u/2&&h[u/2]>h[u]){
//         heap_swap(u,u/2);
//         u/=2;
//     }
// }
// int main(){
//     int n,m=0;
//     // m储存的是插入了几个数
//     cin>>n;
//     while(n--){
//         string op;
//         int k,x;
//         cin>>op;
//         if(op=="I"){
//             cin>>x;
//             cnt++;
//             m++;
//             ph[m]=cnt;
//             hp[cnt]=m;
//             h[cnt]=x;
//             up(cnt);
//         }
//         // 插入的操作
//         else if(op=="PM"){
//             cout<<h[1]<<endl;
//         }
//         // 获取最小值
//         else if(op=="DM"){
//             heap_swap(1,cnt);
//             cnt--;
//             down(1);
//         }
//         // 删除最小值
//         else if(op=="D"){
//             cin>>k;
//             k=ph[k];
//             heap_swap(k,cnt);
//             cnt--;
//             down(k);
//             up(k);
//         }
//         // 删除第k个数
//         else{
//             cin>>k>>x;
//             k=ph[k];
//             h[k]=x;
//             down(k);
//             up(k);
//         }
//         // 修改第k个数
//     }
//     return 0;
// }
#include<iostream>
#include<algorithm>
using namespace std;
const int N=100010;
int h[N],ph[N],hp[N],cnt;
void head_swap(int a,int b){
    swap(ph[hp[a]],ph[hp[b]]);
    swap(hp[a],hp[b]);
    swap(h[a],h[b]);
}
void down(int u){
    int t=u;
    if(u*2<=cnt&&h[u*2]<h[t]){
        t=u*2;
    }
    if(u*2+1<=cnt&&h[u*2+1]<h[t]){
        t=u*2+1;
    }
    if(u!=t){
        head_swap(u,t);
        down(t);
    }
}
void up(int u){
    while(u/2&&h[u/2]>h[u]){
        head_swap(u/2,u);
        u/=2;
    }
}
int main(){
    int n,m=0;
    cin>>n;
    while(n--){
        string op;
        int k,x;
        cin>>op;
        if(op=="I"){
            cin>>x;
            cnt++;
            m++;
            ph[m]=cnt;
            hp[cnt]=m;
            h[cnt]=x;
            up(cnt);
        }
        else if(op=="PM"){
            cout<<h[1]<<endl;
        }
        else if(op=="DM"){
            head_swap(1,cnt);
            cnt--;
            down(1);
        }
        else if(op=="D"){
            cin>>k;
            k=ph[k];
            head_swap(k,cnt);
            cnt--;
            down(k);
            up(k);
        }
        else{
            cin>>k>>x;
            k=ph[k];
            h[k]=x;
            down(k);
            up(k);
        }
    }
    return 0;

}