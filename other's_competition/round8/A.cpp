#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
int count(int x){
    int wei = floor(log10(x)) + 1;
    int res = 0;
    for (int i = 0; i < wei; i++){
        int now = x / (int)(pow(10, i)) % 10;
        if (now == 1) res++;
    }
    return res;
}
signed main(){
    freopen("lucky.in", "r", stdin);
    freopen("lucky.out", "w", stdout);
    int T;
    cin >> T;
    cout << "My answer is:" << endl;
    while(T--){
        int n;
        cin >> n;
        int minx = pow(10, n - 1);
        int maxx = pow(10, n);
        int ans = 0;
        for (int i = minx; i < maxx; i++){
            if (count(i) % 2 == 0) ans++;
            ans %= mod;
        }
        if (n == 1) ans = 9;
        cout << ans << endl;
    }
    return 0;
}