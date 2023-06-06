// “表达式求值”问题，两个核心关键点：

// （1）双栈，一个操作数栈，一个运算符栈；

// （2）运算符优先级，栈顶运算符，和，即将入栈的运算符的优先级比较：
// 如果栈顶的运算符优先级低，新运算符直接入栈

// 如果栈顶的运算符优先级高，先出栈计算，新运算符再入栈

// 这个方法的时间复杂度为O(n)，整个字符串只需要扫描一遍
#include<iostream>
#include<unordered_map>
#include<stack>
#include<string>
using namespace std;
stack<int> num;//储存操作数
stack<char> op;//储存运算符
unordered_map<char,int> h={{'+',1},{'-',1},{'*',2},{'/',2}};
// 上面是优先级，同样的符号前面的优先级大


// 关键运算算法
void eval(){
    int a=num.top();//第二个操作数（逆着取的）
    num.pop();

    int b=num.top();//第一个操作数
    num.pop();

    char p=op.top();//运算符
    op.pop();
    int r=0;
    if(p=='+'){
       r=b+a;
    }
    if(p=='-'){
        r=b-a;
    }
    if(p=='*'){
        r=b*a;
    }
    if(p=='/'){
        r=b/a;
    }
    num.push(r);
    
}
int main(){
    string s;
    cin>>s;
    // 扫描s
    for(int i=0;i<s.size();i++){
        // 检测到数字开头
        if(isdigit(s[i])){
            int x=0,j=i;
            while(j<s.size()&&isdigit(s[j])){
                x=x*10+s[j]-'0';
                j++;
            }
            i=j-1;//记得调整i的位置
            num.push(x);//获得数压进去
        }
        // 左括号没有优先级，直接入栈
        else if(s[i]=='('){
            op.push(s[i]);
        }
        // 遇到又括号，计算括号里面的
        else if(s[i]==')'){
            // 又括号不入栈，直接计算到左括号
            while(op.top()!='('){
                eval();
            }
            op.pop();//左括号出栈
        }
        else{
            while(op.size()&&h[op.top()]>=h[s[i]]){
                eval();//先算优先级大的
            }
            op.push(s[i]);//操作符进栈
        }
    }
    while(op.size()){
        eval();//进行剩余的计算
    }
    cout<<num.top()<<endl;
    return 0;
}
