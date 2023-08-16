#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5 * 1e5 + 5;
const int mod = 998244353, base = 131;
// TODO 1e18级别的模数会导致 WA ？
int h[maxn];
void Hash(char s[]){
    int n = strlen(s + 1);
    int res = 0;
    for (int i = 1; i <= n; i++){
        h[i] = (h[i - 1] * base + s[i]) % mod;
    }
}
int base_pow[maxn];
int getSub(int L, int R){
    return ((h[R] - h[L - 1] * base_pow[R - L + 1]) % mod + mod) % mod;
}
int prim[maxn], min_facter[maxn];
bool isp[maxn];
void getPrim(){
    int cnt = 0;
    for (int i = 2; i < maxn; i++){
        if (!isp[i]){
            prim[++cnt] = i;
            min_facter[i] = i;
        }
        for (int j = 1; j <= cnt && prim[j] * i < maxn; j++){
            isp[i * prim[j]] = 1;
            min_facter[i * prim[j]] = prim[j];
            if (i % prim[j] == 0) break;
        }
    }
}
void init(){
    base_pow[0] = 1;
    for (int i = 1; i < maxn; i++)
        base_pow[i] = (base_pow[i - 1] * base) % mod;
}
char s[maxn];
int all_facter[maxn];
signed main(){
    init();
    getPrim();
    int n, m;
    scanf("%lld", &n);
    scanf("%s", s + 1);
    Hash(s);
    scanf("%lld", &m);
    int l, r, len, tot;
    while (m--){
        scanf("%lld %lld", &l, &r);
        len = r - l + 1;
        tot = 0;
        int tmp = len;
        while(tmp != 1){
            all_facter[++tot] = min_facter[tmp];
            tmp /= min_facter[tmp];
        }
        for (int i = 1; i <= tot; i++){
            if (getSub(l + len / all_facter[i], r) == getSub(l, r - len / all_facter[i]))
                len /= all_facter[i];
        }
        printf("%lld\n", len);
    }
    return 0;
}