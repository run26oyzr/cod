#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 20005, maxlen = 15;;
const int mod = 212370440130137957, base = 26;
int h[15];
int Hash(char s[]){
    int n = strlen(s + 1);
    int res = 0;
    for (int i = 1; i <= n; i++){
        h[i] = (h[i - 1] * base + s[i]) % mod;
    }
    return h[n];
}
int getString(int L, int R){
    return ((h[R] - (int)(h[L - 1] * pow(base, R - L + 1))) % mod + mod) % mod;
}
char s[maxlen];
char all[maxn][maxlen];
int a[maxn];
    int n;
int find(int x){
    int l = 1, r = n;
    while (l < r){
        int mid = (l + r) / 2;
        if (a[mid] < x) l = mid + 1;
        else r = mid;
    }
    return l;
}
unordered_map <int, int> vis;
signed main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> s + 1;
        a[i] = Hash(s);
        for (int j = 1; j <= 10; j++) all[i][j] = s[j];
    }
    sort(a + 1, a + n + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++){
        vis.clear();
        for (int j = 1; j <= 10; j++) s[j] = all[i][j];
        Hash(s);
        int m = strlen(s + 1);
        for (int L = 1; L <= m; L++){
            for (int R = 1; R <= m; R++){
                int tmp = getString(L, R);
                if (vis[tmp]) continue;
                vis[tmp] = 1;
                int pos = find(tmp);
                while (a[pos] == tmp){
                    // cout << i << ' ' << L << ' ' << R << endl;
                    ans++, pos++;
                }
            }
        }
    }
    ans -= n;
    cout << ans;
    return 0;
}