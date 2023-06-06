#include<iostream>
using namespace std;
struct k
{
    int time=0;
    int num=0;
    /* data */
};
int n,m,x,y;
k juzhen[60][60];
void add(int a,int b){
    if(a==x&&b==y){
        juzhen[a][b].time=0;
    }
    else{
        juzhen[a][b].time++;
        juzhen[a][b].num+=juzhen[a][b].time;
    }
}
char op[1010];
int main(){
    cin>>n>>m>>x>>y;
    cin>>op;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            add(i,j);
        }
    }
    for(int i=0;i<m-1;i++){
         if(op[i]=='N'){
            y=y+1;
            
        }
        else if(op[i]=='S'){
            y--;
            
        }
        else if(op[i]=='E'){
            x++;
            
        }
        else{
            x--;
            
        }
        for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            add(i,j);
        }
    }

    }
    for(int i=n;i>=1;i--){
        for(int j=1;j<=n;j++){
            cout<<juzhen[j][i].num<<" ";
        }
        cout<<endl;

    }



}