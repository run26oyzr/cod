#include <bits/stdc++.h>
using namespace std;
const int maxn = 155;
int posx[maxn], posy[maxn];
long double dis[maxn][maxn];
long double diameter[maxn];
long double farest_dis[maxn];
int vis[maxn];
int farm[maxn];
int n;
long double distance(int x, int y){
    return sqrt(pow(abs(posx[x] - posx[y]), 2) + pow(abs(posy[x] - posy[y]), 2));
}
void dfs(int id, int farm_num){
    farm[id] = farm_num;
    for (int i = 1; i <= n; i++){
        if (!farm[i] && dis[i][id] < 1e9) dfs(i, farm_num);
    }
}
int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> posx[i] >> posy[i];
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            dis[i][j] = 1e9;
        }
    }
    char c;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> c;
            if (c == '1' || i == j){
                dis[i][j] = distance(i, j);
            }
        }
    }

    int num = 0;
    for (int i = 1; i <= n; i++){
        if(!farm[i]) dfs(i, ++num);
    }

    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (dis[i][j] < 1e9){
                farest_dis[i] = max(farest_dis[i], dis[i][j]);
            }
        }
        diameter[farm[i]] = max(diameter[farm[i]], farest_dis[i]);
    }

    long double max_num, min_num = 1e9;
    for (int i = 1; i <= n; i++){
        for (int j = i + 1; j <= n; j++){
            if (farm[i] != farm[j]){
                max_num = max(max(diameter[i], diameter[j]), farest_dis[i] + farest_dis[j] + distance(i, j));
                min_num = min(min_num, max_num);
            }
        }
    }
    printf("%.6Lf", min_num);
    system("pause");
    return 0;
}