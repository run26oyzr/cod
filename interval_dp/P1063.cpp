#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 105;
int dp[maxn * 4][maxn * 4], val[maxn * 4], sum[maxn * 4];
signed main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> val[i];
		val[i + n] = val[i];
	}
	for (int len = 1; len < n; len++){
		for (int j = 1; j <= 2 * n; j++){
			int i = j + len;
			if (i > 2 * n) continue;
			for (int k = j; k < i; k++){
				dp[j][i] = max(dp[j][k] + dp[k + 1][i] + val[i + 1] * val[k + 1] * val[j], dp[j][i]);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++){
		ans = max(ans, dp[i][i + n - 1]);
	}
	cout << ans;
	return 0;
} 
