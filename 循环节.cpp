#include<iostream>
#include<cstring>
using namespace std;
const int pp=131;
typedef unsigned long long ULL;
const int N=1000005;
ULL h[N],p[N];
int n;
char str[N];
// ULL ha[5005][5005];
// ULL get_ha(int l,int r){
//     return h[r]-(h[l-1]*p[r-l+1]);
// }
bool get_x(int l,int r,int x){
    ULL h1=h[r]-h[l+x-1]*p[r-l-x+1];
    ULL h2=h[r-x]-h[l-1]*p[r-x-l+1];
    return h1==h2;
}
// 判断是不是循环字符串的函数，x为长度。方法为截取掉后面x个字符剩下的字符，和截取掉前x字符串的
// 剩下的比较，相同就是循环节长度为x的字符串
int st[N],pri[N],cnt;
// st不仅能储存是不是合数了，现在储存的是一个数最小的质数因数
// eg st[8]=2,st[9]=3;
void xianxingshai(){
    for(int i=2;i<=n;i++){
        if(!st[i]){
            pri[cnt++]=i;
            st[i]=i;
        }
        for(int j=0;pri[j]<=n/i;j++){
            st[i*pri[j]]=pri[j];
            if(i%pri[j]==0){
                break;
            }
            
        }
        // 先变st再判断
    }
}
int get_minlen(int l,int r){
    int len=r-l+1,ans=len,d=len;
    while(d!=1){
        int temp=st[d];
        while(d%temp==0&&get_x(l,r,ans/temp)){
            ans/=temp;
            d/=temp;
        }
        while(d%temp==0){
            d/=temp;
        }
    }
    return ans;

}
// ans储存的是答案，d是判断什么时候结束，不断的缩小d来使得d=1来退出，满足ans就继续判断ans、temp
int main(){
    p[0]=1;
    
    cin>>n;
    xianxingshai();
    cin>>str+1;
    
    int q;
    cin>>q;
    
    for(int i=1;i<=n;i++){
        p[i]=p[i-1]*pp;
        h[i]=h[i-1]*pp+str[i];
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=i;j<=n;j++){
    //         ha[i][j]=get_ha(i,j);
    //     }
    // }
    // for(int i=0;i<10;i++){
    //     cout<<st[i]<<" ";
    // }
    // cout<<endl;
    // for(int i=0;i<10;i++){
    //     cout<<pri[i]<<" ";
    // }
    // cout<<endl;
    while(q--){
        int l,r;
        // cin>>l>>r;
        scanf("%d%d",&l,&r);
        //cout<<get_minlen(l,r)<<endl;
        printf("%d\n",get_minlen(l,r));
        // 用这些输入输出快一点
       
    }
    

    return 0;



}