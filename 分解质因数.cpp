#include<iostream>
using namespace std;
int n;
void divd(int x){
    for(int i=2;i<=x/i;i++){
        // 注意是<=
        if(x%i==0){
            int s=0;
            // 记录一个i最多能相乘多少
            while(x%i==0){
                x/=i;
                s++;
            }
            // 不断的修改x
            cout<<i<<" "<<s<<endl;
        }
    }
    if(x>1){
        cout<<x<<" "<<1<<endl;
        
    }
    // 对付本身就是质数的情况
    cout<<endl;
}
int main(){
    cin>>n;
    while(n--){
        int a;
        cin>>a;
        divd(a);
    }
    return 0;

}
