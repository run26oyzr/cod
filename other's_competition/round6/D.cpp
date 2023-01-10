#include <bits/stdc++.h>
#define int long long
using namespace std;
int mp[45][45];
int dis[45][45][45][45];
int vis[45][45];
struct Queue{
    int x, y;
    int dis;
    bool operator < (const Queue T)const{
        return dis < T.dis;
    }
};
priority_queue <Queue> q;
int n, m, Q;
int pos[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
void dijk(int x, int y){
    memset(vis, 0, sizeof(vis));
    dis[x][y][x][y] = mp[x][y];
    q.push({x, y, mp[x][y]});
    while(!q.empty()){
        int nowx = q.top().x, nowy = q.top().y; q.pop();
        if (vis[nowx][nowy]) continue;
        vis[nowx][nowy] = 1;
        for (int i = 0; i < 4; i++){
            int newx = nowx + pos[i][0];
            int newy = nowy + pos[i][1];
            if (newx < 1 || newy < 1 || newx > n || newy > m) continue;
            if (max(dis[x][y][nowx][nowy], mp[newx][newy]) < dis[x][y][newx][newy]){
                dis[x][y][newx][newy] = max(dis[x][y][nowx][nowy], mp[newx][newy]);
                q.push({newx, newy, dis[x][y][newx][newy]});
            }
        }
    }
}
signed main(){
    // freopen("help.in", "r", stdin);
    // freopen("help.out", "w", stdout);
    cin >> n >> m >> Q;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            scanf("%lld", &mp[i][j]);
        }
    }
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            dijk(i, j);
        }
    }
    int x1, y1, x2, y2;
    while(Q--){
        scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
        printf("%lld\n",dis[x1][y1][x2][y2]);
    }
    return 0;
}