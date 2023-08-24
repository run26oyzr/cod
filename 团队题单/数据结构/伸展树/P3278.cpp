#include <bits/stdc++.h>
#define int long long
using namespace std;
#define ls t[id].ch[0]
#define rs t[id].ch[1]
const int mod = 20130426;
const int maxn = 1e5 + 5;
struct Node{
    int rnd;
    int size;
    int ch[2];
    int la, lc;//lc 乘法，la加法
    int sum;
}t[maxn << 2];
int tot = 0;
int newNode(){
    ++tot;
    t[tot].size = 1;
    t[tot].rnd = rand();
    t[tot].ch[0] = t[tot].ch[1] = 0;
    t[tot].la = 0, t[tot].lc = 1, t[tot].sum = 0;
    return tot;
}
void pushdown(int id){
    if(t[id].lc != 1){
        t[ls].lc *= t[id].lc; t[ls].lc %= mod;
        t[ls].la *= t[id].lc; t[ls].la %= mod;
        t[ls].sum *= t[id].lc; t[ls].sum %= mod;
        t[rs].lc *= t[id].lc; t[rs].lc %= mod;
        t[rs].la *= t[id].lc; t[rs].la %= mod;
        t[rs].sum *= t[id].lc; t[rs].sum %= mod;
        t[id].lc = 1;    
	}
	if(t[id].la){
        t[ls].la += t[id].la; t[ls].la %= mod;
        t[ls].sum += t[id].la; t[ls].sum %= mod;
        t[rs].la += t[id].la; t[rs].la %= mod;
        t[rs].sum += t[id].la; t[rs].sum %= mod;
		t[id].la = 0;
	}
	return;
} 
void update(int id){
    t[id].size = 1 + t[ls].size + t[rs].size;
}
void splitk(int id, int k, int &x, int &y){
    if (!id) return (void)(x = y = 0);
    pushdown(id);
    int lsize = t[ls].size;
    if (k <= lsize)
        y = id, splitk(t[y].ch[0], k, x, t[y].ch[0]);
    else
        x = id, splitk(t[x].ch[1], k - lsize - 1, t[x].ch[1], y);
    update(id);
}

int merge(int x, int y){
    if (!x || !y) return x + y;
    pushdown(x); pushdown(y);
    if (t[x].rnd <= t[y].rnd){ //heap
        t[x].ch[1] = merge(t[x].ch[1], y);
        update(x);
        return x;
    }
    else{
        t[y].ch[0] = merge(x, t[y].ch[0]);
        update(y);
        return y;
    }
}
int rt = 0;
void change(int l, int r, int opt, int val){
    int x, y, z;
    splitk(rt, l, x, y);
    splitk(y, r - l + 1, y, z);
    if (opt == 1) t[y].lc *= val, t[y].sum *= val;
    if (opt == 2) t[y].la += val, t[y].sum += val;
    t[y].la %= mod, t[y].lc %= mod, t[y].sum %= mod;
    rt = merge(merge(x, y), z);
}
void mulx(int l, int r){
    int x1, x2, x3, x4;
    splitk(rt, r, x1, x2);
    splitk(x2, 1, x2, x3);
    splitk(x3, 1, x3, x4);
    t[x3].sum += t[x2].sum; t[x3].sum %= mod;
    rt = merge(x1, merge(x3, x4));
    x2 = newNode();
    splitk(rt, l, x1, x3);
    rt = merge(merge(x1, x2), x3);
}
long long mul = 1;
long long ans = 0;
bool first_ = false;
void inorder(int id, int x){
    if (!id) return;
    pushdown(id);
    if (ls) inorder(ls, x);
    // if (t[id].sum != 0) cout << t[id].sum << ' ' << mul << endl;
    ans += mul * t[id].sum; ans %= mod;
    if (first_) {mul *= x; mul %= mod;} else first_ = true;
    if (rs) inorder(rs, x);
}
signed main(){
    // freopen("./data_structure/splay/P3278.in", "r", stdin);
    // freopen("./data_structure/splay/P3278.out", "w", stdout);
    int n;
    cin >> n;
    string s;
    int l, r, val;
    for (int i = 1; i < 2 * maxn; i++){
        rt = merge(rt, newNode());
    }
    while(n--){
        cin >> s;
        if (s == "mul"){
            cin >> l >> r >> val;
            change(l + 1, r + 1, 1, val);
        }
        if (s == "add"){
            cin >> l >> r >> val;
            change(l + 1, r + 1, 2, val);
        }
        if (s == "mulx"){
            cin >> l >> r;
            mulx(l + 1, r + 1);
        }
        if (s == "query"){
            cin >> val;
            mul = 1;
            ans = 0;
            first_ = false;
            inorder(rt, val);
            // cout << endl;
            cout << ans << endl;
        }
    }
    return 0;
}