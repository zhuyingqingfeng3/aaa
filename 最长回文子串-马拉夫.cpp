// 明显的马拉车算法，在O(n)的复杂度下找出一个字符串的最长回文子串的长度
// 与位置
// 核心思想是开头$开头防止越界，然后字母之间穿加#来避免讨奇偶性
// 核心就是能够重复利用之间得到的结果，如果结果不能利用完全或者没有
// 就也只能慢慢匹配
#include<iostream>
#include<cstring>
using namespace std;
const int N=1e6+5;
char str[N*2];//重构后的字符串
char s[N];//原字符串
int p[N*2];//p[i]的含义是在新的字符串中以i为中心（包括i）的回文半径长度
// 例如#a# p[a]=2
int manachar(char *s,char *str,int *p){
    int len;
    str[0]='$';//防止越界
    str[1]='#';//1号位置的填充
    for(len=0;s[len];len++){//构造新字符串
        str[len*2+2]=s[len];
        str[len*2+3]='#';
    }
    // len也要变一变
    len=len*2+2;
    str[len]='\0';//结尾处理
    int rcen=0,rlen=0,id=0,mx=0;
    // rcen表示最长回文子串的中心的位置 rlen表示半径（看上文解释）
    // id表示最右侧子串的中心位置 mx表示最右侧子串位置加1（充当边界判断）
    for(int i=0;str[i];i++){
        p[i]=min(mx-i,p[2*id-i]);//保守获取之前的有用信息
        while(str[i-p[i]]==str[i+p[i]]){
            p[i]++;//继续匹配并且更新p[i]的范围
        }
        // 判断是否要更新又边界与又中心
        if(i+p[i]>mx){
            mx=i+p[i];
            id=i;
        }
        // 判断是否更新最长半径与其中心
        if(p[i]>rlen){
            rlen=p[i];
            rcen=i;
        }
    }
    // 返回的是真正子串的长度是半径-1（因为扩大两倍的关系）
    return rlen-1;
}
int main(){
    cin>>s;
    cout<<manachar(s,str,p);
    return 0;
}