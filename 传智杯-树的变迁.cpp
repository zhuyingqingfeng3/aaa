#include<iostream>
using namespace std;
const int N=1e5+10;
int p[N],cnt[N],cnt2[N];
struct edge
{
    int a;
    int b;
    /* data */
};
edge e[N];
int find(int x){
    while(1){
        if(p[x]==x){
            return x;
        }
        else{
            x=p[x];
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        p[i]=i;
        cin>>cnt[i];
        cnt2[i]=cnt[i];
    }
    for(int i=1;i<=n-1;i++){
        cin>>e[i].a>>e[i].b;
        p[e[i].b]=e[i].a;
        cnt[e[i].a]+=cnt[e[i].b];
    }
    for(int i=0;i<m;i++){
        int op;
        cin>>op;
        if(op==1){
            int idx;
            cin>>idx;
            p[e[idx].b]=e[idx].b;
            int x=e[idx].a;
            while(1){
                if(p[x]!=x){
                    cnt[x]-=cnt[e[idx].b];
                    x=p[x];
                }
                if(p[x]==x){
                    cnt[x]-=cnt[e[idx].b];
                    break;
                }
            }


        }
        else if(op==2){
            int idx,val;
            cin>>idx>>val;
            int idx2=idx;
            
            while(1){
                if(p[idx]!=idx){
                    cnt[idx]=cnt[idx]-cnt2[idx]+val;
                    idx=p[idx];
                }
                if(p[idx]==idx){
                    cnt[idx]=cnt[idx]-cnt2[idx]+val;
                    break;
                }
            }
            cnt2[idx2]=val;
        }
        else{
            int x;
            cin>>x;
            x=find(x);
            // cout<<x<<endl;
            cout<<cnt[x]<<endl;
        }
    }
    // for(int i=1;i<=n;i++){
    //     cout<<p[i]<<" ";
    // }
    // cout<<endl;
    // for(int i=1;i<=n;i++){
    //     cout<<cnt[i]<<" ";
    // }

}