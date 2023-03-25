#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
int n, p;
int qpow(int x, int y, int mod){
    int ans = 1;
    int a = x;
    while(y){
        if (y & 1){
            ans *= a; ans %= mod;
        }
        a *= a; a %= mod;
        y >>= 1;
    }
    return ans;
}
int get_phi(int x){
    int res = 0;
    for (int i = 1; i < x; i++){
        if(__gcd(i, x) == 1) res++;
    }
    return res;
}
signed main(){
    freopen("function.in", "r", stdin);
    freopen("function.out", "w", stdout);
    int T;
    scanf("%lld", &T);
    while(T--){
        scanf("%lld %lld", &n, &p);
        if (n <= 1e5){
            long long ans = 2;
            while(n--){
                ans *= ans;
                ans %= p;
            }
            printf("%lld\n", ans);
        }
        else{
            int phi = get_phi(p);
            int m = qpow(2, n, phi);
            int ans = qpow(2, m, p);
            printf("%lld\n", ans);
        }
    }

    return 0;
}