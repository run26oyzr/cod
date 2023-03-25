/**
 * a[i]升序
 * dp不可行的情况
 * f[i][j]: 最长木棍为 a[i]， 次长为 a[j] 的所有方案中木棍个数和（集合元素个数和)
 * c[i][j]: 最长木棍为 a[i]， 次长为 a[j] 的方案数
 * 不可行答案对应的权值和：
 *  for i = 1~n //选出的木棍中最长木棍的下标
 *      for j = 1~i-1 //选出的木棍中第二长的木棍下标
 *          res += f[i][j] * a[i]
 * 所有情况的答案（包括不可行）：
 *  for i = 1~n //选出的木棍中最长木棍的下标
 *      for j = 1~i //选出的个数
 *          ans += a[i] * j * C(i - 1, j - 1)
 * 最终答案 = 总答案-不可行答案:
 *         = ans - tmp
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5005;
const int mod = 998244353;
int f[maxn][maxn], c[maxn][maxn];
int a[maxn]; 
int inv[maxn], jie_cheng[maxn], inv_jie_cheng[maxn];
void init(){
    inv[1] = 1;
    for (int i = 2; i <= 5000; i++){
        inv[i] = ((((-mod / i) * inv[mod % i]) % mod) + mod) % mod;
    }
    jie_cheng[0] = 1;
    inv_jie_cheng[0] = 1;
    for (int i = 1; i <= 5000; i++){
        jie_cheng[i] = (jie_cheng[i - 1] * i) % mod;
        inv_jie_cheng[i] = (inv_jie_cheng[i - 1] * inv[i]) % mod;
    }
}
int C(int n, int m){
    if (n - m < m) m = n - m;
    if (m == 0) return 1;
    // cout << n << ' ' << m << ' ' << jie_cheng[n] << ' ' << inv_jie_cheng[n - m] << ' ' << inv_jie_cheng[m] << endl;
    return ((jie_cheng[n] * inv_jie_cheng[n - m] % mod) * inv_jie_cheng[m]) % mod;
}
signed main(){
    init();
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    int tmp = 0;
    for (int i = 1; i <= n; i++){
        f[i][0] = c[i][0] = 1;
    }
    for (int i = 1; i <= n; i++){
        int k = i + 1;
        for (int j = 0; j < i; j++){
            if (j != 0) f[i][j] = (f[i][j] + f[i - 1][j]) % mod, c[i][j] = (c[i][j] + c[i - 1][j]) % mod;
            while(a[i] + a[j] > a[k] && k <= n) k++;
            if (k <= n) f[k][i] = (f[k][i] + f[i][j] + c[i][j]) % mod, c[k][i] = (c[k][i] + c[i][j]) % mod;
            // cout << i << ' ' << j << ' ' << f[i][j] << endl;
            tmp = (tmp + f[i][j] * a[i]) % mod; 
        }
    }
    int tmp2 = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= i; j++){
            tmp2 = (tmp2 + (a[i] * j) % mod * C(i - 1, j - 1)) % mod;
            // cout << i << ' ' << j << ' ' << tmp2 << endl;
        }
    }
    // cout << tmp2 << ' ' << tmp << endl;
    int ans = tmp2 - tmp;
    cout << (ans + mod) % mod;
    return 0;
}