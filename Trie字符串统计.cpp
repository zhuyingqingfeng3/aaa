#include<iostream>
#include<unordered_map>//单独的头文件
#include<string>
using namespace std;
unordered_map<string,int> s;
int main(){
    int n;
    cin>>n;
    while(n--){
        char op;
        string m;
        cin>>op>>m;
        if(op=='I'){
            if(s.find(m)==s.end()){//能够判断是否存在这个元素，如果不存在，返回的迭代器是end
                s.insert({m,1});//注意插入插入用的是insert，不是push
            }
            else{
                s[m]++;
            }
        }
        else{
            if(s.find(m)==s.end()){
                printf("%d\n",0);
            }
            else{
                printf("%d\n",s[m]);
            }
        }
        
    }
}