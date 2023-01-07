#include <bits/stdc++.h>
#define int long long
using namespace std;
int mp[45][45];
int f[45][45];
signed main(){
    freopen("help.in", "r", stdin);
    freopen("help.out", "w", stdout);
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            scanf("%lld", &mp[i][j]);
            f[i][j] = mp[i][j];
        }
    }
    int x1, y1, x2, y2;
    while(q--){
        scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
        if(x1 < x2){
            if (y1 < y2){
                for (int i = x1; i <= x2; i++){
                    for (int j = y1; j <= y2; j++){
                        if (i == x1 && j == y1) continue;
                        int a = 1e9, b = 1e9;
                        if (i != x1) a = f[i - 1][j];
                        if (j != y1) b = f[i][j - 1];
                        f[i][j] = max(mp[i][j], min(a, b));
                    }
                }
                cout << f[x2][y2] << endl;
                for (int i = x1; i <= x2; i++){
                    for (int j = y1; j <= y2; j++){
                        f[i][j] = mp[i][j];
                    }
                }
            }else{
                for (int i = x1; i <= x2; i++){
                    for (int j = y1; j >= y2; j--){
                        if (i == x1 && j == y1) continue;
                        int a = 1e9, b = 1e9;
                        if (i != x1) a = f[i - 1][j];
                        if (j != y1) b = f[i][j + 1];
                        f[i][j] = max(mp[i][j], min(a, b));
                    }
                }
                cout << f[x2][y2] << endl;
                for (int i = x1; i <= x2; i++){
                    for (int j = y1; j >= y2; j--){
                        f[i][j] = mp[i][j];
                    }
                }
            }
        }else{
            if (y1 < y2){
                for (int i = x1; i >= x2; i--){
                    for (int j = y1; j <= y2; j++){
                        if (i == x1 && j == y1) continue;
                        int a = 1e9, b = 1e9;
                        if (i != x1) a = f[i + 1][j];
                        if (j != y1) b = f[i][j - 1];
                        f[i][j] = max(mp[i][j], min(a, b));
                    }
                }
                cout << f[x2][y2] << endl;
                for (int i = x1; i >= x2; i--){
                    for (int j = y1; j <= y2; j++){
                        f[i][j] = mp[i][j];
                    }
                }
            }else{
                for (int i = x1; i >= x2; i--){
                    for (int j = y1; j >= y2; j--){
                        if (i == x1 && j == y1) continue;
                        int a = 1e9, b = 1e9;
                        if (i != x1) a = f[i + 1][j];
                        if (j != y1) b = f[i][j + 1];
                        f[i][j] = max(mp[i][j], min(a, b));
                    }
                }
                cout << f[x2][y2] << endl;
                for (int i = x1; i >= x2; i--){
                    for (int j = y1; j >= y2; j--){
                        f[i][j] = mp[i][j];
                    }
                }
            }
        }
    }
    return 0;
}