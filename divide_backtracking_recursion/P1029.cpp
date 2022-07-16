#include <bits/stdc++.h>
using namespace std;
long long a, b, cnt = 0;
bool x(int c, int d){
	int maxn = 1;
	for (int i = 2; i <= min(c, d); i++){
		if (c % i == 0 && d % i == 0) maxn = i;
	}
	return (maxn == a);
}
bool y(int c, int d){
	int e = c * d, minn = e;
	for (int i = 2; i <= min(c, d); i++){
		if (e / i % c == 0 && e / i % d == 0) minn = e / i;
	}
	return (minn == b);
}
int main()
{
	scanf("%d %d", &a, &b);
	for (int i = a; i <= b; i += a){
		for (int j = a; j <= b; j += a){
			if (x(i, j) && y(i, j)){
				cnt ++;
			}
		}
	}
	cout << cnt;
	return 0;
}
