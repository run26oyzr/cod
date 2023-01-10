#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5, maxk = 25;
struct Node{
    int v, nxt, idx;
}t[maxn << 1], tq[maxn << 1];
int tot, h[maxn];
void addEdge(int u, int v){
    ++tot; 
    t[tot].v = v; t[tot].nxt = h[u]; h[u] = tot;
}
int totq, hq[maxn];
void addQ(int u, int v, int idx){
    ++totq; 
    tq[totq].v = v; tq[totq].nxt = hq[u]; hq[u] = totq;
    tq[totq].idx = totq;
}
int fa[maxn];
int vis[maxn];
int ans[maxn];
int getfa(int x){
    if (fa[x] == x) return x;
    return fa[x] = getfa(fa[x]);
}
void merge(int x, int y){
    int fx = getfa(x);
    fa[getfa(y)] = fx;
}
void dfs(int u, int fa){
    for (int i = h[u]; i; i = t[i].nxt){
        int v = t[i].v;
        if(v == fa) continue;
        dfs(v, u);
        merge(u, v); //只能u作为代表员
    }
    for (int i = hq[u]; i; i = tq[i].nxt){
        int v = tq[i].v;
        if (vis[v]) ans[tq[i].idx] = getfa(v);
    }
}
int main(){
    int n, m, s;
    cin >> n >> m >> s;
    int u, v;
    for (int i = 1; i <= n - 1; i++){
        cin >> u >> v;
        addEdge(v, u);
    }
    for (int i = 1; i <= n; i++) fa[i] = i;
    int x, y;
    for (int i = 1; i <= m; i++){
        cin >> x >> y;
        addQ(x, y, i);
        addQ(y, x, i);
    }
    dfs(s, 0);
    for (int i = 1; i <= m; i++){
        cout << ans[i] << endl;
    }
    return 0;
}