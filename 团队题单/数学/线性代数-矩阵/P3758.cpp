/**
 * f[i][j]: 第 i 秒到编号为 j 的城市的总共方案数
 * 	for u,v
 * 		f[i-1][u] -> f[i][v]
 * 		f[i-1][v] -> f[i][v]
 * 		f[i-1][v] -> ans
*/ 
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 2017;
int n;
struct Matrix{
    static const int Size = 35;
    int a[Size][Size];
    Matrix(){memset(a, 0, sizeof(a));}
    Matrix operator * (const Matrix &T)const{
        Matrix res;
        for (int i = 1; i < Size; i++){
            for (int j = 1; j < Size; j++){
                int tmp = 0LL;
                for (int k = 1; k < Size; k++){
                    tmp = (tmp + a[i][k] * T.a[k][j]) % mod;
                }
                res.a[i][j] = tmp;
            }
        }
        return res;
    } 
};
Matrix qpow(Matrix A, long long b){
    Matrix res; //res*=a;
    for (int i = 1; i <= n + 1; i++)
        res.a[i][i] = 1;
    while(b){
        if (b & 1) res = res * A;
        A = A * A;
        b >>= 1;
    }
    return res;
}
signed main(){
	int m;
    cin >> n >> m;
    Matrix A;
    int u, v; 
    while(m--){
    	cin >> u >> v;
		A.a[v][u] = 1; 
		A.a[u][v] = 1;
	}
	for (int i = 1; i <= n; i++){
		A.a[i][i] = 1;
	}
	for (int i = 1; i <= n + 1; i++){
		A.a[n + 1][i] = 1;
	}
	int t;
	cin >> t;
    Matrix ans = qpow(A, t + 1);
//    for (int i = 1; i <= n + 1; i++){
//    	for(int j = 1; j <= n + 1; j++){
//    		cout << ans.a[i][j] << ' ';
//		}
//		cout << endl;
//	}
    cout << ans.a[n + 1][1];
    return 0;
}