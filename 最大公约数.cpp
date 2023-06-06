#include<iostream>
using namespace std;
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
// 求最大公约数的算法
int main(){
    int n;
    cin>>n;
    while(n--){
        int a,b;
        cin>>a>>b;
        cout<<gcd(a,b)<<endl;
    }
    return 0;

}