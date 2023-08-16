#include <bits/stdc++.h>
using namespace std;
struct node{
	int x, y;
	bool operator < (const node T)const{
		return x < T.x;
	}
};
const int maxn = 5 * 1e3 + 5;
node t[maxn];
int main()
{
	int n, m, num = 0;
	scanf("%d %d", &m, &n);
	for (int i = 1; i <= n; i++){
		cin >> t[i].x >> t[i].y;
	}
	sort (t + 1, t + n + 1);
	for (int i = 1; i <= n; i++){
		if (m < 0) break;
		else {
			num += t[i].x * min(m, t[i].y);
		}
		m -= t[i].y;
	}
	printf("%d", num);
	return 0;
}
