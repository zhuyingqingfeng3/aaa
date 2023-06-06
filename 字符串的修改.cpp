#include<iostream>
#include<string>
using namespace std;

//生成一个可以返回字符串a与字符串b最长公共序列长度的函数
int LCS(string a,string b){
    int n=a.size(),m=b.size();
    int dp[200][200];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0||j==0)
                dp[i][j]=0;
            else if(a[i-1]==b[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][m];
}




int main(){
    string a,b;
    cin>>a>>b;
    int num=LCS(a,b);
    int yu=b.length()-num;
    int res=0;
    res=res+yu;
    if(a.length()>num+yu){
        res=res+a.length()-num-yu;
    }
    cout<<res;
}