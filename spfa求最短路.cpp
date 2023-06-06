// 终于来到SPFA算法了！之前已经说明过了Bellman_ford算法 ,我们今天说明的SPFA算法仅仅只是对该算法的一个优化。
// Bellman_ford算法会遍历所有的边，但是有很多的边遍历了其实没有什么意义，我们只用遍历那些到源点距离变小的点所连接的边即可，只有当一个点的前驱结点更新了，该节点才会得到更新；因此考虑到这一点，我们将创建一个队列每一次加入距离被更新的结点。

// 值得注意的是
// 1) st数组的作用：判断当前的点是否已经加入到队列当中了；已经加入队列的结点就不需要反复的把该点加入到队列中了，就算此次还是会更新到源点的距离，那只用更新一下数值而不用加入到队列当中。
// 即便不使用st数组最终也没有什么关系，但是使用的好处在于可以提升效率。
// 2) SPFA算法看上去和Dijstra算法长得有一些像但是其中的意义还是相差甚远的:

// 1] Dijkstra算法中的st数组保存的是当前确定了到源点距离最小的点，且一旦确定了最小那么就不可逆了(不可标记为true后改变为false)；SPFA算法中的st数组仅仅只是表示的当前发生过更新的点，且spfa中的st数组可逆(可以在标记为true之后又标记为false)。顺带一提的是BFS中的st数组记录的是当前已经被遍历过的点。
// 2] Dijkstra算法里使用的是优先队列保存的是当前未确定最小距离的点，目的是快速的取出当前到源点距离最小的点；SPFA算法中使用的是队列(你也可以使用别的数据结构),目的只是记录一下当前发生过更新的点。

// !3) ⭐️Bellman_ford算法里最后return-1的判断条件写的是dist[n]>0x3f3f3f3f/2;而spfa算法写的是dist[n]==0x3f3f3f3f;其原因在于Bellman_ford算法会遍历所有的边，因此不管是不是和源点连通的边它都会得到更新；但是SPFA算法不一样，它相当于采用了BFS，因此遍历到的结点都是与源点连通的，因此如果你要求的n和源点不连通，它不会得到更新，还是保持的0x3f3f3f3f。

// !4) ⭐️ Bellman_ford算法可以存在负权回路，是因为其循环的次数是有限制的因此最终不会发生死循环；但是SPFA算法不可以，由于用了队列来存储，只要发生了更新就会不断的入队，因此假如有负权回路请你不要用SPFA否则会死循环。

// !5) ⭐️由于SPFA算法是由Bellman_ford算法优化而来，在最坏的情况下时间复杂度和它一样即时间复杂度为 O(nm)

//  ，假如题目时间允许可以直接用SPFA算法去解Dijkstra算法的题目。(好像SPFA有点小小万能的感觉?)

//! 6) ⭐️求负环一般使用SPFA算法，方法是用一个cnt数组记录每个点到源点的边数，一个点被更新一次就+1，一旦有点的边数达到了n那就证明存在了负环。
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
const int N=1e5+10;
typedef pair<int,int>PII;
int h[N],e[N],ne[N],w[N],idx;
int dist[N];
bool st[N];
int n,m;
void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}
int spfa(){
    queue<PII>q;
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    q.push({0,1});
    st[1]=true;//判断是否压入了
    while(q.size()){
        PII p=q.front();
        q.pop();
        st[p.second]=false;
        for(int i=h[p.second];i!=-1;i=ne[i]){
            int j=e[i];
            if(dist[j]>dist[p.second]+w[i]){
                dist[j]=dist[p.second]+w[i];
                if(!st[j]){
                    q.push({dist[j],j});
                    st[j]=true;
                }
            }
        }
    }
    return dist[n];
}
int main(){
    scanf("%d%d",&n,&m);
    memset(h,-1,sizeof h);
    while(m--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
    }
    int res=spfa();
    if(dist[n]==0x3f3f3f3f) puts("impossible");
    else printf("%d",res);

    return 0;
}
