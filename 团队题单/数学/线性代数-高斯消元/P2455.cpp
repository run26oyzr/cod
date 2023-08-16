#include <bits/stdc++.h>
using namespace std;
const int maxn = 55;
const long double eps = 1e-10;
long double a[maxn][maxn];
long double x[maxn];
long double tmp1[maxn], tmp2[maxn];
int b[maxn];
int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n + 1; j++)
			cin >> a[i][j];
	int curi = 1;
	for(int i = 1; i <= n; i++){//消第几个元
		//找主元  找i列中i行及以后行中的最大值 
		int r = curi; 
//		cout << i << ' ' << curi << endl;
		for (int j = curi + 1; j <= n; j++)
			if(fabs(a[r][i]) < fabs(a[j][i]))
				r = j;
		if (fabs(a[r][i]) < eps){
			//无解或多解，视a[r][n+1]
			continue;
		}
		//交换
		if (r != curi)
			for(int j = 1; j <= n + 1; j++)
				swap(a[r][j], a[curi][j]);
		//归一化
		double del = a[curi][i];
		for (int j = i; j <= n + 1; j++)
			a[curi][j] /= del; 
		//消元 
		for (int j = 1; j <= n; j++){
			if (j != curi){
				del = a[j][i];
				for (int k = i; k <= n + 1; k++)
					a[j][k] -= del * a[curi][k];
			} 
		}
		b[curi] = i;
		curi++;
	}
//	for (int i = 1; i <= n; i++){
//		for (int j = 1; j <= n + 1; j++){
//			printf("%.02Lf ", a[i][j]);
//		}
//		cout << endl;
//	}
	bool flag = false;
	for (int i = 1; i <= n; i++){
		if (b[i] == 0){
			if (fabs(a[i][n + 1]) >= eps){
				cout << -1;
				return 0;
			}
			flag = true;
			continue;
		} 
		if (fabs(a[i][b[i]]) < eps){
			if (fabs(a[i][n + 1]) >= eps){
//				cout << i << ' ' << b[i] << endl;
				cout << -1;
				return 0;
			}
			flag = true;
		} 
	}
	if (flag){
		cout << 0;
		return 0;
	}
	for (int i = 1; i <= n; i++){
		printf("x%d=%.02Lf\n", i, a[i][n + 1]);
	}
	return 0;
}