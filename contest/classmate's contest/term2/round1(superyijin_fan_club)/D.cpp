#include <bits/stdc++.h>
using namespace std;
const int maxn = 2 * 1e5 + 5;
int a[maxn], b[maxn];
int main(){
	freopen("tof.in", "r", stdin);
	freopen("tof.out", "w", stdout);
	int n, q;
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++){
		scanf("%d %d", &a[i], &b[i]);
	}
	int opt, l, r, x, y;
	while(q--){
		scanf("%d %d %d", &opt, &l, &r);
		if (opt == 1){
			scanf("%d %d", &x, &y);
		}
		else{
			if ((r - l + 1) % 2 == 0) printf("1\n");
			else printf("0\n");
		}
	}
	return 0;
}