#include <iostream>
#include <cmath>
using namespace std;
int map[105], f[105][65][65], state[65], sum_one[65];
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
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			char c;
			int x;
			cin >> c;
			x = (c == 'H')?0:1;
			map[i] = map[i] * 2 + x;
		}
	}
	int maxstate = 1 << m;
	int cnt = 0;
	for (int i = 0; i < maxstate; i++){
		if(i & (i << 1))continue;
		if(i & (i << 2))continue;
		if(i & (i >> 1))continue;
		if(i & (i >> 2))continue;
		state[++cnt] = i;
		sum_one[cnt] = count_one(i);
	}
	for (int i = 1; i <= cnt; i++){
		if ((map[1] & state[i]) != state[i]) continue;
		f[1][i][1] = sum_one[i];
	}
	for (int i = 1; i <= cnt; i++){
		if ((map[2] & state[i]) != state[i]) continue;
		for (int j = 1; j <= cnt; j++){
			if ((map[1] & state[j]) != state[j]) continue;
			if (state[i] & state[j]) continue;
			f[2][i][j] = sum_one[i] + sum_one[j];
		}
	}
	for (int i = 3; i <= n; i++){
		for (int j = 1; j <= cnt; j++){
			int y = state[j];
			if ((map[i] & y) != y) continue;
			for (int k = 1; k <= cnt; k++){
				int x = state[k];
				if(x & y) continue;
				if ((map[i - 1] & x) != x) continue;
				for (int l = 1; l <= cnt; l++){
					int z = state[l];
					if (x & z) continue;
					if (y & z) continue;
					if ((map[i - 2] & z) != z) continue;
					f[i][j][k] = max(f[i][j][k], f[i - 1][k][l] + sum_one[j]);
					f[i][j][k] %= 100000000;
				}
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= cnt; i++){
		if ((state[i] & map[n]) != state[i]) continue;
		for (int j = 1; j <= cnt; j++){
			if ((state[j] & map[n - 1]) != state[j]) continue;
			if (state[i] & state[j]) continue;
			ans = max(ans, f[n][i][j]);
		}
	}
	cout << ans;
	return 0;
}
