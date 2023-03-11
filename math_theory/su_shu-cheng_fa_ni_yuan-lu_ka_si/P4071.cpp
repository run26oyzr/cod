/**
 * 已经确定m个位置，剩下n-m个位置上的数不能和自己相同
 * 可以使用递推计算
 * D[i]: 共有i个位置时，每个位置上的数不能是i的情况下的方案数
 * 所以应该从n个里选出m个位置作为确定的，再乘上剩下的位置错位排列的方案数
 * 故最终答案应为C(n,m)*D[n-m]
 * 
 * D[i]的递推式推导：
 * 数1共可以放到2~n的位置上，共有n-1种放法，这里不妨设1放到了第2位
 * 则分类讨论数2放到哪里：
 *      1) 数2放到第1位
 *          3~n位形成了新的错位排序，有d[n-2]种方案
 *      2) 数2放到第3~n位
 *          可以理解成数2不能放到第1位，数3不能放到第3位……
 *          转化成了共有n-1个数的错位排序，有d[n-1]种方案
 * 综上，d[i]=(i-1)*(d[i-1]+d[i-2])
 * 
 * C(n,m)的计算：
 * 1)使用lucas
 *      由于n,m<=1e6, mod=1e9+7, lucas并没有起作用
 *      相当于暴力算C(n,m), O(n+m)
 *      T<=5*1e5, T*O(n+m)显然大于1e8
 * 2)使用费马小定理
 *      令p=1e9+7
 *      C(n,m) = n! / ( m! * (n-m)! )
 *             = n! * inv(m!) * inv((n-m)!)
 *      所以需要预处理 n! mod p 和 m!, (n-m)! 在模p下的乘法逆元
 *      首先预处理 n! mod p
 *      因为p是质数，所以可以使用费马小定理（ (n!)^(p-1) 同余 1 (mod p) ）
 *      所以 n! 在模p下的乘法逆元为 (n!)^(p-2)
 *      可以使用快速幂计算
 * 
 * 综上，预处理的内容：
 * 对于n=1~1e6
 * 1) n! mod p
 * 2) n! 在模p下的乘法逆元
 * 3) n个数的错位排序方案数
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e6 + 5;
const int mod = 1e9 + 7;
int d[maxn];
int inv[maxn];
int num[maxn];
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
    return res;
}
int C(int n, int m){
    if (m == 0) return 1;
	return (((num[n] * inv[m]) % mod) * inv[n - m]) % mod;
}
signed main(){
	int T;
	cin >> T;
	d[0] = 1, d[1] = 0;
	for (int i = 2; i <= 1e6; i++){
		d[i] = (i - 1) * (d[i - 1] + d[i - 2]) % mod;
	}
	num[0] = 1;
	for (int i = 1; i <= 1e6; i++){
		num[i] = num[i - 1] * i % mod;
		inv[i] = qpow(num[i], mod - 2) % mod;
	}
	while(T--){
		int n, m;
		scanf("%lld %lld", &n, &m);
        if (n == m) printf("%lld\n", 1);
		else printf("%lld\n", (((C(n, m) * d[n - m]) % mod) + mod) % mod);
	}
	return 0;
}