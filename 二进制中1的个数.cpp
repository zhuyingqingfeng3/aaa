// (lowbit) O(nlogn)

// 使用lowbit操作，进行，
// 每次lowbit操作截取一个数字最后一个1后面的所有位，
// 每次减去lowbit得到的数字，直到数字减到0，就得到了最终1的个数，

// lowbit原理
// 根据计算机负数表示的特点，
// 如一个数字原码是10001000，他的负数表示形势是补码，
// 就是反码+1，反码是01110111，加一则是01111000，
// 二者按位与得到了1000，就是我们想要的lowbit操作
#include<iostream>
using namespace std;
int n;
int lowbit(int x){
    return x&-x;
}
int main(){
    cin>>n;
    while (n--)
    {
        int x;
        cin>>x;
        int res=0;
        while(x){
            x-=lowbit(x);
            res++;
        }
        cout<<res<<" ";
        /* code */
    }
    
}