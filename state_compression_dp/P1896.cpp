#include <iostream>
#include <cmath>
using namespace std;
int map[10], state[90], sum_one[90];
long long f[10][90][100];
int count_one(int x){
	int a = 0;
	while (x){
		x -= (x & (-x));
		a++;
	}
	return a;
}
int main(){
	int n, m;
	cin >> n >> m;
	int maxstate = 1 << n;
	int cnt = 0;
	for (int i = 0; i < maxstate; i++){
		if(i & (i << 1))continue;
		if(i & (i >> 1))continue;
		state[++cnt] = i;
		sum_one[cnt] = count_one(i);
	}
	for (int i = 1; i <= cnt; i++){
		f[1][i][sum_one[i]] = 1;
	}
	for (int i = 2; i <= n; i++){
		for (int j = 1; j <= cnt; j++){
			int x = state[j];
			for (int k = 1; k <= cnt; k++){
				int y = state[k];
				if(x & y) continue;
				if(y & (x << 1)) continue;
				if(y & (x >> 1)) continue;
				for (int l = sum_one[j]; l <= m; l++){
					f[i][j][l] += f[i - 1][k][l - sum_one[j]];
				}
			}
		}
	}
	long long ans = 0;
	for (int i = 1; i <= cnt; i++){
		ans += f[n][i][m];
	}
	cout << ans;
	return 0;
}
