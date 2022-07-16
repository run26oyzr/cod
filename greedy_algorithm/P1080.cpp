#include <bits/stdc++.h>
using namespace std;
struct node{
	int x, y;
	bool operator < (const node T)const{
		return x * y < T.x * T.y;
	}
};
const int maxn =1e3 + 5;
node t[maxn];
int main()
{
	int n, m, num = 1, z;
	scanf("%d %d %d", &n, &m, &z);
	for (int i = 1; i <= n; i++){
		cin >> t[i].x >> t[i].y;
	}
	sort (t + 1, t + n + 1);
	int maxm = 0, a;
	for (int i = 1; i <= n; i++){
		a = num / t[i].y;
		if (a > maxm) maxm = a;
		num *= t[i].x;
	}
	printf("%d", maxm);
	return 0;
}
