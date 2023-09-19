#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2505;
char s[maxn];
int f[maxn][maxn];
signed main(){
    int A, B, C;
    int n;
    cin >> n;
    cin >> s + 1;
    cin >> A >> B >> C;
    memset(f, 0x3f, sizeof(f));
    bool flag = true;
    for (int i = 1; i <= n; i++)
        flag &= (s[i] == 'a');
    if (flag){
        f[1][0] = A;
        for (int i = 1; i <= n; i++){
            for (int j = 0; j <= n; j++){
                if (i + 1 <= n)
                    f[i + 1][j] = min(f[i + 1][j], f[i][j] + A);
                if (i + j <= n)
                    f[i + j][j] = min(f[i + j][j], f[i][j] + C);
                f[i][i] = min(f[i][i], f[i][j] + B + C);
            }
        }
        int ans = 1e18;
        for (int i = 0; i <= n; i++)
            ans = min(ans, f[n][i]);
        cout << ans;
    }else{
        f[1][0] = A;
        for (int times = 1; times <= n; times++){
            for (int i = 1; i <= n; i++){
                for (int j = 0; j <= n; j++){
                    if (i + 1 <= n)
                        f[i + 1][j] = min(f[i + 1][j], f[i][j] + A);
                    if (i + j <= n)
                        f[i + j][j] = min(f[i + j][j], f[i][j] + C);
                    f[i][i] = min(f[i][i], f[i][j] + B + C);
                }
            }
        }
    }
    return 0;
}