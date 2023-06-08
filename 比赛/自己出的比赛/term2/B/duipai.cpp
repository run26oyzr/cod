#include <bits/stdc++.h>
using namespace std;
mt19937 mt_rand(time(0));
int rnd(int l, int r){
    return mt_rand() % (r - l + 1) + l;
}
string exepos = "D:\\app\\exe\\";
string nowpos = "D:\\0_OI\\own_contest\\term2\\B\\";
int main()
{   
    int tot;
    while (1) //一直循环，直到找到不一样的数据
    {
        system((exepos + "generator.exe " + to_string(rnd(4900, 5000)) + " " + to_string(rnd(4900, 5000)) + " > " + nowpos + "in.in").c_str());
        system("D:\\app\\exe\\bao_li.exe < .\\term2\\B\\in.in > .\\term2\\B\\bao_li.out");
        system("D:\\app\\exe\\std.exe < .\\term2\\B\\in.in > .\\term2\\B\\std.out");
        if (system("fc .\\term2\\B\\bao_li.out .\\term2\\B\\std.out")){ //当 fc 返回1时，说明这时数据不一样
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
