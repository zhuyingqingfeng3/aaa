#include<iostream>
#include<algorithm>
using namespace std;
class student{
    private:
    int number;
    string name;
    int age;// 计算得到
    int birthday_year;
    int birthday_month;
    int birthday_day;
    int yuwen;
    int english;
    int math;
    public:
    student(){}
    student(int number1,string name1,int birthday_year1,int birthday_month1,int birthday_day1,int yuwen1,int english1,int math1){
       number=number1;
       name=name1;
       birthday_year=birthday_year1;
       birthday_month=birthday_month1;
       birthday_day=birthday_day1;
       yuwen=yuwen1;
       english=english1;
       math=math1;
       

    }
    void show_all(){
        cout<<"学号："<<number<<" "<<"姓名："<<name<<endl;
    }
};
int main(){
    cout<<"哈哈哈";
    return 0;
}
