#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e6 + 5, mod = 1e9 + 7;
struct Math{
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
    int p[maxn], a[maxn], b[maxn];
    void init(){
        a[0] = 1;
        for (int i = 1; i < maxn; i++)
            a[i] = a[i - 1] * i % mod;
        b[0] = 1;
        for (int i = 1; i < maxn; i++)
            b[i] = b[i - 1] * qpow(i, mod - 2) % mod;
    }
    int C(int x, int y){
        return (a[x] * b[x - y] % mod) * b[y] % mod;
    }
    int Ni_Yuan(int x){
        return qpow(x, mod - 2);
    }
}Math;
struct Node{
    signed v, next;
}t[maxn << 1];
signed h[maxn], tot = 0;
void addEdge(int u, int v){
    ++tot;
    t[tot].v = v, t[tot].next = h[u], h[u] = tot;
}
int n;
signed size[maxn];
int f[maxn];
void dfs(int u, int fa){
    int sum = 0; f[u] = 1;
    for (int i = h[u]; i; i = t[i].next){
        int v = t[i].v;
        if (v == fa)
            continue;
        dfs(v, u);
        sum += size[v];
        f[u] = f[u] * (f[v] * Math.C(sum, size[v]) % mod) % mod;
    }
    size[u] = sum + 1;
}
int df[maxn];
void dfs1(int u, int fa){
    df[u] = 1;
    if (fa)
        df[u] = (df[fa] * (f[fa] * Math.Ni_Yuan(f[u] * Math.C(size[fa] - 1, size[u]) % mod) % mod) % mod) * Math.C(n - size[u] - 1, n - size[fa]) % mod;
    for (int i = h[u]; i; i = t[i].next){
        int v = t[i].v;
        if (v == fa)
            continue;
        dfs1(v, u);
    }
}
signed main(){
    Math.init();
    cin >> n;
    int u, v;
    for (int i = 1; i < n; i++){
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }
    // for (int i = 1; i <= n; i++){
    //     dfs(i, 0);
    //     ans = (ans + f[i]) % mod;
    // }
    dfs(1, 0);
    dfs1(1, 0);
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = (ans + ((f[i] * df[i] % mod) * Math.C(n - 1, n - size[i]) % mod)) % mod;
    cout << ans;
    return 0;
}