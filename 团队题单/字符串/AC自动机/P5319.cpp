#include <bits/stdc++.h>
#define eps 1e-4
using namespace std;
const int maxn = 1505;
int ch[maxn][10];
char s[maxn];
long double sum[maxn], cnt[maxn];
int fail[maxn];
int tot = 0, rt = 0;
void insert(char s[], long double val){
	int n = strlen(s + 1);
	int p = rt;
	for (int i = 1; i <= n; i++){
		if (!ch[p][s[i] - '0'])
			ch[p][s[i] - '0'] = ++tot;
		p = ch[p][s[i] - '0'];
	}
	cnt[p]++; sum[p] += val;
}
int q[maxn], front = 1, rear = 0;
int vis[maxn];
void getFail(){
    q[0] = 0;
	for (int i = 0; i < 10; i++){
		if (ch[rt][i]){
			fail[ch[rt][i]] = rt;
			q[++rear] = ch[rt][i];
		}
	}
	int p;
	while (front <= rear){
		p = q[front++];
        cnt[p] += cnt[fail[p]];
        sum[p] += sum[fail[p]];
		for (int i = 0; i < 10; i++){
			if (ch[p][i]){
				fail[ch[p][i]] = ch[fail[p]][i];
				q[++rear] = ch[p][i];
			}else{
				ch[p][i] = ch[fail[p]][i];
			}
		}
	}
}
int n, m;
char T[maxn];
long double f[maxn][maxn];
int from[maxn][maxn];
int from_val[maxn][maxn];
bool check(long double mid){
    for (int i = 0; i <= tot; i++)
        sum[i] -= cnt[i] * mid;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= tot; j++)
            f[i][j] = -1e100;
    f[0][0] = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= tot; j++){
            if (f[i][j] <= -1e90) continue;
            if (T[i + 1] == '.'){
                for (int k = 0; k <= 9; k++){
                    int v = ch[j][k];
                    if (f[i][j] + sum[v] > f[i + 1][v]){
                        f[i + 1][v] = f[i][j] + sum[v];
                        from[i + 1][v] = j;
                        from_val[i + 1][v] = k;
                    }
                }
            }else{
                int v = ch[j][T[i + 1] - '0'];
                if (f[i][j] + sum[v] > f[i + 1][v]){
                    f[i + 1][v] = f[i][j] + sum[v];
                    from[i + 1][v] = j; 
                    from_val[i + 1][v] = T[i + 1] - '0';
                }
            }
        }
    }
    for (int i = 0; i <= tot; i++)
        sum[i] += cnt[i] * mid;
    long double res = -1e100;
    for (int i = 0; i <= tot; i++){
        res = max(res, f[n][i]);
    }
    return (res > 0);
}
int a[maxn];
int main(){
	cin >> n >> m;
    cin >> T + 1;
    int x;
	for (int i = 1; i <= m; i++){
		cin >> s + 1 >> x;
		insert(s, log(x));
	}
	getFail();
    long double l = 0, r = 1e4;
    long double ans;
    while (r - l > eps){
        long double mid = (l + r) / 2;
        if (check(mid))
            ans = l, l = mid;
        else
            r = mid;
    }
    check(ans);
    int id;
    for (int i = 0; i <= tot; i++){
        if (f[n][i] > f[n][id])
            id = i;
    }
    for (int i = n; i >= 1; i--){
        a[i] = from_val[i][id];
        id = from[i][id];
    }
    for (int i = 1; i <= n; i++) 
        cout << a[i];
	return 0;
}