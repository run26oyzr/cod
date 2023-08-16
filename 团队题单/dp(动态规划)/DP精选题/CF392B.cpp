#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 45;
int f[maxn][5][5];
int dis[5][5];
signed main(){
    for (int i = 1; i <= 3; i++){
        for (int j = 1; j <= 3; j++){
            cin >> dis[i][j];
        }
    }
    // for (int k = 1; k <= 3; k++){
    //     for (int i = 1; i <= 3; i++){
    //         for (int j = 1; j <= 3; j++){
    //             dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    //         }
    //     }
    // }
    memset(f, 0x3f, sizeof(f));
    for (int i = 1; i <= 3; i++){
        for (int j = 1; j <= 3; j++){
            int k = 6 - i - j;
            f[1][i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        }
    }
    int n;
    cin >> n;
    for (int t = 2; t <= n; t++){
        for (int i = 1; i <= 3; i++){
            for (int j = 1; j <= 3; j++){
                int k = 6 - i - j;
                f[t][i][j] = min(f[t - 1][i][k] + dis[i][j] + f[t - 1][k][j], f[t - 1][i][j] + dis[i][k] + f[t - 1][j][i] + dis[k][j] + f[t - 1][i][j]);
            }
        }
    }
    cout << f[n][1][3];
    return 0;
}