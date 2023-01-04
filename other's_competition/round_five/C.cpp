#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;
set<int> t[maxn * maxn];
set<int> expirement[maxn];
int pos[maxn];
int main(){
    freopen("medicine.in", "r", stdin);
    freopen("medicine.out", "w", stdout);
    int n, m, q;
    cin >> n >> m >> q;
    char c;
    int x, y;
    int tot = 0;
    for (int i = 1; i <= n; i++){
        
    }
    while(q--){
        cin >> c >> x >> y;
        if (c == 'A'){
            pos[x] = y;
        }
        if (c == 'D'){
            int ans = 0;
            for (int i = 1; i <= n; i++) expirement[i].clear();
            for (int i = 1; i <= n; i++){
                expirement[pos[i]].insert(i);
            }
            for (int i = x; i <= y; i++){
                if (expirement[i].empty()) continue;
                bool flag = true;
                for (int j = 1; j <= tot; j++){
                    if (t[j] == expirement[i]){
                        flag = false;
                        break;
                    }
                }
                if (flag){
                    t[++tot] = expirement[i];
                    ans += expirement[i].size();
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}