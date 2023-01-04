#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e6 + 5, maxval = 1e4 + 5;
int p[maxn], q[maxn], Sum[maxn], bucket[maxval];
int n;
signed main(){
    freopen("station.in", "r", stdin);
    freopen("station.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++){
        scanf("%lld %lld", &p[i], &q[i]);
        if (q[i] > 9880) cout << "YES" << endl;
        bucket[q[i]]++;
    }
    for (int i = 1; i <= maxval; i++) Sum[i] = Sum[i - 1] + bucket[i] * i;
    int ans = 0;
    for (int i = 1; i <= n; i++){
        if (p[i] > maxval) p[i] = maxval;
        int tot = Sum[p[i]];
        if (p[i] >= q[i]) tot -= q[i];
        ans = max(ans, tot);
    }
    cout << ans;
    return 0;
}