#include <bits/stdc++.h>
#define int long long
using namespace std;
void sum(int &p1, int &q1, int p2, int q2){
	int gcd_ = __gcd(p2, q2);
	p2 /= gcd_;
	q2 /= gcd_;
	gcd_ = __gcd(p1, p2);
	int q = q1 * p2 / gcd_ + q2 * p1 / gcd_;
	p1 = p1 * p2 / gcd_, q1 = q;
	gcd_ = __gcd(p1, q1);
	p1 /= gcd_;
	q1 /= gcd_;
}
signed main(){
	int n;
	cin >> n;
	int p1 = 1, q1 = 0;
	for (int i = 1; i <= n; i++){
		sum(p1, q1, n - i + 1, n);
	}
	// cout << q1 << ' ' << p1 << endl;
	int zheng_shu = floor(q1 * 1.0 / p1);
	q1 -= p1 * zheng_shu;
	int len1 = floor(log10(zheng_shu)) + 1;
	int len2 = floor(log10(p1) + 1);
	if (!q1) cout << zheng_shu;
	else{
		for (int i = 1; i <= len1; i++) cout << ' ';
		cout << q1 << endl;
		cout << zheng_shu;
		for (int i = 1; i <= len2; i++) cout << '-';
        cout << endl;
		for (int i = 1; i <= len1; i++) cout << ' ';
		cout << p1 << endl;
	}
	return 0;
}