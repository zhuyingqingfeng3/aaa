#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int res=0;
bool is_zu(string s){
    char a[26];
    for(int i=0;i<26;i++){
        a[i]=0;
    
    }
    for(int i=0;i<s.size();i++){
        a[s[i]-'a']++;
    }
    int num=0;
    for(int i=0;i<26;i++){
        if(a[i]%2==1){
            num++;
        }
    }
    if(s.length()%2==1){
        if(num==1){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        if(num==0){
            return true;
        }
        else{
            return false;
        }
    }
        
}
int getnum(string s,int position,char c){
    int num;
    for(int i=position;i>=(s.size()-1)/2;i--){
        if(s[i]==c){
            num=i;
            break;
        }
    }
    return num;
}
//生成一个函数判断字符串是都是回文字符串
bool is_hui(string s){
    int num=0;
    for(int i=0;i<s.size();i++){
        if(s[i]==s[s.size()-1-i]){
            num++;
        }
    }
    if(num==s.size()){
        return true;
    }
    else{
        return false;
    }
}
void tiao(string &s,int position,char c){
    int num=getnum(s,position,c);
    for(int i=num;i<position;i++){
        char zhong=s[i];
        s[i]=s[i+1];
        s[i+1]=zhong;
        res++;
        if(is_hui(s)){
            break;
        }
    }
}

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    if(!is_zu(s)){
        cout<<"Impossible";
    }
    else{
        
        for(int i=0;i<=(s.size()-1)/2;i++){
            if(s[i]!=s[s.size()-1-i]){
                tiao(s,s.size()-1-i,s[i]);
                
                
            }
        }
        cout<<res;
    }
      
      
    }
    