#include <bits/stdc++.h>
using namespace std;
long long int m, n, a[25], b[25], cnt = 0;
bool isprime(int x){
	if (x == 2) return true;
	int y = sqrt(x);
	for (int i = 2; i <= y; i++){
		if (x % i == 0) return false; 
	}
	return true;
}
void dfs(int x, int y){
	if (x == n){
		if (isprime(y)) cnt++;
		return;
	}
	for (int i = 1; i <= m; i++){
		b[x] = a[i];
		dfs(x + 1, y + b[x]);
	}
	return;
}
int main()
{
	scanf("%d %d", &m, &n);
	for (int i = 1; i <= m; i++){
		scanf("%d", &a[i]);
	}
	dfs(0, 0);
	cnt /= pow(m, n);
	cout << cnt;
	return 0;
}
