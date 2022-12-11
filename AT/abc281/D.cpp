#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 109;
int f[maxn][maxn][maxn], a[maxn];
signed main(){
    int n, k, d;
    cin >> n >> k >> d;
    for (int i = 1; i <= n; i++) cin >> a[i];
    memset(f, -1e9, sizeof(f));
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= i; j++){
            f[i][j][0] = 0;
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= i; j++){
            for (int K = 0; K < d; K++){
                f[i][j][K] = max(f[i - 1][j][K], f[i - 1][j - 1][(K - a[i - 1] + d) % d] + a[i - 1]);
            }
        }
    }
    cout << max((long long)(-1), f[n][k][0]);
    return 0;
}