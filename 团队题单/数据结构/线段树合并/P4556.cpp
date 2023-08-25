#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5, maxk = 20;
int rt[maxn];
struct Segment_Tree{
	int tot = 0;
	struct Node{
		int lson, rson;
		int maxcnt, maxval;
	}t[maxn * 80];
	int newNode(){
		++tot;
		t[tot].maxcnt = t[tot].maxval = 0;
		t[tot].lson = t[tot].rson = 0;
		return tot;
	}
	void update(int id){
		if (t[t[id].lson].maxcnt > t[t[id].rson].maxcnt)
			t[id].maxval = t[t[id].lson].maxval;
		else if (t[t[id].lson].maxcnt < t[t[id].rson].maxcnt)
			t[id].maxval = t[t[id].rson].maxval;
		else
			t[id].maxval = min(t[t[id].lson].maxval, t[t[id].rson].maxval);
		t[id].maxcnt = max(t[t[id].lson].maxcnt, t[t[id].rson].maxcnt);
	}
	void change(int &id, int L, int R, int pos, int c){
		if (!id)
			id = newNode();
		if (L == pos && R == pos){
			t[id].maxcnt += c;
			t[id].maxval = L;
			return;
		}
		int mid = (L + R) >> 1;
		if (pos <= mid)
			change(t[id].lson, L, mid, pos, c);
		else
			change(t[id].rson, mid + 1, R, pos, c);
		update(id);
	}
    int merge(int x, int y, int L, int R){
        if (!x || !y) 
            return x + y;
        if (L == R){
            t[x].maxcnt += t[y].maxcnt;
			t[x].maxval = L;
            return x;
        }
        int mid = (L + R) >> 1;
        t[x].lson = merge(t[x].lson, t[y].lson, L, mid);
        t[x].rson = merge(t[x].rson, t[y].rson, mid + 1, R);
        update(x);
        return x;
    }
}Seg_Tree;
struct LCA{
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
int ans[maxn];
void dfs(int u, int fa){
	for (int i = lca.h[u]; i; i = lca.t[i].nxt){
		int v = lca.t[i].v;
		if (v == fa)
			continue;
		dfs(v, u);
		rt[u] = Seg_Tree.merge(rt[u], rt[v], 1, 1e5);
	}
	ans[u] = Seg_Tree.t[rt[u]].maxval;
}
int main(){
	int n, m;
	cin >> n >> m;
	int u, v;
	for (int i = 1; i <= n - 1; i++){
		cin >> u >> v;
		lca.addEdge(u, v);
		lca.addEdge(v, u);
	}
	lca.dfs(1);
	int x, y, z;
	for (int i = 1; i <= m; i++){
		cin >> x >> y >> z;
		Seg_Tree.change(rt[x], 1, 1e5, z, 1);
		Seg_Tree.change(rt[y], 1, 1e5, z, 1);
		Seg_Tree.change(rt[lca.getLCA(x, y)], 1, 1e5, z, -1);
		if (lca.f[lca.getLCA(x, y)][0])
			Seg_Tree.change(rt[lca.f[lca.getLCA(x, y)][0]], 1, 1e5, z, -1);
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++)
		cout << ans[i] << endl;
	return 0;
}