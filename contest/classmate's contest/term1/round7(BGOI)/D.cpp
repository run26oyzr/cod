#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
struct Node{
    int v, nxt;
}t[maxn << 2];
int h[maxn], tot;
void addEdge(int u, int v){
    ++tot;
    // t[tot].v = v; t[tot].nxt = h[tot]; h[tot] = tot;  错了！！！！！
    t[tot].v = v; t[tot].nxt = h[u]; h[u] = tot; 
}
int ans = 0;
int dfn[maxn], low[maxn], step = 0;
void tarjan(int u, int fa){
    dfn[u] = low[u] = ++step;
    for (int i = h[u]; i; i = t[i].nxt){
        int v = t[i].v;
        if (v == fa) continue;
        if (!dfn[v]){
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
        }
        else low[u] = min(low[u], dfn[v]);
    }
    // if (dfn[u] >= low[u]) ans++; 错了！！！！！
    if (dfn[u] == low[u]) ans++;
}
int main(){
    // freopen("magic3.in", "r", stdin);
    // freopen("magic3.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    if (n == 1 && m == 0){
        cout << 0;
        return 0;
    }
    int u, v;
    while(m--){
        scanf("%d %d\n", &u, &v);
        addEdge(u, v);
        addEdge(v, u);
    }
    tarjan(1, 0);
    cout << n - ans + 1;
    return 0;
}