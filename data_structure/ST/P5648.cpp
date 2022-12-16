#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 5 * 1e5 + 5;
int d[maxn][25];
int log_[maxn];
int a[maxn], pos[maxn];
int n, m;
int f[maxn][25];
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
stack <int> s;
int maxk;
void init()
{
    cin >> n >> m;
    maxk = log2(n) + 1;
	for (int i = 2; i < maxn; i++) log_[i] = log_[i >> 1] + 1;
	for (int i = 1; i <= n; i++) a[i] = read();
    for (int i = 1; i <= n; i++){
        while(!s.empty() && a[s.top()] < a[i]){
            pos[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    // for (int i = n; i >= 1; i--){
    //     while(!s.empty() && a[s.top()] < a[i]) s.pop();
    //     if (s.empty()) pos[i] = n + 1;
    //     else pos[i] = s.top();
    //     s.push(i);
    // }
    while(!s.empty()){
        pos[s.top()] = n + 1;
        s.pop();
    }
    memset(d, 0x3f, sizeof(d));
    for (int i = 1; i <= n; i++){
        d[i][0] = pos[i];
        f[i][0] = a[i] * (d[i][0] - i);
    }
    d[n + 1][0] = n + 1;
	for (int k = 1; k <= maxk; k++){
		for (int i = 1; i <= n - (1 << k) + 1; i++){
            d[i][k] = d[d[i][k - 1]][k - 1];
		}
	}
    for (int k = 1; k <= maxk; k++){
		for (int i = 1; i <= n - (1 << k) + 1; i++){
            f[i][k] = f[i][k - 1] + f[f[i][k - 1]][k - 1];
		}
	}
}
signed main(){
    init();
    int l, r;
    int ans = 0;
    // for (int i = 1; i <= n; i++){
    //     for (int k = 0; k <= maxk; k++){
    //         cout << d[i][k] << ' ';
    //     }
    //     cout << endl;
    // }
    while(m--){
        l = read(); r = read();
        l = 1 + (l ^ ans) % n;
        r = 1 + (r ^ (ans + 1)) % (n - l + 1);
        // cout << l << ' ' << r << endl;
        r += l - 1;
        ans = 0;
        for (int i = maxk; i >= 0; i--){
            // cout << l << ' ' << i << ' ' << d[l][i] << endl;
            if (d[l][i] <= r){
                ans += f[l][i];
                l = d[l][i];
            }
        }
        ans += a[l] * (r - l + 1);
        printf("%d\n", ans);
    }
}