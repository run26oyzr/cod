#include <bits/stdc++.h>
using namespace std;
const int maxn = 5 * 1e4 + 5;
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
    #undef lson
    #undef rson
}Treap;
int a[maxn];
int n;
struct Segment_Tree{
    #define lson (id << 1)
    #define rson (id << 1 | 1)
    struct node{
        int rt;
    }t[maxn << 2];
    void del(int id, int L, int R, int pos, int val){
        Treap.del(t[id].rt, val);
        if (L == R && L == pos)
            return;
        int mid = (L + R) >> 1;
        if (pos <= mid)
            del(lson, L, mid, pos, val);
        else
            del(rson, mid + 1, R, pos, val);
    }
    void add(int id, int L, int R, int pos, int val){
        Treap.insert(t[id].rt, val);
        if (L == R && L == pos)
            return;
        int mid = (L + R) >> 1;
        if (pos <= mid)
            add(lson, L, mid, pos, val);
        else
            add(rson, mid + 1, R, pos, val);
    }
    int rank(int id, int L, int R, int l, int r, int val){
        if (L >= l && R <= r){
            return Treap.rank(t[id].rt, val);
        }
        int mid = (L + R) >> 1;
        if (r <= mid)
            return rank(lson, L, mid, l, r, val);
        else if (l > mid)
            return rank(rson, mid + 1, R, l, r, val);
        else
            return rank(lson, L, mid, l, r, val) + rank(rson, mid + 1, R, l, r, val) - 1;
    }
    int kth(int l, int r, int k){
        if (k == 0)
            return -2147483647;
        if (k > r - l + 1)
            return 2147483647;
        int L = 0, R = 1e8;
        while (L < R){
            int mid = (L + R + 1) >> 1;
            if (rank(1, 1, n, l, r, mid) > k)
                R = mid - 1;
            else
                L = mid;
        }
        return L;
    }
}Tree;
int main(){
    int m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        Tree.add(1, 1, n, i, a[i]);
    } 
    int opt, l, r, pos, k;
    while (m--){
        scanf("%d", &opt);
        if (opt == 1){
            scanf("%d %d %d", &l, &r, &k);
            cout << Tree.rank(1, 1, n, l, r, k) << endl;
        }else if (opt == 2){
            scanf("%d %d %d", &l, &r, &k);
            cout << Tree.kth(l, r, k) << endl;
        }else if (opt == 3){
            scanf("%d %d", &pos, &k);
            Tree.del(1, 1, n, pos, a[pos]);
            Tree.add(1, 1, n, pos, k);
            a[pos] = k;
        }else if (opt == 4){
            scanf("%d %d %d", &l, &r, &k);
            cout << Tree.kth(l, r, Tree.rank(1, 1, n, l, r, k) - 1) << endl;
        }else if (opt == 5){
            scanf("%d %d %d", &l, &r, &k);
            cout << Tree.kth(l, r, Tree.rank(1, 1, n, l, r, k + 1)) << endl;
        }
    }
    return 0;
}