#include <bits/stdc++.h>
using namespace std;
const int maxn = 155;
int posx[maxn], posy[maxn];
float dis[maxn][maxn];
int vis[maxn];
int cntx[maxn];
int map_[maxn][maxn];
int from[maxn];
int farm[maxn][maxn];
int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            dis[i][j] = 1e9;
        }
    }
    for (int i = 1; i <= n; i++){
        cin >> posx[i] >> posy[i];
    }
    int x;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> x;
            if (x == 1){
                map_[i][++cntx[i]] = j;
                dis[i][j] = sqrt(pow(abs(posx[i] - posx[j]), 2) + pow(abs(posy[i] - posy[j]), 2));
            }
        }
    }
    int num1 = 0, num2;
    for (int i = 1; i <= n; i++){
        if (!vis[i]){
            num2 = 0;
            vis[i] = 1;
            num1++;
            from[i] = num1;
            farm[num1][++num2] = i; 
            for (int j = 1; j <= cntx[i]; j++){
                vis[map_[i][j]] = 1;
                from[map_[i][j]] = num1;
                farm[num1][++num2] = map_[i][j]; 
            }
        }
    }
    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    
    system("pause");
    return 0;
}