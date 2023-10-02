#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
struct Node{
    int l, r, block;
    int id;
    int a, b;
    bool operator < (const Node &T) const{
        if (block == T.block && (block & 1))
            return r < T.r;
        else if (block == T.block && !(block & 1))
            return r > T.r;
        else
            return l < T.l;
    }
}q[maxn];
struct Ans{
    int a, b;
}ans[maxn];
struct Fen_Kuai{
    int bsize, bnum;
    int block[maxn], a[maxn];
    int tot[maxn], cnt[maxn];
    void init(int n){
        bsize = sqrt(n);
        for(int i = 1; i <= n; i++)
            block[i] = (i - 1) / bsize + 1;
        bnum = block[n];
    }
    void add(int c){
        if (a[c] == 0)
            cnt[block[c]]++;
        a[c]++;
        tot[block[c]]++;
    }
    void del(int c){
        a[c]--;
        if (a[c] == 0)
            cnt[block[c]]--;
        tot[block[c]]--;
    } 
    Ans query(int L, int R){
        Ans res;
        res.a = res.b = 0;
        //前面非整块
        int e = min(R, block[L] * bsize);
        for(int i = L; i <= e; i++){
            res.a += a[i];
            res.b += a[i] ? 1 : 0;
        }
        //中间的整段
        for (int i = block[L] + 1; i <= block[R] - 1; i++){
            res.a += tot[i];
            res.b += cnt[i];
        }
        //后面非整块
        if (block[L] != block[R]){
            for (int i = (block[R] - 1) * bsize + 1; i <= R; i++){
                res.a += a[i];
                res.b += a[i] ? 1 : 0;
            }
        }
        return res;
    }
}T;
void add(int val){
    T.add(val);
}
void del(int val){
    T.del(val);
}
int a[maxn];
int main(){
    int n, m;
    cin >> n >> m;
    T.init(1e5);
    int block_size = sqrt(n);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++){
        cin >> q[i].l >> q[i].r >> q[i].a >> q[i].b;
        q[i].id = i;
        q[i].block = q[i].l / block_size;
    }
    sort(q + 1, q + m + 1);
    int nl = 1, nr = 0;
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
        ans[q[i].id] = T.query(q[i].a, q[i].b);
    } 
    for (int i = 1; i <= m; i++)
        printf("%d %d\n", ans[i].a, ans[i].b);
    return 0;
}