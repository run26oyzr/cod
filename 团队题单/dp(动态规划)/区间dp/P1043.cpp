#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 55, maxm = 15;
int dpmax[maxn * 2][maxn * 2][maxm], dpmin[maxn * 2][maxn * 2][maxm], val[maxn * 2], sum[maxn * 2];
int mod(int x, int y){
	return ((sum[y] - sum[x - 1]) % 10 + 10) % 10;
}
signed main(){
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> val[i];
		val[i + n] = val[i];
		sum[i] = sum[i - 1] + val[i];
	}
	for (int i = n + 1; i <= 2 * n; i++){
		sum[i] = sum[i - 1] + val[i];
	}
	if (n == m){
		int x = 1;
		for (int i = 1; i <= n; i++) x *= mod(i, i);
		cout << x << endl << x;
		return 0;
	}
	for (int i = 1; i <= n; i++){
		for (int j = i; j < i + n; j++){
			dpmax[i][j][1] = mod(i, j);
			dpmin[i][j][1] = mod(i, j);
			for (int k = 2; k <= m; k++) dpmin[i][j][k] = INT_MAX;
		}
	}
	for (int num = 2; num <= m; num++){
		for (int len = 1; len < n; len++){
				for (int j = 1; j <= 2 * n; j++){
					int i = j + len;
					if (i > 2 * n) continue;
					for (int k = i + 1; k <= 2 * n; k++){
						dpmax[j][k][num] = max(dpmax[j][i][num - 1] * mod(i + 1, k), dpmax[j][k][num]);
						dpmin[j][k][num] = min(dpmin[j][i][num - 1] * mod(i + 1, k), dpmin[j][k][num]);
					}
				}
			}
	}
	
	int ansmin = INT_MAX, ansmax = 0;
	for (int i = 1; i <= n; i++){
		ansmax = max(ansmax, dpmax[i][i + n - 1][m]);
		ansmin = min(ansmin, dpmin[i][i + n - 1][m]);
	}
	cout << ansmin << endl << ansmax;
	return 0;
} 
