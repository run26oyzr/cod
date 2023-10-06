#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5 * 1e5 + 5, maxm = 1e6 + 5, mod = 1e9 + 7;
int n, m;
int e[maxn], v[maxn], esum[maxn];
struct Graph{   
    struct Node{
        int v, next;
        int tag;
        bool del;
    }t[maxm << 1], T[maxn << 1];
    int tot = 1, h[maxn];
    void addEdge(int u, int v){
        t[++tot].v = v;
        t[tot].next = h[u];
        h[u] = tot;
    }
    int tot2 = 0, H[maxn];
    void addEdge2(int u, int v){
        T[++tot2].v = v;
        T[tot2].next = H[u];
        H[u] = tot2;
    }
    int bccnum = 0;
    int dfn[maxn], low[maxn], dep = 0;
    void tarjan(int u){
        dfn[u] = low[u] = ++dep;
        for (int i = h[u]; i; i = t[i].next){
            int v = t[i].v;
            if (t[i].tag == -1)
                continue;
            t[i ^ 1].tag = -1;
            if (!dfn[v]){
                tarjan(v);
                low[u] = min(low[v], low[u]);
                if (low[v] > dfn[u]){
                    t[i].del = t[i ^ 1].del = true;
                }
            }
            else low[u] = min(dfn[v], low[u]);
        }
    }
    int bcc[maxn];
    void dfs(int u){
        v[bccnum]++;
        bcc[u] = bccnum;
        for (int i = h[u]; i; i = t[i].next){
            int v = t[i].v;
            if (bcc[v] || t[i].del)
                continue;
            dfs(v);
        }
    }
    void Suo_Dian(){
        for (int i = 1; i <= n; i++)
            if (!dfn[i])
                tarjan(i);
        for (int i = 1; i <= n; i++)
            if (!bcc[i]){
                ++bccnum;
                dfs(i);
            }
        for (int u = 1; u <= n; u++){
            for (int i = h[u]; i; i = t[i].next){
                int v = t[i].v;
                if (bcc[u] != bcc[v]){
                    if(i & 1){
                        addEdge2(bcc[u], bcc[v]);
                        addEdge2(bcc[v], bcc[u]);
                    }
                }else{
                    e[bcc[u]]++;
                }
            }
        }
        for (int i = 1; i <= bccnum; i++){
            e[i] /= 2;
        }
    }
    void dfs(int u, int fa){
        esum[u] = e[u];
        for (int i = H[u]; i; i = T[i].next){
            int v = T[i].v;
            if (v == fa)
                continue;
            dfs(v, u);
            esum[u] += esum[v] + 1;
        }
    }
}G;
int qpow(int x, int y){
    int res = 1;
    while (y){
        if (y & 1)
            res = res * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return res;
}
int f[maxn][2];
void dfs(int u, int fa){
    f[u][0] = qpow(2, esum[u]);
    f[u][1] = qpow(2, e[u] + v[u]);
    for (int i = G.H[u]; i; i = G.T[i].next){
        int v = G.T[i].v;
        if (v == fa)
            continue;
        dfs(v, u);
        f[u][1] = f[u][1] * (f[v][1] + 2 * f[v][0]) % mod;
    }
    f[u][1] = (f[u][1] - f[u][0] + mod) % mod;
}
signed main(){
    cin >> n >> m;
    int u, v;
    for (int i = 1; i <= m; i++){
        cin >> u >> v;
        G.addEdge(u, v);
        G.addEdge(v, u);
    }
    G.Suo_Dian();
    G.dfs(1, 0);
    dfs(1, 0);
    int ans = 0;
    for (int i = 1; i <= G.bccnum; i++){
        ans = (ans + f[i][1] * qpow(2, m - esum[i] - ((i == 1) ? (0) : (1)))) % mod;
    }
    cout << ans;
    return 0;
}