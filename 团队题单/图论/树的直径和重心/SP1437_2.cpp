//树形dp，可以解决负权边
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;
struct Node{
    int v, c, next;
}t[maxn << 1];
int h[maxn], tot = 0;
void addEdge(int u, int v, int c){
    ++tot;
    t[tot].v = v, t[tot].c = c, t[tot].next = h[u], h[u] = tot;
}
int f[maxn];
int ans = -1e9;
void dfs(int u, int fa){
    int secondmax = -1e9;
    for (int i = h[u]; i; i = t[i].next){
        int v = t[i].v;
        if (v == fa)
            continue;
        dfs(v, u);
        if (f[v] + t[i].c > f[u]){
            secondmax = f[u];
            f[u] = f[v] + t[i].c;
        }else if (f[v] + t[i].c > secondmax){
            secondmax = f[v] + t[i].c;
        }
    }
    ans = max(ans, f[u] + secondmax);
}
int main(){
    int n;
    cin >> n;
    int u, v;
    for (int i = 1; i < n; i++){
        cin >> u >> v;
        addEdge(u, v, 1);
        addEdge(v, u, 1);
    }
    dfs(1, 0);
    cout << ans;
    return 0;
}