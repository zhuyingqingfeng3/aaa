#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    string temp = "aaabcdaaa!!!";
    int num = count(temp.begin(),temp.end(),'a');
    cout <<"在字符串" << temp << "中，" <<"字母a出现的次数是" << num << endl;
    return 0 ;
}