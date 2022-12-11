#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn], sum[maxn];
signed main(){
    int n, t;
    cin >> n >> t;
    int all = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        all += a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    int T = t % all, ans = 0;
    for (int i = n; i >= 1; i--){
        if (sum[i] <= T) {ans = i; break;}
    }
    cout << ans + 1 << ' ' << T - sum[ans];
    return 0;
}