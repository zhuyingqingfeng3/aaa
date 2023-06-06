#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
char m[50];
void D(string &s,char c){
    int index=s.find(c);
    s.erase(s.begin()+index);
}
void I(string &s,char c,char d){
    reverse(s.begin(),s.end());
    int index=s.find(c);
    s.insert(s.begin()+index,d);
    reverse(s.begin(),s.end());

}
void R(string &s,char c,char d){
    for(int i=0;i<s.size();i++){
        if(s[i]==c){
            s[i]=d;
        }
    }
}
int main(){
    string s;
    getline(cin,s);
    getchar();
    string h;
    getline(cin,h);
    for(int i=0;i<h.size();i++){
        if(h[i]!=' '){
            m[i]=h[i];
        }
    }
    for(int i=0;i<50;i++){
        if(m[i]=='D'){
            D(s,m[i+1]);
        }
        else if(m[i]=='I'){
            I(s,m[i+1],m[i+2]);
        }
        else if(m[i]=='R'){
            R(s,m[i+1],m[i+2]);
        
        }
    }
    cout<<s;
}