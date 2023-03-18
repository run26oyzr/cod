#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4;
int n, a[maxn];
void dp(){
	int x = -1;
	int sum = 0;
	for (int i = 1; i <= n; i++){
		if (a[i] >= x) sum += a[i];
		else sum = a[i];
		x = a[i];
		cout << sum << ' ';
	}
	return;
}
int main()
{
	freopen("bignum.in", "r", stdin);
	freopen("bignum.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	dp();
	return 0;
}
