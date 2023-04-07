#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;
const long double eps = 1e-10;
long double a[maxn][maxn];
long double x[maxn];
int linked[maxn][maxn];
int out[maxn];
long double tmp[maxn * maxn];
long double P[maxn];
int main(){
	int n, m, p, q;
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int u, v;
		cin >> u >> v;
		if (u != n){
            linked[u][v] = i;
            out[u]++;
        }
		if (v != n){
            linked[v][u] = i;
            out[v]++;
        }
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j < n; j++)
			if (linked[i][j]){
				a[i][j] = -(1.0 / out[j]); 
            }
		a[i][i] = 1.0;
		if (i == 1) a[i][n + 1] = 1.0;
		else a[i][n + 1] = 0;
	}
	// for (int i = 1; i <= n; i++){
	// 	for (int j = 1; j <= n + 1; j++){
    //         if (j == n) continue;
	// 		cout << a[i][j] << ' ';
	// 	}
	// 	cout << endl;
	// }
	for(int i = 1; i <= n; i++){//消第几个元(主元为第i行第i列)
		//找主元  找i列中i行及以后行中的最大值 
		int r = i; 
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
	}
	for (int i = 1; i <= n; i++){
		P[i] = a[i][n + 1];
        // cout << P[i] << ' ';
	}
    // cout << endl;
	for (int i = 1; i <= n; i++){
		for (int j = i + 1; j <= n; j++){
			if (linked[i][j]){
                int x = linked[i][j];
                if (i != n) tmp[x] += P[i] / out[i];
                if (j != n) tmp[x] += P[j] / out[j]; 
			}
		}
	}
	sort(tmp + 1, tmp + m + 1);
	long double ans = 0;
	for (int i = 1; i <= m; i++){
		ans += tmp[i] * (m - i + 1); 
	} 
	printf("%.03Lf", ans);
	return 0;
}