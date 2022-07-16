#include <bits/stdc++.h>
using namespace std;
const int maxn = 55;
struct node{
	int loc, val;
}t[maxn];
int dp[maxn][maxn][2], sum[maxn];
int n, m;
int dis(int x, int y){
	return sum[n] - sum[y] + sum[x];
}
int tim(int x, int y){
	return t[y].loc - t[x].loc;
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			for (int k = 0; k <= 1; k++) dp[i][j][k] = 1e9;
		}
	}
	for (int i = 1; i <= n; i++){
		cin >> t[i].loc >> t[i].val;
		sum[i] = sum[i - 1] + t[i].val;
	}
	dp[m][m][0] = dp[m][m][1] = 0;
	for (int len = 2; len <= n; len++){
		for (int i = 1; i + len - 1 <= n; i++){
			int j = i + len - 1;
			dp[i][j][0] = min(dp[i + 1][j][1] + dis(i, j) * tim(i, j), dp[i + 1][j][0] + dis(i, j) * tim(i, i + 1));
			dp[i][j][1] = min(dp[i][j - 1][0] + dis(i - 1, j - 1) * tim(i, j), dp[i][j - 1][1] + dis(i - 1, j - 1) * tim(j - 1, j));
		}
	}
	int ans = min(dp[1][n][1], dp[1][n][0]);
	cout << ans;
	return 0;
}
