/***
 * f[i][j]: 跳到第 i 行，第 j 列时的总方案数
 * 则 f[i][j] = f[i-1][j-1] + f[i][j-1] + f[i+1][j-1] + f[i-1][j-3] + f[i][j-3] + f[i+1][j-3] + ......
 * 可以发现 f[i][j-2] 包含且仅仅包含 f[i-1][j-3] + f[i][j-3] + f[i+1][j-3] + ...... 
 * 所以转移方程可以优化为 f[i][j] = f[i-1][j-1] + f[i][j-1] + f[i+1][j-1] + f[i][j-2]
 * 构造列向量：
 * f[1][j]
 * ...
 * f[n][j]
 * f[1][j-1]
 * ...
 * f[n][j-1]
 * 不难发现，j 维可以去掉
 * 
 * 注意：
 *  i=1,j=3 时，转移方程中的 f[1][3-2] 并不是再之前的 f[i-1][3-3] + f[i][3-3] + f[i+1][3-3] 等的和，而是马的初始位置，规定状态为1
 *  所以所有转移方程中包含 f[1][3] 的项都被多计算了1，故答案应减去 f[1][3] 出现的次数
 *  f[1][3] 出现的次数即为 以 (1,3) 为开始， (n,m) 为结束的马的总方案数，即 f[n][m-2]
 * 
 * 所以，最终答案 = f[n][m] - f[n][m-2]
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 30011;
int n;
struct Matrix{
    static const int Size = 105;
    int a[Size][Size];
    Matrix(){memset(a, 0, sizeof(a));}
    Matrix operator * (const Matrix &T)const{
        Matrix res;
        for (int i = 1; i < Size; i++){
            for (int j = 1; j < Size; j++){
                int tmp = 0LL;
                for (int k = 1; k < Size; k++){
                    tmp = (tmp + a[i][k] * T.a[k][j]) % mod;
                }
                res.a[i][j] = tmp;
            }
        }
        return res;
    } 
};
Matrix qpow(Matrix A, long long b){
    Matrix res;
    if (b < 0) return res;
    for (int i = 1; i <= 2 * n; i++)
        res.a[i][i] = 1;
    while(b){
        if (b & 1) res = res * A;
        A = A * A;
        b >>= 1;
    }
    return res;
}
signed main(){
    int t;
    cin >> n >> t;
    Matrix A;
    for (int i = 1; i <= n; i++){
        if (i != 1) A.a[i][i - 1] = 1;
        A.a[i][i] = 1;
        if (i != n) A.a[i][i + 1] = 1;
        A.a[i][i + n] = 1;
    }
    for (int i = 1; i <= n; i++){
        A.a[i + n][i] = 1;
    }
    // for (int i = 1; i <= 2 * n; i++){
    //     for (int j = 1; j <= 2 * n; j++){
    //         cout << A.a[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    Matrix ans = qpow(A, t - 1);
    // for (int i = 1; i <= 2 * n; i++){
    //     for (int j = 1; j <= 2 * n; j++){
    //         cout << ans.a[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    Matrix tmp = qpow(A, t - 3);
    cout << ans.a[n][1] << endl;
    cout << ((ans.a[n][1] - tmp.a[n][1]) % mod + mod) % mod;
    return 0;
}