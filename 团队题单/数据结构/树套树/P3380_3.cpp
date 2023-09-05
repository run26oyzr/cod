#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5, maxval = 1e8 + 1, logmaxval = 30;
struct Treap{
    #define lson (t[id].ch[0])
    #define rson (t[id].ch[1])
    struct Node{
        int val, rnd;
        int size;
        int ch[2];
    }t[maxn * 40];
    int tot = 0;
    int newNode(int val){
        ++tot;
        t[tot].size = 1;
        t[tot].rnd = rand();
        t[tot].val = val;
        t[tot].ch[0] = t[tot].ch[1] = 0;
        return tot;
    }
    void update(int id){
        t[id].size = 1 + t[lson].size + t[rson].size;
    }
    void split(int id, int val, int &x, int &y){
        if (!id) return (void)(x = y = 0);
        if (t[id].val <= val){
            x = id;
            split(rson, val, rson, y);
        }
        else{
            y = id;
            split(lson, val, x, lson);
        }
        update(id);
    }
    int merge(int x, int y){
        if (!x || !y) return x + y;
        if (t[x].rnd < t[y].rnd){
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
    void insert(int &rt, int val){
        int x, y;
        split(rt, val, x, y);
        rt = merge(merge(x, newNode(val)), y);
    }
    void del(int &rt, int val){
        int x, y, z;
        split(rt, val, y, z);
        split(y, val - 1, x, y);
        y = merge(t[y].ch[0], t[y].ch[1]);
        rt = merge(merge(x, y), z);
    }
    int rank(int &rt, int val){
        int x, y;
        split(rt, val - 1, x, y);
        int k = t[x].size + 1;
        rt = merge(x, y);
        return k;
    }
    int num(int &rt, int l, int r){
        int x, y, z;
        split(rt, r, y, z);
        split(y, l - 1, x, y);
        int k = t[y].size;
        rt = merge(merge(x, y), z);
        return k;
    }
    #undef lson
    #undef rson
}Treap;
int a[maxn];
int n;
struct Segment_Tree{
    struct node{
        int lson, rson;
        int rt;
    }t[maxn * logmaxval * 4];
    int tot = 0;
    int newNode(){
		++tot;
		t[tot].lson = t[tot].rson = 0;
		return tot;
	}
    void del(int &id, int L, int R, int pos, int val){
        Treap.del(t[id].rt, val);
        if (L == R && L == pos)
            return;
        int mid = (L + R) >> 1;
        if (pos <= mid)
            del(t[id].lson, L, mid, pos, val);
        else
            del(t[id].rson, mid + 1, R, pos, val);
    }
    void add(int &id, int L, int R, int pos, int val){
        if (!id)
            id = newNode();
        Treap.insert(t[id].rt, val);
        if (L == R && L == pos)
            return;
        int mid = (L + R) >> 1;
        if (pos <= mid)
            add(t[id].lson, L, mid, pos, val);
        else
            add(t[id].rson, mid + 1, R, pos, val);
    }
    int kth(int id, int L, int R, int l, int r, int k){
        if (L == R){
            return L;
        }
        int lsize = Treap.num(t[t[id].lson].rt, l, r);
        int mid = (L + R) >> 1;
        if (k <= lsize)
            return kth(t[id].lson, L, mid, l, r, k);
        else 
            return kth(t[id].rson, mid + 1, R, l, r, k - lsize);
    }
    int rank(int id, int L, int R, int l, int r, int val){
        if (val == 0)
            return 0;
        if (L == R){
            return Treap.num(t[id].rt, l, r);
        }
        int mid = (L + R) >> 1;
        if (val <= mid)
            return rank(t[id].lson, L, mid, l, r, val);
        else
            return Treap.num(t[t[id].lson].rt, l, r) + rank(t[id].rson, mid + 1, R, l, r, val);
    }
}Tree;
int rt;
int main(){
    srand(time(0));
    int m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        a[i]++;
        Tree.add(rt, 1, maxval, a[i], i);
    } 
    int opt, l, r, pos, k;
    while (m--){
        cin >> opt;
        if (opt == 1){
            cin >> l >> r >> k;
            k++;
            cout << Tree.rank(rt, 1, maxval, l, r, k - 1) + 1 << endl;
        }else if (opt == 2){
            cin >> l >> r >> k;
            cout << Tree.kth(rt, 1, maxval, l, r, k) - 1 << endl;
        }else if (opt == 3){
            cin >> pos >> k;
            k++;
            Tree.del(rt, 1, maxval, a[pos], pos);
            Tree.add(rt, 1, maxval, k, pos);
            a[pos] = k;
        }else if (opt == 4){
            cin >> l >> r >> k;
            k++;
            int rnk = Tree.rank(rt, 1, maxval, l, r, k - 1) + 1;
            if (rnk == 1){
                cout << -2147483647 << endl;
                continue;
            }
            cout << Tree.kth(rt, 1, maxval, l, r, rnk - 1) - 1 << endl;
        }else if (opt == 5){
            cin >> l >> r >> k;
            k++;
            int rnk = Tree.rank(rt, 1, maxval, l, r, k) + 1;
            if (rnk > r - l + 1){
                cout << 2147483647 << endl;
                continue;
            }
            cout << Tree.kth(rt, 1, maxval, l, r, rnk) - 1 << endl;
        }
    }
    return 0;
}