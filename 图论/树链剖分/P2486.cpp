#include <bits/stdc++.h>
#define int long long
#define ls (id << 1)
#define rs (id << 1 | 1)
using namespace std;
const int maxn = 1e5 + 5;
int p;
struct Segment_Tree{
    int left, right;
    int lval, rval;
    int lazy;
    int ans;
}t[maxn << 2];
int dfn[maxn], rk[maxn], size[maxn], fa[maxn], wson[maxn], top[maxn], dep[maxn];
void update(int id){
    t[id].lval = t[ls].lval;
    t[id].rval = t[rs].rval;
    t[id].ans = t[ls].ans + t[rs].ans;
    if (t[ls].rval == t[rs].lval) t[id].ans--;
}
void pushdown(int id){
    if (t[id].lazy == -1) return; 
    t[ls].lazy = t[id].lazy;
    t[ls].lval = t[id].lazy;
    t[ls].rval = t[id].lazy;
    t[ls].ans = 1;
    t[rs].lazy = t[id].lazy;
    t[rs].lval = t[id].lazy;
    t[rs].rval = t[id].lazy;
    t[rs].ans = 1;
    t[id].lazy = -1;
}
int a[maxn];
void buildtree(int id, int L, int R){
    t[id].left = L, t[id].right = R, t[id].lazy = -1;
    if (L == R){
        t[id].lval = t[id].rval = a[rk[L]];
        t[id].ans = 1;
        return;
    }
    int mid = (L + R) / 2;
    buildtree(ls, L, mid);
    buildtree(rs, mid + 1, R);
    update(id);
}
void change(int id, int L, int R, int val){
    if (t[id].left == L && t[id].right == R){
        t[id].lazy = val;
        t[id].lval = val;
        t[id].rval = val;
        t[id].ans = 1;
        return;
    }
    pushdown(id);
    if (R < t[rs].left) change(ls, L, R, val);
    else if (L > t[ls].right) change(rs, L, R, val);
    else{
        change(ls, L, t[ls].right, val);
        change(rs, t[rs].left, R, val);
    }
    update(id);
}
Segment_Tree query(int id, int L, int R){
    if (t[id].left == L && t[id].right == R){
        return t[id];
    }
    pushdown(id);
    if (R < t[rs].left) return query(ls, L, R);
    else if (L > t[ls].right) return query(rs, L, R);
    else{
        Segment_Tree lans = query(ls, L, t[ls].right);
        Segment_Tree rans = query(rs, t[rs].left, R);
        Segment_Tree res;
        res.lval = lans.lval;
        res.rval = rans.rval;
        res.ans = lans.ans + rans.ans;
        if(lans.rval == rans.lval) res.ans--;
        return res;
    }
}
struct Node{
    int v, next;
}e[maxn << 1];
int tot, h[maxn];
void addEdge(int u, int v){
    ++tot;
    e[tot].v = v;
    e[tot].next = h[u];
    h[u] = tot;
}
void dfs1(int u, int father, int depth){
    fa[u] = father;
    dep[u] = depth;
    size[u] = 1;
    for (int i = h[u]; i; i = e[i].next){
        int v = e[i].v;
        if (v == father) continue;
        dfs1(v, u, depth + 1);
        size[u] += size[v];
        if (size[wson[u]] < size[v])
            wson[u] = v;
    }
}
int cnt = 0;
void dfs2(int u, int Top){
    top[u] = Top;
    dfn[u] = ++cnt;
    rk[cnt] = u;
    if (!wson[u]) return;
    dfs2(wson[u], Top);
    for (int i = h[u]; i; i = e[i].next){
        int v = e[i].v;
        if (v != wson[u] && v != fa[u])
            dfs2(v, v);
    }
}
void change_Path(int x, int y, int val){
    //不在同一条重链中
    while(top[x] != top[y]){
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        change(1, dfn[top[x]], dfn[x], val);
        x = fa[top[x]];
    }
    //在同一条重链中
    if (dep[x] > dep[y]) swap(x, y);
    change(1, dfn[x], dfn[y], val);
}
int query_Path(int x, int y){
    //不在同一条重链中
    int ans = 0;
    int lastx = 0, lasty = 0;
    while(top[x] != top[y]){
        if (dep[top[x]] < dep[top[y]]){
            Segment_Tree tmp = query(1, dfn[top[y]], dfn[y]);
            ans += tmp.ans;
            if (lasty == tmp.rval) ans--;
            lasty = tmp.lval;
            y = fa[top[y]];
        }else{
            Segment_Tree tmp = query(1, dfn[top[x]], dfn[x]);
            ans += tmp.ans;
            if (lastx == tmp.rval) ans--;
            lastx = tmp.lval;
            x = fa[top[x]];
        }
    }
    //在同一条重链中
    if (dep[x] > dep[y]){
        Segment_Tree tmp = query(1, dfn[y], dfn[x]);
        ans += tmp.ans;
        if (tmp.lval == lasty) ans--;
        if (tmp.rval == lastx) ans--;
    }else{
        Segment_Tree tmp = query(1, dfn[x], dfn[y]);
        ans += tmp.ans;
        if (tmp.lval == lastx) ans--;
        if (tmp.rval == lasty) ans--;
    }
    return ans;
}
signed main(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int u, v;
    for (int i = 1; i <= n - 1; i++){
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }
    int r = 1;
    dfs1(r, 0, 1);
    dfs2(r, r);
    buildtree(1, 1, n);
    char opt;
    int x, y, c;
    while(m--){
        cin >> opt;
        if (opt == 'C'){
            cin >> x >> y >> c;
            change_Path(x, y, c);
        }else if (opt == 'Q'){
            cin >> x >> y;
            cout << query_Path(x, y) << endl;
        }
        // for (int i = 1; i <= n; i++){
            // cout << query(1, dfn[i], dfn[i]) << ' ';
            // cout << query_Path(i, i) << ' ';
        // }
        // cout << endl;
    }
    return 0;
}