//  这个用筛式方法即可
// 明白f[i]要么是质数，要么就是被之前的质数更新过
// 如果是质数的话，那么更新为f[i]=i就好，然后用这个质数去更新其他没有
// 被更新的数，经常用到判断if(f[i])来判断是否被更新过
#include<iostream>
using namespace std;
const int N=3e6+10;
int f[N+3];
long long s[N+3];//数值储存较大用long long
int main(){
    int n;
    cin>>n;
    for(int i=2;i<=N;i++){
        if(f[i]){
            continue;
        }
        else{
            f[i]=i;
            for(int j=2;j*i<=N;j++){
                if(f[i*j]){
                    continue;
                }
                else{
                    f[i*j]=i;
                }
            }
        }
    }
    for(int i=2;i<=N;i++){
        s[i]=s[i-1]+f[i];
    }
    while(n--){
        int k;
        scanf("%d",&k);
        printf("%lld\n",s[k]);
    }
    return 0;
}


