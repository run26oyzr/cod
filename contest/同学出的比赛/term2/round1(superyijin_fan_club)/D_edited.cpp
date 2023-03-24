#include <bits/stdc++.h>
#define int long long  
#define ls (id << 1)
#define rs (id << 1 | 1)
using namespace std;
const int maxn = 2 * 1e5 + 5;
const int mod = 998244353;
int n, k;
struct Matrix{
    static const int Size = 3;
    int a[Size][Size];
    Matrix(){
        for(int i = 1; i <= 2; i++){
            for(int j = 1; j <= 2; j++){
                a[i][j] = 0;
            }
        }
    }
    Matrix operator * (const Matrix &T)const{
        Matrix res;
        for (int i = 1; i < Size; i++){
            for (int j = 1; j < Size; j++){
                for (int k = 1; k < Size; k++){
                    res.a[i][j] = (res.a[i][j] + a[i][k] * T.a[k][j]) % mod;
                }
            }
        }
        return res;
    } 
};
Matrix qpow(Matrix A, int b){
    Matrix res; //res*=a;
    for (int i = 1; i <= 2; i++)
        res.a[i][i] = 1;
    while(b){
        if (b & 1) res = res * A;
        A = A * A;
        b >>= 1;
    }
    return res;
}
int qpow(int A, int b){
    int res = 1;
    while(b){
        if (b & 1) res = res * A;
        A = A * A;
        b >>= 1;
    }
    return res;
}
int a[maxn], b[maxn];
struct Node{
	int left, right;
	Matrix fen_zi; 
	int fen_mu;
	int lazya, lazyb;
}t[maxn << 2];
void change_Matrix(int id, int a, int b){
	t[id].fen_zi.a[1][1] = a - b;
	t[id].fen_zi.a[1][2] = b;
	t[id].fen_zi.a[2][1] = b;
	t[id].fen_zi.a[2][2] = a - b;
}
void update(int id){
	t[id].fen_zi = t[ls].fen_zi * t[rs].fen_zi;
	t[id].fen_mu = t[ls].fen_mu * t[rs].fen_mu % mod;
}
void pushdown(int id){
    if (t[id].lazya == 0 && t[id].lazyb == 0) return;
	t[ls].lazya = t[id].lazya;
	t[ls].lazyb = t[id].lazyb;
	change_Matrix(ls, t[id].lazya, t[id].lazyb);
    t[ls].fen_zi = qpow(t[ls].fen_zi, t[ls].right - t[ls].left + 1);
	t[ls].fen_mu = qpow(t[id].lazya, t[ls].right - t[ls].left + 1);
	t[rs].lazya = t[id].lazya;
	t[rs].lazyb = t[id].lazyb;
	change_Matrix(rs, t[id].lazya, t[id].lazyb);
    t[rs].fen_zi = qpow(t[rs].fen_zi, t[rs].right - t[rs].left + 1);
	t[rs].fen_mu = qpow(t[id].lazya, t[rs].right - t[rs].left + 1);
	t[id].lazya = 0; t[id].lazyb = 0;
}
void buildtree(int id, int L, int R){
	t[id].left = L, t[id].right = R, t[id].lazya = 0, t[id].lazyb = 0;
	if (L == R){
		change_Matrix(id, a[L], b[L]);
		t[id].fen_mu = a[L];
		return;
	}
	int mid = (L + R) >> 1;
	buildtree(ls, L, mid);
	buildtree(rs, mid + 1, R);
	update(id);
}
void change(int id, int L, int R, int a, int b){
	if (t[id].left == L && t[id].right == R){
		t[id].lazya = a;
		t[id].lazyb = b;
		change_Matrix(id, a, b);
        t[id].fen_zi = qpow(t[id].fen_zi, R - L + 1);
		t[id].fen_mu = qpow(t[id].lazya, R - L + 1);
		return;
	}
	pushdown(id);
	if (R < t[rs].left) change(ls, L, R, a, b);
	else if (L > t[ls].right) change(rs, L, R, a, b);
	else{
		change(ls, L, t[ls].right, a, b);
		change(rs, t[rs].left, R, a, b);
	}
}
Node query(int id, int L, int R){
	if (t[id].left == L && t[id].right == R){
		return t[id];
	}
	pushdown(id);
	if (R < t[rs].left) return query(ls, L, R);
	else if (L > t[ls].right) return query(rs, L, R);
	else{
		Node lson = query(ls, L, t[ls].right);
		Node rson = query(rs, t[rs].left, R);
		Node ans;
		ans.fen_zi = lson.fen_zi * rson.fen_zi;
		ans.fen_mu = lson.fen_mu * rson.fen_mu % mod;
		return ans;
	}
}
int A, B, x, y;
int exgcd(int A, int B, int &x, int &y){
	if (B == 0){x = 1, y = 0; return A;}
	int res = exgcd(B, A % B, x, y);
	int T = x;
	x = y;
	y = T - A / B * y;
    return res;
}
int func(int A, int c){
	B = mod;
	exgcd(A, B, x, y);
    x = (x % mod) * c % mod;
    return (x % mod + mod) % mod;
}
int read(){
    int x = 0;
	char c = getchar();
	for (;!isdigit(c); c = getchar());
	for (;isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
    return x;
}
void print(int n){
    if(n < 0){
        putchar('-');
        n *= -1;
    }
    if(n > 9) print(n / 10);
    putchar(n % 10 + '0');
}
signed main(){
	int n, q;
	n = read(), q = read();
	for (int i = 1; i <= n; i++){
		a[i] = read(), b[i] = read();
	}
	buildtree(1, 1, n);
	int opt, l, r, x, y;
	Matrix tmp;
	tmp.a[1][1] = 1, tmp.a[1][2] = 0;
	while(q--){
		opt = read(), l = read(), r = read();
		if (opt == 1){
			x = read(), y = read();
			change(1, l, r, x, y);
		}
		else{
			Node res = query(1, l, r);
			Matrix tmp2 = tmp * res.fen_zi;
            int z = tmp2.a[1][1];
			// int z = res.fen_zi.a[1][1];
			// cout << z << ' ' << res.fen_mu << endl;
			print(func(res.fen_mu, z));
            putchar('\n');
		}
	}
}