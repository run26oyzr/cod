#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

int rand(int l, int r){
    return rand() % (r - l + 1) + l;
}
signed main(){
    int id;
    srand(time(0));
    for (int yanglishu = 1; yanglishu <= 10; yanglishu++){
        int n, m;
        freopen(("./own_competition/C/yang_li/interval" + std::to_string(yanglishu) + ".in").c_str(), "w", stdout);
        if (yanglishu <= 4)
            n = m = 2000;
        else 
            n = m = 1e5;
        cout << n << ' ' << m << endl;
        int opt;
        int l, r, val;
        while(m--){
            opt = rand(1, 2);
            cout << opt << ' ';
            l = rand(1, n);
            r = rand(l, n);
            cout << l << ' ' << r;
            if (opt == 1){
                cout << endl;
            }else{
                val = rand(1, 1000);
                cout << ' ' << val << endl;
            }
        }
    }
    // system("pause");
}