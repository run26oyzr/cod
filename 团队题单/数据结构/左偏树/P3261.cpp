#include <bits/stdc++.h>
#define int long 
#define ls t[id].lson
#define rs t[id].rson
using namespace std;
const int maxn = 3 * 1e5 + 5;
struct Lefist_Tree{
    struct Node{
        int lson, rson;
        int val, s;
        int id;
        int lc, la; //乘，加的lazy
    }t[maxn];
    int tot = 0;
    int newNode(int val, int id){
        ++tot;
        t[tot].s = 0;
        t[tot].val = val;
        t[tot].lson = t[tot].rson = 0;
        t[tot].id = id;
        t[tot].lc = 1, t[tot].la = 0;
        return tot;
    }
    void pushdown(int id){
        if (t[id].la == 0 && t[id].lc == 1)
            return;
        t[ls].lc *= t[id].lc;
        t[ls].la *= t[id].lc;
        t[ls].la += t[id].la;
        t[ls].val *= t[id].lc;
        t[ls].val += t[id].la;
        t[rs].lc *= t[id].lc;
        t[ls].la *= t[id].lc;
        t[rs].la += t[id].la;
        t[rs].val *= t[id].lc;
        t[rs].val += t[id].la;
        t[id].lc = 1, t[id].la = 0;
    }
    int merge(int x, int y){
        if (!x || !y)
            return x + y;
        if (t[x].val > t[y].val)
            swap(x, y);
        pushdown(x);
        t[x].rson = merge(t[x].rson, y);
        if (t[t[x].lson].s < t[t[x].rson].s)
            swap(t[x].lson, t[x].rson);
        t[x].s = t[t[x].rson].s + 1;
        return x;
    }
    int top(int x){
        return t[x].val;
    }
    int pop(int x){
        pushdown(x);
        return merge(t[x].lson, t[x].rson);
    }
}heap;
int rt[maxn];
int h[maxn], f[maxn], a[maxn], v[maxn];
int dep[maxn];
int start[maxn], dead[maxn]; //c:从深度为c_i的节点开始攻击，died:牺牲在深度为died_i的结点
int cnt[maxn]; //死在该节点的骑士数量
signed main(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    for (int i = 2; i <= n; i++)
        cin >> f[i] >> a[i] >> v[i];
    dep[1] = 1;
    for (int i = 2; i <= n; i++)
        dep[i] = dep[f[i]] + 1;
    int s, c;
    for (int i = 1; i <= m; i++){
        cin >> s >> c;
        start[i] = dep[c];
        rt[c] = heap.merge(rt[c], heap.newNode(s, i));
    }
    for (int i = n; i >= 1; i--){
        while (rt[i] && heap.top(rt[i]) < h[i]){
            dead[heap.t[rt[i]].id] = dep[i];
            rt[i] = heap.pop(rt[i]);
            cnt[i]++;
        }
        if (!rt[i])
            continue;
        if (a[i] == 0){
            heap.t[rt[i]].la += v[i];
            heap.t[rt[i]].val += v[i];
        }else{
            heap.t[rt[i]].lc *= v[i];
            heap.t[rt[i]].la *= v[i];
            heap.t[rt[i]].val *= v[i];
        }
        rt[f[i]] = heap.merge(rt[f[i]], rt[i]);
    }
    for (int i = 1; i <= n; i++)
        cout << cnt[i] << endl;
    for (int i = 1; i <= m; i++)
        cout << start[i] - dead[i] << endl;
    return 0;
}