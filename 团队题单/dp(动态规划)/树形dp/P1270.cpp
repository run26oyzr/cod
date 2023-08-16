#include <bits/stdc++.h>
#define ls (u << 1)
#define rs (u << 1 | 1)
#define int long long
using namespace std;
const int maxn = 105, maxt = 6005;
int f[maxn << 2][maxt];
struct Node{
	int num, time;
}t[maxn << 2];
int T;
void dfs(int u, int tim){
    if (f[u][tim]) return;
	if (tim <= 0) return;
    if (t[u].num){
        f[u][tim] = min(t[u].num, (tim - 2 * t[u].time) / 5);
        return;
    }
    for (int i = 0; i <= tim - 2 * t[u].time; i++){
        dfs(ls, i);
        dfs(rs, tim - i - 2 * t[u].time);
        f[u][tim] = max(f[u][tim], f[ls][i] + f[rs][tim - i - 2 * t[u].time]);
    }
    // cout << u << ' ' << tim << ' ' << f[u][tim] << endl;
}
void read(int u){
    cin >> t[u].time >> t[u].num;
    if (t[u].num == 0){
        read(ls);
        read(rs);
    }
}
signed main(){
	int rt = 1;
    cin >> T;
    T--;
    read(rt);
	dfs(rt, T);
    int ans = f[rt][T];
	cout << ans;
	return 0;
}