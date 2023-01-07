#include <bits/stdc++.h>
using namespace std;
const int mod = 2022 * 2023;
int main(){
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    long long ans = 1;
    for (int i = 1; i < n; i++){
        ans *= (m - 1);
        ans %= mod;
    }
    ans *= m;
    ans %= mod;
    cout << ans;
    return 0;
}