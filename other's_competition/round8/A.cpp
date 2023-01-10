#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
int qpow(int x, int y){
    int a = x;
    int res = 1;
    while(y){
        if (y & 1){
            res *= a;
            res %= mod;
        }
        a *= a;
        a %= mod;
        y >>= 1;
    }
    return res;
}
signed main(){
    // freopen("lucky.in", "r", stdin);
    // freopen("lucky.out", "w", stdout);
    int T;
    cin >> T;
    cout << "My answer is:" << endl;
    while(T--){
        int n;
        cin >> n;
        int ans = 7 * qpow(8, n - 1) + 9 * qpow(10, n - 1);
        ans *= qpow(2, mod - 2);
        ans %= mod;
        if (n == 1) ans = 9;
        printf("%lld\n", ans);
    }
    return 0;
}