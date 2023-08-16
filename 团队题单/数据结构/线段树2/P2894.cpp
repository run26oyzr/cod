#include <bits/stdc++.h>
#define lson (id << 1)
#define rson ((id << 1 ) | 1)
using namespace std;
const int maxn = 5 * 1e5 + 5;
struct Node{
    int left, right;
    int maxs, rsum, lsum, lazy;
};
Node t[maxn << 2];
int pos[maxn], a[maxn];
int n;
int max(int x, int y, int z){
    return max(max(x, y), z);
}
int len(int id){
    return t[id].right - t[id].left + 1;
}
void update(int id){
    t[id].maxs = max(t[lson].maxs, t[rson].maxs, t[lson].rsum + t[rson].lsum);
//     t[id].lsum = t[lson].lsum;
//     if (t[id].lsum == len(lson)) t[id].lsum += t[rson].lsum;
//     t[id].rsum = t[rson].rsum;
//     if (t[id].rsum == len(rson)) t[id].rsum += t[lson].rsum;
    if(t[lson].lsum == len(lson)) 
        t[id].lsum = t[lson].lsum + t[rson].lsum;
    else 
        t[id].lsum = t[lson].lsum;
    
    if(t[rson].rsum == len(rson))
        t[id].rsum = t[rson].rsum + t[lson].rsum;
    else
        t[id].rsum = t[rson].rsum;
}
void pushdown(int id){
    if (t[id].lazy == 2){
        t[rson].lazy = t[lson].lazy = 2;
        t[lson].lsum = t[lson].rsum = t[lson].maxs = 0;
        t[rson].lsum = t[rson].rsum = t[rson].maxs = 0;
    } 
    else if(t[id].lazy == 1){
        t[rson].lazy = t[lson].lazy = 1;
        t[lson].lsum = t[lson].lsum = t[lson].maxs = len(lson);
        t[rson].lsum = t[rson].lsum = t[rson].maxs = len(rson);
    }
    t[id].lazy = 0;
}
void build(int l,int r,int id){
	t[id].left = l, t[id].right = r;
	if (l == r){
        t[id].lsum = t[id].rsum = t[id].maxs = 1;
        return;
    }
	int mid = (l+r)>>1;
    t[id].lsum = t[id].rsum = t[id].maxs = r - l + 1;
	build(l,mid,lson);
	build(mid+1,r,rson);
	// update(id);
}
void change(int id, int L, int R, int lazy){
    if(t[id].left == L && t[id].right == R){
        if (lazy == 1){
            // cout << "1: "<< L << " " << R << endl;
            t[id].maxs = t[id].lsum = t[id].rsum = len(id);
            // for (int i = L; i <= R; i++) pos[i] = 1;
        }
        else if (lazy == 2){
            t[id].maxs = t[id].lsum = t[id].rsum = 0;
            // for (int i = L; i <= R; i++) pos[i] = 0;
        }
        t[id].lazy = lazy;
        return;
    }
    pushdown(id);
    if (R <= t[lson].right) change(lson, L, R, lazy);
	else if (t[rson].left <= L) change(rson, L, R, lazy);
	else {
		change(lson, L, t[lson].right, lazy);
		change(rson, t[rson].left, R, lazy);
	}
    update(id);
    // cout << "-------------------------------------------2r" << t[2].rsum << endl;

}
int query(int id, int Len, int L, int R){
    pushdown(id);
    if (L == R) return L;
    int mid = (L + R) >> 1;
    if (t[lson].maxs >= Len) return query(lson, Len, L, mid);
    else if (t[lson].rsum + t[rson].lsum >= Len) return mid - t[lson].rsum + 1;
    else return query(rson, Len, mid + 1, R);
}
int main(){
    // freopen ("P2894.in", "r", stdin);
    cin >> n;
    int m;
    cin >> m;
    int x, y, z;
    build(1, n, 1);
    for (int i = 1; i <= n; i++) pos[i] = 1;
    while(m--){
        cin >> x;
        if (x == 1){
            cin >> y;
            if (t[1].maxs >= y){
                z = query(1, y, 1, n);
                cout << z << endl;
                change(1, z, z + y - 1, 2);
            }
            else cout << 0 << endl;
        }
        else{
            cin >> y >> z;
            // cout << "!!!!!!!!!!!!!!!!!!!!!!!!!"<< y << endl;
            change(1, y, y + z - 1, 1);
        }
        // cout << "-----------------------------------empty";
        // for (int i = 1; i <= n; i++){
        //     cout << pos[i] << ' ';
        // }
        // cout << endl;
        // cout << "-------------------------------------------2r" << t[2].rsum << endl;
    }
    // system("Pause");
    return 0;
}