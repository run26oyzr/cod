#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

void sheng_cheng_shu_ju(int n, int t){
    cout << n << " " << t << "\n";
    for (int i = 1; i <= n; i++){
        cout << rand() % (long long)(1e9) + 1 << " ";
    }
    int op, l, r, x;
    for (int i = 1; i <= t; i++){
        op = rand() % 2 + 1;
        cout << op << " ";
        if (op == 1){
            l = rand() % n + 1;
            r = l + (rand() % 10);
            cout << l << " " << r << " ";
        }
        if (op == 2){
            l = rand() % n + 1;
            r = rand() % (n - l + 1) + l;
            cout << l << " " << r << " ";
            cout << rand() % (long long)(1e9) + 1;
        }
        cout << "\n";
    }
}
signed main(){
    int id;
    // srand((unsigned)time(NULL));
    for (int yanglishu = 1; yanglishu <= 10; yanglishu++){
        id = 0;
        srand(time(0));
        Sleep(1000);
        // char *name;
        // name[++id] = 'D';
        // name[++id] = (char)(yanglishu + '0');
        // name[++id] = '.'; name[++id] = 'i'; name[++id] = 'n';
        // cout << name << endl;
        // cout << ("D" + std::to_string(yanglishu) + ".in").c_str();
        freopen(("./own_competition/D/yang_li/gcd" + std::to_string(yanglishu) + ".in").c_str(), "w", stdout);
        if (yanglishu <= 5)
            sheng_cheng_shu_ju(1000, 1000);
        else 
            sheng_cheng_shu_ju(300000, 100000);
    }
    // system("pause");
}