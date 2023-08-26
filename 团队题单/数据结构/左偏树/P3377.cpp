#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
struct Lefist_Tree{
    struct Node{
        int lson, rson;
        int val, s;
        int id;
    }t[maxn];
    int tot = 0;
    int newNode(int val, int id){
        ++tot;
        t[tot].s = 0;
        t[tot].val = val;
        t[tot].lson = t[tot].rson = 0;
        t[tot].id = id;
        return tot;
    }
    int merge(int x, int y){
        if (!x || !y)
            return x + y;
        if ((t[x].val > t[y].val) || ((t[x].val == t[y].val) && t[x].id > t[y].id))
            swap(x, y);
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
        return merge(t[x].lson, t[x].rson);
    }
}heap;
struct DSU{
    int fa[maxn];
    void init(){
        for (int i = 0; i < maxn; i++)
            fa[i] = i;
    }
    int getfa(int x){
        if (fa[x] == x) return x;
        return fa[x] = getfa(fa[x]);
    }
    void merge(int x, int y){
        int fx = getfa(x);
        int fy = getfa(y);
        fa[fy] = fx;
    }
}dsu;
int rt[maxn], deleted[maxn];
int main(){
    dsu.init();
    heap.t[0].s = -1;
    int n, m;
    cin >> n >> m;
    int x, y;
    for (int i = 1; i <= n; i++){
        cin >> x;
        rt[i] = heap.newNode(x, i);
    }
    int op;
    while (m--){
        cin >> op;
        if (op == 1){
            cin >> x >> y;
            if (deleted[x] || deleted[y])
                continue;
            int fx = dsu.getfa(x);
            int fy = dsu.getfa(y);
            if (fx == fy)
                continue;
            rt[fx] = rt[fy] = heap.merge(rt[fx], rt[fy]);
            dsu.merge(x, y);
        }else{
            cin >> x;
            if (deleted[x]){
                cout << -1 << endl;
                continue;
            }
            int fx = dsu.getfa(x);
            deleted[rt[fx]] = 1;
            cout << heap.top(rt[fx]) << endl;
            rt[fx] = heap.pop(rt[fx]);
        }
    }
    return 0;
}