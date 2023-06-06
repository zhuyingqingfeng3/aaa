// 总结一下心得体会，就是这种后面会受到前面影响的，一定是有一个变量来储存
// 全局的或者阶段性的，从而指导后面的
// 这个题目你可以理解为有很多楼层（有编号），但是你只能住编号比你自身号码
// 相同或者更高的，a数组储存的就是你不断变化住的楼层的编号
// b[i]储存的是经由i楼层（询问了b[i]往上至少走几层可能有空楼层）
// 每当有数来询问，就++，因为来询问的都是跟楼层编号相同的数，不断的++储存
// 就可以告诉后来者直接跳到几层，跳完了再询问再跳，直到找到空楼层
#include<iostream>
#include<cstring>
using namespace std;
const int N=1e5+10;
const int M=1e6+10;
int a[N],b[M];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
      cin>>a[i];
      // 跳跃过程
      while(b[a[i]]){
        b[a[i]]++;
        a[i]+=(b[a[i]]-1);
      }
      // 完成后记得更新新楼层
      b[a[i]]++;
      // a[i]储存的是最新的楼层编号
      cout<<a[i]<<" ";
    }
    return 0;
}