#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
using namespace std;
struct point
{
    /* data */
    double x;
    double y;
    double r;
    int flag=0;
};
double dis(point a,point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
point m[1001];
point k[1001];
void dfs(point h,int n){
    for(int j=0;j<n;j++){
        if(dis(h,m[j])<=h.r&&m[j].flag==0){
            m[j].flag=1;
            dfs(m[j],n);
        }
    }
}
int main(){
    int n,p;
    cin>>n>>p;
    for(int i=0;i<n;i++){
        cin>>m[i].x>>m[i].y>>m[i].r;
    }
    for(int i=0;i<p;i++){
        cin>>k[i].x>>k[i].y>>k[i].r;
    }
    
    for(int i=0;i<p;i++){
        int yuan=0,xian=0;
        for(int j=0;j<n;j++){
            if(m[j].flag==0){
                yuan=yuan+1;
            }
        }
       for(int j=0;j<n;j++){
           if(m[j].flag==0&&dis(m[j],k[i])<=k[i].r){
               m[j].flag=1;
               dfs(m[j],n);
           }
       }
       for(int j=0;j<n;j++){
            if(m[j].flag==0){
                xian=xian+1;
            }
        }
        cout<<yuan-xian<<endl;
    }
    return 0;
}