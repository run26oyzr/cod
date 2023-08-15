#include <bits/stdc++.h>
using namespace std;
const int maxn = 20, maxk = 16;
int t[maxn], w[maxn];
int tim[1 << maxk];
int f[1 << maxk];
int main(){
    int W, n;
    cin >> W >> n;
    for (int i = 1; i <= n; i++) 
        cin >> t[i] >> w[i];
    for (int s = 0; s < (1 << n); s++){
        int sum = 0;
        for (int i = 1; i <= n; i++){
            if ((s >> (i - 1)) & 1){
                tim[s] = max(tim[s], t[i]);
                sum += w[i];
            }
        }
        if (sum > W)
            tim[s] = 0x3f3f3f3f;
    }
    memset(f, 0x3f, sizeof(f));
    f[0] = 0;
    for (int s = 0; s < (1 << n); s++){
        for (int T = s; T; T = s & (T - 1)){
            f[s] = min(f[s], f[s ^ T] + tim[T]);
        }
        f[s] = min(f[s], f[0] + tim[s]);
    }
    cout << f[(1 << n) - 1];
    return 0;
}