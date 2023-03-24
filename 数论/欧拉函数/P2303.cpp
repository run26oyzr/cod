/**
 * gcd(x,n)=i 的个数为 gcd(x/i,n/i)=1 的个数，即为 phi(n/i)
 * ans = i * phi(n/i) (1<=i<=n且i|n)
 * n 的大于 sqrt(n) 的因数必为 n 除以一个比 sqrt(n) 小的因数，故只用遍历到 sqrt(n) 
 * ans = i * phi(n/i) + (n/i) * phi(i) (1<=i<=sqrt(n)且i|n)
 * 若 n 为平方数，当 i = sqrt(n)时，sqrt(n)*phi(sqrt(n)) 被计算了两次，需要减去一次 
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
int phi(int x){
	int xx = x;
	int num = sqrt(x);
	int res = 1;
	for (int i = 2; i <= num; i++){
		if (xx % i == 0){
			res *= (i - 1);
			xx /= i;
		}
		while(xx % i == 0){
			res *= i;
			xx /= i;
		}
	}
	if (xx != 1){
		res *= xx - 1;
	}
	return res;
}
signed main(){
	int n;
	cin >> n;
	int num = sqrt(n);
	int ans = 0;
	for (int i = 1; i <= num; i++){
		if (n % i == 0){
			ans += i * phi(n / i);
			ans += (n / i) * phi(i);
		}
	}
	if (num * num == n){
		ans -= num * phi(num);
	}
	cout << ans;
	return 0;
}