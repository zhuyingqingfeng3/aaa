#include<iostream>
using namespace std;
const int N=100010;
int a[N],s[N];
int n,m;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }//前缀和的初始化
    while(m--){
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d\n",s[r]-s[l-1]);//利用前缀和计算片段和
    }
    return 0;
}
//特别之处：a[0]与s[0]都是0,注意for循环都是i=1开始的，i<=n，与平常的不一样