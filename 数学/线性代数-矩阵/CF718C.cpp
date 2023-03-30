#include <bits/stdc++.h>
#define ls (id << 1)
#define rs (id << 1 | 1)
#define int long long
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
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
    Matrix operator + (const Matrix &T)const{
        Matrix res;
        for (int i = 1; i < Size; i++){
            for (int j = 1; j < Size; j++){
                res.a[i][j] = (a[i][j] + T.a[i][j]) % mod;
            }
        }
        return res;
    }
};
Matrix A;
Matrix qpow(Matrix A, int b){
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
int a[maxn];
struct Node{
    int left, right;
    Matrix sum;
    Matrix lazy;
}t[maxn << 2];
void setLazy(int id, int val){
    t[id].lazy.a[1][1] = t[id].lazy.a[2][2] = val;
    //lazy 56行部分忘清空，导致WA
    t[id].lazy.a[1][2] = t[id].lazy.a[2][1] = 0;
}
void changeNode(int id, Matrix lazy){
    t[id].lazy = t[id].lazy * lazy;
    t[id].sum = t[id].sum * lazy;
}
void update(int id){
    t[id].sum = t[ls].sum + t[rs].sum;
}
void pushdown(int id){
    changeNode(ls, t[id].lazy);
    changeNode(rs, t[id].lazy);
    setLazy(id, 1);
}
void buildtree(int id, int L, int R){
    t[id].left = L, t[id].right = R;
    setLazy(id, 1);
    if (L == R){
        t[id].sum = qpow(A, a[L] - 1);
        return;
    }
    int mid = (L + R) / 2;
    buildtree(ls, L, mid);
    buildtree(rs, mid + 1, R);
    update(id);
}
void change(int id, int L, int R, Matrix val){
    // cout << L << ' ' << R << ' ' << t[id].left << ' ' << t[id].right << endl;
    if (t[id].left == L && t[id].right == R){
        changeNode(id, val);
        return;
    }
    pushdown(id);
    if (L > t[ls].right) change(rs, L, R, val);
    else if (R < t[rs].left) change(ls, L, R, val);
    else{
        change(ls, L, t[ls].right, val);
        change(rs, t[rs].left, R, val);
    }
    update(id);
} 
Matrix query(int id, int L, int R){
    if (t[id].left == L && t[id].right == R){
        return t[id].sum;
    }
    pushdown(id);
    if (L > t[ls].right) return query(rs, L, R);
    else if (R < t[rs].left) return query(ls, L, R);
    else return query(ls, L, t[ls].right) + query(rs, t[rs].left, R);
}
signed main(){
    A.a[1][1] = 1, A.a[1][2] = 1;
    A.a[2][1] = 1, A.a[2][2] = 0;
    int n, m;
    scanf("%lld %lld", &n, &m);
    for (int i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
    }
    buildtree(1, 1, n);
    int opt, l, r, c;
    while(m--){
        scanf("%lld %lld %lld", &opt, &l, &r);
        if (opt == 1){
            scanf("%lld", &c);
            Matrix tmp = qpow(A, c);
            change(1, l, r, tmp);
        }else if (opt == 2){
            Matrix tmp = query(1, l, r);
            printf("%lld\n", tmp.a[1][1]);
        }
    }
    return 0;
}