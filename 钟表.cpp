// 思路比较简单，就是不断的遍历每一分每一秒每一小时总共也就6*60*60
// 分别求出每一刻时候分针，时针，秒针对应的从0点开始的度数
// 做减法再求绝对值再与360-A与A求最小值就好
// 关键点在于要明白是由秒求分，由分求时，知道他们之间的倍数关系
// 秒一秒钟走m*360/60  分由自己的整数部分加秒/60  时由整数部分加分/12
// 注意用double来储存，绝对值用fabs  最后因为是double 所以判断相等
// !是小于一定的值而不是用==  f和m不能等于60
#include<iostream>
#include<cmath>
#include<math.h>
using namespace std;
int main(){
    for(int s=1;s<=6;s++){
        for(int f=0;f<60;f++){
            for(int m=0;m<60;m++){
                double dm=360*m/60;
                double df=360*f/60+dm/60;
                double ds=360*s/12+df/12;
                double A=fabs(df-ds);
                double B=fabs(df-dm);
                A=min(A,360-A);
                B=min(B,360-B);
                if(fabs(A-2*B)<=1e-10){
                   cout<<s<<" "<<f<<" "<<m<<endl;
                }
            }
        }
    }
    return 0;
}