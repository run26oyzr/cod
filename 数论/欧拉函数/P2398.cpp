/* https://www.luogu.com.cn/blog/573215/p2398-post */
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
int prim[maxn], phi[maxn];
bool isp[maxn];
int sum[maxn];
signed main(){
	int n;
	cin >> n;
	phi[1] = 0;
	int cnt = 0;
	for (int i = 2; i <= n; i++){
		if (!isp[i]){
			prim[++cnt] = i;
			phi[i] = i - 1;
		}
		for (int j = 1; j <= cnt && i * prim[j] <= n; j++){
			isp[i * prim[j]] = 1;
			if (i % prim[j] == 0){
				phi[i * prim[j]] = phi[i] * prim[j];
				break;
			}
			else phi[i * prim[j]] = phi[i] * phi[prim[j]];
		}
	}
	for (int i = 1; i <= n; i++){
		sum[i] = sum[i - 1] + phi[i];
	}
	int ans = 0;
	for (int g = 1; g <= n; g++){
		ans += g * sum[n / g];
//		printf("%d\n",ans);
	}
	ans *= 2;
	ans += n * (n + 1) / 2;
	cout << ans;
	return 0;
}