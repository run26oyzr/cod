#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e6 + 5;
struct Node{
    int v, next;
}t[maxn << 1];
int h[maxn], tot = 0;
void addEdge(int u, int v){
    ++tot;
    t[tot].v = v, t[tot].next = h[u], h[u] = tot;
}
int f[maxn], size[maxn];
void add(int x, int y){
    size[x] += size[y];
    f[x] += size[y] + f[y];
}
void del(int x, int y){
    size[x] -= size[y];
    f[x] -= size[y] + f[y];
}
int ans, ansdis = 0;
void update_ans(int id){
    if (f[id] > ansdis){
        ans = id;
        ansdis = f[id];
    }
}
void dfs1(int u, int fa){
    size[u] = 1;
    for (int i = h[u]; i; i = t[i].next){
        int v = t[i].v;
        if (v == fa)
            continue;
        dfs1(v, u);
        add(u, v);
    }
}
int n;
void dfs2(int u, int fa){
    if (fa){
        del(fa, u);
        add(u, fa);
    }
    update_ans(u);
    for (int i = h[u]; i; i = t[i].next){
        int v = t[i].v;
        if (v == fa)
            continue;
        dfs2(v, u);
    }
    if (fa){
        del(u, fa);
        add(fa, u);
    }
}
signed main(){
    cin >> n;
    int u, v;
    for (int i = 1; i < n; i++){
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }
    dfs1(1, 0);
    dfs2(1, 0);
    cout << ans;
    return 0;
}