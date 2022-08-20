#include <bits/stdc++.h>
using namespace std;
const int maxn = 305;
int dis[maxn][maxn];
int main(){
    int n, m, t;
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            dis[i][j] = 1e9;
        }
    }
    for (int i = 1; i <= n; i++){
        dis[i][i] = 0;
    }
    int x, y, z;
    for (int i = 1; i <= m; i++){
        cin >> x >> y >> z;
        dis[x][y] = z;
    }
    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                dis[i][j] = min(dis[i][j], max(dis[i][k], dis[k][j]));
            }
        }
    }
    for (int i = 1; i <= t; i++){
        cin >> x >> y;
        if (dis[x][y] >= 1e9) 
            cout << -1 << endl;
        else cout << dis[x][y] << endl;
    }
    system("pause");
    return 0;
}