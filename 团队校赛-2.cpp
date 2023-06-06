#include<iostream>
#include<cstring>
using namespace std;
int len;
const int N=1e6+5;
int pp=131;
typedef unsigned long long ULL;
ULL h[N],p[N];
bool get_ha(int x){
    ULL h1=h[len-x];
    
    ULL h2=h[len]-h[x]*p[len-x];
    return h2==h1;
}
int get_min(){
    for(int i=1;i<=len;i++){
       if(get_ha(i)){
        return i;
       }
    }
}
int main(){
    string str;
    p[0]=1;
    for(int i=1;i<N;i++){
        p[i]=p[i-1]*pp;
    }
    int n;
    cin>>n;
    while(n--){
        
        cin>>str;
         len=str.length();
        for(int i=1;i<=len;i++){
            h[i]=h[i-1]*pp+str[i-1];
        }
        cout<<get_min()<<endl;
        
        
    }
    
    
    
    

}