#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e4, maxs = 5e5 + 5;
int a[maxn], b[maxn], s[maxn];
int f[maxs];
signed main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++)
        b[i] = a[i + 1] - a[i];
    n--;
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + b[i];
    memset(f, 0x3f, sizeof(f));
    f[0] = 0;
    for (int i = 1; i <= n; i++){
        if (b[i] == 0)
            continue;
        for (int j = maxs - 1; j >= 0; j--){
            if (f[j] >= 1e18)
                continue;
            f[j + i * b[i]] = min(f[j + i * b[i]], f[j] + 2 * j * b[i] + i * b[i] * b[i]);
            f[j + s[i]] = min(f[j + s[i]], f[j] + s[i] * s[i]);
            f[j] = 1e18;
        }
    }
    int ans = 1e18;
    for (int i = 0; i < maxs; i++){
        if (f[i] < 1e18)
            ans = min(ans, (n + 1) * f[i] - i * i);
    }
    cout << ans;
    return 0;
}