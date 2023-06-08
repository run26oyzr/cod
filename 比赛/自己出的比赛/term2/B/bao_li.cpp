#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
const int mod = 998244353;
int c[maxn];
signed main(){
    int n, q;
    scanf("%lld %lld", &n, &q);
    for(int i = 1; i <= n; i++) cin >> c[i];
    while(q--){
        int op, l, r, val;
        cin >> op >> l >> r;
        if(op == 1){
            cin >> val;
            for(int i = 1; i <= n; i++)
                if(l * i <= n && n <= (r + 1) * i - 1){
                    c[i] = (c[i] + val) % mod;
                }
        }else{
            int ans = 0;
            for(int i = 1; i <= n; i++) 
                if(l * i <= n && n <= (r + 1) * i - 1){
                    // cout << "c[i]:" << c[i] << endl;
                    ans = (ans + i * c[i]) % mod;
                }
            cout << ans << endl;
        }
    }
    return 0;
}
