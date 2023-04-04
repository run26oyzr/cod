#include <bits/stdc++.h>
using namespace std;
const int maxn = 305;
const long double eps = 1e-6;
long double a[maxn][maxn];
long double x[maxn];
bool linked[maxn][maxn];
int out[maxn];
int main(){
	int n, m, p, q;
	cin >> n >> m >> p >> q;
	for (int i = 1; i <= m; i++){
		int u, v;
		cin >> u >> v;
		linked[u][v] = linked[v][u] = true;
		out[u]++; out[v]++;
	}
	for (int i = 1; i <= n; i++)
		if (linked[1][i])
			a[1][i] = -(1 - 1.0 * p / q) / out[i];
	a[1][1] = 1;
	a[1][n + 1] = 1.0 * p / q;
	for (int i = 2; i <= n; i++){
		for (int j = 1; j <= n; j++)
			if (linked[i][j]) 
				a[i][j] = -(1 - 1.0 * p / q) / out[j]; 
		a[i][i] = 1;
		a[i][n + 1] = 0;
	}
	int curi = 1;
	for(int i = 1; i <= n; i++){//消第几个元(主元为第i行第i列)
		//找主元  找i列中i行及以后行中的最大值 
		int r = curi; 
		for (int j = i + 1; j <= n; j++)
			if(fabs(a[r][i]) < fabs(a[j][i]))
				r = j;
		//交换
		if (r != i)
			for(int j = 1; j <= n + 1; j++)
				swap(a[r][j], a[i][j]);
		//归一化
		double del = a[i][i];
		for (int j = i; j <= n + 1; j++)
			a[i][j] /= del; 
		//消元 
		for (int j = 1; j <= n; j++){
			if (i == j) continue;
			del = a[j][i];
			for (int k = i; k <= n + 1; k++)
				a[j][k] -= del * a[i][k];
		}
		curi++;
	}
	for (int i = 1; i <= n; i++){
		printf("%.09Lf\n", a[i][n + 1]);
	}
	return 0;
}