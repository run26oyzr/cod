#include <bits/stdc++.h>
using namespace std;
const int maxn = 15 + 5, maxk = 15, maxval = (1 << maxk) - 1 + 5;
double f[maxval][maxn];
double x[maxn], y[maxn];
double dis(int i, int j){
    return sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
}
int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> x[i] >> y[i];
    for (int s = 0; s < (1 << n); s++)
        for (int i = 1; i <= n; i++)
            f[s][i] = 1e18;
    for (int i = 1; i <= n; i++)
        f[(1 << (i - 1))][i] = dis(0, i);
    for (int s = 0; s < (1 << n); s++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if (!((s >> (j - 1)) & 1)){
                    f[s | (1 << (j - 1))][j] = min(f[s | (1 << (j - 1))][j], f[s][i] + dis(i, j));
                }
            }
        }
    }
    double ans = 1e18;
    for (int i = 1; i <= n; i++)
        ans = min(ans, f[(1 << n) - 1][i]);
    printf("%.2lf", ans);
    return 0;
}