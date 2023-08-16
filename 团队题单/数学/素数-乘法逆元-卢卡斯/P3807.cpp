#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e5 + 5;
int inv[maxn];
int p;
int C(int n, int m){
	if (m > n) return 0;
	int res = 1;
	for (int i = n; i >= n - m + 1; i--){
		res *= i; res %= p;
	}
	for (int i = 1; i <= m; i++){
		res *= inv[i]; res %= p;
	}
	return res;
}
int lucas(int n, int m){
	if (n < p) return C(m, n);
	return lucas(n / p, m / p) * C(m % p, n % p) % p;
}
signed main(){
	int T;
	cin >> T;
	while(T--){
		int n, m;
		cin >> n >> m >> p;
		m = n + m;
		inv[1] = 1;
		for (int i = 2; i <= m; i++){
			inv[i] = (((-p / i) * inv[p % i] % p) + p) % p;
		}
		cout << lucas(n, m) << endl;	
	}
	return 0;
}