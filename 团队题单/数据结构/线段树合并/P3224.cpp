#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int rt[maxn], p[maxn];
struct Segment_Tree{
	int tot = 0;
	struct Node{
		int lson, rson;
		int size;
	}t[maxn * 40];
	int newNode(){
		++tot;
		t[tot].lson = t[tot].rson = 0;
		t[tot].size = 0;
		return tot;
	}
	void update(int id){
		t[id].size = t[t[id].lson].size + t[t[id].rson].size;
	}
	void change(int &id, int L, int R, int pos, int c){
		if (!id)
			id = newNode();
		if (L == pos && R == pos){
			t[id].size += c;
			return;
		}
		int mid = (L + R) >> 1;
		if (pos <= mid)
			change(t[id].lson, L, mid, pos, c);
		else
			change(t[id].rson, mid + 1, R, pos, c);
		update(id);
	}
    int query(int id, int L, int R, int k){
		if (L == R){
            return L;
        }
		int mid = (L + R) >> 1;
        int lsize = t[t[id].lson].size;
        // cout << L << ' ' << R << ' ' << lsize << ' ' << t[t[id].rson].size << ' ' << k << endl;
		if (k <= lsize)
			return query(t[id].lson, L, mid, k);
		else
			return query(t[id].rson, mid + 1, R, k - lsize);
	}
    int merge(int x, int y, int L, int R){
        if (!x || !y) 
            return x + y;
        if (L == R){
            t[x].size += t[y].size;
            return x;
        }
        int mid = (L + R) >> 1;
        t[x].lson = merge(t[x].lson, t[y].lson, L, mid);
        t[x].rson = merge(t[x].rson, t[y].rson, mid + 1, R);
        update(x);
        return x;
    }
}Seg_Tree;
int n, m, q;
struct DSU{
    int fa[maxn];
    void init(){
        for (int i = 0; i < maxn; i++)
            fa[i] = i;
    }
    int getfa(int x){
        if (fa[x] == x) return x;
        return fa[x] = getfa(fa[x]);
    }
    void merge(int x, int y){
        int fx = getfa(x);
        int fy = getfa(y);
        fa[fy] = fx;
        rt[fx] = Seg_Tree.merge(rt[fx], rt[fy], 1, n);
    }
}dsu;
int id[maxn];
int main(){
    dsu.init();
	cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> p[i];
        id[p[i]] = i;
        Seg_Tree.change(rt[i], 1, n, p[i], 1);
    }
    int x, y;
    for (int i = 1; i <= m; i++){
        cin >> x >> y;
        dsu.merge(x, y);
    }
    cin >> q;
    char op;
    while (q--){
        cin >> op >> x >> y;
        if (op == 'Q'){
            if (y > Seg_Tree.t[rt[dsu.getfa(x)]].size)
                cout << -1 << endl;
            else
                cout << id[Seg_Tree.query(rt[dsu.getfa(x)], 1, n, y)] << endl;
        }
        else
            dsu.merge(x, y);
    }
	return 0;
}