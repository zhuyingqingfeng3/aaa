#include<iostream>
using namespace std;
// 欧兰函数h[n]求的就是1-n所有与n互质的数的个数，公式为n*(1-1/底1)（1-1/底2）。。。。。。
// 底为分解质因数的底
int main(){
    int n;
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        int res=x;
        for(int i=2;i<=x/i;i++){
            if(x%i==0){
                res=res/i*(i-1);
                while(x%i==0){
                    x/=i;
                }

            }
        }
        if(x>1){
            res=res/x*(x-1);
        }
        // 分解出质因数，顺便更新计算res
        cout<<res<<endl;
    }
    return 0;

}