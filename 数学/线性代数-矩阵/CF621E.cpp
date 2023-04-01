/**
 * f[i][j]:取了 i 个数,组成的数模 x 余 j 的方案数
 * f[i][j] * cnt[k] => f[i+1][(10*j+k)%x]
 * 构造矩阵
 * 	for i = 0~x-1
 * 		for j = 1~9
 * 			A[(10*i+j)%x][i]+=cnt[j]
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
struct Matrix{
    static const int Size = 105;
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
Matrix qpow(Matrix A, int b){
    Matrix res;
    for (int i = 1; i <= 101; i++)
        res.a[i][i] = 1;
    while(b){
        if (b & 1) res = res * A;
        A = A * A;
        b >>= 1;
    }
    return res;
}
int cnt[15];
signed main(){
	int n, b, k, x;
	cin >> n >> b >> k >> x;
	int tmp;
	for (int i = 1; i <= n; i++){
		cin >> tmp;
		cnt[tmp]++;
	}
    Matrix A;
    for (int i = 0; i <= x - 1; i++){
    	for (int j = 1; j <= 9; j++){
    		A.a[(10 * i + j) % x + 1][i + 1] += cnt[j];
    	}
    }
    Matrix ans = qpow(A, b);
    cout << ans.a[k + 1][1];
    return 0;
}