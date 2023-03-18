#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxval = 65540, maxn = 1e5;
int f[maxval];
int money[maxn], sum[maxn];
int a[20];
signed main(){
    int K, n;
    cin >> K >> n;
    for (int i = 1; i <= K; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++){
        cin >> money[i];
        sum[i] = sum[i - 1] + money[i];
    }
    for (int s = 0; s < (1 << K); s++){
        for (int k = 0; k < K; k++){
            if (!((1 << k) & s)){
                int l = f[s], r = n, ans;
                while(l <= r){
                    int mid = (l + r) / 2;
                    if (a[k + 1] >= sum[mid] - sum[f[s]]) ans = mid, l = mid + 1;
                    else r = mid - 1;
                } 
                f[s | (1 << k)] = max(f[s | (1 << k)], ans);
            }
        }
    }
    int ans = -1;
    for (int i = 0; i < (1 << K); i++){
        if (f[i] == n){
            int tot = 0;
            for (int j = 0; j < K; j++){
                if (!((1 << j) & i)) tot += a[j + 1];
            }
            ans = max(ans, tot);
        }
    }
    cout << ans << endl;
    system("pause");
    return 0;
}