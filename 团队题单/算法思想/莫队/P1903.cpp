#include <bits/stdc++.h>
using namespace std;
const int maxn = 133333 + 5, maxval = 1e6 + 5;
struct Query{
    int l, r, lblock, rblock, t;
    int id;
    bool operator < (const Query &T) const{
        if (lblock == T.lblock)
            if (rblock == T.rblock)
                return t < T.t;
            else
                return rblock < T.rblock;
        else
            return lblock < T.lblock;
    }
}q[maxn];
struct Change{
    int pos, val;
}c[maxn];
int ans = 0;
int cnt[maxval];
void add(int val){
    if (!cnt[val])
        ans++;
    cnt[val]++;
}
void del(int val){
    cnt[val]--;
    if (!cnt[val])
        ans--;
}
int a[maxn];
void change(int i, int t){
    if (q[i].l <= c[t].pos && c[t].pos <= q[i].r){
        del(a[c[t].pos]);
        add(c[t].val);
    }
    swap(a[c[t].pos], c[t].val);
}
int res[maxn];
signed main(){
    int n, m;
    cin >> n >> m;
    int block_size = pow(n, 2.0 / 3.0);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int change_cnt = 0;
    char op;
    for (int i = 1; i <= m; i++){
        cin >> op;
        if (op == 'R'){
            cin >> c[++change_cnt].pos >> c[change_cnt].val;
        }else if (op == 'Q'){
            int pos = i - change_cnt;
            cin >> q[pos].l >> q[pos].r;
            q[pos].id = pos;
            q[pos].t = change_cnt;
            q[pos].lblock = q[pos].l / block_size;
            q[pos].rblock = q[pos].r / block_size;
        }
    }
    m -= change_cnt;
    sort(q + 1, q + m + 1);
    int nl = 1, nr = 0, t = 0;
    for (int i = 1; i <= m; i++){
        //扩大区间
        while (q[i].l < nl)
            add(a[--nl]);
        while (nr < q[i].r)
            add(a[++nr]);
        //缩小区间
        while (nl < q[i].l)
            del(a[nl++]);
        while (q[i].r < nr)
            del(a[nr--]);
        //修改
        while (t < q[i].t)
            change(i, ++t);
        while (t > q[i].t)
            change(i, t--);
        res[q[i].id] = ans;
    } 
    for (int i = 1; i <= m; i++)
        cout << res[i] << endl;
    return 0;
}