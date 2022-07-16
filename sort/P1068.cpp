#include <iostream>
#include <cmath>
using namespace std;
int a[5005][3], b[5005], c[5005], d[5005], t[5005], f[5005], h[5005];
bool e[5005], g[5005];
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
void merge_s(int a[], int l, int r) {
	if (l >= r) return;
	int m = (l + r) >> 1;
	merge_s(a, l, m);
	merge_s(a, m + 1, r);
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
	int n, m, cnt = 0;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 2; j++) {
			scanf("%d", &a[i][j]);
		}
		b[i] = a[i][2];
		c[i] = a[i][2];
	}
	merge(b, 1, n);
	int num = b[int(m * 1.5)];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n && b[i] >= num; j++) {
			if (b[i] == c[j] && e[j] == false) {
				d[i] = a[j][1];
				h[i] = j;
				e[j] = true;
				cnt++;
				break;
			}
		}
	}
	int k = 1;
		for (int i = 1; i <= n; i++) {
			if (b[i + 1] == b[i]) {
				f[k] = a[h[i]][1];
				f[++k] = a[h[i + 1]][1];
			} else if (k != 1) {
				merge_s(f, 1, k);
				for (int l = 1; l <= k; l++) {
					for (int j = 1; j <= n; j++) {
						if (a[j][1] == f[l] && g[j] == false && c[j] == b[i - k + 1]) {
							d[i - k + l] = a[j][1];
							g[j] = true;
						}
					}
				}
				for (int j = 1; j <= k; j++) f[j] = 0;
				k = 1;
			}
		}
	printf("%d %d\n", num, cnt);
	for (int i = 1; i <= cnt; i++) {
		printf("%d %d\n", d[i], b[i]);
	}
	return 0;
}
