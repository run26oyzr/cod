#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5, maxk = 15;
const int mod = 998244353;
int c[maxn];
struct Node{
    int v, nxt;
}t[maxn << 1];
int tot, h[maxn];
void addEdge(int u, int v){
    ++tot; 
    t[tot].v = v; t[tot].nxt = h[u]; h[u] = tot;
}
int dep[maxn], f[maxn][maxk + 1];
bool vis[maxn];
void dfs(int u){
    vis[u] = 1;
    for (int j = 1; j <= maxk; j++){
        if (dep[u] < (1 << j)) break;
        f[u][j] = f[f[u][j - 1]][j - 1];
    }
    for (int i = h[u]; i; i = t[i].nxt){
        int v = t[i].v;
        if (vis[v]) continue;
        dep[v] = dep[u] + 1;
        f[v][0] = u;
        dfs(v);
    }
}
int tmp[maxn];
int tmp2[maxn];
void add(int u, int v, int val){
    int LCA;
    int uu = u, vv = v;
    if (dep[u] < dep[v]) swap(u, v);
    int t = dep[u] - dep[v];
    for (int i = 0; i <= maxk; i++)
        if(t & (1 << i))
            u = f[u][i];
    if (u == v) LCA = u;
    else{
        for(int i = maxk; i >= 0; i--){
            if (f[u][i] != f[v][i]){
                u = f[u][i];
                v = f[v][i];
            }
        }  
        LCA = f[u][0];
    }
    for(int i = uu; i != LCA; i = f[i][0]) c[i] = (c[i] + val) % mod;
    c[LCA] = (c[LCA] + val) % mod;
    for(int i = vv; i != LCA; i = f[i][0]) c[i] = (c[i] + val) % mod;
}
void rev(int u, int v){
    int LCA;
    int uu = u, vv = v;
    if (dep[u] < dep[v]) swap(u, v);
    int t = dep[u] - dep[v];
    for (int i = 0; i <= maxk; i++)
        if(t & (1 << i))
            u = f[u][i];
    if (u == v) LCA = u;
    else{
        for(int i = maxk; i >= 0; i--){
            if (f[u][i] != f[v][i]){
                u = f[u][i];
                v = f[v][i];
            }
        }  
        LCA = f[u][0];
    }
    int pos = 0, pos_;
    for(int i = uu; i != LCA; i = f[i][0]) tmp[++pos] = c[i];
    tmp[++pos] = c[LCA];
    pos_ = pos;
    for(int i = vv; i != LCA; i = f[i][0]) tmp[++pos] = c[i];
    reverse(tmp + pos_ + 1, tmp + pos + 1);
    // for(int i = 1; i <= pos; i++) cout << tmp[i] << ' ';
    // cout << endl;
    for(int i = uu; i != LCA; i = f[i][0]) c[i] = tmp[pos--];
    c[LCA] = tmp[pos--];
    reverse(tmp + 1, tmp + pos + 1);
    for(int i = vv; i != LCA; i = f[i][0]) c[i] = tmp[pos--];
}
int query(int u, int v){
    int LCA;
    int uu = u, vv = v;
    if (dep[u] < dep[v]) swap(u, v);
    int t = dep[u] - dep[v];
    for (int i = 0; i <= maxk; i++)
        if(t & (1 << i))
            u = f[u][i];
    if (u == v) LCA = u;
    else{
        for(int i = maxk; i >= 0; i--){
            if (f[u][i] != f[v][i]){
                u = f[u][i];
                v = f[v][i];
            }
        }  
        LCA = f[u][0];
    }
    int res = 0;
    for(int i = uu; i != LCA; i = f[i][0]) res = (res + c[i]) % mod;
    res = (res + c[LCA]) % mod;
    for(int i = vv; i != LCA; i = f[i][0]) res = (res + c[i]) % mod;
    return res;
}
signed main(){
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> c[i];
    int u, v;
    for (int i = 1; i <= n - 1; i++){
        cin >> u >> v;
        addEdge(v, u);
        addEdge(u, v);
    }
    dfs(1);
    f[1][0] = 1;
    int opt, a, b, k;
    while(q--){
        cin >> opt;
        if(opt == 1){
            cin >> a >> b >> k;
            add(a, b, k);
            // for(int i = 1; i <= n; i++){
            //     cout << c[i] << ' ';
            // }
            // cout << endl;
        }else if(opt == 2){
            cin >> a >> b;
            rev(a, b);
            // for(int i = 1; i <= n; i++){
            //     cout << c[i] << ' ';
            // }
            // cout << endl;
        }else if(opt == 3){
            cin >> a >> b;
            cout << query(a, b) % mod << endl;
        }
    }
    return 0;
}