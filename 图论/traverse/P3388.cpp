#include <bits/stdc++.h>
using namespace std;
const int maxn = 2 * 1e4 + 5, maxm = 1e5 + 5;

struct Node{
    int v, next;
}t[maxm << 2];
int tot = 0, h[maxn];
void addEdge(int u, int v){
    t[++tot].v = v;
    t[tot].next = h[u];
    h[u] = tot;
}

int dfn[maxn], low[maxn], dep;
bool cut[maxn];
void dfs(int u, int fa){
    dfn[u] = low[u] = ++dep;
    int son = 0;
    for (int i = h[u]; i; i = t[i].next){
        int v = t[i].v;
        if(v == fa) continue;
        son++;
        if (!dfn[v]){
            dfs(v, u);
            low[u] = min(low[v], low[u]);
            //子节点 存在一个子节点
            if (fa != 0 && low[v] >= dfn[u] || fa == 0 && son >= 2) cut[u] = 1;
        }
        else low[u] = min(dfn[v], low[u]);
    }
}
int main(){
    int n, m;
    cin >> n >> m;
    int x, y;
    while(m--){
        cin >> x >> y;
        addEdge(x, y);
        addEdge(y, x);
    }
    for (int i = 1; i <= n; i++){
        if(!dfn[i]) dfs(i, 0);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++){
        if (cut[i]) cnt++;
    }
    cout << cnt << endl;
    for (int i = 1; i <= n; i++){
        if (cut[i]) cout << i << ' ';
    }
    system("pause");
}