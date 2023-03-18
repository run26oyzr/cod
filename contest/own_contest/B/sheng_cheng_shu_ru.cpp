#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

void sheng_cheng_shu_ju(int n, int maxnum){
    cout << n << "\n";
    int x;
    for (int i = 1; i <= n; i++){
        cout << rand() % maxnum + 1 << ' ';
    }
    cout << "\n";
    for (int i = 1; i <= n; i++){
        cout << rand() % maxnum + 1 << ' ';
    }
}
void start(){
    int id;
    for (int yanglishu = 1; yanglishu <= 10; yanglishu++){
        id = 0;
        srand(time(0));
        Sleep(600);
        freopen(("./own_competition/B/yang_li/multiset" + std::to_string(yanglishu) + ".in").c_str(), "w", stdout);
        if (yanglishu <= 5)
            sheng_cheng_shu_ju(300, 100000);
        else 
            sheng_cheng_shu_ju(300000, 1000000000);
    }
}
signed main(){
	for (int yanglishu = 1; yanglishu <= 10; yanglishu++){
        srand(time(0));
        Sleep(1000);
        freopen(("./own_competition/B/yang_li/multiset" + std::to_string(yanglishu) + ".in").c_str(), "w", stdout);
        if (yanglishu <= 5){
			sheng_cheng_shu_ju(1000, 1000);
		} 
        else{
			sheng_cheng_shu_ju(300000, 100000);
		}
    }
	return 0;
}