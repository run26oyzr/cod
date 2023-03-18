#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
int fa[maxn];
int getfather(int x){
    if (fa[x] == x) return x;
    return fa[x] = getfather(fa[x]);
}
bool merge(int x, int y, int mod = 0){
    int fx = getfather(x);
    int fy = getfather(y);
    if (fx == fy) return false;
    if (mod) fa[fy] = fx;
    return true;
}
int main(){
    int n, m, p;
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++) fa[i] = i;
    int x, y, z;
    while(m --){
        cin >> x >> y;
        merge(x, y, 1);
    }
    while(p--){
        cin >> x >> y;
        if (!merge(x, y)){
            cout << "Yes" << endl;
        }
        else cout << "No" << endl;
    }
    system("Pause");
    return 0;
}