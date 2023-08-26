#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
int rt[maxn];
struct Segment_Tree{
	int tot = 0;
	struct Node{
		int lson, rson;
		int maxcnt, maxsum;
	}t[maxn * 40];
	int newNode(){
		++tot;
		t[tot].maxcnt = t[tot].maxsum = 0;
		t[tot].lson = t[tot].rson = 0;
		return tot;
	}
	void update(int id){
		if (t[t[id].lson].maxcnt > t[t[id].rson].maxcnt)
			t[id].maxsum = t[t[id].lson].maxsum;
		else if (t[t[id].lson].maxcnt < t[t[id].rson].maxcnt)
			t[id].maxsum = t[t[id].rson].maxsum;
		else
			t[id].maxsum = t[t[id].lson].maxsum + t[t[id].rson].maxsum;
		t[id].maxcnt = max(t[t[id].lson].maxcnt, t[t[id].rson].maxcnt);
	}
	void change(int &id, int L, int R, int pos, int c){
		if (!id)
			id = newNode();
		if (L == pos && R == pos){
			t[id].maxcnt += c;
			t[id].maxsum = L;
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
			t[x].maxsum = L;
            return x;
        }
        int mid = (L + R) >> 1;
        t[x].lson = merge(t[x].lson, t[y].lson, L, mid);
        t[x].rson = merge(t[x].rson, t[y].rson, mid + 1, R);
        update(x);
        return x;
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
int ans[maxn];
int n, m;
void dfs(int u, int fa){
	for (int i = h[u]; i; i = t[i].nxt){
		int v = t[i].v;
		if (v == fa)
			continue;
		dfs(v, u);
		rt[u] = Seg_Tree.merge(rt[u], rt[v], 1, n);
	}
	ans[u] = Seg_Tree.t[rt[u]].maxsum;
}
signed main(){
	cin >> n;
    int x;
    for (int i = 1; i <= n; i++){
        cin >> x;
        Seg_Tree.change(rt[i], 1, n, x, 1);
    }
	int u, v;
	for (int i = 1; i <= n - 1; i++){
		cin >> u >> v;
		addEdge(u, v);
		addEdge(v, u);
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++)
		cout << ans[i] << ' ';
	return 0;
}