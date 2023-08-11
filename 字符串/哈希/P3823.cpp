#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int maxn = 2 * 1e5 + 5, maxk = 50;
const int mod = 998244353, p = 1e7 + 19, base = 131;
struct Node{
    int pre, nxt;
    char val;
}t[maxn];
struct Hash_Table{
    struct Node{
        int nxt;
        int cnt, val;
    }t[p];
    int h[p], tot = 0;
    void add(int h2, int val){
        int h1 = h2 % p;
        for (int i = h[h1]; i; i = t[i].nxt)
            if (t[i].val == h2){
                t[i].cnt += val;
                return;
            }
        ++tot;
        t[tot].val = h2; t[tot].cnt = val; t[tot].nxt = h[h1]; h[h1] = tot;
    }
    int query(int h2){
        int h1 = h2 % p;
        for (int i = h[h1]; i; i = t[i].nxt)
            if (t[i].val == h2)
                return t[i].cnt;
        return 0;
    }
}Hash_T;
char s[(int)(1e7 + 5)];
int h[(int)(1e7 + 5)];
int base_pow[maxk + 5];
signed main(){
    base_pow[0] = 1;
    for (int i = 1; i <= maxk; i++)
        base_pow[i] = base_pow[i - 1] * base;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> t[i].val;
        Hash_T.add(t[i].val, 1);
    }
    int op, x, y;
    while(m--){ 
        cin >> op;
        if (op == 1){
            cin >> x >> y;
            t[x].nxt = y;
            t[y].pre = x;
            int L = maxk, R = maxk - 1;
            for (int i = x; i && L > 1; i = t[i].pre)
                s[--L] = t[i].val;
            for (int i = y; i && R < maxk * 2 - 1; i = t[i].nxt)
                s[++R] = t[i].val;
            h[L - 1] = 0;
            for (int i = L; i <= R; i++)
                h[i] = h[i - 1] * base + s[i]; 
            for (int i = L; i <= maxk - 1; i++)
                for (int j = maxk; j <= min(R, i + 50 - 1); j++)
                    Hash_T.add(h[j] - h[i - 1] * base_pow[j - i + 1], 1);
        }else if (op == 2){
            cin >> x;
            y = t[x].nxt;
            t[x].nxt = 0;
            t[y].pre = 0;
            int L = maxk, R = maxk - 1;
            for (int i = x; i && L > 1; i = t[i].pre)
                s[--L] = t[i].val;
            for (int i = y; i && R < maxk * 2 - 1; i = t[i].nxt)
                s[++R] = t[i].val;
            h[L - 1] = 0;
            for (int i = L; i <= R; i++)
                h[i] = h[i - 1] * base + s[i];
            for (int i = L; i <= maxk - 1; i++)
                for (int j = maxk; j <= min(R, i + 50 - 1); j++)
                    Hash_T.add(h[j] - h[i - 1] * base_pow[j - i + 1], -1);
        }else{
            cin >> s + 1 >> x;
            int Len = strlen(s + 1);
            h[0] = 0;
            for (int i = 1; i <= Len; i++)
                h[i] = h[i - 1] * base + s[i];
            int ans = 1;
            for (int i = 1; i <= Len - x + 1; i++){
                int j = i + x - 1;
                ans = (ans * Hash_T.query(h[j] - h[i - 1] * base_pow[x])) % mod;
            }
            cout << ans << endl;
        }
    }
    return 0;
}