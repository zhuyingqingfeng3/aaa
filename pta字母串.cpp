#include<iostream>
using namespace std;
void pan(string s){
    int flag=1;
    for(int i=0;i<s.length()-1;i++){
        if(s[i]>='a'&&s[i]<='z'){
           if(s[i]-s[i+1]!=32&&s[i]-s[i+1]!=1){
            flag=0;
            cout<<"N"<<endl;
            break;
           }
        }
        else{
            if(s[i+1]-s[i]!=1&&s[i+1]-s[i]!=32){
                flag=0;
                cout<<"N"<<endl;
                break;
            }
        }
    }
    if(flag){
        cout<<"Y"<<endl;
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        pan(s);
    }
}