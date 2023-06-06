#include<iostream>
using namespace std;
int a[3000];
int main(){
    a[0]=1;
    int h1,h2,fen1,fen2;
    for(int h=0;h<=23;h++){
        for(int i=0;i<=59;i++){
            if(h<=9){
               fen1=i/10;
               fen2=i-fen1*10;
               if(fen2-fen1==fen1-h&&(h*60+i)!=0){
                  a[h*60+i]=a[h*60+i-1]+1;
                //   cout<<h<<":"<<i<<endl;
               }
               if(fen2-fen1!=fen1-h){
                a[h*60+i]=a[h*60+i-1];
               }
            }
            else{
                h1=h/10;
                h2=h%10;
                fen1=i/10;
               fen2=i-fen1*10;
               if(fen2-fen1==fen1-h2&&fen1-h2==h2-h1){
                  a[h*60+i]=a[h*60+i-1]+1;
                //   cout<<h<<":"<<i<<endl;
               }
               else{
                a[h*60+i]=a[h*60+i-1];
               }

            }
        }
    }
    int n;
    cin>>n;
    int cishu=n/(24*60);
    n=n%(24*60);
    cout<<a[24*60-1]*cishu+a[n];


}