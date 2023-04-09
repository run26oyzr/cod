#include <bits/stdc++.h>
using namespace std;
const int maxn = 2005;
const int mod = 998244353;
long long f[maxn];
long long sum[maxn];
int main(){
	int n, m;
	cin >> n >> m;
//	n = 2000, m = 2000;
	for (int i = 1; i <= m; i++){
		f[i] = 1;
		sum[i] = i;
	}
	for (int i = 2; i <= n; i++){
		for (int j = 1; j <= m; j++){
			long long tmp = 0;
			for (int k = 2; k <= m && k * j <= m; k++){
				tmp = (tmp + f[k * j]) % mod;
			}
			f[j] = ((sum[m] - tmp) % mod + mod) % mod;
		}
		sum[0] = 0;
		for (int j = 1; j <= m; j++) sum[j] = (sum[j - 1] + f[j]) % mod;
	}
	long long ans = 0;
	for (int i = 1; i <= m; i++){
		ans = (ans + f[i]) % mod;
	}
//	cout << 1197100469 % mod << endl;
	cout << (ans % mod + mod) % mod;
	return 0;
}
//m = 2000; sum(m/i)(1<=i<=m) = 15518
//若特判i=1，可以减至13518，判断同样耗时，总复杂度好像差不多 
//15518*2000<1e8
//加m^2预处理m的倍数?
//n=2000,m=2000,ans=1197100469,取模错了