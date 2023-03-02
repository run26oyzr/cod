#include <bits/stdc++.h>
using namespace std;
#define int long long
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
    int X, Y, M, N, L;
    cin >> X >> Y >> M >> N >> L;
    a = N- M, b = L, c = X - Y;
    if (a < 0){
        a = -a;
        c = -c;
    }
	int gcd = __gcd(a, b);
	if ((c % gcd) != 0) {
		cout << "Impossible" << endl;
		return;
	}
	a /= gcd;
	b /= gcd;
    c /= gcd;
	exgcd(a, b, x, y);
    x *= c, y *= c;
    // cout << x << ' ' << y << endl;
	int xa = a;
	int xb = b;
    int mink, maxk;
    mink = ceil((-x + 1.0) / xb * 1.0);
    maxk = floor((y - 1.0) / xa * 1.0);
    int minx = x + mink * xb;
    int miny = y - maxk * xa;
    cout << minx << endl;
}
signed main(){
    func();
	return 0;
}