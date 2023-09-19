#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int minval = 1, maxval = 1e8;
struct Node{
	int lson, rson;
	int size, sum;
	Node operator + (const Node T) const{
		return {0, 0, size + T.size, sum + T.sum};
	}
};
struct Segment_Tree1{
	Node t[maxn * 40];
	int tot = 0;
	int trash[maxn * 40], tp = 0;
	int newNode(){
		++tot;
		t[tot].lson = t[tot].rson = 0;
		t[tot].sum = 0;
		t[tot].size = 0;
		return tot;
	}
	void update(int id){
		t[id].size = t[t[id].lson].size + t[t[id].rson].size;
		t[id].sum = t[t[id].lson].sum + t[t[id].rson].sum;
	}
	void change(int &id, int L, int R, int pos, int c){
		if (!id)
			id = newNode();
		if (L == pos && R == pos){
			t[id].size += c;
			t[id].sum += c * L;
			return;
		}
		int mid = (L + R) >> 1;
		if (pos <= mid)
			change(t[id].lson, L, mid, pos, c);
		else
			change(t[id].rson, mid + 1, R, pos, c);
		update(id);
	}
    Node query(int id, int L, int R, int l, int r){
		if (R < l || L > r)
			return;
		if (l <= L && R <= r){
			return t[id];
		}
		int mid = (L + R) >> 1;
		return query(t[id].lson, L, mid, l, r) + query(t[id].rson, mid + 1, R, l, r);
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
	void del(int id){
		trash[++tp] = id;
		if (t[id].lson)
			del(t[id].lson);
		if (t[id].rson)
			del(t[id].rson);
	}
}Val_Tree;
struct Segment_Tree2{
	#define lson (id << 1)
	#define rson (id << 1 | 1)
	struct node{	
		int rt;
		int c, lc;
		int sum;
	}t[maxn << 2];
	void pushdown(int id){
		if (t[id].lc){
			Node x, y;
			if (t[lson].lc)
				pushdown(lson);
			t[lson].lc = t[id].lc;
			x = Val_Tree.query(t[lson].rt, minval, maxval, 1, t[id].lc);
			y = Val_Tree.query(t[lson].rt, minval, maxval, t[id].lc + 1, maxval);
			t[lson].sum += (t[id].lc * x.size - x.sum) + (y.sum - t[id].lc * y.size);
			int siz = Val_Tree.t[t[lson].rt].size;
			Val_Tree.del(t[lson].rt);
			t[lson].rt = 0;
			Val_Tree.change(t[lson].rt, minval, maxval, t[id].lc, siz);

			if (t[rson].lc)
				pushdown(rson);
			t[rson].lc = t[id].lc;
			x = Val_Tree.query(t[rson].rt, minval, maxval, 1, t[id].lc);
			y = Val_Tree.query(t[rson].rt, minval, maxval, t[id].lc + 1, maxval);
			t[rson].sum += (t[id].lc * x.size - x.sum) + (y.sum - t[id].lc * y.size);
			int siz = Val_Tree.t[t[rson].rt].size;
			Val_Tree.del(t[rson].rt);
			t[rson].rt = 0;
			Val_Tree.change(t[rson].rt, minval, maxval, t[id].lc, siz);

			t[id].lc = 0;
		}
	}
	void update(int id){
		t[id].sum = t[lson].sum + t[rson].sum;
		t[id].rt = Val_Tree.merge(t[lson].rt, t[rson].rt);
	}
	void add(int id, int L, int R, int pos, int val){
		if (L == R){
			Treap.insert(t[id].rt, val);
			return;
		}
		int mid = (L + R) >> 1;
		if (pos <= mid)
			add(lson, L, mid, pos, val);
		else
			add(rson, mid + 1, R, pos, val);
		update(id);
	}
	void change(int id, int L, int R, int l, int r, int val){
		if (R < l || L > r)
			return;
		if (l <= L && R <= r){
			int x, y;
			t[id].lc = val;
			Treap.split(t[id].rt, val, x, y);
			t[id].sum += (val * Treap.t[x].size - Treap.t[x].sum) + (Treap.t[y].sum - val * Treap.t[y].size);
			cout << L << " ~ " << R << " : " << Treap.t[x].size << ' ' << Treap.t[x].sum << " | " << Treap.t[y].size << ' ' << Treap.t[y].sum << " => " << (val * Treap.t[x].size - Treap.t[x].sum) + (Treap.t[y].sum - val * Treap.t[y].size) << endl;
			Treap.t[x].lazy = t[id].lc; Treap.t[x].val = t[id].lc;
			Treap.t[y].lazy = t[id].lc; Treap.t[y].val = t[id].lc;
			t[id].rt = Treap.merge(x, y);
			Treap.t[t[id].rt].lazy = val; Treap.t[t[id].rt].val = val;
			return;
		}
		pushdown(id);
		int mid = (L + R) >> 1;
		change(lson, L, mid, l, r, val);
		change(rson, mid + 1, R, l, r, val);
		update(id);
	}
	int query(int id, int L, int R, int l, int r){
		if (R < l || L > r)
			return 0;
		if (l <= L && R <= r){
			return t[id].sum;
		}
		pushdown(id);
		int mid = (L + R) >> 1;
		return query(lson, L, mid, l, r) + query(rson, mid + 1, R, l, r);
	}
}Seg_Tree;
int main(){
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		Tree.add(1, 1, n, i, i);
	}
	int opt, l, r, val;
	while (m--){
		cin >> opt;
		if (opt == 1){
			cin >> l >> r >> val;
			Tree.change(1, 1, n, l, r, val);
		}else{
			cin >> l >> r;
			cout << Tree.query(1, 1, n, l, r) << endl;
		}
	}
	return 0;
}