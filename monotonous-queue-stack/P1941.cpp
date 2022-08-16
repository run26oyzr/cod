#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5, maxm = 1e3 + 5;
int x[maxn], y[maxn];
int f[maxn][maxm];
int pos[maxn];
int vis[maxn];
struct node{
    int p, l, h;
    bool operator <(const node T)const{
        return p < T.p;
    }
}t[maxn];
int main(){
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++){
        cin >> x[i] >> y[i];
    }
    for (int i = 1; i <= k; i++){
        cin >> t[i].p >> t[i].l >> t[i].h;
        vis[t[i].p] = 1;
        pos[t[i].p] = i;
    }
    sort(t + 1, t + k + 1);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            f[i][j] = 1e9;
        }
    }
    for (int i = 1; i <= m; i++) f[1][i] = 0; 
    for (int i = 2; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (vis[i])
                if (t[pos[i]].l >= j || t[pos[i]].h <= j){
                    continue;
                }
            if (j + y[i - 1] <= m) f[i][j] = min(f[i][j], f[i][j + y[i - 1]]);
            for (int k = 1; k * x[i - 1] <= j; k++){
                if (j - x[i - 1] <= 0) continue;
                f[i][j] = min(f[i][j], f[i][j - x[i - 1] * k] + k);
            }
        }
    }
    node now;
    for (int i = 1; i <= k; i++){
        now = t[i];
        int p = now.p, l = now.l, h = now.h;
        int flag = 0;
        for (int j = l + 1; j < h; j++){
            if (f[p][j] < 1e9) {flag = 1; break;}
        }
        if (!flag){
            cout << 0 << endl << i - 1;
            system("pause");
            return 0;
        }
    }
    int ans = 1e9;
    for (int i = 1; i <= m; i++){
        ans = min(ans, f[n][i]);
    }
    cout << 1 << endl << ans;
    system("pause");
    return 0;
}