/**
 * g[i]:满足 i|gcd(x,y) 的 (x,y) 组数
 * n里有 floor(n/i) 个 i 的倍数，m 里有 floor(m/i) 个 i 的倍数
 * 所以 g[i] = floor(n/i) * floor(m/i)
 * f[i]:满足 gcd(x,y)=i 的 (x,y) 组数
 * f[i] = g[i] - f[2i] - f[3i] - ...... - f[floor(min(n,m)/i)]
 * ans = (2*i-1)*f[i] （1<=i<=min(n,m)） 
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e5 + 5;
int g[maxn], f[maxn];
signed main(){
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= min(n, m); i++){
		g[i] = (n / i) * (m / i);
	}
	for (int gcd = min(n, m); gcd >= 1; gcd--){
		f[gcd] = g[gcd];
		for (int i = 2; i <= min(n, m) && i * gcd <= min(n, m); i++){
			f[gcd] -= f[i * gcd];
		}
	}
	int ans = 0;
	for (int i = 1; i <= min(n, m); i++){
//		cout << i << ' ' << f[i] << endl;
		ans += (2 * i - 1) * f[i];
	}
	cout << ans;
	return 0;
}