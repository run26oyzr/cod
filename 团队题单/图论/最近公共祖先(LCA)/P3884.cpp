#include <bits/stdc++.h>
using namespace std;
const int maxn = 5 * 1e5 + 5, maxk = 25;
struct Node{
    int v, nxt;
}t[maxn << 1];
int tot, h[maxn];
void addEdge(int u, int v){
    ++tot; 
    t[tot].v = v; t[tot].nxt = h[u]; h[u] = tot;
}
int dep[maxn], f[maxn][maxk + 1];
bool vis[maxn];
void dfs(int u){
    vis[u] = 1;
    for (int j = 1; j <= maxk; j++){
        if (dep[u] < (1 << j)) break;
        f[u][j] = f[f[u][j - 1]][j - 1];
    }
    for (int i = h[u]; i; i = t[i].nxt){
        int v = t[i].v;
        if (vis[v]) continue;
        dep[v] = dep[u] + 1;
        f[v][0] = u;
        dfs(v);
    }
}
int ans = 0;
int LCA(int u, int v){
	bool flag = false;
    if (dep[u] < dep[v]){
    	swap(u, v);	
    	flag = true;
	}
    int t = dep[u] - dep[v];
    if (flag) ans += t;
    else ans += t * 2;
    for (int i = 0; i <= maxk; i++)
        if(t & (1 << i))
            u = f[u][i];
    if (u == v) return u;
    for(int i = maxk; i >= 0; i--){
        if (f[u][i] != f[v][i]){
            u = f[u][i];
            v = f[v][i];
            ans += 3 * pow(2, i);
        }
    }  
    ans += 3;
    return f[u][0];
}
int width, height;
int tmp[105];
void func(int u, int step, int fa){
//	cout << u << ' ' << step << ' ' << fa << endl;
	tmp[step]++;
	height = max(height, step);
	for (int j = h[u]; j; j = t[j].nxt){
		if (t[j].v == fa) continue;
		func(t[j].v, step + 1, u);
	}
}
int main(){
    int n;
    cin >> n;
    int u, v;
    for (int i = 1; i <= n - 1; i++){
        cin >> u >> v;
        addEdge(v, u);
        addEdge(u, v);
    }
    func(1, 1, 0);
    for (int i = 1; i <= 100; i++) width = max(width, tmp[i]);
    cout << height << endl;
    cout << width << endl;
    dfs(1);
    f[1][0] = 1;
    int x, y;
    cin >> x >> y;
    LCA(x, y);
    cout << ans << endl;
    return 0;
}