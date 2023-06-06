// 遍历所有男生
// 让该男生考虑所有心动女生
// 如果当前女生单身，或者该女生的对象能找到备胎，该女生就接受该男生绿了原来男朋友
// 但是该女生找对象时候不能再考虑该女生。如果找不到备胎，只能放弃。
// 只遍历男生就够了
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=510,M=100010;
int h[N],e[M],ne[M],idx;
bool st[N];//st[i]表示i号妹子是不是正在被占据，能否下手，0表示能下手
int match[N];//match[i]储存的是妹子现在的对象的序号
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
bool find(int x){//返回的是序号为x的男生能不能找到一个女孩
    // 遍历所有心动女孩到找到就停或者找完失望离开
    for(int i=h[x];i!=-1;i=ne[i]){
        int j=e[i];
        if(!st[j]){//防止自己占据的女孩又被下手
            st[j]=true;//占据住女孩
            if(match[j]==0||find(match[j])){
                // 单身或者能绿对象就和他在一起并停止寻找
                match[j]=x;
                return true;
            }

        }
    }
    return false;//放弃

}
int n1,n2,m;
int main(){

    scanf("%d%d%d", &n1, &n2, &m);

    memset(h, -1, sizeof h);

    while (m -- )
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
    }

    int res = 0;
    for (int i = 1; i <= n1; i ++ )
    {
        memset(st, false, sizeof st);//给每一个男孩挖墙脚的机会
        if (find(i)) res ++ ;
    }

    printf("%d\n", res);

    return 0;



}
    

