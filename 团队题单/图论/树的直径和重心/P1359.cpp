#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e4 + 5;
struct Node{
    int v, next;
}t[maxn << 1];
int h[maxn], tot = 0;
void addEdge(int u, int v){
    ++tot;
    t[tot].v = v, t[tot].next = h[u], h[u] = tot;
}
int n;
int size[maxn];
int ans, ansdis = 1e9;
void dfs(int u, int fa){
    size[u] = 1;
    int maxa = 0;
    for (int i = h[u]; i; i = t[i].next){
        int v = t[i].v;
        if (v == fa)
            continue;
        dfs(v, u);
        size[u] += size[v];
        maxa = max(maxa, size[v]);
    }
    maxa = max(maxa, n - size[u]);
    if (maxa < ansdis){
        ansdis = maxa;
        ans = u;
    }else if (maxa == ansdis){
        ans = min(ans, u);
    }
}
int dis = 0;
void dfs2(int u, int fa, int depth){
    dis += depth;
    for (int i = h[u]; i; i = t[i].next){
        int v = t[i].v;
        if (v == fa)
            continue;
        dfs2(v, u, depth + 1);
    }
}
int main(){
    cin >> n;
    int u, v;
    for (int i = 1; i < n; i++){
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }
    dfs(1, 0);
    dfs2(ans, 0, 0);
    cout << ans << ' ' << dis;
    return 0;
}