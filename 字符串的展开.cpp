#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    int p1,p2,p3;
    cin>>p1>>p2>>p3;
    string s;
    getline(cin,s);
    for(int i=0;i<s.length();i++){
        if(s[i]=='-'){
           if(s[i+1]-s[i-1]==1){
               s.erase(s.begin()+i);
           }
           else if(s[i+1]-s[i-1]<=0){

           }
           else{
               if(p1==1){
                   
               }
               else if(p1==2){

               }
               else{

               }

               
           }
        }
    }
    
    
}