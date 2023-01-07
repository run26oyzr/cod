#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e4 + 5, maxm = 1e6 + 5;
struct Node{
    int v, nxt;
}t[maxm];
int h[maxn], tot;
void addEdge(int u, int v){
    ++tot;
    t[tot].v = v; t[tot].nxt = h[u]; h[u] = tot;
}
int v[maxn], ans[maxn];
int maxnum, maxpos;
bool vis[maxn];
int dfs(int u){
    int max = 0, smax = 0;
    for (int i = h[u]; i; i = t[i].nxt){
        int v = t[i].v;
        int res = dfs(v);
        if (res > max){
            smax = max;
            max = res;
        }else if (res > smax){
            smax = res;
        }
    }
    ans[u] = max + smax + v[u];
    if (ans[u] > maxnum){
        maxnum = ans[u];
        maxpos = u;
    }
    vis[u] = true;
    return ans[u];
}
signed main(){
    freopen("dag.in", "r", stdin);
    freopen("dag.out", "w", stdout);
    int n, m;
    scanf("%lld %lld", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%lld", &v[i]);
    int u, v;
    while(m--){
        scanf("%lld %lld", &u, &v);
        addEdge(u, v);
    }
    for (int i = 1; i <= n; i++){
        if (!vis[i]){
            dfs(i);
        }
    }
    cout << maxpos << ' ' << maxnum;
    return 0;
}