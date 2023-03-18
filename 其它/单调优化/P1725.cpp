#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e6 + 5;
int q[maxn], a[maxn], f[maxn];
signed main(){
	int n, l, r;
	cin >> n >> l >> r;
	for (int i = 0; i <= n; i++) cin >> a[i];
	int front = 1, rear = 1, ans = LLONG_MIN;
	for(int i = 1; i <= n; i++){
		f[i]=LLONG_MIN;
	}
	int p = 0;
	for (int i = l; i <= n; i++){
		//入队尾 
		while(front <= rear && f[q[rear]] <= f[p]) rear--;
		q[++rear] = p;
		//删队首 
		while(front <= rear && q[front] < i - r) front++;
		//取队首
		f[i] = a[i] + f[q[front]];
		p++;
	}
	for (int i = n - r + 1; i <= n; i++)
		ans = max(ans, f[i]);
	cout << ans;
	return 0;
}
