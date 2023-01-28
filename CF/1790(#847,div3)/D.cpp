#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2 * 1e5 + 5;
template<typename T> inline void read(T &x) {
	x = 0;
	char c = getchar();
	for (;!isdigit(c); c = getchar());
	for (;isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
}
int a[maxn];
signed main(){
    int T;
    read(T);
    while(T--){
        int n;
        read(n);
        for (int i = 1; i <= n; i++) read(a[i]);
        sort(a + 1, a + n + 1);
        int cnt = 0;
        int ans = 0;
        int pos = 0;
        while(cnt < n){
            while(a[pos] == 0) pos++;
            if (pos > n) break;
            int now = a[pos];
            a[pos] = 0;
            cnt++;
            ans++;
            for (int i = pos + 1; i <= n; i++){
                if (a[i] == now + 1){
                    now = a[i];
                    a[i] = 0;
                    cnt++;
                }
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}