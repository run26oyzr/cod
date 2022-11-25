#include <bits/stdc++.h>
using namespace std;
const int maxval = 1e5 + 5, maxn = 1e4 + 5, maxm = 55, mod = 1e9 + 7;
int tree[maxval], a[maxn], dp[maxn][maxm];
int n, m;
int lowbit(int x){
    return x & (-x);
}
void add(int id, int val){
    while (id <= n){
        tree[id] += val;
        id += lowbit(id);
    }
}
int query(int id){
    int res = 0;
    while(id >= 1){
        res += tree[id];
        res %= mod;
        id -= lowbit(id);
    }
    return res;
}
int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) dp[i][1] = i;
    for (int i = 2; i <= m; i++){
        memset(tree, 0, sizeof(tree));
        for (int j = 1; j <= n; j++){
            dp[j][i] = (query(maxval - 1) - query(a[j] - 1) + mod) % mod;
            add(a[j], dp[j][i - 1]);
        }
    }
    cout << dp[n][m];
    system("pause");
    return 0;
}