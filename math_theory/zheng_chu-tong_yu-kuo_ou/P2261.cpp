//除法分块
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	int n, k;
	cin >> n >> k;
	int ans = n * k;
	int L, R;
	for (L = 1; L <= min(n, k); L = R + 1){
		R = k / (k / L);
		if (R > n) R = n;
		int num = (R - L + 1) * (R + L) / 2;
		ans -= (k / L) * num;
//		cout << L << ' ' << R << ' ' << ans << endl;
	}
	cout << ans << endl;
	return 0;
}