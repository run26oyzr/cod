#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100000005;
int a[maxn], b[maxn], n, k;

int check(int x) {
	int cnt = 0, j = 1, c;
	while (j <= n) {
		c = 0;
		for (int i = 1; i <= n; i++) {
			if (a[j] + x <= a[i]) {
				cnt++;
				j = i;
				c = 1;
				break;
			}
		}
		if(c == 0) break;
	}
	return cnt + 1;
}

int main() {
	int mn = 0;
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (a[i] > mn) mn = a[i];
	}
	sort(a + 1, a + n + 1);
	int l = 1, r = mn, mid = 0;
	while (l < r) {
//		printf("%d %d\n", l, r);
		mid = (l + r + 1) >> 1;
		if (check(mid) >= k) l = mid;
		else r = mid - 1;
	}
	printf("%d", l);
	return 0;
}
