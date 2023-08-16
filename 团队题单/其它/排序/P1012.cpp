#include <iostream>
#include <cstring>
using namespace std;
char a[25][10];
void swap(int x, int y) {
	char s[10];
	for (int i = 0; i < 10; i++) s[i] = a[y][i];
	for (int i = 0; i < 10; i++) a[y][i] = a[x][i];
	for (int i = 0; i < 10; i++) a[x][i] = s[i];
	return;
}
void bouble(char a[25][10], int n) {
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= n - i; j++) {
			if (strcmp(a[j], a[j + 1]) < 0) {
				swap(j, j + 1);
			}
		}
	}
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%s", a[i]);
	}
	bouble(a, n);
	for (int i = 1; i <= n; i++) {
		printf("%s", a[i]);
	}
	return 0;
}
