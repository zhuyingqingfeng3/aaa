#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
using namespace std;
//生成一个返回数组a中第一个最大值的索引的函数
int max_index(int*a,int n){
    int max=a[0];
    int index=0;
    for(int i=1;i<n;i++){
        if(a[i]>max){
            max=a[i];
            index=i;
        }
    }
    return index;
}
//生成一个返回在数组a中指定索引k后连续有几个与啊【k】相同的元素的函数
int same_num(int*a,int n,int k){
    int count=0;
    for(int i=k+1;i<n;i++){
        if(a[i]==a[k]){
            count++;
        }
        else{
            break;
        }
    }
    return count;
}
//生成一个返回判断数组a是否全部为1的函数
bool all_one(int*a,int n){
    for(int i=0;i<n;i++){
        if(a[i]!=1){
            return false;
        }
    }
    return true;
}
int mofa(int m){
    int s=sqrt(m/2+1);
    return s;
}
int main(){
    int n;
    cin>>n;
    int*a=new int[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int res=0;
    while(!all_one(a,n)){
        int d=max_index(a,n);
        int k=a[d];
        
        
        for(int i=d;i<n;i++){
            if(a[i]==k){
                a[i]=mofa(k);
            }
            else{
                break;
            }
        }
        
        
        
        res++;
    }
    
    cout<<res;
    
    return 0;


}