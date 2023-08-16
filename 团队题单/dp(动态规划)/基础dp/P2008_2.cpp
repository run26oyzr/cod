#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;
int n, t[maxn], x[maxn], sum[maxn];
void dp(){
	x[1] = 1;
	sum[1] = t[1];
	cout << t[1];
	for (int i = 2; i <= n; i++){
		for (int j = 1; j < i; j++){
			if (x[j] >= x[i] && t[j] <= t[i]){
				x[i] = x[j] + 1;
				sum[i] = sum[j] + t[i];
			}
		}
		if (sum[i] == -1){
			x[i] = 1;
			sum[i] = t[i];
		}
		cout << ' ' << sum[i];
	}
	return;
}
int main()
{
	memset(sum, -1, sizeof(sum));
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> t[i];
	}
	dp();
	return 0;
}
