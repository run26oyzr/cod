#include <iostream>
using namespace std;
int a[305][4], b[305], c[305], t[305], d[305], f[305];
bool e[305], g[305];
void merge(int a[], int l, int r) {
	if (l >= r) return;
	int m = (l + r) >> 1;
	merge(a, l, m);
	merge(a, m + 1, r);
	int i = l, j = m + 1, k = l;
	while (i <= m && j <= r) {
		if (a[i] >= a[j]) t[k++] = a[i++];
		else t[k++] = a[j++];
	}
	while (i <= m) t[k++] = a[i++];
	while (j <= r) t[k++] = a[j++];
	for (int i = l; i <= r; i++) a[i] = t[i];
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= 3; j++) {
			scanf("%d", &a[i][j]);
			cnt += a[i][j];
		}
		b[i] = cnt;
		c[i] = cnt;
	}
	merge(b, 1, n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (b[i] == c[j] && e[j] == false) {
				d[i] = j;
				e[j] = true;
				break;
			}
		}
	}
	int k = 1;
	for (int i = 1; i <= n; i++) {
		if (b[i + 1] == b[i]) {
			f[k] = a[d[i]][1];
			f[++k] = a[d[i + 1]][1];
		} else if (k != 1) {
			merge(f, 1, k);
			for (int l = 1; l <= k; l++) {
				for (int j = 1; j <= n; j++) {
					if (a[j][1] == f[l] && g[j] == false && c[j] == b[i - k + 1]) {
						d[i - k + l] = j;
						g[j] = true;
					}
				}
			}
			for (int j = 1; j <= k; j++) f[j] = 0;
			k = 1;
		}
	}
	for (int i = 1; i <= 5; i++) {
		printf("%d %d\n", d[i], b[i]);
	}
	return 0;
}
