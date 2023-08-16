#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
unordered_map <string, int> vis;
unordered_map <string, int> sum;
string s[maxn];
signed main(){
    int n;
    cin >> n;
    while (n--){
        cin >> s[1];
        vis[s[1]] = 1;
    }
    int m;
    cin >> m;
    int ans1 = 0;
    for (int i = 1; i <= m; i++){
        cin >> s[i];
        if (vis[s[i]] == 1){
            vis[s[i]] = 2;
            ans1++;
        }
    }
    int l = 1, r;
    int ans2 = 1e9;
    int cnt = 0;
    for (int i = 1; i <= m; i++){
        if (vis[s[i]]){
            if (!sum[s[i]]) cnt++;
            sum[s[i]]++;
        }
        r = i;
        while (l <= r){
            bool flag = true;
            // cout << l << ' ' << sum[s[l]] << endl;
            if (sum[s[l]] > 1) {sum[s[l]]--; l++; flag = false;}
            if (!vis[s[l]]) {l++; flag = false;}
            if(flag) break;
        }
        // while (l <= r && sum[s[l]] > 1) {l++; sum[s[l]]--;}
        // while (l <= r && !vis[s[l]]) l++;
        if (cnt == ans1){
            ans2 = min(ans2, r - l + 1);
            // cout << l << ' ' << r << endl;
        }
    }
    cout << ans1 << endl;
    cout << ans2;
    return 0;
}