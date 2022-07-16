#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5, maxm = 1e3 + 5;
struct node{
	int x, w, f, c;
	bool operator < (const node T) const{
		return x < T.x;
	}
}t[maxn];
int l, n, b;
int dp[maxm][maxm];
int main()
{
	cin >> l >> n >> b;
	for (int i = 1; i <= n; i++) cin >> t[i].x >> t[i].w >> t[i].f >> t[i].c;
	sort(t + 1, t + n + 1);
	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 0; j <= b - t[i].c; j++){
			if (dp[t[i].x][j] != -1)dp[t[i].x + t[i].w][j + t[i].c] = max(dp[t[i].x][j] + t[i].f, dp[t[i].x + t[i].w][j + t[i].c]);
		}
	}
	int ans = 0;
	for (int i = 0; i <= b; i++) ans = max(ans, dp[l][i]);
	if (ans == 0) ans = -1;
	cout << ans;
	return 0;
}
