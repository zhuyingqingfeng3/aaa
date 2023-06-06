#include<iostream>
using namespace std;
const int N=3000;
int a[N];
bool pan3(int n){
    int a=n/100;
    int b=(n-a*100)/10;
    int c=n-a*100-b*10;
    if(c-b==b-a){
        return true;
    }
    else{
        return false;
    }
}
bool pan4(int n){
    int a=n/1000;
    int b=(n-a*1000)/100;
    int c=(n-a*1000-b*100)/10;
    int d=n-a*1000-b*100-c*10;
    if(c-b==b-a==d-c){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    a[0]=1;
    for(int i=1;i<=2359;i++){
        if(i%100>59){
            a[i]=a[i-1];
        }
        else{
            if(i<1000){
                if(pan3(i)){
                    a[i]=a[i-1]+1;
                }
                else{
                    a[i]=a[i-1];
                }
            }
            else{
                if(pan4(i)){
                    a[i]=a[i-1]+1;

                }
                else{
                    a[i]=a[i-1];
                }
            }
        }
    }
    int n;
    cin>>n;
    int cishu=n/(24*60);
    n=n%(24*60);
    int h=n/60;
    int fen=n%60;
    
    cout<<pan4(2345);

}