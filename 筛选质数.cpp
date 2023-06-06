#include<iostream>
using namespace std;
int cnt=0;

const int N=100010;
bool st[N];
// cnt储存质数的个数 st[i]=1代表i是合数 st[i]=0 表示是质数
void xuan(int n){
    for(int i=2;i<=n;i++){
        if(!st[i]){
            cnt++;
            for(int j=i+i;j<=n;j+=i){
                st[j]=1;
            }
        }
        // 不断除去质数的倍数，先判断，再除去倍数
    }
}
int main(){
    int n;
    cin>>n;
    xuan(n);
    cout<<cnt<<endl;
    return 0;

}