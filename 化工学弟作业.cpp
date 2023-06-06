#include<iostream>
#include<cmath>
using namespace std;
const int N=1e6+10;
int flag[N];
int main(){
    
    for(int i=11;i<=1e6;i++){
        int g,q,w;
        g=i%10;
        q=i/10;
        for(int i=1;i<=6;i++){
            if(q<pow(10,i)){
                w=i;
                break;
            }
        }
        int res=g*pow(10,w)+q;
        if(res%i==0||i%res==0){
            if(res!=i){
               flag[res]=1;
               flag[i]=1;
            }
            
        }
    }
    for(int i=1;i<=1e6;i++){
        if(flag[i]==1){
            printf("%d\n",i);
        }
    }
    return 0;
}