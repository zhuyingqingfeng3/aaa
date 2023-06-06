#include<iostream>
using namespace std;
const int N=100003;
// 大于100000的最小质数，作为模的话最好是质数
int h[N],e[N],ne[N],idx;
void init(){
    for(int i=0;i<N;i++){
        h[i]=-1;
    }
}
// 初始化
void insert(int x){
    int k=(x%N+N)%N;
    // 求余数的方法，这样做是防止有负数
    e[idx]=x;
    ne[idx]=h[k];
    h[k]=idx++;
    // 拉链法，就是每个对应点上拉出一个链表来查找
}
// 一般的哈希表方法为求模
bool find(int x){
    int k=(x%N+N)%N;
    for(int i=h[k];i!=-1;i=ne[i]){
        if(e[i]==x){
            return true;
            break;
        }
    }
    return false;
}
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
            if(find(x)){
                cout<<"Yes"<<endl;
            }
            else{
                cout<<"No"<<endl;
            }
        }
    }
    return 0;

}
