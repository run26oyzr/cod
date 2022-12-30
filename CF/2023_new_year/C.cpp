#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 105;
int a[maxn], vis[maxn];
void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j < i; j++){
            if (a[i] == a[j]){
                cout << "NO" << endl;
                return;
            }
        }
    }
    for (int i = 2; i <= n; i++){
        memset(vis, 0, sizeof(vis));
        for (int j = 1; j <= n; j++){
            for (int k = 1; k < j; k++){
                if (a[j] % i == a[k] % i){
                    vis[a[j] % i] = 1;
                }
            }
        }
        for (int j = 0; j < i; j++){
            // cout << i << ' ' << j << ' ' << vis[j] << endl;
            if (vis[j] == 0) break;
            if (j == i - 1){
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
    return;
}
signed main(){
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}