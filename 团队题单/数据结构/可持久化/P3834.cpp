#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
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
	int query(int l, int r, int L, int R, int k){
		if (L >= R){
			return b[L];
		}
		int mid = (L + R) >> 1;
 		if (t[t[r].lson].size - t[t[l].lson].size >= k)
			return query(t[l].lson, t[r].lson, L, mid, k);
		else 
			return query(t[l].rson, t[r].rson, mid + 1, R, k - (t[t[r].lson].size - t[t[l].lson].size));
	}
}Seg_Tree;
int main(){
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	sort(b + 1, b + n + 1);
	int nn = unique(b + 1, b + n + 1) - b - 1;
	for (int i = 1; i <= n; i++)
		a[i] = lower_bound(b + 1, b + nn + 1, a[i]) - b;
	for (int i = 1; i <= n; i++)
		Seg_Tree.change(rt[i - 1], rt[i], 1, n, a[i], 1);
	int l, r, k;
	while (m--){
		scanf("%d %d %d", &l, &r, &k);
		cout << Seg_Tree.query(rt[l - 1], rt[r], 1, n, k) << endl;
	}
	return 0;
}