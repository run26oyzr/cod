#include <bits/stdc++.h>
using namespace std;
mt19937 mt_rand(time(0));
int rnd(int l, int r){
    return mt_rand() % (r - l + 1) + l;
}
string exepos = "D:\\app\\exe\\";
string nowpos = "D:\\0_OI\\own_contest\\term2\\D\\";
int main()
{   
    int tot;
    while (1) //一直循环，直到找到不一样的数据
    {
        system((exepos + "generator.exe " + to_string(rnd(1e4 - 100, 1e4)) + " " + to_string(rnd(1e4 - 100, 1e4)) + " 0 " + to_string(rnd(5, 15)) + " > " + nowpos + "in.in").c_str());
        system("D:\\app\\exe\\bao_li.exe < .\\term2\\D\\in.in > .\\term2\\D\\bao_li.out");
        system("D:\\app\\exe\\std.exe < .\\term2\\D\\in.in > .\\term2\\D\\std.out");
        if (system("fc .\\term2\\D\\bao_li.out .\\term2\\D\\std.out")){ //当 fc 返回1时，说明这时数据不一样
            cout << "error";
            break;                          //不一样就跳出循环
        }
        tot++;
        cout << tot << endl;
    }
    // system("cls");
    cout << tot;
    system("pause");
    return 0;
}
