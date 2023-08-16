#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1205, maxlen = 1505;
const int mod = 1e9 + 7;
int ch[maxlen][26];
char s[maxn];
bool flag[maxlen];
int fail[maxlen];
int tot = 0, rt = 0;
void insert(char s[]){
	int n = strlen(s + 1);
	int p = rt;
	for (int i = 1; i <= n; i++){
		if (!ch[p][s[i] - '0'])
			ch[p][s[i] - '0'] = ++tot;
		p = ch[p][s[i] - '0'];
	}
	flag[p] |= true;
}
queue <int> q;
void getFail(){
    for (int i = 0; i < 10; i++){
		if (ch[rt][i]){
			fail[ch[rt][i]] = rt;
			q.push(ch[rt][i]);
		}
	}
	int p;
	while (!q.empty()){
		p = q.front(); q.pop();
        flag[p] |= flag[fail[p]];
		for (int i = 0; i < 10; i++){
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
int f[maxn][maxlen][2];
char T[maxlen];
int dp(){
    for (int k = 1; k < T[1] - '0'; k++){
        int v = ch[rt][k];
        if (flag[v]) continue;
        f[1][v][0] += 1;
    }
    if (!flag[ch[rt][T[1] - '0']])
        f[1][ch[rt][T[1] - '0']][1] = 1;
    for (int i = 1; i < n; i++){
        for (int k = 1; k < 10; k++){
            int v = ch[rt][k];
            if (flag[v]) continue;
            f[i + 1][v][0] += 1;
        }
        for (int j = 0; j <= tot; j++){
            if (flag[j]) continue;
            for (int k = 0; k < 10; k++){
                int v = ch[j][k];
                if (flag[v]) continue;
                if (k < T[i + 1] - '0'){
                    f[i + 1][v][0] += f[i][j][1];
                    f[i + 1][v][0] %= mod;
                }
                f[i + 1][v][0] += f[i][j][0];
                f[i + 1][v][0] %= mod;
            }
            int v = ch[j][T[i + 1] - '0'];
            if (flag[v]) continue;
            f[i + 1][v][1] += f[i][j][1];
            f[i + 1][v][1] %= mod;
        }
    }
    int res = 0;
    for (int i = 0; i <= tot; i++){
        res = (res + f[n][i][0]) % mod;
        res = (res + f[n][i][1]) % mod;
    }
    return res;
}
signed main(){
	cin >> T + 1;
    cin >> m;
    n = strlen(T + 1);
	for (int i = 1; i <= m; i++){
		cin >> s + 1;
		insert(s);
	}
	getFail();
    cout << dp();
	return 0;
}