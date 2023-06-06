#include<iostream>
#include<string>
using namespace std;
string a[3];
//生成一个可以对a从小到大排序的函数
void sort(string a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                string temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}
int main(){
    for(int i=0;i<3;i++)
    {
        cin>>a[i];
    }
    sort(a,3);
    for(int i=0;i<3;i++)
    {
        cout<<a[i]<<endl;
    }
    return 0;

}