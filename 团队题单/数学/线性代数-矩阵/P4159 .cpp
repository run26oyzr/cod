#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 2009;
int n;
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
	int t;
    cin >> n >> t;
    Matrix A;
    for(int i = 1; i <= n; i++){
    	string s;
    	cin >> s;
    	for(int j = 1; j <= n; j++){
    		char c = s[j - 1];
    		int tmp = c - '0';
    		if (tmp != 0) A.a[j][(tmp - 1) * 10 + i] = 1;
		}
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= 9; j++)
			A.a[j * 10 + i][(j - 1) * 10 + i] = 1;
	}
//    for (int i = 1; i <= 100; i++){
//    	for(int j = 1; j <= 100; j++){
//    		cout << A.a[i][j] << ' ';
//		}
//		cout << endl;
//	}
//	cout << endl;
    Matrix ans = qpow(A, t);
//    for (int i = 1; i <= 100; i++){
//    	for(int j = 1; j <= 100; j++){
//    		cout << ans.a[i][j] << ' ';
//		}
//		cout << endl;
//	}
    cout << ans.a[n][1];
    return 0;
}