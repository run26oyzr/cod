#include <iostream>
using namespace std;
int a[200005], t[200005];
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
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
	}
	merge(a, 1, n);
	int cnt = 1;
	for (int i = 1; i <= n; i++){
		if (a[i + 1] == a[i]) cnt++;
		else {
			printf("%d %d\n", a[i], cnt);
			cnt = 1;
		}
	}
	return 0;
}
