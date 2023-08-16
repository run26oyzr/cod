#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 65;
const int mod = 45989;
int n, m;
struct Matrix{
    static const int Size = 125;
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
    for (int i = 1; i <= 2 * m; i++)
        res.a[i][i] = 1;
    while(b){
        if (b & 1) res = res * A;
        A = A * A;
        b >>= 1;
    }
    return res;
}
int end_[maxn << 1], start_[maxn << 1];
signed main(){
	int a, b, t;
    cin >> n >> m >> t >> a >> b;
    Matrix A;
    int u, v;
    for (int i = 1; i <= m; i++){
    	cin >> u >> v;
    	start_[i] = u, end_[i] = v;
	}
	for (int i = 1; i <= m; i++){
		start_[i + m] = end_[i], end_[i + m] = start_[i];
//		cout << start_[i + m] << ' ' << end_[i + m] << endl;
	}
	for (int i = 1; i <= 2 * m; i++){
		for (int j = 1; j <= 2 * m; j++){
			if (i != j && abs(i - j) != m)
				A.a[j][i] = (end_[i] == start_[j]); 
		}
	}
//    for (int i = 1; i <= 2 * m; i++){
//    	for(int j = 1; j <= 2 * m; j++){
//    		cout << A.a[i][j] << ' ';
//		}
//		cout << endl;
//	}
//	cout << endl;
    Matrix ans = qpow(A, t - 1);
//    for (int i = 1; i <= 2 * m; i++){
//    	for(int j = 1; j <= 2 * m; j++){
//    		cout << ans.a[i][j] << ' ';
//		}
//		cout << endl;
//	}
//	cout << endl;
    Matrix B;
    for (int i = 1; i <= 2 * m; i++){
    	if (start_[i] == a) B.a[i][1] = 1;
	}
	ans = ans * B;
//    for (int i = 1; i <= 2 * m; i++){
//    	for(int j = 1; j <= 2 * m; j++){
//    		cout << ans.a[i][j] << ' ';
//		}
//		cout << endl;
//	}
	int res = 0;
	for (int i = 1; i <= 2 * m; i++){
		if (end_[i] == b) res += ans.a[i][1];
	}
    cout << res % mod;
    return 0;
}