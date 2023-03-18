#include <bits/stdc++.h>
using namespace std;
const int maxn = 5 * 1e4;
int fa[maxn], c[maxn];
int getfather(int x){
    if (fa[x] == x) return x;
    int fx = getfather(fa[x]);
    c[x] = (c[x] + c[fa[x]]) % 3;
    return fa[x] = fx;
}
bool check(int d, int x, int y){
    int fx = getfather(x);
    int fy = getfather(y);
    if (fx == fy){
        return (c[x] + d - 1) % 3 == c[y];
    }
    else{
        fa[fy] = fx;
        c[fy] = (c[x] + d - 1 - c[y] + 3) % 3;
        return true;
    }
}
int main(){
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        fa[i] = i;
    }
    int x, y, z;
    int a;
    int cnt = 0;
    while(k--){
        cin >> a;
        cin >> x >> y;
        if (x > n | y > n){cnt++; continue;}
        if (!check(a, x, y)) cnt++;
    }
    cout << cnt;
    system("Pause");
    return 0;
}