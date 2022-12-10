#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
inline ll read()
{
    ll x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}
long long wei_shu = 0;
long double ans = 1;
long long a_wei_shu = 0;
int solve(int x){
    for (int i = 18; i >= 1; i--){
        if (x > pow(10, i - 1)) return i;
    }
    return 1;
}
long long qpow(int x, int y, int z){
    long double a = x;
    while(y){
        if (y & 1){
            ans *= a;
            wei_shu += a_wei_shu;
        }
        a *= a;
        a_wei_shu *= 2;
        y >>= 1;
        if (ans >= 1e9){
            ans /= 1e9;
            wei_shu += 9;
        }
        if (a >= 1e9){
            a /= 1e9;
            a_wei_shu += 9;
        }
    }
    ans *= z;
    return wei_shu + solve(ans);
}
signed main(){
    freopen("genshin.in", "r", stdin);
    freopen("genshin.out", "w", stdout);
    int T = read();
    int x, y, z;
    while(T--){
        ans = 1;
        wei_shu = 0;
        a_wei_shu = 0;
        x = read(), y = read(), z = read();
        cout << qpow(x, y, z) << endl;
    }
    return 0;
}