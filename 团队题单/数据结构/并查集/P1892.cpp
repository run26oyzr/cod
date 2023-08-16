#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5, maxm = 5 * 1e3 + 5;
int cnt[maxn], enemy[maxn][maxm];
int fa[maxn];
int n, m;
int getfather(int x){
    if (fa[x] == x) return x;
    return fa[x] = getfather(fa[x]);
}
void merge(int x, int y){
    int fx = getfather(x);
    int fy = getfather(y);
    if (fx != fy){
        fa[fy] = fx;
    }
}
int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++) fa[i] = i;
    char ch;
    int x, y;
    while(m--){
        cin >> ch;
        cin >> x >> y;
        if (ch == 'F'){
            merge(x, y);
        }
        else{
            enemy[x][++cnt[x]] = y;
            enemy[y][++cnt[y]] = x;
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j < cnt[i]; j++){
            merge(enemy[i][j], enemy[i][j + 1]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++){
        if (fa[i] == i) ans++;
    }
    cout << ans;
    system("pause");
    return 0;
}