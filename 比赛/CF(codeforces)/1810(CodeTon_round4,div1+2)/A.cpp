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
    int n;
    while(T--){
        read(n);
        bool flag = true;
        int x;
        for (int i = 1; i <= n; i++){
            read(x);
            // cout << x << ' ';
            if (x <= i && flag){
                flag = false;
                cout << "YES" << endl;
            }
        }
        if (flag) cout << "NO" << endl;
    }
    return 0;
}