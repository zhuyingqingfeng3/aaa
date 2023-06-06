#include<iostream>
using namespace std;
int n;
bool is_z(int x){
    if(x<2){
        return false;
    }
    // 小于2都不是
    else{
        for(int i=2;i<=x/i;i++){
            if(x%i==0){
                return false;
            }
        }
        return true;
    }
    // 特别注意是i<n/i而不是sqrt(n)，每次调用sqrt是很费时间的
}

int main(){
    cin>>n;
    while(n--){
        int a;
        cin>>a;
        if(is_z(a)){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    return 0;

}