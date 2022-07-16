#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
char c[maxn];
int n, l;
long long cnt = 0;
void dfs(int q){
	if (cnt == n - 1){
		cout << c;
		return;
	}
//	cout << c << ' ' << q << endl;
	for (int i = 1; i <= l; i++){
		c[q] = i + 'A' - 1;
		if (q == 0) dfs(q + 1);
		int flag = 0;
		for (int j = 1; j <= (q + 1) / 2; j++){
			string a, b;
			for (int m = 1; m <= j; m++){
				a += c[q - j + m];
				b += c[q - 2 * j + m];
			}
			if (a == b){
				flag = 1;
				break;
			}
		}
		if (!flag) {cnt ++; dfs(q + 1);}
	}
}
int main(){
	scanf("%d %d", &n, &l);
	dfs(0);
	return 0;
}
