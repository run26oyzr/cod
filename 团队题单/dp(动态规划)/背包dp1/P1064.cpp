#include <bits/stdc++.h>
using namespace std;
const int maxn = 4 * 1e4 + 5;
int v[maxn], w[maxn], dp[maxn];
struct node{
	int v[5], w[5], num;
}t[maxn];
int main()
{
	int n, m, a, b, c, cnt = 0;
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		cin >> a >> b >> c;
		if (c == 0){
			t[++cnt].v[1] = a;
			t[cnt].w[1] = a * b;
			t[cnt].num ++;
		}
		else{
			t[c].v[++t[c].num] = a + t[c].v[1];
			t[c].w[t[c].num] = a * b + t[c].w[1];
			if (t[c].num == 3){
				t[c].num ++;
				t[c].v[4] = t[c].v[1] + t[c].v[2] + t[c].v[3];
				t[c].w[4] = t[c].w[1] + t[c].w[2] + t[c].w[3];
			}
		}
	}
	for (int i = 1; i <= cnt; i++){
		for (int j = n; j >= 1; j--){
			for (int k = t[i].num; k >= 1; k--){
				if (j >= t[i].v[k])
					dp[j] = max(dp[j - t[i].v[k]] + t[i].w[k], dp[j]);
			}
		}
	}
	cout << dp[n];
	return 0;
}
