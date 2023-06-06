#include<iostream>
#include<set>
using namespace std;
set<int> s;
int n;
int main(){
    cin>>n;
    while(n--){
        string op;
        int a;
        cin>>op>>a;
        if(op=="I"){
            s.insert(a);
        }
        else{
            if(s.count(a)==0){
                cout<<"No"<<endl;
            }
            else{
                cout<<"Yes"<<endl;
            }
        }
    }
    return 0;
    
}