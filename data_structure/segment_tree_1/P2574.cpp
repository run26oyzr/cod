#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2 * 1e5 + 5;
struct Node{
	int left, right;
	int sum, lazy;
};
int n, m, a[maxn];
Node t[maxn << 2];
void update(int id){
	t[id].sum = t[id << 1].sum + t[id << 1 | 1].sum;
}
void pushdown(int id){
	if (t[id].lazy){
		t[id << 1].sum = t[id << 1].right - t[id << 1].left + 1 - t[id << 1].sum;
		t[id << 1 | 1].sum = t[id << 1 | 1].right - t[id << 1 | 1].left + 1 - t[id << 1 | 1].sum;
		t[id << 1].lazy ^= 1;
		t[id << 1 | 1].lazy ^= 1;
		t[id].lazy = 0; 
	}
}
void buildtree(int id, int L, int R){
	t[id].left = L, t[id].right = R, t[id].lazy = 0;
	if (L == R){
		t[id].sum = a[L];
		return;
	}
	int mid = (L + R) >> 1;
	buildtree(id << 1, L, mid);
	buildtree(id << 1 | 1, mid + 1, R);
	update(id);
}
void change(int id, int L, int R){
	if (t[id].left == L && t[id].right == R){
		t[id].sum = t[id].right - t[id].left + 1 - t[id].sum;
		t[id].lazy ^= 1;
		return;
	}
	pushdown(id);
	if (R <= t[id << 1].right) change(id << 1, L, R);
	else if (t[id << 1 | 1].left <= L) change(id << 1 | 1, L, R);
	else {
		change(id << 1, L, t[id << 1].right);
		change(id << 1 | 1, t[id << 1 | 1].left, R);
	}
	update(id);
}
int query(int id, int L, int R){
	if (t[id].left == L && t[id].right == R){
		return t[id].sum;
	}
	pushdown(id);
	if (R <= t[id << 1].right) return query(id << 1, L, R);
	else if (t[id << 1 | 1].left <= L) return query(id << 1 | 1, L, R);
	else 
		return query(id << 1, L, t[id << 1].right) + query(id << 1 | 1, t[id << 1 | 1].left, R);
}
signed main()
{
	cin >> n >> m;
	char c;
	for (int i = 1; i <= n; i++){
		cin >> c;
		a[i]  = c - '0';
	}
	buildtree(1, 1, n);
	while (m--){
		int x, y, z;
		cin >> x >> y >> z;
		if (x == 0) change(1, y, z);
		else if (x == 1) cout << query(1, y, z) << endl;
	}
	return 0;
}
