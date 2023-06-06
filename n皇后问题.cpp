//这个跟排列数字那个题目本质是一样的，一共就n个空位置
// 采用深度遍历，只不过一个能不能用是看st，皇后问题是看
// 列，斜线，反斜线能不能用，每一层的每一个位置都试一试，
// 合适的话遍历下一层，但是记得恢复现场来给下一列机会

#include<iostream>
using namespace std;
const int N=20;
int n;
char g[N][N];
bool col[N],dg[N],udg[N];
void dfs(int u){
    if(u==n){
        for(int i=0;i<n;i++){
            puts(g[i]);
            
        }
        puts("");
        return;
        
    }
    else{
        for(int i=0;i<n;i++){
            if(!col[i]&&!dg[u+i]&&!udg[n-u+i]){
                g[u][i]='Q';
                col[i]=true;
                dg[u+i]=true;
                udg[n-u+i]=true;
                dfs(u+1);
                g[u][i]='.';
                col[i]=false;
                dg[u+i]=false;
                udg[n-u+i]=false;

            }
        }
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            g[i][j]='.';
        }
    }
    dfs(0);
    return 0;
    

}
// 这种思想就是类似于全排列的思想，知道有几层的情况下的dfs