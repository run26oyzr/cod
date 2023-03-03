#include <bits/stdc++.h>
using namespace std;
#define int long long
int a, b, c, x, y;
/**
 * ax+by=bx'+(a%b)y'
 *      =bx'+(a-floor(a/b)*b)y'
 *      =ay'+b(x'-floor(a/b)*y')
 * so, x = y'
 *     y = x' - floor(a/b) * y'
*/
int exgcd(int a, int b, int &x, int &y){
	if (b == 0){x = 1, y = 0; return a;}
	int res = exgcd(b, a % b, x, y);
	int t = x;
	x = y;
	y = t - a / b * y;
    return res;
}
void func(){
	cin >> a >> b >> c;
	int gcd = __gcd(a, b);
	if ((c % gcd) != 0) {
		cout << -1 << endl;
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
    // cout << "------------k:" << mink << ' ' << maxk << endl;
	if (maxk >= mink){
        // x + k * xb > 0
        // y - k * xa > 0
        // k > -x/xb
        // k < y/xa
        int minx, maxx, miny, maxy;
        minx = x + mink * xb;
        maxx = x + maxk * xb;
        if (minx > maxx) swap(minx, maxx);
        miny = y - mink * xa;
        maxy = y - maxk * xa;
        if (miny > maxy) swap(miny, maxy);
        cout << maxk - mink + 1 << ' ' << minx << ' ' << miny << ' ' << maxx << ' ' << maxy << endl;
    }
    else{
        int minx = x + mink * xb;
        int miny = y - maxk * xa;
        cout << minx << ' ' << miny << endl;
    }
}
signed main(){
	int t;
    cin >> t;
	while(t--){
        func();
	}
	return 0;
}