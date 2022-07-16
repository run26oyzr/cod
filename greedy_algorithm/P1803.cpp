#include <bits/stdc++.h>
using namespace std;
struct node{
	int x, y;
	bool operator < (const node T)const{
		return y < T.y;
	}
};
const int maxn = 1e6 + 5;
node t[maxn];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		cin >> t[i].x;
		cin >> t[i].y;
	}
	sort (t + 1, t + n + 1);
	int cnt = 0, y = -1;
	for (int i = 1; i <= n; i++){
		if (t[i].x >= y){
			cnt++;
			y = t[i].y;
		}
	}
	cout << cnt;
	return 0;
}
