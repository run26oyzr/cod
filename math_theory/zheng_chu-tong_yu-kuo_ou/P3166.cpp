#include <bits/stdc++.h>
using namespace std;
#define int long long
int C(int x, int y){
	if (x < y) return 0;
	int ans = 1;
	for (int i = x; i >= x - y + 1; i--){
		ans *= i; 
	}
	for (int i = 1; i <= y; i++){
		ans /= i;
	}
	return ans;
} 
signed main(){	
	int m, n;
	cin >> m >> n;
	n++; m++;
	int res = C(n * m, 3);
//	cout << res << endl;
	res -= n * C(m, 3);
	res -= m * C(n, 3);
//	cout << res << endl;
    /**
     * 从(0,0)到(x,y)上有gcd(x,y)+1个点（包括(0,0)与(x,y)）
     * 以(0,0)为其中一点，(x,y)为另一点，共有gcd(x,y)-1个点会使三点共线（(gcd(x,y)+1) - 2）
    */
	for (int i = 1; i < n; i++){
		for (int j = 1; j < m; j++){
			if (i + j < 3) continue;
			res -= (__gcd(i, j) - 1) * (n - i) * (m - j) * 2;
//			cout << res << endl;
		}
	}
	cout << res;
	return 0; 
}