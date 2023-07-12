/***
 * f[i][j][k][p]: 二进制第 i 位, 到 a 序列第 j 位, 二进制中 1 的数量为 k, 第 j 位二进制对下一位的进位为 p 时的权值和
 * f[i][j][k][p] * {v_j}^x * C_{n - i}^{x}  -> f[i + 1][j + x][k + (x + p) \bmod 2][\lfloor \dfrac{x + p}{2} \rfloor] （x 表示 a_x 为 i 的个数）
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 35, maxm = 105;
const int mod = 998244353;
int f[maxm][maxn][maxn][maxn];
int v[maxm], C[maxn][maxn];
int Pow[maxm][maxn];
int count1(int x){
    int res = 0;
    while(x){
        if (x & 1) res++;
        x >>= 1;
    }
    return res;
}
signed main(){
    int n, m, K;
    cin >> n >> m >> K;
    for (int i = 0; i <= m; i++) cin >> v[i];
    for (int i = 0; i <= n; i++) C[i][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    f[0][0][0][0] = 1;
    for (int i = 0; i <= m; i++){
        Pow[i][0] = 1;
        for (int j = 1; j <= n; j++) Pow[i][j] = Pow[i][j - 1] * v[i] % mod;
    }
    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++)
            for (int k = 0; k <= K; k++)
                for (int p = 0; p <= n / 2; p++){
                    for (int x = 0; x <= n - j; x++){
                        f[i + 1][j + x][k + (x + p) % 2][(x + p) / 2] += f[i][j][k][p] * Pow[i][x] % mod * C[n - j][x] % mod;
                        f[i + 1][j + x][k + (x + p) % 2][(x + p) / 2] %= mod;
                    }
                }
    int ans = 0;
    for (int k = 0; k <= K; k++)
        for (int p = 0; p <= n / 2; p++){
            if (k + count1(p) <= K){
                // cout << m + 1 << ' ' << n << ' ' << k << ' ' << p << ' ' << f[m + 1][n][k][p] << endl;
                ans += f[m + 1][n][k][p];
                ans %= mod;
            }
        }
    cout << ans;
    return 0;
}