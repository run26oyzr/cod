/**
 * 将a质因数分解，得 a = p1^k1 * p2^k2 * ...... * pn^kn
 * 则 a^b = p1^(k1*b) * p2(k2*b) * pn(kn*b)
 * a^b的因数和为 (p1^0 + p1^1 + ...... + p1^(k1*b)) * (p2^0 + p2^1 + ...... + p2^(k2*b)) * ...... * (pn^0 + pn^1 + pn^(kn*b))
 * 令    S = pi^0 + pi^1 + ...... + pi^(ki*b)
 * 则 pi*S =        pi^1 + ...... + pi^(ki*b) + pi^(ki*b+1)
 * (pi-1)*S = pi^(ki*b+1) - pi^0
 * S = (pi^(ki*b+1) - pi^0) / (pi - 1)
 * 通过快速幂计算分母，并使用exgcd求出 pi -1 在模 9901 下的乘法逆元即可
 * 注意：需要特判(pi-1)是9901的倍数时
 *      此时，pi 同余 1 mod 9901
 *       pi^0 + pi^1 + ...... + pi^(ki*b)
 *      =1    + 1    + ...... + 1
 *      共 ki*b+1 个 1
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int mod = 9901;
int p[10], k[10];
int x, y;
int exgcd(int a, int b, int &x, int &y){
	if (b == 0){x = 1, y = 0; return a;}
	int res = exgcd(b, a % b, x, y);
	int t = x;
	x = y;
	y = t - a / b * y;
    return res;
}
int func(int x, int p){
	int a, b, c;
	a = x, b = p, c = 1;
	int gcd = __gcd(a, b);
	if ((c % gcd) != 0) {
		return 0;
	}
	exgcd(a, b, x, y);
    x *= c / gcd, y *= c / gcd;
	int xa = a / gcd;
	int xb = b / gcd;
    int mink, maxk;
    mink = ceil((-x + 1.0) / xb * 1.0);
    maxk = floor((y - 1.0) / xa * 1.0);
    return (x + mink * xb) % mod;
}
int qpow(int x, int y){
	int res = 1;
	int xx = x % mod;
	while(y){
		if (y & 1){
			res *= xx; res %= mod;
		}
		xx *= xx; xx %= mod;
		y >>= 1;
	}
	return res % mod;
}
signed main(){
	int a, b;
	cin >> a >> b;
	int aa = a;
	int cnt = 0;
	for (int i = 2; i <= sqrt(a); i++){
		if (aa % i == 0){
			p[++cnt] = i;
			while(aa % i == 0){
				aa /= i;
				k[cnt]++;
			}
		}
	}
	if (aa != 1){
		p[++cnt] = aa;
		k[cnt] = 1;
	}
	int res = 1;
	for (int i = 1; i <= cnt; i++){
		int P, Q;
		Q = qpow(p[i] % mod, k[i] * b + 1) - 1;
		if (p[i] % mod == 1){
			Q = k[i] * b + 1;
			P = 1;
		}
		else{
			P = func(p[i] - 1, 9901);
		}
		res = res * Q % mod;
		res = res * P % mod;
	}
	cout << (res + mod) % mod;
	return 0;
}