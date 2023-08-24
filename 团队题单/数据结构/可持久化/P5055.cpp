#include <bits/stdc++.h>
#define int long long
#define lson ch[0]
#define rson ch[1]
using namespace std;
const int maxn = 2 * 1e5 + 5;
int rt[maxn];
struct Persistant_Treap{
    struct Node{
        int size, rnd;
        int ch[2];
        int val, sum, rev;
    }t[60 * maxn];
    //TODO 空间开到40*maxn就会WA,60*maxn就A了?
    int tot = 0;
    int newNode(int val){
        ++tot;
        t[tot].size = 1;
        t[tot].rnd = rand();
        t[tot].val = t[tot].sum = val;
        t[tot].rev = 0;
        t[tot].lson = t[tot].rson = 0;
        return tot;
    }
    int copyNode(int p){
        ++tot; 
        t[tot] = t[p];
        return tot;
    }
    void update(int id){
        t[id].size = t[t[id].lson].size + t[t[id].rson].size + 1;
        t[id].sum = t[t[id].lson].sum + t[t[id].rson].sum + t[id].val;
    }
    void pushdown(int id){
        if (t[id].rev){
            if (t[id].lson)
                t[id].lson = copyNode(t[id].lson);
            if (t[id].rson)
                t[id].rson = copyNode(t[id].rson);
            swap(t[id].lson, t[id].rson);
            t[t[id].lson].rev ^= 1;
            t[t[id].rson].rev ^= 1;
            t[id].rev = 0;
        }
    }
    void splitk(int id, int k, int &x, int &y){
        if (!id) return (void)(x = y = 0);
        pushdown(id);
        if (t[t[id].lson].size < k){
            x = copyNode(id);
            splitk(t[x].rson, k - t[t[id].lson].size - 1, t[x].rson, y);
            update(x);
        }
        else{
            y = copyNode(id);
            splitk(t[y].lson, k, x, t[y].lson);
            update(y);
        }
    }
    int merge(int x, int y){
        if (!x || !y) return x + y;
        pushdown(x); pushdown(y);
        if (t[x].rnd < t[y].rnd){
            t[x].rson = merge(t[x].rson, y);
            update(x);
            return x;
        }
        else{
            t[y].lson = merge(x, t[y].lson);
            update(y);
            return y;
        }
    }
    void insert(int &root, int pos, int val){
        int x = 0, y = 0;
        splitk(root, pos, x, y);
        root = merge(merge(x, newNode(val)), y);
    }
    void del(int &root, int pos){
        int x = 0, y = 0, z = 0;
        splitk(root, pos, y, z);
        splitk(y, pos - 1, x, y);
        root = merge(x, z);
    }
}treap;
signed main(){
    srand(time(0));
    int n;
    cin >> n;
    rt[0] = 0;
    int ver, op, x, y;
    int lastans = 0;
    for (int i = 1; i <= n; i++){
        cin >> ver >> op;
        rt[i] = rt[ver];
        if (op == 1){
            cin >> x >> y;
            x ^= lastans; y ^= lastans;
            treap.insert(rt[i], x, y);
        }else if (op == 2){
            cin >> x;
            x ^= lastans;
            treap.del(rt[i], x);
        }else if (op == 3){
            cin >> x >> y;
            x ^= lastans; y ^= lastans;
            int a = 0, b = 0, c = 0;
            treap.splitk(rt[i], y, b, c);
            treap.splitk(b, x - 1, a, b);
            treap.t[b].rev ^= 1;
            rt[i] = treap.merge(treap.merge(a, b), c);
        }else if (op == 4){
            cin >> x >> y;
            x ^= lastans; y ^= lastans;
            int a = 0, b = 0, c = 0;
            treap.splitk(rt[i], y, b, c);
            treap.splitk(b, x - 1, a, b);
            lastans = treap.t[b].sum;
            cout << lastans << endl;
            rt[i] = treap.merge(treap.merge(a, b), c);
        }
    }
    return 0;
}