#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

class DoubleColorBall {
private:
    vector<int> red_balls;
    vector<int> blue_balls;
    vector<int> random_red_balls;
    vector<int> random_blue_balls;

public:
    void generate_random_numbers() {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis_red(1, 33);
        uniform_int_distribution<> dis_blue(1, 16);
        for (int i = 0; i < 6; i++) {
            int num = dis_red(gen);
            while (find(red_balls.begin(), red_balls.end(), num) != red_balls.end()) {
                num = dis_red(gen);
            }
            red_balls.push_back(num);
        }
        blue_balls.push_back(dis_blue(gen));
        random_red_balls = red_balls;
        random_blue_balls = blue_balls;
    }

    void get_user_numbers() {
        red_balls.clear();
        blue_balls.clear();
        cout << "请输入6个红球号码（1-33之间的整数）：" << endl;
        for (int i = 0; i < 6; i++) {
            int num;
            while (true) {
                cin >> num;
                if (num < 1 || num > 33) {
                    cout << "请输入1-33之间的整数！" << endl;
                    continue;
                }
                if (find(red_balls.begin(), red_balls.end(), num) != red_balls.end()) {
                    cout << "请勿重复输入！" << endl;
                    continue;
                }
                red_balls.push_back(num);
                break;
            }
        }
        int num;
        cout << "请输入1个蓝球号码（1-16之间的整数）：" << endl;
        while (true) {
            cin >> num;
            if (num < 1 || num > 16) {
                cout << "请输入1-16之间的整数！" << endl;
                continue;
            }
            blue_balls.push_back(num);
            break;
        }
    }

    void compare_numbers() {
        int red_count = 0;
        int blue_count = 0;
        for (int i = 0; i < 6; i++) {
            if (find(random_red_balls.begin(), random_red_balls.end(), red_balls[i]) != random_red_balls.end()) {
                red_count++;
            }
        }
        if (blue_balls[0] == random_blue_balls[0]) {
            blue_count = 1;
        }
        cout << "您猜对了" << red_count << "个红球，" << blue_count << "个蓝球。" << endl;
        cout << "随机生成的号码为：" << endl;
        cout << "红球：";
        for (int i = 0; i < 6; i++) {
            cout << " " << random_red_balls[i];
        }
        cout << endl;
        cout << "蓝球： " << random_blue_balls[0] << endl;
    }

    void play() {
        generate_random_numbers();
        get_user_numbers();
        compare_numbers();
    }
};
int main(){
    DoubleColorBall game;
game.play();
return 0;
}