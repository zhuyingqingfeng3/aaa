#include<iostream>
#include<vector>
using namespace std;
struct k
{
    vector<int> p;
    int num=0;
    /* data */
};
int n,m;
k juzhen[60][60];
int cctime=1;
int main(){
    int x,y;
    cin>>n>>m>>x>>y;
    char op[1010];
    cin>>op;
    juzhen[x][y].p.push_back(1);
    for(int i=0;i<m-1;i++){
        cctime++;
        if(op[i]=='N'){
            y=y+1;
            juzhen[x][y].p.push_back(cctime);
        }
        else if(op[i]=='S'){
            y--;
            juzhen[x][y].p.push_back(cctime);
        }
        else if(op[i]=='E'){
            x++;
            juzhen[x][y].p.push_back(cctime);
        }
        else{
            x--;
            juzhen[x][y].p.push_back(cctime);
        }



    }
    int qian[1010];
    qian[0]=0;
    for(int i=1;i<1010;i++){
        qian[i]=qian[i-1]+i;
    }
    for(int i=n;i>=1;i--){
        for(int j=1;j<=n;j++){
             if(juzhen[i][j].p.size()==0){
                juzhen[i][j].num=qian[m];
             }
             else{
                int qia=1;
                
                for(int ci=0;ci<juzhen[i][j].p.size();ci++){
                    juzhen[i][j].num+=qian[juzhen[i][j].p[ci]-qia];
                    qia=juzhen[i][j].p[ci];
                }
                juzhen[i][j].num+=qian[m-qia];
             }
             
        }
        
    }
    for(int i=n;i>=1;i--){
        for(int j=1;j<=n;j++){
            cout<<juzhen[j][i].num<<" ";
        }
        if(i==1){

        }
        else{
cout<<endl;
        }
        
    }

}