#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 15, maxk = 12;
int dis[maxn][maxn];
int f[maxn][1 << maxk];
signed main(){
    int n, m;
    cin >> n >> m;
    int u, v, c;
    memset(dis, 0x3f, sizeof(dis));
    while (m--){
        cin >> u >> v >> c;
        dis[u][v] = min(dis[u][v], c);
        dis[v][u] = min(dis[v][u], c); 
    }
    memset(f, 0x3f, sizeof(f));
    for (int i = 1; i <= n; i++)
        f[0][1 << (i - 1)] = 0; 
    for (int s = 0; s < (1 << n); s++){
        for (int t = s; t; t = s & (t - 1)){
            // int ss = t;
            // for (int i = 1; i <= n; i++){
            //     if (!((t >> (i - 1)) & 1))
            //         continue;
            //     for (int j = 1; j <= n; j++){
            //         if (dis[i][j] < 1e8)
            //             ss |= (1 << (j - 1));
            //     }
            // }
            // if ((s ^ ss) & s) continue;
            int num = 0;
            int ss = s ^ t;
            for (int i = 1; i <= n; i++){
                if (!((ss >> (i - 1) & 1)))
                    continue;
                int minnum = 1e9;
                for (int j = 1; j <= n; j++){
                    if (!(t >> (j - 1) & 1))
                        continue;
                    minnum = min(minnum, dis[j][i]);
                }
                num += minnum;
            }
            for (int i = 1; i <= n; i++)
                f[i][s] = min(f[i][s], f[i - 1][t] + num * i);
        }
    }
    int ans = 1e9;
    for (int i = 1; i <= n; i++)
        ans = min(ans, f[i][(1 << n) - 1]);
    cout << ans;
    return 0;
}