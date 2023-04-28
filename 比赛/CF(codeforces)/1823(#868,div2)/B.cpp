#include <bits/stdc++.h>
using namespace std;
#define int long long
template<typename T> inline void read(T &x) {
	x = 0;
	char c = getchar();
	for (;!isdigit(c); c = getchar());
	for (;isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
}
int a[(int)(2 * 1e5 + 5)];
signed main(){
    int T;
    read(T);
    while(T--){
        int n, k;
        read(n); read(k);
        for (int i = 1; i <= n; i++) read(a[i]);
        int cnt = 0;
        for (int i = 1; i <= k; i++){
            for (int j = 0; i + j * k <= n; j++){
                int tmp = a[i + j * k] % k;
                if (tmp == 0) tmp = k;
                if (tmp != i){
                    cnt++;
                }
            }
        }
        if (cnt == 0) cout << 0 << endl;
        else if (cnt == 2) cout << 1 << endl;
        else cout << -1 << endl;
    }
    return 0;
}