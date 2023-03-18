#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
int n, k;
struct Matrix{
    static const int Size = 101;
    int a[Size][Size];
    Matrix(){memset(a, 0, sizeof(a));}
    Matrix operator * (const Matrix &T)const{
        Matrix res;
        for (int i = 1; i < Size; i++){
            for (int j = 1; j < Size; j++){
                for (int k = 1; k < Size; k++){
                    res.a[i][j] = (res.a[i][j] + a[i][k] * T.a[k][j]) % mod;
                }
                // cout << res.a[i][j] << ' ';
            }
            // cout << endl;
        }
        return res;
    } 
};
Matrix qpow(Matrix A, long long b){
    Matrix res; //res*=a;
    for (int i = 1; i <= n; i++)
        res.a[i][i] = 1;
    while(b){
        if (b & 1) res = res * A;
        A = A * A;
        b >>= 1;
    }
    return res;
}
signed main(){
    cin >> n >> k;
    Matrix A;
    int x;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> x;
            A.a[i][j] = x;
            // cout << i << ' ' << j << ' ' << A.a[i][j] << endl;
        }
    }
    Matrix ans = qpow(A, k);
    // cout << "out";
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            printf("%lld ", ans.a[i][j]);
        }
        cout << endl;
    }
    return 0;
}