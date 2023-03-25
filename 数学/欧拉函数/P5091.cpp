//扩展欧拉定理
#include <bits/stdc++.h>
using namespace std;
#define int long long
int phim = 1;
void read(long long& x) {
    int f = 1; x = 0; char s = getchar();
    while (s > '9' || s < '0') { if (s == '-')f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') { x = x * 10 % phim + (s - '0') % phim; s = getchar(); }
    x = x % phim * f;
}
int mod;
int qpow(int x, int y){
	int xx = x % mod;
	int res = 1;
	while(y){
		if (y & 1){
			res = res * xx % mod;
		}
		xx = xx * xx % mod;
		y >>= 1;
	}
	return res;
}
signed main(){
	int a, b, m;
	cin >> a >> m;
	mod = m;
	for (int i = 2; i <= sqrt(m); i++){
		if (m % i == 0){
			phim *= (i - 1);
			m /= i;
		}
		while(m % i == 0){
			phim *= i;
			m /= i;
		}
	}
	if (m != 1){
		phim *= (m - 1);
	}
	read(b);
	if(b % phim == 0) cout << qpow(a, b + phim);
	else cout << qpow(a, b);
	return 0;
}