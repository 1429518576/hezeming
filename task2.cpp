#include <random>
#include <iostream>
using namespace std;

int random()
{
    random_device seed;//硬件生成随机数种子
    ranlux48 engine(seed());//利用种子生成随机数引擎
    uniform_int_distribution<> distrib(INT_MIN, INT_MAX);//设置随机数范围，并为均匀分布
    int random = distrib(engine);//随机数
    return random;
}
//bool end() { return (Robot1 <= 0) || (Robot2 <= 0); }

string rule(int &Blood1, int &Blood2)
{
    int r = 0;
    //int r=random();
    //while(r%2==0&&r%3==0)//与同学讨论到这里可以不用循环，用递归（积累到了一种算法）
    do
    {
        r = random();
        cout << r << endl;
        if (r % 3 == 0 && r % 2 != 0)
        {
            Blood2 -= 10;
            return "射击";
        }
        else if (r % 2 == 0 || r % 6 == 0) { return "没有子弹打出"; }
        else if (r % 2 != 0 && r % 3 != 0)
        {
            Blood1 -= 40;
            cout <<"炸膛," <<"再次转盘"<< endl;
        }//return string rule (int Blood1,int Blood2);
    } while (r % 2 != 0 && r % 3 != 0);
}
int main()
{
    int Robot1 = 200, Robot2 = 200;
    while (Robot1 > 0 && Robot2 > 0)
    {
        cout << "1号机器人回合" << rule(Robot1, Robot2) << endl;
        cout << "Robot1=" << Robot1 << ":" << "Robot2=" << Robot2 << endl;
        getchar();
        cout << "2号机器人回合" << rule(Robot2, Robot1) << endl;
        cout << "Robot1=" << Robot1 << ":" << "Robot2=" << Robot2 << endl;
        getchar();
    }
}
