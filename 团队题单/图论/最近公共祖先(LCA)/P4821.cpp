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
   	scanf("%d %d", &n, &q);
    int u, v;
    for (int i = 1; i <= n - 1; i++){
       	scanf("%d %d", &u, &v);
        addEdge(v, u);
        addEdge(u, v);
    }
    int s = 1;
    dfs(s);
    f[s][0] = s;
    int x, y, z;
    while(q--){
        scanf("%d %d %d", &x, &y, &z);
        int ans = 1e9, id = 0;
        int lca1 = 0, lca2 = 0, tmp;
        lca1 = LCA(x, y);
        tmp = LCA(x, z);
    	if (tmp != lca1) lca2 = tmp;
    	tmp = LCA(y, z);
    	if (tmp != lca1 && tmp != lca2) lca2 = tmp;
    	if (!lca2) lca2 = lca1;
//    	cout << lca1 << ' ' << lca2 << endl;
    	if (dep[lca1] < dep[lca2]) swap(lca1, lca2);
    	ans = dep[x] + dep[y] + dep[z] - 3 * dep[lca2] - (dep[lca1] - dep[lca2]);
    	id = lca1;
        printf("%d %d\n", id, ans);
    }
    return 0;
}