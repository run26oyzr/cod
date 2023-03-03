#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 3 * 1e6 + 5;
int phi[maxn];
signed main(){
    int n, p;
    cin >> n >> p;
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