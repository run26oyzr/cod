#include <bits/stdc++.h>
using namespace std;
#define int long long
template<typename T> inline void read(T &x) {
	x = 0;
	char c = getchar();
	for (;!isdigit(c); c = getchar());
	for (;isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
}
int vis[(int)(4 * 1e4)];
int pos[(int)(4 * 1e4)];
signed main(){
    int cnt = 0;
    int n, q;
    int T;
    read(T);
    while(T--){
        int n;
        read(n);
        int tot = 0;
        int tot2 = 0;
        int all = 0;
        for (int i = 2; i <= 4 * 1e4; i++){
            if (n == 1) break;
            if (n % i == 0){
                while(n % i == 0){
                    n /= i;
                    if (!vis[i]) pos[++tot2] = i;
                    vis[i]++;
                    all ++;
                }
            }
        }
        if (n != 1 && all == 0){
            cout << n << endl;
            continue;
        }
        int ans = 0;
        if (n != 1){
            int minnum = 1;
            int now = 0;
            int mul = 1;
            for (int i = 1; i <= tot2; i++){
                mul *= pos[i];
            }
            ans += mul * minnum * n;
            for (int i = 1; i <= tot2; i++){
                vis[pos[i]] -= 1;
            }
            all -= tot2;
        }
        while(all > 0){
            int minnum = 1e9;
            int now = 0;
            int mul = 1;
            for (int i = 1; i <= tot2; i++){
                if (vis[pos[i]] == 0) continue;
                else now++;
                minnum = min(minnum, vis[pos[i]]);
                mul *= pos[i];
            }
            ans += mul * minnum;
            for (int i = 1; i <= tot2; i++){
                if (vis[pos[i]] == 0) continue;
                vis[pos[i]] -= minnum;
            }
            all -= now * minnum;
        }
        cout << ans << endl;
    }
    return 0;
}