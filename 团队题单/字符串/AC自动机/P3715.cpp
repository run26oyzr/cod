#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int maxn = 55, maxlen = 105, maxl = 105;
const int mod = 1e9 + 7;
int ch[maxlen][26];
char s[maxlen];
bool flag[maxlen];
int fail[maxlen];
int tot = 1, rt = 1;
void insert(char s[]){
	int n = strlen(s + 1);
	int p = rt;
	for (int i = 1; i <= n; i++){
		if (!ch[p][s[i] - 'a'])
			ch[p][s[i] - 'a'] = ++tot;
		p = ch[p][s[i] - 'a'];
	}
	flag[p] |= true;
}
queue <int> q;
void getFail(){
    for (int i = 0; i < 26; i++){
		if (ch[rt][i]){
			fail[ch[rt][i]] = rt;
			q.push(ch[rt][i]);
		}else{
			ch[rt][i] = rt;
		}
	}
	int p;
	while (!q.empty()){
		p = q.front(); q.pop();
        flag[p] |= flag[fail[p]];
		for (int i = 0; i < 26; i++){
			if (ch[p][i]){
				fail[ch[p][i]] = ch[fail[p]][i];
				q.push(ch[p][i]);
			}else{
				ch[p][i] = ch[fail[p]][i];
			}
		}
	}
}

int n, m, l;
char S[maxn][maxlen];
int len[maxn];
int f[maxl][maxlen];
int dp(){
    f[0][rt] = 1;
    for (int i = 0; i < l; i++){
        for (int j = rt; j <= tot; j++){
			if (f[i][j] == 0) continue;
            for (int k = 1; k <= n; k++){
				if (i + len[k] > l) continue;
                int p = j;
				bool Flag = false;
				for (int i_ = 1; i_ <= len[k]; i_++){
					p = ch[p][S[k][i_] - 'a'];
                	if (flag[p]){
						Flag = true;
						break;
					}
				}
				if (Flag) continue;
				f[i + len[k]][p] += f[i][j];
				f[i + len[k]][p] %= mod;
            }
        }
    }
    int res = 0;
    for (int i = rt; i <= tot; i++){
        res = (res + f[l][i]) % mod;
    }
    return res;
}
struct Matrix{
    static const int Size = 205;
    int a[Size][Size];
    Matrix(){memset(a, 0, sizeof(a));}
    Matrix operator * (const Matrix &T)const{
        Matrix res;
        for (int i = 1; i <= 2 * tot; i++){
            for (int j = 1; j <= 2 * tot; j++){
                int tmp = 0LL;
                for (int k = 1; k <= 2 * tot; k++){
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
	cin >> n >> m >> l;
	for (int i = 1; i <= n; i++){
		cin >> s + 1;
		len[i] = strlen(s + 1);
		for (int j = 1; j <= len[i]; j++)
			S[i][j] = s[j];
	}
	for (int i = 1; i <= m; i++){
		cin >> s + 1;
		insert(s);
	}
	getFail();
	if (l <= 100)
    	cout << dp();
	else{
		Matrix A, B;
		for (int i = 1; i <= n; i++){
			for (int j = rt; j <= tot; j++){
				int p = j;
				bool Flag = false;
				for (int k = 1; k <= len[i]; k++){
					p = ch[p][S[i][k] - 'a'];
					if (flag[p]){
						Flag = true;
						break;
					}
				}
				if (Flag)
					continue;
				if (len[i] == 1)
					B.a[j][p] += 1;
				else
					B.a[tot + j][p] += 1;
			}
		}
		for (int i = 1; i <= tot; i++)
			B.a[i][tot + i] = 1;
		A.a[1][1] = 1;
		//A为一行矩阵，f[i]行对应的在左边，f[i-1]行对应的在右边
		A = A * qpow(B, l);
		int ans = 0;
		for (int i = rt; i <= tot; i++){
			ans = (ans + A.a[1][i]) % mod;
		}
		cout << ans;
	}
	return 0;
}