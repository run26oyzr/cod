#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int a[maxn], rt[maxn];
struct Segment_Tree{
	int tot;
	struct Node{
		int lson, rson;
		int val;
	}t[maxn * 40];
	int newNode(int p){
		++tot; //回收空间 --top 
		t[tot] = t[p];
		return tot;
	}
	void buildtree(int &id, int L, int R){
		id = ++tot;
		t[id].val = 0;
		if (L == R){
			t[id].val = a[L];
			return;
		}
		int mid = (L + R) >> 1;
		buildtree(t[id].lson, L, mid);
		buildtree(t[id].rson, mid + 1, R);
	}
	void change(int pre, int &id, int L, int R, int pos, int c){
		id = newNode(pre);
		if (L == pos && R == pos){
			t[id].val = c;
			return;
		}
		int mid = (L + R) >> 1;
		if (pos <= mid)
			change(t[pre].lson, t[id].lson, L, mid, pos, c);
		else
			change(t[pre].rson, t[id].rson, mid + 1, R, pos, c);
	}
	int query(int id, int L, int R, int pos){
		if (L == pos && R == pos){
			return t[id].val;
		}
		int mid = (L + R) >> 1;
		if (pos <= mid)
			return query(t[id].lson, L, mid, pos);
		else
			return query(t[id].rson, mid + 1, R, pos);
	}
}Seg_Tree;
int main(){
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	Seg_Tree.buildtree(rt[0], 1, n);
	int op, ver, pos, val;
	for (int i = 1; i <= m; i++){
		scanf("%d %d", &ver, &op);
		if (op == 1){
			scanf("%d %d", &pos, &val);
			Seg_Tree.change(rt[ver], rt[i], 1, n, pos, val);
		}else{
			scanf("%d", &pos);
			rt[i] = rt[ver];
			printf("%d\n", Seg_Tree.query(rt[ver], 1, n, pos));
		}
	}
	return 0;
}