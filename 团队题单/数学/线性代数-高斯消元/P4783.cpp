//费马小定理求逆元
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 805;
int a[maxn][maxn];
int qpow(int x, int y){
    int xx = x;
    int res = 1;
    while(y){
        if (y & 1) res = res * xx % mod;
        xx = xx * xx % mod;
        y >>= 1;
    }
    return res;
}
signed main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
        a[i][i + n] = 1;
    }
    for (int i = 1; i <= n; i++){
        if (a[i][i] == 0){
            for (int j = i + 1; j <= n; j++){
                if (a[j][i] != 0){
                    // swap(a[i], a[j]);
                    for (int k = 1; k <= 2 * n; k++)
                        swap(a[i][k], a[j][k]);
                    break;
                }
            }
            if (a[i][i] == 0){
                cout << "No Solution";
                return 0;
            }
        }
        int del = qpow(a[i][i], mod - 2);
        for (int j = 1; j <= 2 * n; j++)
            a[i][j] = a[i][j] * del % mod;
        for (int j = 1; j <= n; j++){
            if (i == j) continue;
            del = a[j][i];
            for (int k = 1; k <= 2 * n; k++){
                a[j][k] = (a[j][k] - a[i][k] * del) % mod;
            }
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = n + 1; j <= 2 * n; j++){
            cout << (a[i][j] % mod + mod) % mod << ' ';
        }
        cout << endl;
    }
    return 0;
}