#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 80005;
struct Node{
    int v, c, nxt;
    float k;
}t[maxn];
int h[maxn], tot;
void addEdge(int u, int v, int c, float k){
    ++tot;
    t[tot].v = v; t[tot].c = c; t[tot].k = k; t[tot].nxt = h[u]; h[u] = tot;
}
int vis[maxn], dis[maxn];
queue <int> q;
void spfa(int s){
    memset(dis, -0x3f, sizeof(dis));
    dis[s] = 0; vis[s] = 1; q.push(s);
    int role = 150;
    while(!q.empty()){
        memset(vis, 0, sizeof(vis));
        int u = q.front(); q.pop();
        for (int i = h[u]; i; i = t[i].nxt){
            int v = t[i].v;
            if (dis[u] + t[i].c > dis[v]){
                dis[v] = dis[u] + t[i].c;
                if (!vis[v]){
                    t[i].c = floor(t[i].c * t[i].k);
                    q.push(v); vis[v] = 1;
                }
            }
        }
    }
}
signed main(){
    freopen("treasure.in", "r", stdin);
    freopen("treasure.out", "w", stdout);
    int n, m, s;
    cin >> n >> m;
    int u, v, c;
    float k;
    while(m--){
        cin >> u >> v >> c >> k;
        addEdge(u, v, c, k);
    }
    cin >> s;
    spfa(s);
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, dis[i]);
    cout << ans;
    return 0;
}