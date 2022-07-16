#include <bits/stdc++.h>
#define int long long
using namespace std;
#define lson (id << 1)
#define rson (id << 1 | 1)
const int maxn = 1e5 + 5;
struct Node{
    int left, right;
    int sum, lc, la;
};
Node t[maxn << 2];
int a[maxn];
int n, m, p;
int len(int id){
    return t[id].right - t[id].left + 1;
}
void pushdown(int id){
    t[lson].sum = t[lson].sum * t[id].lc + (t[id].la * len(lson)); t[lson].sum %= p;
    t[rson].sum = t[rson].sum * t[id].lc + (t[id].la * len(rson)); t[rson].sum %= p;
    t[lson].lc *= t[id].lc; t[lson].lc %= p;
    t[rson].lc *= t[id].lc; t[rson].lc %= p;
    // t[lson].la = (t[lson].la * t[id].lc % p + t[id].la); t[lson].lc %= p;
    // t[rson].la = (t[rson].la * t[id].lc % p + t[id].la); t[rson].lc %= p;
    // 不拆分成2个表达式运算是可以AC的，那应该是 t[lson].la * t[id].lc + t[id].la 正好会爆？
    t[lson].la = (t[lson].la * t[id].lc + t[id].la) % p;
    t[rson].la = (t[rson].la * t[id].lc + t[id].la) % p;
    t[id].lc = 1; t[id].la = 0;
}
void buildtree(int id, int L, int R){
    t[id].left = L, t[id].right = R, t[id].lc = 1, t[id].la = 0;
    if (L == R){
        t[id].sum = a[L];
    }
    else{
        int mid = (L + R) >> 1;
        buildtree(id << 1, L, mid);
        buildtree(id << 1 | 1, mid + 1, R);
        t[id].sum = t[id << 1].sum + t[id << 1 | 1].sum;
    }
    t[id].sum %= p;
}
void changemul(int id, int L, int R, int val){
    if (t[id].right < L || t[id].left > R) return;
    if (t[id].left >= L && t[id].right <= R){
        t[id].sum *= val; t[id].sum %= p;
        t[id].la *= val; t[id].la %= p;
        t[id].lc *= val; t[id].lc %= p;
        return;
    }
    pushdown(id);
    changemul(lson, L, R, val);
    changemul(rson, L, R, val);
    /* int mid = (t[id].left + t[id].right) >> 1;
	if (L <= mid) changemul(lson, L, R, val);
	if (R > mid) changemul(rson, L, R, val); */
    t[id].sum = (t[lson].sum + t[rson].sum) % p;
}
void changeadd(int id, int L, int R, int val){
    if (t[id].right < L || t[id].left > R) return;
    if (t[id].left >= L && t[id].right <= R){
        t[id].la += val; t[id].la %= p;
        t[id].sum += val * len(id); t[id].sum %= p;
        return;
    }
    pushdown(id);
    changeadd(lson, L, R, val);
    changeadd(rson, L, R, val);
    /* int mid = (t[id].left + t[id].right) >> 1;
	if (L <= mid) changeadd(lson, L, R, val);
	if (R > mid) changeadd(rson, L, R, val); */
    t[id].sum = (t[lson].sum + t[rson].sum) % p;
}
/* void change(int id, int L, int R, int val, int mod){
    if (t[id].left == L && t[id].right == R){
        if (mod == 1){
            t[id].sum *= val;
            t[id].lc *= val;
            t[id].la *= val;
        }
        else if (mod == 2){
            t[id].sum += val * len(id);
            t[id].la += val;
        }
        t[id].lc %= p;
        t[id].la %= p;
        t[id].sum %= p;
        return;
    }
    pushdown(id);
    if (R <= t[lson].right) change(lson, L, R, val, mod);
    else if (L >= t[rson].left) change(rson, L, R, val, mod);
    else {
        change(lson, L, t[lson].right, val, mod);
        change(rson, t[rson].left, R, val, mod);
    }
    update(id);
}
 */
int query(int id, int L, int R){
    // if (t[id].left == L && t[id].right == R){
    //     return t[id].sum;
    // }
    // pushdown(id);
    // if (R <= t[lson].right) return query(lson, L, R) % p;
    // else if (L >= t[rson].left) return query(rson, L, R) % p;
    // else {
    //     return (query(lson, L, t[lson].right) + query(rson, t[rson].left, R)) % p;
    // }
    if (t[id].right < L || t[id].left > R) return 0;
    if (t[id].left >= L && t[id].right <= R) return t[id].sum;
    pushdown(id);
    return (query(lson, L, R) + query(rson, L, R)) % p;
    /* int val = 0;
	int mid = (t[id].left + t[id].right) >> 1;
	if (L <= mid) val = (val + query(lson, L, R)) % p;
	if (R > mid) val = (val + query(rson, L, R)) % p;
	return val; */
}
signed main(){
    freopen("P3373.in", "r", stdin);
    freopen("P3373.out", "w", stdout);
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int x, y, z, k;
    buildtree(1, 1, n);
    // for (int i = 1; i <= n; i++){
    //         cout << t[pos[i]].sum << ' ';
    // }
    // cout << endl;
    while(m--){
        cin >> x;
        cin >> y >> z;
        if (x == 1){
            cin >> k;
            changemul(1, y, z, k);
        }
        else if (x == 2){
            cin >> k;
            changeadd(1, y, z, k);
        }
        else{
           cout << query(1, y, z) << endl;
        }
        // cout << "-----------------------------------------sum";
        // for (int i = 1; i <= n; i++){
        //     cout << query(1, i, i) << ' ';
        // }
        // cout << endl;
    }
    // system("Pause");
    return 0;
}