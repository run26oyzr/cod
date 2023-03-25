#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e6 + 5, maxval = 1e4 + 5;
int p[maxn], q[maxn], Q[maxn], Sum[maxn];
int tree[maxn];
int lowbit(int x){return x & (-x);}
int n;
void add(int id, int val){
    while(id <= maxval){
        tree[id] += val;
        id += lowbit(id);
    }
}
int sum(int id){
    int res = 0;
    while(id >= 1){
        res += tree[id];
        id -= lowbit(id);
    }
    return res;
}
signed main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        scanf("%lld %lld", &p[i], &q[i]);
        Q[i] = q[i];
        add(q[i], 1); 
    }
    sort(q + 1, q + n + 1);
    for (int i = 1; i <= n; i++) Sum[i] = Sum[i - 1] + q[i];
    int ans = 0;
    for (int i = 1; i <= n; i++){
        int x = sum(p[i]);
        int tot = Sum[x] - Q[i];
        ans = max(ans, tot);
    }
    cout << ans;
    return 0;
}