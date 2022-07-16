#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
struct node{
	long long x, y;
	bool operator < (const node T)const{
		return x < T.x;
	}
};
node t[maxn];
int main()
{
	freopen("P2949_2.in", "r", stdin);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		cin >> t[i].x >> t[i].y;
	}
	sort (t + 1, t + n + 1);
	long long maxm = t[1].y;
	long long cnt = 0;
	for (int i = 2; i <= n; i++){
		if (t[i].x == t[i - 1].x){
			if (t[i].y > maxm) maxm = t[i].y;
		}
		else{
			cnt += maxm;
			maxm = t[i].y;
		}
	}
	cnt += maxm;
	cout << cnt;
	return 0;
}
