#include <bits/stdc++.h>
using namespace std;
const int maxn = 15;
const long double eps = 1e-10;
long double a[maxn][maxn];
long double x[maxn];
long double tmp1[maxn], tmp2[maxn];
int main(){
	int n;
	cin >> n;
	long double sum = 0;
	for (int i = 1; i <= n; i++){
		cin >> tmp1[i];
		sum += tmp1[i] * tmp1[i];
	}
	for (int i = 1; i <= n; i++){
		long double sum2 = 0;
		for(int j = 1; j <= n; j++){
			cin >> tmp2[j];
			sum2 += tmp2[j] * tmp2[j];
		}
		a[i][n + 1] = sum2 - sum;
		for (int j = 1; j <= n; j++){
			a[i][j] = 2 * (tmp2[j] - tmp1[j]);
		}
	}
//	for (int i = 1; i <= n; i++){
//		for (int j = 1; j <= n + 1; j++){
//			printf("%.03Lf ", a[i][j]);
//		}
//		cout << endl;
//	}
	int curi = 1;
	for(int i = 1; i <= n; i++){//消第几个元(主元为第i行第i列)
		//找主元  找i列中i行及以后行中的最大值 
		int r = curi; 
		for (int j = i + 1; j <= n; j++)
			if(fabs(a[r][i]) < fabs(a[j][i]))
				r = j;
		if (fabs(a[r][i]) < eps){
			//无解或多解，视a[r][n+1] 
			cout << "No Solution";
			return 0;
		}
		//交换
		if (r != i)
			for(int j = 1; j <= n + 1; j++)
				swap(a[r][j], a[i][j]);
		//归一化
		double del = a[i][i];
		for (int j = i; j <= n + 1; j++)
			a[i][j] /= del; 
		//消元 
		for (int j = i + 1; j <= n; j++){
			del = a[j][i];
			for (int k = i; k <= n + 1; k++)
				a[j][k] -= del * a[i][k];
		}
		curi++;
	}
	//行阶梯矩阵 
//	for (int i = 1; i <= n; i++){
//		for (int j = 1; j <= n + 1; j++){
//			printf("%.03Lf ", a[i][j]);
//		}
//		cout << endl;
//	}
	//回代 
	x[n] = a[n][n + 1];
	for (int i = n - 1; i >= 1; i--){
		x[i] = a[i][n + 1];
		for (int j = n; j > i; j--){
			x[i] -= a[i][j] * x[j];
			a[i][j] = 0;
		}
	}
	//约化行阶梯矩阵 
//	for (int i = 1; i <= n; i++){
//		for (int j = 1; j <= n + 1; j++){
//			printf("%.03Lf ", a[i][j]);
//		}
//		cout << endl;
//	}
	for (int i = 1; i <= n; i++){
		printf("%.03Lf ", x[i]);
	}
	return 0;
}