#include <bits/stdc++.h>
using namespace std;
const int maxn = 5 * 1e5 + 5, maxk = 25;
struct Node{
    int v, nxt;
}t[maxn << 1];
int tot, h[maxn];
int in[maxn];
void addEdge(int u, int v){
    ++tot; 
    t[tot].v = v; t[tot].nxt = h[u]; h[u] = tot;
    in[v] ++;
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
int dis(int u, int v){
	int res = 0;
    if (dep[u] < dep[v]) swap(u, v);
    int t = dep[u] - dep[v];
    res += t;
    for (int i = 0; i <= maxk; i++)
        if(t & (1 << i))
            u = f[u][i];
    if (u == v) return res;
    for(int i = maxk; i >= 0; i--){
        if (f[u][i] != f[v][i]){
            u = f[u][i];
            v = f[v][i];
            res += 2 * pow(2, i);
        }
    } 
    res += 2;
    return res;
}
int main(){
    int n, q;
    cin >> n >> q;
    int u, v;
    for (int i = 1; i <= n - 1; i++){
        cin >> u >> v;
        addEdge(v, u);
        addEdge(u, v);
    }
    int s = 1;
    dfs(s);
    f[s][0] = s;
    int x1, y1, x2, y2;
    while(q--){
        cin >> x1 >> y1 >> x2 >> y2;
        int tmp1 = LCA(x1, y1), tmp2 = LCA(x2, y2);
//        cout << tmp1 << ' ' << tmp2 << endl;
//        cout << dis(x1, tmp2) << '+' << dis(tmp2, y1) << '?' << dis(x1, y1) << endl << dis(x2, tmp1) << '+' << dis(tmp1, y2) << '?' << dis(x2, y2) << endl;
        if (dis(x1, tmp2) + dis(tmp2, y1) == dis(x1, y1) || dis(x2, tmp1) + dis(tmp1, y2) == dis(x2, y2)) cout << 'Y' << endl;
        else cout << 'N' << endl;
    }
    return 0;
}