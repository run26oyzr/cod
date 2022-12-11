#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
map <int, int> vis;
int t[maxn];
void solve(){
    int n; cin >> n;
    vis.clear();
    for (int i = 1; i <= n; i++){
        cin >> t[i];
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= 33334; j += 2){
            int jj = j;
            if (j == 1) jj = 2;
            if (t[i] == 1) break;
            if (t[i] % jj == 0){
                if (vis[jj]){
                    cout << "Yes" << endl; return;
                }
                vis[jj] = 1;
                while(t[i] % jj == 0) t[i] /= jj;
            }
        }
    }
    for (int i = 1; i <= n; i++) vis[t[i]]++;
    for (int i = 1; i <= n; i++) if (vis[t[i]] > 1){cout << "Yes" << endl; return;}
    cout << "No" << endl;
}
int main(){
    int T; cin >> T;
    while(T--){
        solve();
    }
    return 0;
}