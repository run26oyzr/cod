#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
struct Node{
    int v, c, next;
}t[maxn << 1];
int h[maxn], tot = 0;
void addEdge(int u, int v, int c){
    ++tot;
    t[tot].v = v, t[tot].c = c, t[tot].next = h[u], h[u] = tot;
}
int f[maxn], sum[maxn];
void add(int x, int y, int w){
    sum[x] += sum[y];
    f[x] += f[y] + sum[y] * w;
}
void del(int x, int y, int w){
    sum[x] -= sum[y];
    f[x] -= f[y] + sum[y] * w;
}
int ans = 1e18;
void update_ans(int id){
    ans = min(ans, f[id]);
}
int a[maxn];
void dfs1(int u, int fa){
    sum[u] = a[u];
    for (int i = h[u]; i; i = t[i].next){
        int v = t[i].v;
        if (v == fa)
            continue;
        dfs1(v, u);
        add(u, v, t[i].c);
    }
}
int n;
void dfs2(int u, int fa){
    if (fa){
    }
    update_ans(u);
    for (int i = h[u]; i; i = t[i].next){
        int v = t[i].v;
        if (v == fa)
            continue;
        del(u, v, t[i].c);
        add(v, u, t[i].c);
        dfs2(v, u);
        del(v, u, t[i].c);
        add(u, v, t[i].c);
    }
}
signed main(){
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int u, v, c;
    for (int i = 1; i < n; i++){
        cin >> u >> v >> c;
        addEdge(u, v, c);
        addEdge(v, u, c);
    }
    dfs1(1, 0);
    dfs2(1, 0);
    cout << ans;
    return 0;
}