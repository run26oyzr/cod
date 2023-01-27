#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e5 + 5;
vector <int> t[maxn];
signed main(){
    int T; cin >> T;
    int n, m;
    while(T--){
        cin >> n >> m;
        for (int i = 1; i <= n; i++) t[i].clear();
        int x, y;
        for (int i = 1; i <= m; i++){
            cin >> x >> y;
            if (x > y) swap(x, y);
            t[y].push_back(x);
        }
        for (int i = 1; i <= n; i++) sort(t[i].begin(), t[i].end());
        int z = 0, ans = 0;
        for (int i = 1; i <= n; i++){
            if (!t[i].empty()) z = max(z, t[i].back());
            ans += (i - z);
        }
        cout << ans << endl;
    }
    return 0;
}