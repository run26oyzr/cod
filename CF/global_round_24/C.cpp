#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2 * 1e5 + 5, maxval = 1e6;
int a[maxn], b[maxval], vis[maxval];
signed main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            b[a[i]] ++;
        }
        sort(a + 1, a + n + 1);
        int size_ = 0;
        long long ans = 0;
        for (int i = 1; i <= n; i++){
            if (vis[a[i]]) continue;
            vis[a[i]] = 1;
            size_ += b[a[i]];
            ans = max(ans, max(size_ * (n - size_), b[a[i]] / 2));
            b[a[i]] = 0;
        }
        for (int i = 1; i <= n; i++){
            vis[a[i]] = 0;
        }
        cout << ans << endl;
    }
    system("pause");
    return 0;
}