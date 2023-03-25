#include <bits/stdc++.h>
using namespace std;
const int maxn = 3 * 1e4;
map<int, int> vis;
int a[maxn];
int n;
bool dfs(int step, int val){
    if (step == n + 1){
        if (vis[val]) return true;
        else vis[val] = 1;
        return false;
    }
    else{
        if(dfs(step + 1, val - a[step]) || dfs(step + 1, val + a[step])) return true;
    }
    return false;
}
int main(){
    int T;
    cin >> T;
    while(T--){
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        if (n > 20) cout << "Yes" << endl;
        else{
            vis.clear();
            if (dfs(1, 0)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    system("pause");
    return 0;
}