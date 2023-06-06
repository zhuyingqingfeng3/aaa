#include<iostream>
#include<cstring>
using namespace std;
const int N=200003;
// 一般蹲坑法开的数组是需要数组大小的2倍多的质数
const int null=0x3f3f3f3f;
// null为超过10的9次方的一个数，代表脱离的数据范围表示为空
int h[N];
void init(){
    memset(h,null,sizeof h);
}
int find(int x){
    int k=(x%N+N)%N;
    while(h[k]!=null&&h[k]!=x){
        k++;
        if(k==N){
            k=0;
        }
        // 这个保证是循环，找到尽头没有找到的话，就返回头继续找
    }
    // 寻找坑位的方法，首先看有没有坑位，再看如果有的话是不是自己预定的，如果不是，就看下一个坑位
    return k;
}
// 这个函数返回的是x的安装的地方或者该安装的地方
void insert(int x){
    h[find(x)]=x;
    
}
// 插入操作，直接在该安装的地方安装上就好，h[k]储存的是数而不像拉链法储存的是指针
bool query(int x){
    if(h[find(x)]==null){
        return false;
    }
    else{
        return true;
    }

}
// 判断该安装的地方是否有就好

int main(){
    init();
    int n;
    cin>>n;
    while(n--){
        string op;
        int x;
        cin>>op>>x;
        if(op=="I"){
            insert(x);
        }
        else{
            if(query(x)){
                cout<<"Yes"<<endl;
            }
            else{
                cout<<"No"<<endl;
            }
        }
    }
    return 0;

}