#include<stdio.h>
#include<string.h>
#define max 505
int arr[max][max],kul[max][max];
int main()
{
    int n,m,k,val,i,j,p;
    scanf("%d%d%d",&n,&m,&val);
    memset(kul,0,sizeof(kul));
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            scanf("%d",&arr[i][j]);
            kul[i][j]=kul[i-1][j]+kul[i][j-1]+arr[i][j]-kul[i-1][j-1];
        }
    }
    int flag=0,mi=0;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            for(k=i; k<=n; k++)
            {
                for(p=j; p<=m; p++)
                {
                    if(kul[k][p]-kul[i-1][p]-kul[k][j-1]+kul[i-1][j-1]<=val)
                    {
                        flag++;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
    }
     
    printf("%d",flag);
    return 0;
}