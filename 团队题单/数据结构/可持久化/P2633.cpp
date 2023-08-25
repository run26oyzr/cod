#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5, maxk = 20;
int a[maxn], b[maxn], rt[maxn];
struct Segment_Tree{
	int tot;
	struct Node{
		int lson, rson;
		int size;
	}t[maxn * 40];
	int newNode(int p){
		++tot;
		t[tot] = t[p];
		return tot;
	}
	void update(int id){
		t[id].size = t[t[id].lson].size + t[t[id].rson].size;
	}
	void change(int pre, int &id, int L, int R, int pos, int c){
		id = newNode(pre);
		if (L == pos && R == pos){
			t[id].size += c;
			return;
		}
		int mid = (L + R) >> 1;
		if (pos <= mid)
			change(t[pre].lson, t[id].lson, L, mid, pos, c);
		else
			change(t[pre].rson, t[id].rson, mid + 1, R, pos, c);
		update(id);
	}
	int query(int x, int y, int lca, int z, int L, int R, int k){
		if (L >= R){
			return b[L];
		}
		int mid = (L + R) >> 1;
        int lsize = t[t[x].lson].size + t[t[y].lson].size - t[t[lca].lson].size - t[t[z].lson].size;
 		if (lsize >= k)
			return query(t[x].lson, t[y].lson, t[lca].lson, t[z].lson, L, mid, k);
		else 
			return query(t[x].rson, t[y].rson, t[lca].rson, t[z].rson, mid + 1, R, k - lsize);
	}
}Seg_Tree;
struct Node{
    int v, nxt;
}t[maxn << 1];
int tot, h[maxn];
void addEdge(int u, int v){
    ++tot; 
    t[tot].v = v; t[tot].nxt = h[u]; h[u] = tot;
}
struct LCA{
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
	int getLCA(int u, int v){
		if (dep[u] < dep[v]) swap(u, v);
		int t = dep[u] - dep[v];
		for (int i = 0; i <= maxk; i++)
			if(t & (1 << i))
				u = f[u][i];
		if (u == v) return u;
		for(int i = maxk; i >= 0; i--){
			if (f[u][i] != f[v][i]){
				u = f[u][i];
				v = f[v][i];
			}
		}  
		return f[u][0];
	}
}lca;
int n, m, nn;
void dfs(int u, int fa){
    Seg_Tree.change(rt[fa], rt[u], 1, nn, a[u], 1);
    for (int i = h[u]; i; i = t[i].nxt){
        int v = t[i].v;
        if (v == fa)
            continue;
        dfs(v, u);
    }
}
signed main(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b + 1, b + n + 1);
	nn = unique(b + 1, b + n + 1) - b - 1;
	for (int i = 1; i <= n; i++)
		a[i] = lower_bound(b + 1, b + nn + 1, a[i]) - b;
    int u, v;
    for (int i = 1; i <= n - 1; i++){
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }
    lca.dfs(1);
	dfs(1, 0);
	int x, y, k;
    int last = 0;
	while (m--){
		cin >> x >> y >> k;
        x ^= last;
        last = Seg_Tree.query(rt[x], rt[y], rt[lca.getLCA(x, y)], rt[lca.f[lca.getLCA(x, y)][0]], 1, nn, k);
		cout << last << endl;
	}
	return 0;
}