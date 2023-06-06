// 这个题目的数据范围比较弱，ai的全部和加起来也不超过1e5就说明可以采用暴力
// 另外觉得巧妙的是用一个bool 数组来储存这个数组中哪些数是存在的
// 用的时候先判断是不是存在，存在的话就可以用，很巧妙
#include<iostream>
using namespace std;
const int N=1e5+10;
int a[N];
bool st[N];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        st[a[i]]=true;
    }
    for(int i=0;i<n;i++){
        bool flag=false;
        for(int j=1;j<a[i];j++){
              if(st[j]&&st[a[i]-j]){
                flag=true;
                break;
              }
        }
        if(flag){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}