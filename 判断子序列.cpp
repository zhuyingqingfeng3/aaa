// 1.j指针用来扫描整个b数组，i指针用来扫描a数组。
// 若发现a[i] == b[j]，则让i指针后移一位。
// 2.整个过程中，j指针不断后移，
// 而i指针只有当匹配成功时才后移一位，若最后若i == n，则说明匹配成功。
#include<iostream>
using namespace std;
const int N=1e5+10;
int a[N],b[N];
int n,m;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=m;i++){
        scanf("%d",&b[i]);
    }
    int j=0;
    for(int i=1;i<=m;i++){
        if(j+1<=n&&a[j+1]==b[i]){
            j++;
        }
    }
    if(j==n){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
    return 0;
}