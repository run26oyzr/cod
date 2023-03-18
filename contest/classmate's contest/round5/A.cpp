#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;
int fa[maxn];
int getfather(int x){
    if (fa[x] == x) return x;
    return fa[x] = getfather(fa[x]);
}
void merge(int x, int y){
    int fx = getfather(x);
    int fy = getfather(y);
    fa[fx] = fy;
}
int main(){
    freopen("faith.in", "r", stdin);
    freopen("faith.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) fa[i] = i;
    int x, y;
    while(m--){
        cin >> x >> y;
        merge(x, y);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++){
        if (fa[i] == i) cnt++;
    }
    cout << cnt;
    return 0;
}