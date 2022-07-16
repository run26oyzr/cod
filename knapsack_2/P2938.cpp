#include <bits/stdc++.h>
using namespace std;
int s, d, m, t[55][15], dp[500005];
int ans = 0;
int main(){
	cin >> s >> d >> m;
	for (int i = 1; i <= s; i++){
		for (int j = 1; j <= d; j++){
			cin >> t[i][j];
		}
	}
	int n, m1 = 0;
	for (int i = 1; i < d; i++){
		ans = max(ans, m);
		n = 0;
		memset(dp, 0, sizeof(dp));
		for (int j = 1; j <= s; j++){
			for (int k = t[j][i]; k <= m; k++){
				dp[k] = max(dp[k], dp[k - t[j][i]] + t[j][i + 1] - t[j][i]);
				n = max(n, dp[k]);
			}
		}
		m += n;
	}
	ans = max(ans, m);
	cout << ans;
	return 0;
}
