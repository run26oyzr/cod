#include <bits/stdc++.h>
using namespace std;
int n;
void dfs(int x){
	if (x == 0) {printf("0"); return;}
	int m = -1;
	for (int i = 0; i <= 15; i++, m++){
		if (pow(2, i) > x) break;
	}
	int b = 1;
	for (int i = m; i >= 0; i--){
		if (x / pow(2, i) >= 1){
			x -= pow(2, i);
			b = 1;
			if (i == 1) printf("2");
			else{
				printf("2(");
				dfs(i);
				printf(")");
			}
			if (x != 0)printf("+");
		}
	}
	return;
}
int main()
{
	scanf("%d", &n);
	dfs(n);
	return 0;
}
