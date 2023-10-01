#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
struct Node{
    int l, r, block;
    int id;
    int k;
    bool operator < (const Node &T) const{
        if (block == T.block && (block & 1))
            return r < T.r;
        else if (block == T.block && !(block & 1))
            return r > T.r;
        else
            return l < T.l;
    }
}q[maxn];
struct Fen_Kuai{ //按每个股票持股人数分块
    int bsize, bnum;
    int block[maxn], cnt[maxn], tot[maxn]; //cnt:有多少种股票的热度为i, tot:有多少种股票的热度在i区间内
    void init(int n){
        bsize = sqrt(n);
        for(int i = 1; i <= n; i++)
            block[i] = (i - 1) / bsize + 1;
        bnum = block[n];
    }
    void add(int c){
        cnt[c]++;
        tot[block[c]]++;
    }
    void del(int c){
        cnt[c]--;
        tot[block[c]]--;
    } 
    int query(int k){
        int now_block = bnum + 1;
        for (int i = 1; i <= bnum; i++){
            if (tot[i] < k){
                k -= tot[i];
            }else{
                now_block = i;
                break;
            }
        }
        if (tot[now_block] < k){
            return -1;
        }
        int res;
        for (int i = (now_block - 1) * bsize + 1; i <= now_block * bsize; i++){
            if (cnt[i]){
                k -= cnt[i];
                if (k <= 0){
                    res = i;
                    break;
                }
            }
        }
        return res;
    }
}T;
int cnt[maxn];
void add(int val){
    T.del(cnt[val]);
    cnt[val]++;
    T.add(cnt[val]);
}
void del(int val){
    T.del(cnt[val]);
    cnt[val]--;
    T.add(cnt[val]);
}
int ans[maxn];
int a[maxn], aa[maxn];
int main(){
    int n, m;
    cin >> n >> m;
    T.init(n);
    int block_size = sqrt(n);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        aa[i] = a[i];
    }
    sort(aa + 1, aa + n + 1);
    int nn = unique(aa + 1, aa + n + 1) - aa - 1;
    for (int i = 1; i <= n; i++)
        a[i] = lower_bound(aa + 1, aa + nn + 1, a[i]) - aa;
    for (int i = 1; i <= m; i++){
        cin >> q[i].l >> q[i].r >> q[i].k;
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
        ans[q[i].id] = T.query(q[i].k);
    } 
    for (int i = 1; i <= m; i++)
        printf("%d\n", ans[i]);
    return 0;
}