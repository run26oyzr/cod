#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int maxn = 1e4 + 5;
const int mod = 212370440130137957, base = 62;
int Hash(char s[]){
    int n = strlen(s);
    int res = 0;
    for (int i = 0; i < n; i++){
        res = (res * base + s[i]) % mod;
    }
    return res;
}
char s[maxn];
int a[maxn];
signed main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> s;
        a[i] = Hash(s);
    }
    sort(a + 1, a + n + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++){
        if (a[i] != a[i - 1])
            ans++;
    }
    cout << ans;
    return 0;
}