#include <bits/stdc++.h>
using namespace std;
const int maxn = 205;
int t[maxn], vis[maxn];
int dis[maxn][maxn];
int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> t[i];
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            dis[i][j] = 1e9;
        }
    }
    for (int i = 0; i < n; i++){
        dis[i][i] = 0;
    }
    int x, y, z;
    for  (int i = 1; i <= m; i++){
        cin >> x >> y >> z;
        dis[x][y] = min(dis[x][y], z);
        dis[y][x] = min(dis[y][x], z);
    }
    int q;
    cin >> q;
    int k = 0;
    while(q--){
        cin >> x >> y >> z;
        for(;t[k] <= z && k < n; k++){
            vis[k] = 1;
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
            
        }
        // cout << "x = " << x << "  y = " << y << "   ans = ";
        if (!vis[x] || !vis[y] || dis[x][y] >= 1e9)
            cout << -1 << endl;
        else cout << dis[x][y] << endl;
    }
    system("pause");
    return 0;
}