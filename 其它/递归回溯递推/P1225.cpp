#include <bits/stdc++.h>
using namespace std;
const int maxn = 5005;
long long a[maxn];
void dfs(){
	for (int i = 3; i <= 5000; i++){
		a[i] = a[i - 1] + a[i - 2];
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	a[1] = 1;
	a[2] = 2;
	dfs();
	cout << a[n];
	return 0;
}
