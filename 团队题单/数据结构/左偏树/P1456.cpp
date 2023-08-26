#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
struct Lefist_Tree{
    struct Node{
        int lson, rson;
        int val, s;
    }t[maxn];
    int tot = 0;
    int newNode(int val){
        ++tot;
        t[tot].s = 0;
        t[tot].val = val;
        t[tot].lson = t[tot].rson = 0;
        return tot;
    }
    int merge(int x, int y){
        // cout << "xy: " << x << ' ' << y << endl;
        if (!x || !y)
            return x + y;
        if (t[x].val < t[y].val)
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
    void init(){
        tot = 0;
    }
    void clear(int id){
        t[id].s = 0;
        t[id].val = 0;
        t[id].lson = t[id].rson = 0;
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
int rt[maxn];
int main(){
    heap.t[0].s = -1;
    int n, m;
    while (~scanf("%d", &n)){
        dsu.init();
        heap.init();
        int x, y;
        for (int i = 1; i <= n; i++){
            cin >> x;
            rt[i] = heap.newNode(x);
        }
        cin >> m;
        while (m--){
            cin >> x >> y;
            int fx = dsu.getfa(x);
            int fy = dsu.getfa(y);
            if (fx == fy){
                cout << -1 << endl;
                continue;
            }
            int valx = heap.top(rt[fx]);
            int valy = heap.top(rt[fy]);
            int rx = rt[fx], ry = rt[fy];
            rt[fx] = heap.pop(rt[fx]);
            rt[fy] = heap.pop(rt[fy]);
            heap.clear(rx);
            heap.clear(ry);
            heap.t[rx].val = valx / 2;
            heap.t[ry].val = valy / 2;
            rt[fx] = heap.merge(rt[fx], rx);
            rt[fy] = heap.merge(rt[fy], ry);
            rt[fx] = rt[fy] = heap.merge(rt[fx], rt[fy]);
            dsu.merge(x, y);
            cout << heap.top(rt[fx]) << endl;
        }
    }
    return 0;
}