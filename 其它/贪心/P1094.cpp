#include <bits/stdc++.h>
using namespace std;
const int maxn = 3 * 1e4 + 5;
int a[maxn];
int main(){
	int m, n;
	scanf("%d %d", &m, &n);
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	sort (a + 1, a + n + 1);
	int cnt = 0, l = 1, r = n;
	while (l <= r){
		if (a[l] + a[r] <= m){
			l++;
			r--;
			cnt++;
		}
		else
		{
			r--;
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
