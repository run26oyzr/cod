/**
 * 不难得出，第i张牌被洗牌一次后的位置为 (i*2) mod (n + 1)
 * 设洗完m次牌后L位置上的牌为x
 * 则 2^m * x 同余 L (mod (n+1))
 * 
 * 法1：
 *      使用exgcd求解不定方程：2^m * x + L * y = x
 * 法2：
 *      令 y 满足 y^m = x
 *      2^m * x 同余 L (mod (n+1))
 *      2^m * y^m 同余 L (mod (n+1))
 *      (2y)^m 同余 L (mod (n+1))
 *      (2y)^m 在模 n+1 下的乘法逆元为 n+2
 *      则y=n/2+1
 *      使用快速幂计算 y^m，得到 2^m * x 同余 1 (mod (n+1)) 的解
 *      所以x需要再乘以L，得到 2^m * x 同余 L (mod (n+1)) 的解
*/
#include <bits/stdc++.h>
using namespace std;
#define int __int128
int mod;
inline void read(int &n){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    n=x*f;
}
inline void print(int n){
    if(n<0){
        putchar('-');
        n*=-1;
    }
    if(n>9) print(n/10);
    putchar(n % 10 + '0');
}
int qpow(int x, int y){
	int res = 1;
	int xx = x % mod;
	while(y){
		if (y & 1){
			res = res * xx % mod;
		}
		xx = xx * xx % mod;
		y >>= 1;
	}
	return res % mod;
}
int x, y;
int exgcd(int a, int b, int &x, int &y){
	if (b == 0){x = 1, y = 0; return a;}
	int res = exgcd(b, a % b, x, y);
	int t = x;
	x = y;
	y = t - a / b * y;
    return res;
}
int func(int A, int B, int C){
	int a, b, c;
	a = A % mod, b = B, c = C % mod;
	int gcd = __gcd(a, b);
	if ((c % gcd) != 0) {
		return 0;
	}
	exgcd(a, b, x, y);
    x = x * c / gcd % mod, y = y *  c / gcd % mod;
	int xa = a / gcd;
	int xb = b / gcd;
    int mink, maxk;
    mink = ceil((-x + 1.0) / xb * 1.0);
    maxk = floor((y - 1.0) / xa * 1.0);
    return (x + mink * xb) % mod;
}
signed main(){
	int n, m, l;
	read(n); read(m); read(l);
	mod = n + 1;
	print( func(qpow(2, m), mod, l) );
	return 0;
}