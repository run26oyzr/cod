#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
int n, t[maxn][maxn], a[maxn][maxn];
int ans = 0;
void dp(){
	t[1][1] = a[1][1];
	for (int i = 2; i <= n; i++){
		t[i][1] = a[i][1] + t[i - 1][1];
		ans = max(ans, t[i][1]);
		t[i][i] = a[i][i] + t[i - 1][i - 1];
		ans = max(ans, t[i][i]);
		for (int j = 2; j < i; j++){
			t[i][j] = max(t[i - 1][j - 1], t[i - 1][j]) + a[i][j];
			ans = max(ans, t[i][j]);
		}
	}
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= i; j++){
			cin >> a[i][j];
		}
	}
	dp();
	cout << ans;
	return 0;
}
