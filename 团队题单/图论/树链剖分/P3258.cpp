#include <bits/stdc++.h>
#define int long long
#define ls (id << 1)
#define rs (id << 1 | 1)
using namespace std;
const int maxn = 3 * 1e5 + 5;
int p;
struct Segment_Tree{
    int left, right;
    int sum, lazy;
}t[maxn << 2];
/** @brief
 * dfn:每个节点的新编号（可以保证每条重链和每个子树的编号连续）
 * rk:编号对应的节点
 * size:i及其子树中节点个数和
 * fa:i节点的父节点
 * son:i节点的重子节点
 * top:i节点所在的重链的顶端
 * dep:i节点在树中的深度
*/
int dfn[maxn], rk[maxn], size[maxn], fa[maxn], son[maxn], top[maxn], dep[maxn];
void update(int id){
    t[id].sum = t[ls].sum + t[rs].sum;
}
void pushdown(int id){
    t[ls].lazy += t[id].lazy;
    t[ls].sum += t[id].lazy * (t[ls].right - t[ls].left + 1);
    t[rs].lazy += t[id].lazy;
    t[rs].sum += t[id].lazy * (t[rs].right - t[rs].left + 1);
    t[id].lazy = 0;
}
int a[maxn];
void buildtree(int id, int L, int R){
    t[id].left = L, t[id].right = R, t[id].lazy = 0;
    if (L == R){
        t[id].sum = 0;
        return;
    }
    int mid = (L + R) / 2;
    buildtree(ls, L, mid);
    buildtree(rs, mid + 1, R);
    update(id);
}
void change(int id, int L, int R, int val){
    // cout << t[id].left << ' ' << t[id].right << endl;
    // cout << L << ' ' << R << endl;
    // cout << endl;
    if (t[id].left == L && t[id].right == R){
        t[id].lazy += val;
        t[id].sum += val * (R - L + 1);
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
int query(int id, int L, int R){
    // cout << t[id].left << ' ' << t[id].right << endl;
    // cout << L << ' ' << R << endl;
    // cout << endl;
    if (t[id].left == L && t[id].right == R){
        // cout << L << ' ' << R << ' ' << t[id].sum << endl;
        return t[id].sum;
    }
    pushdown(id);
    if (R < t[rs].left) return query(ls, L, R);
    else if (L > t[ls].right) return query(rs, L, R);
    else return query(ls, L, t[ls].right) + query(rs, t[rs].left, R);
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
        if (size[son[u]] < size[v])
            son[u] = v;
    }
}
int cnt = 0;
void dfs2(int u, int Top){
    top[u] = Top;
    dfn[u] = ++cnt;
    rk[cnt] = u;
    if (!son[u]) return;
    dfs2(son[u], Top);
    for (int i = h[u]; i; i = e[i].next){
        int v = e[i].v;
        if (v != son[u] && v != fa[u])
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
    // cout << "query_Path-1" << endl;
    int res = 0;
    //不在同一条重链中
    while(top[x] != top[y]){
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        res += query(1, dfn[top[x]], dfn[x]);
        x = fa[top[x]];
    }
    //在同一条重链中
    if (dep[x] > dep[y]) swap(x, y);
    // cout << "query_Path-2" << endl;
    // cout << dep[x] << ' ' << dep[y] << endl;
    // cout << dfn[x] << ' ' << dfn[y] << endl;
    res += query(1, dfn[x], dfn[y]);
    return res;
}
void change_Tree(int rt, int val){
    // cout << dfn[rt] << ' ' << dfn[rt] + size[rt] - 1 << endl;
    // cout << rk[dfn[rt]] << ' ' << rk[dfn[rt] + size[rt] - 1] << endl;
    change(1, dfn[rt], dfn[rt] + size[rt] - 1, val);
}
int query_Tree(int rt){
    return query(1, dfn[rt], dfn[rt] + size[rt] - 1);
}
signed main(){
    int n, r = 1;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int u, v;
    for (int i = 1; i <= n - 1; i++){
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }
    dfs1(r, 0, 1);
    dfs2(r, r);
    buildtree(1, 1, n);
    for (int i = 1; i <= n - 1; i++){
        change_Path(a[i], a[i + 1], 1);
        change(1, dfn[a[i + 1]], dfn[a[i + 1]], -1);
        // for (int j = 1; j <= n; j++){
        //     printf("%lld ", query(1, dfn[j], dfn[j]));
        // }
        // cout << endl;
    }
    for (int i = 1; i <= n; i++){
        printf("%lld\n", query(1, dfn[i], dfn[i]));
    }
    return 0;
}