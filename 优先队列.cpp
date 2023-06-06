#include<iostream>
#include<queue>
#include<vector>
using namespace std;
priority_queue<int,vector<int>,greater<int>>q;
// greater是按照从小到大的顺序自动排序，top（）返回最小值
// less返回最大值
// 参数有三部分组成，类型，储存容器，排序方式

int main(){
    q.push(1);
    q.push(2);
    cout<<q.top();
}