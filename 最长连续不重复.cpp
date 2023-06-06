#include<iostream>
using namespace std;
const int N=100010;
int n;
int a[N],s[N];//s[i]的大小是a[i]在片段出现的次数，来判断是否有重复的
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int res=0;
    for(int i=0,j=0;i<n;i++){
        s[a[i]]++;
        while(s[a[i]]>1){
            s[a[j]]--;//不符合的话就不要前面的
            j++;//然后往后挪动 直到满意为止
            
        }
        res=max(res,i-j+1);//保存最好的结果
    }
    cout<<res;
    return 0;
}