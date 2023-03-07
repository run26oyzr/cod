#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 19260817;
void read(long long& x) {
    int f = 1; x = 0; char s = getchar();
    while (s > '9' || s < '0') { if (s == '-')f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') { x = x * 10 % mod + (s - '0') % mod; s = getchar(); }
    x = x % mod * f;
}
int a, b, c, x, y;
int exgcd(int a, int b, int &x, int &y){
	if (b == 0){x = 1, y = 0; return a;}
	int res = exgcd(b, a % b, x, y);
	int t = x;
	x = y;
	y = t - a / b * y;
    return res;
}
void func(){
	read(c); read(b);
	a = 19260817;
	int gcd = __gcd(a, b);
	if ((c % gcd) != 0) {
		cout << -1 << endl;
		return;
	}
	a /= gcd;
	b /= gcd;
    c /= gcd;
	exgcd(a, b, x, y);
    y = (y * c) % mod;
	cout << (y + mod) % mod;
}
signed main(){
	func();
	return 0;
}