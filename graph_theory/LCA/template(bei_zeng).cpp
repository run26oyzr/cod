#include <bits/stdc++.h>
using namespace std;
const int maxn = 5 * 1e5 + 5, maxk = 25;
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
int LCA(int u, int v){
    if (dep[u] < dep[v]) swap(u, v);
    int t = dep[u] - dep[v];
    for (int i = 0; i <= maxk; i++)
        if(t & (1 << i))
            u = f[u][i];
    if (u == v) return u;
    for(int i = maxk; i >= 0; i--){
        if (f[u][i] != f[v][i]){
            u = f[u][i];
            v = f[v][i];
        }
    }  
    return f[u][0];
}
int main(){
    int n, m, s;
    cin >> n >> m >> s;
    int u, v;
    for (int i = 1; i <= n - 1; i++){
        cin >> u >> v;
        addEdge(v, u);
    }
    dfs(s);
    f[s][0] = s;
    int x, y;
    while(m--){
        cin >> x >> y;
        cout << LCA(x, y) << endl;
    }
    return 0;
}