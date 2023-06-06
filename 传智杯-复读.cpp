#include<iostream>
#include<set>
using namespace std;
set<string> p;
int main(){
    string s;
    int size=0;
    int size2=0;
    while(1){
        cin>>s;
        if(s=="0"){
            break;
        }
        else{
            p.insert(s);
            size2=p.size();
            if(size2>size){
                cout<<s;
                size=size2;
            }
        }
    }

}