#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxval = 260, maxn = 1005, maxk = 8;
int f[maxn][maxval][20];
int t[maxn], b[maxn]; 
signed main(){
    int T;
    cin >> T;
    while (T--){
        memset(f, 0x3f, sizeof(f));
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> t[i] >> b[i];
        f[1][0][7] = 0;
        for (int i = 1; i <= n; i++){
            for (int s = 0; s < (1 << maxk); s++){
                for (int dis = max(-maxk, -i); dis <= min(maxk - 1, n - i); dis++){
                    if (f[i][s][dis + 8] >= 1e18) continue;
                    if (s & 1) 
                        f[i + 1][s >> 1][dis - 1 + 8] = min(f[i + 1][s >> 1][dis - 1 + 8], f[i][s][dis + 8]);
                    else{
                        int max_dis = 1e18;
                        for (int k = 0; k <= max_dis; k++){
                            if (!((s >> k) & 1)){
                                max_dis = min(max_dis, k + b[i + k]);
                                f[i][s | (1 << k)][k + 8] = min(f[i][s | (1 << k)][k + 8], f[i][s][dis + 8] + ((i + dis) ? (t[i + dis] ^ t[i + k]) : (0)));
                            }
                        }   
                    }
                }
            }
        }
        int ans = 1e18;
        for (int i = -maxk; i <= 0; i++)
            ans = min(ans, f[n + 1][0][i + 8]);
        cout << ans << endl;
    }
    return 0;
}