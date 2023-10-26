#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 5;
int g[maxn][27];
int f[maxn];
char s[maxn]; int a[maxn];
int main(){
	int n;
	cin >> n;
	cin >> s + 1;
	for (int i = 1; i <= n; i++)
		a[i] = s[i] - 'a';
    memset(g, 0x3f, sizeof(g));
	for (int i = 1; i <= n; i++){
        if (i > 1 && a[i] == a[i - 1])
            g[i][26] = 2;
		else
            g[i][26] = g[i - 1][a[i]] + 2;
        if (g[i][26] > i)
            continue;
		for (int j = 0; j <= 25; j++)
			g[i][j] = g[i - g[i][26]][j] + g[i][26];
		g[i][a[i - g[i][26]]] = g[i][26];
	} 
	for (int i = 1; i <= n; i++)
		if (g[i][26] <= i)
			f[i] = f[i - g[i][26]] + 1;
	long long ans = 0;
	for (int i = 1; i <= n; i++)
		ans += f[i];
	cout << ans;
	return 0;
} 