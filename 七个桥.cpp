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
	}//�����ڽӾ���Ĵ��� 
	for(int i=0;i<n;i++){
		for(int y=0;y<n;y++){
			map[i][y]=0;
		}
	}//����ȫ��0��
	zuo z;
	 for(int i=0;i<m;i++){
	 	cin>>z.a>>z.b;
	 	map[z.a-1][z.b-1]=1;
	 	map[z.b-1][z.a-1]=1;
	 }//�����ڽӾ���
	 int* du=new int[n];//����ÿһ�еĶ� 
	 int sum=0;
	 for(int i=0;i<n;i++){
	 	for(int y=0;y<n;y++){
	 		sum=sum+map[i][y];
		 }
		 du[i]=sum;
		 sum=0;
	 } //��ÿһ�еĶ��Ƕ��� 
	 for(int i=0;i<n;i++){
	 	if(du[i]%2!=0){
	 		cout<<"0";
	 		break;
	 		exit();
		 }
	 }//�ж϶����ǲ���ż��
	 int *yi=new int[n];
	 for(int i=0;i<n;i++){
	 	yi[i]=map[0][i];
	 } //��һ��ժ���� �����ж��ܷ�ȫ������ 
	 for(int i=1;i<n;i++){
	 	
	 } 
    
	
}
