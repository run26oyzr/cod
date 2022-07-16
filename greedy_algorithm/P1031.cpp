#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e2 + 5;
int a[maxn];
int main()
{
	int n, cnt = 0, num = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		num += a[i];
	}
	num /= n;
	for (int i = 1; i <= n; i++){
		if (a[i] != num){
			cnt ++;
			a[i + 1] -= num - a[i];
		}
	}
	cout << cnt;
	return 0;
}
