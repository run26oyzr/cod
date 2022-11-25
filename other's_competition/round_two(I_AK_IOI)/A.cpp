#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 105;
int pre[maxn][maxn][maxn], a[maxn][maxn][maxn];
signed main(){
    int n, m, p, l;
    cin >> n >> m >> p >> l;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            for (int k = 1; k <= p; k++){
                scanf("%d", &a[i][j][k]);
            }
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            for (int k = 1; k <= p; k++){
                pre[i][j][k] = pre[i][j][k - 1] + pre[i][j - 1][k] - pre[i][j - 1][k - 1] + a[i][j][k];
            }
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            for (int k = 1; k <= p; k++){
                pre[i][j][k] += pre[i - 1][j][k];
            }
        }
    }
    long long ans = -1e18;
    for (int i = 1; i <= n - l + 1; i++){
        for (int j = 1; j <= m - l + 1; j++){
            for (int k = 1; k <= p - l + 1; k++){
                int i_ = i + l - 1, j_ = j + l - 1, k_ = k + l - 1;
                ans = max(ans, pre[i_][j_][k_] - pre[i - 1][j_][k_] - pre[i_][j - 1][k_] - pre[i_][j_][k - 1] + pre[i - 1][j - 1][k_] + pre[i - 1][j_][k - 1] + pre[i_][j - 1][k - 1] - pre[i - 1][j - 1][k - 1]);
            }
        }
    }
    cout << ans;
    system("pause");
    return 0;
}