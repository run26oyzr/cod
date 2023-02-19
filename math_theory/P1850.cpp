#include <bits/stdc++.h>
using namespace std;
const int maxn = 2005, maxm = 2005, maxv = 305;
template<typename T> inline void read(T &x) {
	x = 0;
	char c = getchar();
	for (;!isdigit(c); c = getchar());
	for (;isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
}
int dis[maxv][maxv];
int c[maxn], d[maxn];
long double p[maxn];
long double f[maxn][maxm][2];
int main(){
	int n, m, v, e;
	cin >> n >> m >> v >> e;
    for (int i = 1; i <= n; i++) read(c[i]);
    for (int i = 1; i <= n; i++) read(d[i]);
    for (int i = 1; i <= n; i++) cin >> p[i];
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 1; i <= v; i++) dis[i][i]= dis[0][i] = dis[i][0] = 0;
    int start, end, val;
    for (int i = 1; i <= e; i++){
        read(start); read(end); read(val);
        dis[start][end] = min(val, dis[start][end]);
        dis[end][start] = min(val, dis[end][start]);
    }
    for (int k = 1; k <= v; k++){
        for (int i = 1; i <= v; i++){
            for (int j = 1; j <= v; j++){
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
	//f[i][j][k]:选择到了第i节课，共申请j次，k=0：第i节课不申请；k=1：第i节课申请的期望最小距离
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            for (int k = 0; k <= 1; k++)
                f[i][j][k] = 1e9;
    f[0][0][0] = 0;
    for (int i = 1; i <= n; i++){
        f[i][0][0] = f[i - 1][0][0] + dis[c[i - 1]][c[i]];
        // f[i][1][1] = f[i][0][0];
        // cout << c[i - 1] << ' ' << c[i] << ' ' << dis[c[i - 1]][c[i]] << endl;
        // cout << f[i][0][0] << endl;
    }
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			f[i][j][0] = min(f[i][j][0], f[i - 1][j][0] + dis[c[i - 1]][c[i]]);
			f[i][j][0] = min(f[i][j][0], f[i - 1][j][1] + (1 - p[i - 1]) * dis[c[i - 1]][c[i]] + p[i - 1] * dis[d[i - 1]][c[i]]);
			f[i][j][1] = min(f[i][j][1], f[i - 1][j - 1][0] + (1 - p[i]) * dis[c[i - 1]][c[i]] + p[i] * dis[c[i - 1]][d[i]]);
			f[i][j][1] = min(f[i][j][1], f[i - 1][j - 1][1] + (1 - p[i - 1]) * (1 - p[i]) * dis[c[i - 1]][c[i]] + (1 - p[i - 1]) * p[i] * dis[c[i - 1]][d[i]] + p[i - 1] * (1 - p[i]) * dis[d[i - 1]][c[i]] + p[i - 1] * p[i] * dis[d[i - 1]][d[i]]);
            // cout << f[i][j][0] << ' ' << f[i][j][1] << endl;
		}
	}
    // printf("%.02Lf", min(f[n][m][0], f[n][m][1]));
    long double ans = 1e9;
    for (int i = 0; i <= m; i++){
        ans = min(ans, f[n][i][0]);
        ans = min(ans, f[n][i][1]);
    }
    printf("%.02Lf", ans);
	return 0;
}