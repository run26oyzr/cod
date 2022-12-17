#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e5 + 5;

inline int read()
{
    register int x = 0,f = 1;
    char c = getchar();
    while(c < '0' || c > '9')
    {
        if(c == '-') f = -1;
        c = getchar();
    }
    while(c >= '0' && c <= '9') 
    {
        x = (x << 3) + (x << 1) + (c ^ 48);
        c = getchar();
    }
    return x * f;
}

int bsize;
int mod;
int book[maxn], a[maxn], sum[maxn], lc[maxn], la[maxn];
void update(int L){
    for (int i = (book[L] - 1) * bsize + 1; i <= book[L] * bsize; i++){
        a[i] = a[i] * lc[i] + la[i];
        a[i] %= mod;
    }
    lc[book[L]] = 1; la[book[L]] = 0;
}
void change(int L, int R, int add, int mul){
    //前面非整块
    update(L);
    int e = min(R, book[L] * bsize);
    for(int i = L; i <= e; i++){
        a[i] *= mul; sum[book[i]] += a[i] * (mul - 1);
        a[i] %= mod; sum[book[i]] %= mod;
        a[i] += add; sum[book[i]] += add;
        a[i] %= mod; sum[book[i]] %= mod;
    }
    //中间的整段
    for (int i = book[L] + 1; i <= book[R] - 1; i++){
        lc[i] *= mul; la[i] *= mul; sum[i] *= mul;
        lc[i] %= mod; la[i] %= mod; sum[i] %= mod;
        la[i] += add; sum[i] += add * bsize;
        la[i] %= mod; sum[i] %= mod;
    }
    //后面非整块
    if (book[L] != book[R]){
        update(R);
        for (int i = (book[R] - 1) * bsize + 1; i <= R; i++){
            a[i] *= mul; sum[book[i]] += a[i] * (mul - 1);
            a[i] %= mod; sum[book[i]] %= mod;
            a[i] += add; sum[book[i]] += add;
            a[i] %= mod; sum[book[i]] %= mod;
        }
    }
}
int query(int L, int R){
    int res = 0;
    //前面非整块
    update(L);
    int e = min(R, book[L] * bsize);
    for(int i = L; i <= e; i++){
        res += a[i];
        res %= mod;
    }
    //中间的整段
    for (int i = book[L] + 1; i <= book[R] - 1; i++){
        res += sum[i] * lc[i] + la[i];
        res %= mod;
    }
    //后面非整块
    if (book[L] != book[R]){
        update(R);
        for (int i = (book[R] - 1) * bsize + 1; i <= R; i++){
            res += a[i];
            res %= mod;
        }
    }
    return res % mod;
}
int n, m;
void init(){
    for (int i = 0; i < maxn; i++) lc[i] = 1;
    n = read(), m = read(), mod = read();
    bsize = sqrt(n);
    for(int i = 1; i <= n; i++) book[i] = (i - 1) / bsize + 1;
    for(int i = 1; i <= n; i++){
        a[i] = read();
        sum[book[i]] += a[i];
    }
}
signed main(){
    init();
    int opt, L, R, c;
    while(m--){
        cin >> opt >> L >> R;
        if (opt == 1){
            cin >> c;
            change(L, R, 0, c);
        }
        if (opt == 2){
            cin >> c;
            change(L, R, c, 1);
        }
        if (opt == 3) cout << query(L, R) << endl;
    }
}
