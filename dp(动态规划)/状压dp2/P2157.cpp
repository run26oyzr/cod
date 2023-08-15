#include <bits/stdc++.h>
#define eps 1e-6
#define int long long
using namespace std;
const int maxval = 262150, maxn = 20, maxk = 18;
int f[maxval];
int line[maxn][maxn];
long double x[maxn], y[maxn];
signed main(){
    int T;
    cin >> T;
    while (T--){
        memset(f, 0x3f, sizeof(f));
        memset(line, 0, sizeof(line));
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            cin >> x[i] >> y[i];
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if (fabs(x[i] - x[j]) < eps) continue;
                long double a = (x[j] * y[i] - y[j] * x[i]) / (x[i] * x[i] * x[j] - x[i] * x[j] * x[j]);
                long double b = (y[i] * x[j] * x[j] - y[j] * x[i] * x[i]) / (x[i] * x[j] * x[j] - x[j] * x[i] * x[i]);
                if (a > -eps) continue;
                for (int k = 1; k <= n; k++)
                    if (fabs((a * x[k] * x[k] + b * x[k]) - y[k]) < eps)
                        line[i][j] |= (1 << (k - 1));
            }
        }
        f[0] = 0;
        for (int s = 0; s < (1 << n); s++){
            int x = 1;
            for (int i = 1; i <= n; i++){
                if (!(s & (1 << (i - 1)))){
                    x = i;
                    break;
                }
            }
            for (int i = 1; i <= n; i++)
                f[s | line[x][i]] = min(f[s | line[x][i]], f[s] + 1);
            f[s | (1 << (x - 1))] = min(f[s | (1 << (x - 1))], f[s] + 1);
        }
        cout << f[(1 << n) - 1] << endl;
    }
    return 0;
}