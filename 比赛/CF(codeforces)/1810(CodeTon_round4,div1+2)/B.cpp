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
        int n;
        read(n);
        if (n % 2 == 0){
            cout << -1 << endl;
            continue;
        }
        for (int i = 0; i <= 31; i++){
            if (n < pow(2, i)){
                cout << i - 1 << endl;
                break;
            }
        }
        bool flag = false;
        for (int i = 31; i >= 1; i--){
            int tmp = (int)(n / pow(2, i)) % 2;
            if (tmp != 0 && (!flag)) flag = true;
            if (flag) cout << tmp + 1 << ' ';
        }
        cout << endl;
    }
    return 0;
}