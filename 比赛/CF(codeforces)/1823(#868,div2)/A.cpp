#include <bits/stdc++.h>
using namespace std;
#define int long long
template<typename T> inline void read(T &x) {
	x = 0;
	char c = getchar();
	for (;!isdigit(c); c = getchar());
	for (;isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
}
signed main(){
    int T;
    read(T);
    while(T--){
        int n, k;
        read(n); read(k);
        int x, y;
        bool flag = false;
        for (int i = 0; i <= n / 2; i++){
            x = i;
            y = n - i;
            if (x * (x - 1) + y * (y - 1) == k * 2){
                cout << "YES" << endl;
                for (int i = 1; i <= x; i++) cout << 1 << ' ';
                for (int i = 1; i <= y; i++) cout << -1 << ' ';
                cout << endl;
                flag = true;
                break;
            }
        }
        if (!flag)cout << "NO" << endl;
    }
    return 0;
}