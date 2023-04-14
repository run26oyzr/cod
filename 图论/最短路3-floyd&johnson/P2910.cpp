#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
int dis[maxn][maxn];
int must_go[10005];
int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        cin >> must_go[i];
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> dis[i][j];
        }
    }
    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    int ans = 0;
    for (int i = 2; i <= m; i++){
        ans += dis[must_go[i - 1]][must_go[i]];
    }
    cout << ans;
    system("pause");
    return 0;
}