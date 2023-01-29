#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
template<typename T> inline void read(T &x) {
	x = 0;
	char c = getchar();
	for (;!isdigit(c); c = getchar());
	for (;isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
}
int n, m;
int request[maxn];
int now[maxn];
int cost[15];
int L[15], R[15], num[15];
int tot = 0;
int ans = 1e9;
void dfs(int step){
    if (step == m + 1){
        for (int i = 1; i <= 100; i++){
            // cout << i << ' ' << now[i] << ' ' << request[i] << endl;
            if (now[i] < request[i]) return;
        }
        ans = min(ans, tot);
        return;
    }
    for (int i = L[step]; i <= R[step]; i++){
        now[i] += num[step];
    }
    tot += cost[step];
    dfs(step + 1);
    for (int i = L[step]; i <= R[step]; i++){
        now[i] -= num[step];
    }
    tot -= cost[step];
    dfs(step + 1);
}
int main(){
    read(n); read(m);
    int l, r, val;
    for (int i = 1; i <= n; i++){
        read(l); read(r); read(val);
        for (int i = l; i <= r; i++) request[i] += val;
    }
    for (int i = 1; i <= m; i++){
        read(L[i]);
        read(R[i]);
        read(num[i]);
        read(cost[i]);
    }
    dfs(1);
    cout << ans;
    return 0;
}