#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;
long long n;
const long long p = 998244353;
const long long maxn = 100009;
const long long maxlg = 18;
// Treap
long long bigrand()
{
    return (rand() << 15) + rand();
}
struct Treap
{
    long long l, r, rnd, size;
    long long val, sum, lazy;
    bool rev;
    Treap()
    {
        l = 0, r = 0, val = 0, sum = 0, rnd = 0, size = 0, lazy = 1;
    }
    Treap(long long a)
    {
        l = 0, r = 0, val = a, sum = a, rnd = bigrand(), size = 1, lazy = 1;
    }
} st[maxn * 4];
long long rt = 0;
long long pos = 0;
long long allocate(Treap x)
{
    st[++pos] = x;
    return pos;
}
void add(long long id, long long a)
{
    st[id].val = (st[id].val + a) % p;
    st[id].sum = (st[id].sum + st[id].size * a % p) % p;
    st[id].lazy = (st[id].lazy + a) % p;
}
void rev(long long id)
{
    swap(st[id].l, st[id].r);
    st[id].rev ^= 1;
}
void pushdown(long long id)
{
    if (st[id].rev)
    {
        rev(st[id].l);
        rev(st[id].r);
        st[id].rev = 0;
    }
    add(st[id].l, st[id].lazy);
    add(st[id].r, st[id].lazy);
    st[id].lazy = 0;
}
void pushup(long long id)
{
    st[id].size = (st[st[id].l].size + st[st[id].r].size + 1) % p;
    st[id].sum = (st[st[id].l].sum + st[st[id].r].sum + st[id].val) % p;
}
void split(long long id, long long k, long long &x, long long &y)
{
    if (!id)
        x = y = 0;
    else
    {
        pushdown(id);
        long long ls = st[st[id].l].size;
        if (k - 1 <= ls)
        {
            split(st[id].l, k, x, st[id].l);
            y = id;
        }
        else
        {
            split(st[id].r, k - ls - 1, st[id].r, y);
            x = id;
        }
        pushup(id);
    }
}
long long merge(long long a, long long b)
{
    if (!a || !b)
        return a | b;
    if (st[a].rnd < st[b].rnd)
    {
        pushdown(a);
        st[a].r = merge(st[a].r, b);
        pushup(a);
        return a;
    }
    else
    {
        pushdown(b);
        st[b].l = merge(a, st[b].l);
        pushup(b);
        return b;
    }
}
void addRange(long long l, long long r, long long c)
{
    long long x, y, z;
    split(rt, r, y, z);
    split(y, l, x, y);
    add(y, c);
    rt = merge(merge(x, y), z);
}
long long queryRange(long long l, long long r)
{
    long long x, y, z;
    split(rt, r, y, z);
    split(y, l, x, y);
    long long res = st[y].sum;
    rt = merge(merge(x, y), z);
    return res;
}
// Graph (Tree)
long long w1[maxn << 1];
struct Node
{
    long long fa, size, hson, top, id, w0, depth;
    long long begin;
} nodes[maxn];
long long cid = 1;
long long ep = 2, nxt[maxn << 1], to[maxn << 1];
void connect(long long u, long long v)
{
    to[ep] = v;
    nxt[ep] = nodes[u].begin;
    nodes[u].begin = ep;
    ep++;
}
long long stat(long long a, long long f, long long depth)
{
    long long res = 1;
    nodes[a].fa = f;
    nodes[a].depth = depth;
    for (long long e = nodes[a].begin; e; e = nxt[e])
    {
        if (to[e] == f)
            continue;
        long long sz = stat(to[e], a, depth + 1);
        if (sz >= nodes[nodes[a].hson].size)
            nodes[a].hson = to[e];
        res += sz;
    }
    nodes[a].size = res;
    return res;
}
void dfs(long long a, long long f)
{
    nodes[a].id = cid++;
    if (a == nodes[f].hson)
        nodes[a].top = nodes[f].top;
    else
        nodes[a].top = a;
    w1[nodes[a].id] = nodes[a].w0;
    if (nodes[a].hson != 0)
        dfs(nodes[a].hson, a);
    for (long long e = nodes[a].begin; e; e = nxt[e])
    {
        if (to[e] == f || to[e] == nodes[a].hson)
            continue;
        dfs(to[e], a);
    }
}
void addPath(long long u, long long v, long long c)
{
    while (nodes[u].top != nodes[v].top)
    {
        if (nodes[nodes[u].top].depth < nodes[nodes[v].top].depth)
            swap(u, v);
        addRange(nodes[nodes[u].top].id, nodes[u].id + 1, c);
        u = nodes[nodes[u].top].fa;
    }
    if (nodes[u].depth < nodes[v].depth)
        swap(u, v);
    addRange(nodes[v].id, nodes[u].id + 1, c);
}
long long queryPath(long long u, long long v)
{
    long long res = 0;
    while (nodes[u].top != nodes[v].top)
    {
        if (nodes[nodes[u].top].depth < nodes[nodes[v].top].depth)
            swap(u, v);
        res = (res + queryRange(nodes[nodes[u].top].id, nodes[u].id + 1)) % p;
        u = nodes[nodes[u].top].fa;
    }
    if (nodes[u].depth < nodes[v].depth)
        swap(u, v);
    res = (res + queryRange(nodes[v].id, nodes[u].id + 1)) % p;
    return res;
}
long long lca(long long u, long long v)
{
    while (nodes[u].top != nodes[v].top)
    {
        if (nodes[nodes[u].top].depth < nodes[nodes[v].top].depth)
            swap(u, v);
        u = nodes[nodes[u].top].fa;
    }
    if (nodes[u].depth < nodes[v].depth)
        swap(u, v);
    return v;
}
long long pieces[maxlg];
void cutPath(long long &p, long long i, long long anc, long long dec)
{
    long long l = nodes[anc].id, r = nodes[dec].id + 1;
    long long x, y, z;
    split(pieces[i], r, y, z);
    split(y, l, x, y);
    pieces[i] = z;
    pieces[i + 1] = x;
    p = merge(y, p);
}
void joinPath(long long &p, long long i, long long anc, long long dec)
{
    long long l = nodes[anc].id, r = nodes[dec].id + 1;
    long long cut;
    split(p, st[p].size - (r - l) + 1, p, cut);
    rt = merge(merge(pieces[i + 1], cut), rt);
}
void revPath(long long u, long long v)
{
    long long anc = lca(u, v);
    if (nodes[u].id < nodes[v].id)
        swap(u, v);
    // lca v u
    // Cut
    long long a, i;
    long long pu = 0, pv = 0;
    bool uHeavy;
    pieces[0] = rt;
    for (a = u, i = 0; nodes[a].top != nodes[anc].top; a = nodes[nodes[a].top].fa, i++)
    {
        cutPath(pu, i, nodes[a].top, a);
    }
    if (a != anc)
    {
        cutPath(pu, i, anc, a);
        uHeavy = 1;
    }
    for (a = v; nodes[a].top != nodes[anc].top; a = nodes[nodes[a].top].fa, i++)
    {
        cutPath(pv, i, nodes[a].top, a);
    }
    if (!uHeavy)
        cutPath(pv, i, anc, a);
    // Rev
    rev(pu);
    long long lsize = st[pv].size;
    long long p = merge(pu, pv);
    long long newpv, newpu;
    split(p, lsize + 1, newpv, newpu);
    rev(newpv);
    // join
    rt = pieces[0];
    for (a = u, i = 0; nodes[a].top != nodes[anc].top; a = nodes[nodes[a].top].fa, i++)
    {
        joinPath(newpu, i, nodes[a].top, a);
    }
    if (a != anc)
    {
        joinPath(newpu, i, anc, a);
        uHeavy = 1;
    }
    for (a = v; nodes[a].top != nodes[anc].top; a = nodes[nodes[a].top].fa, i++)
    {
        joinPath(newpv, i, nodes[a].top, a);
    }
    if (!uHeavy)
    {
        joinPath(newpv, i, anc, a);
    }
}
// Main
signed main()
{
    srand(time(0));
    long long q;
    cin >> n >> q;
    for (long long i = 1; i <= n; i++)
    {
        cin >> nodes[i].w0;
    }
    for (long long i = 0; i < n - 1; i++)
    {
        long long u, v;
        cin >> u >> v;
        connect(u, v);
        connect(v, u);
    }
    stat(1, 0, 1);
    dfs(1, 0);
    for (long long i = 1; i <= n; i++)
    {
        rt = merge(rt, allocate(Treap(w1[i])));
    }
    for (long long i = 0; i < q; i++)
    {
        long long op;
        cin >> op;
        if (op == 1)
        {
            long long x, y, z;
            cin >> x >> y >> z;
            addPath(x, y, z);
            // for(long long i = 1; i <= n; i++) cout << queryPath(i, i) << ' ';
            // cout << endl;
        }
        else if (op == 2)
        {
            long long x, y;
            cin >> x >> y;
            revPath(x, y);
            // for(long long i = 1; i <= n; i++) cout << queryPath(i, i) << ' ';
            // cout << endl;
        }
        else if (op == 3)
        {
            long long x, y;
            cin >> x >> y;
            cout << queryPath(x, y) << endl;
        }
    }
    return 0;
}