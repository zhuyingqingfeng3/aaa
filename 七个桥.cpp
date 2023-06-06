#include<iostream>
using namespace std;
struct zuo{
	int a,b;
};
int main(){
    int n,m;
    cin>>n>>m;
    int**map=new int*[n];
    for(int i=0;i<n;i++){
    	map[i]=new int[n];
	}//进行邻接矩阵的创建 
	for(int i=0;i<n;i++){
		for(int y=0;y<n;y++){
			map[i][y]=0;
		}
	}//进行全部0化
	zuo z;
	 for(int i=0;i<m;i++){
	 	cin>>z.a>>z.b;
	 	map[z.a-1][z.b-1]=1;
	 	map[z.b-1][z.a-1]=1;
	 }//输入邻接矩阵
	 int* du=new int[n];//储存每一行的度 
	 int sum=0;
	 for(int i=0;i<n;i++){
	 	for(int y=0;y<n;y++){
	 		sum=sum+map[i][y];
		 }
		 du[i]=sum;
		 sum=0;
	 } //看每一行的度是多少 
	 for(int i=0;i<n;i++){
	 	if(du[i]%2!=0){
	 		cout<<"0";
	 		break;
	 		exit();
		 }
	 }//判断度数是不是偶数
	 int *yi=new int[n];
	 for(int i=0;i<n;i++){
	 	yi[i]=map[0][i];
	 } //第一行摘出来 用来判断能否全部相连 
	 for(int i=1;i<n;i++){
	 	
	 } 
    
	
}
