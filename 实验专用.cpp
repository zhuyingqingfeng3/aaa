#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
using namespace std;
int mofa(int m){
    int s=sqrt(m/2+1);
    return s;
}
int main(){
    cout<<mofa(4);
}