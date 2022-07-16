#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100000005;
int a[maxn], b[maxn], n, k;

bool check(int x) {
	int j = 1, cnta = 0;
	for (int i = 2; i <= n + 2; i++){
		if (a[i] - a[i - 1] < x) {
			if (cnta == k) return false; 
			else {
				cnta++;
				if (a[i + 1] - a[i - 1] < x) return false;
				i++;
			}
		}
	}
	return true;
}

int main() {
	int q;
	scanf("%d %d %d", &q, &n, &k);
	a[1] = 0;
	a[n + 2] = q;
	for (int i = 2; i <= n + 1; i++) {
		scanf("%d", &a[i]);
	}
	int l = 1, r = q, mid = 0;
	while (l < r) {
		mid = (l + r + 1) >> 1;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	printf("%d", l);
	return 0;
}
