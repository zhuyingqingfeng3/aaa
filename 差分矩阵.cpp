//差分的套路是先输入a[i]的时候对b[i]进行初始化
// 然后把对a[i]的变化要求转到b[i]中来，时刻记住a[i]是前缀和
// 变b[i]注意自己只要影响该影响的地区，及时消除其他地区的影响
// 然后再求变化过后的b[i]的前缀和就是答案了
#include<iostream>
using namespace std;
const int N=1010;
int n,m,q;
int a[N][N];
int b[N][N];
void insert(int x1,int y1,int x2,int y2,int c){
    b[x1][y1]+=c;//影响的地区是右下方所有区域
    b[x2+1][y1]-=c;
    b[x1][y2+1]-=c;
    b[x2+1][y2+1]+=c;
}//实现b变化导致a[x1][y1]-a[x2][y2]之间所有的元素都加c
int main(){
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
            insert(i,j,i,j,a[i][j]);// 求初始b
        }
    }
    while(q--){
        int x1,y1,x2,y2,c;
        scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&c);
        insert(x1,y1,x2,y2,c);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            b[i][j]=b[i][j]+b[i][j-1]+b[i-1][j]-b[i-1][j-1];
        }
    }//求前缀和
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            printf("%d ",b[i][j]);
        }
        puts("");
    }
    return 0;
    
}