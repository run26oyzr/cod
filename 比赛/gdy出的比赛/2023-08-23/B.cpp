#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 6, maxlog = 21;
int a[maxn];
int lastpos[maxn], f[maxn][maxlog];
int main(){
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        lastpos[i] = n + 1;
    f[n + 1][0] = n + 1;
    for (int i = n; i >= 1; i--){
        f[i][0] = min(f[i + 1][0], lastpos[a[i]]);
        lastpos[a[i]] = i;
    }
    for (int i = n; i >= 1; i--)
        for (int k = 1; k < maxlog; k++){
            if (f[i][k - 1] > n || f[i][k - 1] <= 0)
                break;
            f[i][k] = f[f[i][k - 1]][k - 1];
        }
    int l, r;
    while (q--){
        scanf("%d %d", &l, &r);
        if (l > r)
            swap(l, r);
        int u = l;
        int ans = 2 * (r - l + 1) - 2;
        for (int k = maxlog - 1; k >= 0; k--){
            if (f[u][k] <= r && f[u][k] != 0){
                u = f[u][k];
                ans -= (1 << k);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}