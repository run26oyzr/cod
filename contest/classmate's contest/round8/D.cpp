#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5, mod = pow(2, 30);
int t[maxn];
signed main(){
    freopen("bitwise.in", "r", stdin);
    freopen("bitwise.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) scanf("%lld", &t[i]);
    int m;
    cin >> m;
    int opt, l, r, val;
    while(m--){
        scanf("%lld", &opt);
        scanf("%lld %lld", &l, &r);
        if (opt == 5){
            int ans = 0;
            for (int i = l; i <= r; i++){
                ans += t[i];
            }
            printf("%lld\n", ans);
        }
        else{
            scanf("%lld", &val);
            for (int i = l; i <= r; i++){
                if (opt == 1) t[i] &= val;
                if (opt == 2) t[i] |= val;
                if (opt == 3) t[i] ^= val;
                if (opt == 4){
                    t[i] <<= val;
                    t[i] %= mod;
                }
            }
        }
    }
    return 0;
}