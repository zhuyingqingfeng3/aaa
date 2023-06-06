// 启发我们做比值时候结果储存要用double 被除数要用double 除数要用int
#include <iostream>;
using namespace std;
int gcd(int a,int b){
  return b?gcd(b,a%b):a;
}
int main()
{
    double a;
    int  b;
    int c, m, n = 0;
    double min = 100;
    cin >> a >> b >> c;
    double d;
    d = a / b;
    for (double i = 1;i <= c;i++)
    {
        for (int j = 1;j <= c;j++)
        {

            if(gcd((int)i,j)==1){
              double f;
              f = i  / j;
              if (f >= d && ((f - d) <= min))
              {
                m = i;
                n = j;
                min = f - d;
              }

            }
            

        }
    }
    
    cout << m << " " << n;
    // 请在此输入您的代码  1498 902 10
    return 0;
}