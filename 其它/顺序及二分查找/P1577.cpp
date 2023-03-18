#include <iostream>
#include <cmath>
using namespace std;
const int maxn = 1e5 + 5;
float a[maxn];
int n, k;

int check(float x){
	int cnt = 0;
	for (int i = 1; i <= n; i++){
		cnt += floor(a[i] / x);
	}
	return cnt;
}

int main(){
	freopen("P1577_3.in", "r", stdin);
	float mn = 0;
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++){
		scanf("%f", &a[i]);
		if (a[i] > mn) mn = a[i];
	}
	float l = 0, r = mn, mid = 0;
	while (l < r){
		mid = (l + r) / 2;
		if (check(mid) >= k) l = mid;
		else if (k - check(mid) >= 1) r = mid - 1;
		else r = mid - 0.01;
	}
	printf("%.2f", l);
	return 0;
}
