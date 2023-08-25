#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2 * 1e5 + 5;
int rt[maxn];
int s[maxn], e[maxn], p[maxn], a[maxn];
struct Segment_Tree{
	int tot;
	struct Node{
		int lson, rson;
		int size, sum;
        int val;
	}t[maxn * 40];
	int newNode(int p){
		++tot;
		t[tot] = t[p];
		return tot;
	}
	void update(int id){
		t[id].size = t[t[id].lson].size + t[t[id].rson].size;
        t[id].sum = t[t[id].lson].sum + t[t[id].rson].sum;
	}
	void change(int pre, int &id, int L, int R, int pos, int c){
		id = newNode(pre);
		if (L == pos && R == pos){
			t[id].size += c;
            t[id].sum += c * p[L];
            t[id].val = p[L];
			return;
		}
		int mid = (L + R) >> 1;
		if (pos <= mid)
			change(t[pre].lson, t[id].lson, L, mid, pos, c);
		else
			change(t[pre].rson, t[id].rson, mid + 1, R, pos, c);
		update(id);
	}
	int query(int id, int L, int R, int k){
		if (L >= R){
			return min(t[id].sum, t[id].val * k);
		}
		int mid = (L + R) >> 1;
 		if (t[t[id].lson].size >= k)
			return query(t[id].lson, L, mid, k);
		else 
			return t[t[id].lson].sum + query(t[id].rson, mid + 1, R, k - t[t[id].lson].size);
	}
}Seg_Tree;
struct Node{
    int ver, pos, val;
    bool operator < (const Node T) const{
        return ver < T.ver;
    } 
}t[maxn];
signed main(){
	int n, m;
	cin >> n >> m;
    int l, r;
	for (int i = 1; i <= n; i++){
		cin >> l >> r >> p[i];
        t[i * 2 - 1].ver = l; t[i * 2 - 1].val = 1;
        t[i * 2].ver = r + 1; t[i * 2].val = -1;
		a[i] = p[i];
	}
	sort(p + 1, p + n + 1);
	int nn = unique(p + 1, p + n + 1) - p - 1;
	for (int i = 1; i <= n; i++)
		a[i] = lower_bound(p + 1, p + nn + 1, a[i]) - p;
    for (int i = 1; i <= n; i++)
        t[i * 2 - 1].pos = t[i * 2].pos = a[i];
    sort(t + 1, t + 2 * n + 1);
	for (int i = 1; i <= 2 * n; i++){
		Seg_Tree.change(rt[t[i - 1].ver], rt[t[i].ver], 1, nn, t[i].pos, t[i].val);
        for (int j = t[i - 1].ver + 1; j < t[i].ver; j++){
            rt[j] = rt[t[i - 1].ver];
        }
    }
	int x, a, b, c, k;
    int pre = 1;
	while (m--){
		cin >> x >> a >> b >> c;
        k = 1 + (a * pre + b) % c;
        pre = Seg_Tree.query(rt[x], 1, nn, k);
		cout << pre << endl;
	}
	return 0;
}