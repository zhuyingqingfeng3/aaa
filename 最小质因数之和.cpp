//  �����ɸʽ��������
// ����f[i]Ҫô��������Ҫô���Ǳ�֮ǰ���������¹�
// ����������Ļ�����ô����Ϊf[i]=i�ͺã�Ȼ�����������ȥ��������û��
// �����µ����������õ��ж�if(f[i])���ж��Ƿ񱻸��¹�
#include<iostream>
using namespace std;
const int N=3e6+10;
int f[N+3];
long long s[N+3];//��ֵ����ϴ���long long
int main(){
    int n;
    cin>>n;
    for(int i=2;i<=N;i++){
        if(f[i]){
            continue;
        }
        else{
            f[i]=i;
            for(int j=2;j*i<=N;j++){
                if(f[i*j]){
                    continue;
                }
                else{
                    f[i*j]=i;
                }
            }
        }
    }
    for(int i=2;i<=N;i++){
        s[i]=s[i-1]+f[i];
    }
    while(n--){
        int k;
        scanf("%d",&k);
        printf("%lld\n",s[k]);
    }
    return 0;
}


