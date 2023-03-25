#include <bits/stdc++.h>
#define int long long
using namespace std;
int mod;
int n;
struct Matrix{
    static const int Size = 3;
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
    Matrix res;
    for (int i = 1; i <= 2; i++)
        res.a[i][i] = 1;
    while(b){
        if (b & 1) res = res * A;
        A = A * A;
        b >>= 1;
    }
    return res;
}
signed main(){
	int p, q, a1, a2;
	cin >> p >> q >> a1 >> a2;
    cin >> n >> mod;
    Matrix A;
    A.a[1][1] = a2;
    A.a[2][1] = a1;
    Matrix B;
    B.a[1][1] = p;
    B.a[1][2] = q;
    B.a[2][1] = 1;
    Matrix ans = qpow(B, n - 2) * A;
    cout << ans.a[1][1];
    return 0;
}