#include <bits/stdc++.h>
#define lson (id << 1)
#define rson (id << 1 | 1)
using namespace std;
const int maxn = 1e5 + 5;
struct Node{
    int left, right;
    int maxs, rsum, lsum, sum;
};
Node t[maxn << 2];
int pos[maxn], a[maxn];
int n;
int max(int x, int y, int z){
    return max(max(x, y), z);
}
void update(int id){
    t[id].maxs = max(t[lson].maxs, t[rson].maxs, t[lson].rsum + t[rson].lsum);
    t[id].lsum = max(t[lson].lsum, t[lson].sum + t[rson].lsum);
    t[id].rsum = max(t[rson].rsum, t[rson].sum + t[lson].rsum);
    t[id].sum = t[lson].sum + t[rson].sum;
}
void build(int l,int r,int id){
	t[id].left = l,t[id].right = r;
	if (l == r){
		t[id].sum = a[l];
		t[id].lsum = t[id].rsum = t[id].maxs = a[l];
		pos[l] = id;
		return;
	}
	int mid = (l+r)>>1;
	build(l,mid,lson);
	build(mid+1,r,rson);
	update(id);
}
void change(int id, int c){
    t[id].lsum = t[id].rsum = t[id].sum = t[id].maxs = c;
    id >>= 1;
    while (id){
        update(id);
        id >>= 1;
    }
}
Node query(int id, int L, int R){
    if (t[id].left == L && t[id].right == R) return t[id];
    if (R <= t[lson].right) return query(lson, L, R);
    if (L >= t[rson].left)  return query(rson, L, R);
    else {
        Node ls = query(lson, L, t[lson].right);
        Node rs = query(rson, t[rson].left, R);
        Node now;
        now.maxs = max(ls.maxs, rs.maxs, ls.rsum + rs.lsum);
        now.lsum = max(ls.lsum, ls.sum + rs.lsum);
        now.rsum = max(rs.rsum, rs.sum + ls.rsum);
        now.sum = ls.sum + rs.sum;
        return now;
    }
}
int main(){
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int m;
    cin >> m;
    int x, y, z;
    build(1, n, 1);
    while(m--){
        cin >> x >> y >> z;
        if (x == 0){
            change(pos[y], z);
        }
        else{
            cout << query(1, y, z).maxs << endl;
        }
    }
    system("Pause");
    return 0;
}