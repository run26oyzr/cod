#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2 * 1e7 + 5;
char s[maxn], ss[maxn];
int z[maxn], p[maxn];
int n, m;
signed main(){
    cin >> s + 1 >> ss + 1;
    n = strlen(s + 1), m = strlen(ss + 1);

    int L = 1, R = 0;
    z[1] = m;
    for (int i = 2; i <= m; i++){
        if (i <= R) z[i] = min(z[i - L + 1], R - i + 1);
        while (i + z[i] <= m && ss[i + z[i]] == ss[1 + z[i]]) z[i]++;
        if (i + z[i] - 1 >= R){
            L = i;
            R = i + z[i] - 1;
        }
    }
    int res = 0;
    for (int i = 1; i <= m; i++) res = res ^ (i * (z[i] + 1));
    cout << res << endl;
    
    L = 1, R = 0;
    for (int i = 1; i <= n; i++){
        if (i <= R) p[i] = min(z[i - L + 1], R - i + 1);
        while (i + p[i] <= n && s[i + p[i]] == ss[1 + p[i]]) p[i]++;
        if (i + p[i] - 1 >= R){
            L = i;
            R = i + p[i] - 1;
        }
    }
    res = 0;
    for (int i = 1; i <= n; i++) res = res ^ (i * (p[i] + 1));
    cout << res;
    return 0;
}