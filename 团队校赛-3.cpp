#include<iostream>
using namespace std;
const int N=1000010;
int zy[N]={0},yz[N]={0};
int len;
void insert(int op,string x){
    len++;
    if(op==1&&x=="D"){
        for(int i=len;i>=2;i--){
            zy[i]=zy[i-1]-1;
        }
        zy[1]=-1;
        yz[len]=yz[len-1]-1;
    }
    else if(op==1&&x=="W"){
        for(int i=len;i>=2;i--){
            zy[i]=zy[i-1]+1;
        }
        zy[1]=1;
        yz[len]=yz[len-1]+1;
    }
    else if(op==1&&x=="R"){
        for(int i=len;i>=2;i--){
            zy[i]=zy[i-1];
        }
        zy[1]=0;
        yz[len]=yz[len-1];
    }
    else if(op==2&&x=="D"){
        zy[len]=zy[len-1]-1;
        for(int i=len;i>=2;i--){
            yz[i]=yz[i-1]-1;
        }
        yz[1]=-1;
    }
    else if(op==2&&x=="W"){
        zy[len]=zy[len-1]+1;
        for(int i=len;i>=2;i--){
            yz[i]=yz[i-1]+1;
        }
        yz[1]=1;
    }
    else if(op==2&&x=="R"){
        zy[len]=zy[len-1];
        for(int i=len;i>=2;i--){
            yz[i]=yz[i-1];
        }
        yz[1]=0;
    }
    int m=0;
    for(int i=1;i<=len;i++){
        if(zy[i]==0||yz[i]==0){
         m=max(m,i);  
        }
        
    }
    cout<<m<<endl;


}
int main(){
    int n;
    cin>>n;
    string str;
    cin>>str;
    len=str.length();
    for( unsigned int i=0;i<str.length();i++){
        if(str[i]=='R'){
            zy[i+1]=zy[i];
        }
        else if(str[i]=='W'){
            zy[i+1]=zy[i]+1;
        }
        else{
            zy[i+1]=zy[i]-1;
        }
    }
    for(unsigned int i=0;i<str.length();i++){
        if(str[len-1-i]=='R'){
            yz[i+1]=yz[i];
        }
        else if(str[len-1-i]=='W'){
            yz[i+1]=yz[i]+1;
        }
        else{
            yz[i+1]=yz[i]-1;
        }
    }
    int mm=0;
    for(int i=1;i<=len;i++){
        if(zy[i]==0||yz[i]==0){
         mm=max(mm,i);  
        }
        
    }
    cout<<mm<<endl;
    // for(int i=1;i<=len;i++){
    //     cout<<zy[i]<<" ";
    // }
    // cout<<endl;
    // for(int i=1;i<=len;i++){
    //     cout<<yz[i]<<" ";
    // }
    while(n--){
        int op;
        string x;
        cin>>op>>x;
        insert(op,x);
        
        
    
    }
    return 0;


    

}