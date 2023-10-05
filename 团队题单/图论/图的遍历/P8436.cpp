#include <bits/stdc++.h>
using namespace std;
const int maxn = 5 * 1e5 + 5, maxm = 2 * 1e6 + 5;
struct Node{
    int v, next;
    int tag;
    bool del;
}t[maxm << 1];
int tot = 1, h[maxn];
void addEdge(int u, int v){
    t[++tot].v = v;
    t[tot].next = h[u];
    h[u] = tot;
}

int bccnum = 0;
vector<int> bcc[maxn];
int dfn[maxn], low[maxn], dep = 0;
void tarjan(int u){
    dfn[u] = low[u] = ++dep;
    for (int i = h[u]; i; i = t[i].next){
        int v = t[i].v;
        if (t[i].tag == -1)
            continue;
        t[i ^ 1].tag = -1;
        if (!dfn[v]){
            tarjan(v);
            low[u] = min(low[v], low[u]);
            if (low[v] > dfn[u]){
                t[i].del = t[i ^ 1].del = true;
            }
        }
        else low[u] = min(dfn[v], low[u]);
    }
}
int vis[maxn];
void dfs(int u){
    vis[u] = 1;
    bcc[bccnum].push_back(u);
    for (int i = h[u]; i; i = t[i].next){
        int v = t[i].v;
        if (vis[v] || t[i].del)
            continue;
        dfs(v);
    }
}
int main(){
    int n, m;
    cin >> n >> m;
    int x, y;
    while(m--){
        cin >> x >> y;
        if (x == y) 
            continue;
        addEdge(x, y);
        addEdge(y, x);
    }
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan(i);
    for (int i = 1; i <= n; i++)
        if (!vis[i]){
            ++bccnum;
            dfs(i);
        }
    cout << bccnum << endl;
    for (int i = 1; i <= bccnum; i++){
        cout << bcc[i].size() << ' ';
        while (!bcc[i].empty()){
            cout << bcc[i].back() << ' ';
            bcc[i].pop_back();
        }
        cout << endl;
    }
    return 0;
}