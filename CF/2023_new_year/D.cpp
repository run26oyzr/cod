#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
const int mod = 998244353;
int a[maxn], b[maxn],vis[maxn];
signed main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) cin >> b[i];
        int cnt = 0;
        for (int i = 1; i <= n; i++){
            if (a[i] == b[i]){
                cnt++;
                vis[i] = 1;
            }
        }
    }
    return 0;
}