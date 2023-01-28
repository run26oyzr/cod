#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 105;
template<typename T> inline void read(T &x) {
	x = 0;
	char c = getchar();
	for (;!isdigit(c); c = getchar());
	for (;isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
}
int vis[maxn];
int t[maxn][maxn];
int ans[maxn];
signed main(){
    int T;
    read(T);
    while(T--){
        int n;
        read(n);
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n - 1; j++){
                cin >> t[i][j];
            }
        }
        int last;
        for (int i = 1; i <= n; i++){
            vis[t[i][n - 1]]++;
            if (vis[t[i][n - 1]] > 1){
                last = t[i][n - 1];
                ans[n] = last;
                break;
            }
        }
        for (int i = 1; i <= n; i++){
            if (t[i][n - 1] != last){
                for (int j = 1; j < n; j++) ans[j] = t[i][j];
                break;
            }
        }
        for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
        cout << endl;
    }
    return 0;
}