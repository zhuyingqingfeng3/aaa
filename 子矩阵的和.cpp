#include<iostream>
using namespace std;
const int N=1010;
int n,m,q;
int a[N][N];//矩阵
int s[N][N];//矩阵前缀和
int main(){
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            s[i][j]=a[i][j]+s[i][j-1]+s[i-1][j]-s[i-1][j-1];//前缀和公式
        }
    }//求前缀和
    while (q--)
    {
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        printf("%d\n",s[x2][y2]-s[x2][y1-1]-s[x1-1][y2]+s[x1-1][y1-1]);//局部矩阵和
    }
    return 0;
    
}