#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 6;
int a[maxn];
int lastpos[maxn], f[maxn];
int main(){
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int u, v;
    while (q--){
        cin >> u >> v;
        if (u > v) 
            swap(u, v);
        if (u == v){
            cout << '0' << endl;
            continue;
        }
        int ans = v - u;
        for (int i = 1; i <= n; i++)
            lastpos[i] = u - 1;
        for (int i = u; i <= v; i++)
            f[i] = 0x3f3f3f3f;
        f[u - 1] = 0;
        for (int i = u; i <= v; i++){
            f[i] = min(f[i - 1] + 1, f[lastpos[a[i]]] + (i - lastpos[a[i]] - 1));
            lastpos[a[i]] = i;
        }
        cout << ans + f[v] << endl;
    }
    return 0;
}