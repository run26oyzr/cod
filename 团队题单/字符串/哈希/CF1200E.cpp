#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e6 + 5;
const int mod = 998244353, base = 131;
//用取模就不能用自然溢出，不能开 unsigned long long
char s[maxn];
int H[maxn];
void Hash(char s[]){
    int n = strlen(s + 1);
    int res = 0;
    H[0] = 0;
    for (int i = 1; i <= n; i++){
        H[i] = (H[i - 1] * base + s[i]) % mod;
    }
}
int tot = 0;
int h[maxn];
void AddHash(char s[]){
    int n = strlen(s + 1);
    for (int i = 1; i <= n; i++){
        tot++;
        h[tot] = (h[tot - 1] * base + s[i]) % mod;
    }
}
int qpow(int x, int y){
    int res = 1;
    while(y){
        if (y & 1)
            res = (res * x) % mod;
        x = (x * x) % mod;
        y >>= 1;
    }
    return res % mod;
}
int QuerySub(int l, int r, int h[]){
    return ((h[r] - (h[l - 1] * qpow(base, r - l + 1))) % mod + mod) % mod;
}
void Delete(int l, int r){
    int n = strlen(s + 1);
    for (int i = l; i <= n - (r - l + 1); i++)
        s[i] = s[i + (r - l + 1)];
    s[n - (r - l + 1) + 1] = '\0';
}
signed main(){
    memset(h, 0, sizeof(h));
    int n;
    cin >> n;
    while (n--){
        cin >> s + 1;
        Hash(s);
        int m = strlen(s + 1);
        int len = 0;
        for (int i = min(m, tot); i >= 0; i--){
            if (QuerySub(tot - i + 1, tot, h) == QuerySub(1, i, H)){
                len = i;
                break;
            }
        }
        Delete(1, len);
        AddHash(s);
        cout << s + 1;
    }
    return 0;
}