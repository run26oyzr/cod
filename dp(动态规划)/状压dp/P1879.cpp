#include <iostream>
#include <cmath>
using namespace std;
const int maxn = 15;
int map[15], f[15][9000], state[9000];
int main(){
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			int x;
			cin >> x;
			map[i] = map[i] * 2 + x;
		}
	}
	int maxstate = 1 << m;
	for (int i = 0; i < maxstate; i++){
		if ((!(i & (i << 1))) && !(i & (i >> 1))) state[i] = 1;
	}
	f[0][0] = 1;
	for (int i = 1; i <= n; i++){
		for (int y = 0; y < maxstate; y++){
			if (!state[y]) continue;
			if ((map[i] & y) != y) continue;
			for (int x = 0; x < maxstate; x++){
				if (!state[x]) continue;
				if(x & y) continue;
				f[i][y] += f[i-1][x];
				f[i][y] %= 100000000;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < maxstate; i++) ans += f[n][i], ans %= 100000000;
	cout << ans;
	return 0;
}
