#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 3 * 1e6 + 5;
int phi[maxn];
signed main(){
    int n, p;
    cin >> n >> p;
    /**
     * 令p=ki+r(k=floor(p/i), r=p mod i)
     * ki + r 同余 0 (mod p)
     * 左右同乘 i^-1 * r^-1, 得：
     * k * r^-1 + i^-1 同余 0 (mod p)
     * 移向，得：
     * i^-1 同余 -k * r^-1 (mod p)
     * 代入，得：
     * i^-1 同余 floor(-p/i) * (p%i)^-1 (mod p)
    */
    //phi(i) = (-p/i)*phi(p%i)%p
    phi[1] = 1;
    for (int i = 2; i <= n; i++){
        phi[i] = (((-p / i) * phi[p % i] % p) + p) % p;
    }
    for (int i = 1; i <= n; i++){
        printf("%lld\n", phi[i]);
    }
    return 0;
}