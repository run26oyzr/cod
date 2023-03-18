#include <iostream>
#include <cmath>
using namespace std;
int a[2005], b[2005], t[2005], a2[2005], b2[2005];
void merge(int a[], int l, int r) {
	if (l >= r) return;
	int m = (l + r) >> 1;
	merge(a, l, m);
	merge(a, m + 1, r);
	int i = l, j = m + 1, k = l;
	while (i <= m && j <= r) {
		if (a[i] <= a[j]) t[k++] = a[i++];
		else t[k++] = a[j++];
	}
	while (i <= m) t[k++] = a[i++];
	while (j <= r) t[k++] = a[j++];
	for (int i = l; i <= r; i++) a[i] = t[i];
}
int main() {
	int n, m, l, c1, c2, c3, c4, k1 = 0, k2 = 0;
	scanf("%d %d %d %d %d", &n, &n, &l, &m, &n);
	for (int i = 1; i <= n; i++) {
		a2[i] = 0;
		b2[i] = 0;
		scanf("%d %d %d %d", &c1, &c2, &c3, &c4);
		if (c1 == c3) a[++k1] = min(c2, c4);
		else if (c2 == c4) b[++k2] = min(c1, c3);
	}
	merge(a, 1, k1);
	merge(b, 1, k2);
	int k7 = 0, k8 = 0;
	b[k2 + 1] = 0;
	for (int i = 1; i <= k2; i++) {
		if (b[i] != b[i + 1]) k8++;
	}
	a[k1 + 1] = 0;
	for (int i = 1; i <= k1; i++) {
		if (a[i] != a[i + 1]) k7++;
	}
	int k3 = k7, k4 = k8, k5, k6;
	a[0] = 0;
	int cnt = 1;
	for (int i = 1; i <= k1; i++) {
		if (a[i] == a[i - 1]) cnt++;
		else {
			a2[cnt]++;
			cnt = 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (k3 != l) k3 -= a2[i];
		else {
			k5 = i;
			break;
		}
	}
	b[0] = 0;
	cnt = 1;
	for (int i = 1; i <= k2; i++) {
		if (b[i] == b[i - 1]) cnt++;
		else {
			b2[cnt++];
			cnt = 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (k4 != m) k4 -= b2[i];
		else {
			k6 = i;
			break;
		}
	}
	b[k2 + 1] = 0;
	for (int i = 1; i <= k2; i++) {
		if (b[i] != b[i + 1] && b[i] >= k5) printf("%d ", b[i]);
	}
	printf("\n");
	a[k1 + 1] = 0;
	for (int i = 1; i <= k1; i++) {
		if (a[i] != a[i + 1] && a[i] >= k5) printf("%d ", a[i]);
	}
	return 0;
}
