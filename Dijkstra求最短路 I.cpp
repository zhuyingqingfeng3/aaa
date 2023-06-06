// Dijkstra 的整体思路比较清晰
// 即进行n（n为n的个数）次迭代去确定每个点到起点的最小值 最后输出的终点的即为我们要找的最短路的距离

// 所以按照这个思路除了存储图外我们还需要存储两个量
// dist[n] 用于存储每个点到起点的最短距离
// st[n]   用于在更新最短距离时 判断当前的点的最短距离是否确定 是否需要更新
// 每次迭代的过程中我们都先找到当前未确定的最短距离的点中距离最短的点
// int t=-1;       将t设置为-1 因为Dijkstra算法适用于不存在负权边的图
// for(int j=1;j<=n;j++)
// {
//     if(!st[j]&&(t==-1||dist[t]>dist[j])    //该步骤即寻找还未确定最短路的点中路径最短的点
//         t=j;
// }
// 通过上述操作当前我们的t代表就是剩余未确定最短路的点中 路径最短的点
// 而与此同时该点的最短路径也已经确定我们将该点标记
// st[t]=true;
// 然后用这个去更新其余未确定点的最短距离
// for(int j=1;j<=n;j++)
//     dist[j]=min(dist[j],dist[t]+g[t][j]);
// 这里可能有同学要问j如果从1开始的话 会不会影响之前已经确定的点的最小距离
// 但其实是不会 因为按照我们的Dijkstra算法的操作顺序 先确定最短距离的点的距离已经比后确定的要小 所以不会影响
// 当然你也可以在循环判断条件里加上if(!st[i])
// 这里j从1开始只是为了代码的简洁
// 进行n次迭代后最后就可以确定每个点的最短距离
// 然后再根据题意输出相应的 要求的最短距离
#include<iostream>
#include<cstring>
using namespace std;
const int N=510;
int n,m;
int g[N][N];
int dist[N];
bool st[N];
int dijkstra(){
    memset(dist,0x3f,sizeof(dist));//极限最大值不会被更新即便加新值
    dist[1]=0;//初始值
    // n-1次迭代，这里控制的仅仅是次数
    for(int i=0;i<n-1;i++){
        int t=-1;//代表此次迭代下还未找到未确定的点
        // 循环遍历找不确定的并且是dist最小的点的序号
        for(int j=1;j<=n;j++){
            if(!st[j]&&(t==-1||dist[t]>dist[j])){
                t=j;
            }
        }
        // 该利用该点进行更新操作
        for(int j=1;j<=n;j++){
            dist[j]=min(dist[j],dist[t]+g[t][j]);
        }
        st[t]=true;//表示该点确定了
    }
    // 在C++中，0x3f和0x3f3f3f3f都是用来表示正无穷的，
    // 但是它们的区别在于0x3f只能用来表示无权图的最短路，
    // 而0x3f3f3f3f可以用来表示有权图的最短路。
    // 这是因为0x3f3f3f3f是0x3f的平方，
    // 而在有权图中，最短路的长度可能会超过0x3f的平方，
    // 因此需要使用0x3f3f3f3f来表示正无穷。
    if(dist[n]==0x3f3f3f3f){
        return -1;
    }
    return dist[n];
}
int main(){
    scanf("%d%d", &n, &m);

    memset(g, 0x3f, sizeof g);
    while (m -- )
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        //对付自环和重边
        g[a][b] = min(g[a][b], c);
    }

    printf("%d\n", dijkstra());

    return 0;
    

}