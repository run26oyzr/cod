#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5 * 1e5 + 5;
long double f[maxn];
int a[maxn];
long double w(int i, int j){
    return a[j] + sqrt(i - j);
}
void sv(int l, int r, int x, int y){
    if (l > r || x > y) return;
    int mid = (l + r) >> 1, p = -1;
    long double maxnum = 0;
    for (int i = x; i <= min(mid, y); i++){
        if (w(mid, i) > maxnum){
            maxnum = w(mid, i);
            p = i;
        }
    }
    f[mid] = max(f[mid], maxnum - a[mid]);
    sv(l, mid - 1, x, p);
    sv(mid + 1, r, p, y);
}
signed main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sv(1, n, 1, n);
    // for (int i = 1; i <= n; i++) cout << f[i] << ' ';
    // cout << endl;
    for (int i = 1; i <= n / 2; i++){
        swap(a[i], a[n - i + 1]);
        swap(f[i], f[n - i + 1]);
    }
    sv(1, n, 1, n);
    // for (int i = n; i >= 1; i--) cout << f[i] << ' ';
    // cout << endl;
    for (int i = n; i >= 1; i--) cout << (int)(ceil(f[i])) << endl;
    return 0;
}