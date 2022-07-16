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
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) fa[i] = i;
    int x, y, z;
    while(m --){
        cin >> x >> y >> z;
        if (x == 1){
            merge(y, z, 1);
        }
        else{
            if (!merge(y, z)){
                cout << 'Y' << endl;
            }
            else cout << 'N' << endl;
        }
    }
    system("Pause");
    return 0;
}