#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 105, maxlen = 6005;
const int mod = 1e4 + 7;
int ch[maxlen][26];
char s[maxn];
bool flag[maxlen];
int fail[maxlen];
int tot = 0, rt = 0;
void insert(char s[]){
	int n = strlen(s + 1);
	int p = rt;
	for (int i = 1; i <= n; i++){
		if (!ch[p][s[i] - 'A'])
			ch[p][s[i] - 'A'] = ++tot;
		p = ch[p][s[i] - 'A'];
	}
	flag[p] |= true;
}
queue <int> q;
void getFail(){
    for (int i = 0; i < 26; i++){
		if (ch[rt][i]){
			fail[ch[rt][i]] = rt;
			q.push(ch[rt][i]);
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
int n, m;
int f[maxn][maxlen];
int dp(){
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= tot; j++)
            f[i][j] = 0;
    f[0][0] = 1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= tot; j++){
            for (int k = 0; k < 26; k++){
                int v = ch[j][k];
                if (flag[v]) continue;
                f[i + 1][v] += f[i][j];
                f[i + 1][v] %= mod;
            }
        }
    }
    int res = 0;
    for (int i = 0; i <= tot; i++){
        res = (res + f[n][i]) % mod;
    }
    return res;
}
int qpow(int x, int y){
    int res = 1;
    while(y){
        if (y & 1)
            res = res * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return res;
}
signed main(){
	cin >> m >> n;
	for (int i = 1; i <= m; i++){
		cin >> s + 1;
		insert(s);
	}
	getFail();
    int ans = qpow(26, n) - dp();
    ans = (ans + mod) % mod;
    cout << ans;
	return 0;
}