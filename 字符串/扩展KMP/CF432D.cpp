#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
char s[maxn];
int z[maxn];
int sum[maxn];
int n;
void getZ(char* s){
    int L = 1, R = 0;
    z[1] = n;
    for (int i = 2; i <= n; i++){
        if (i <= R) z[i] = min(z[i - L + 1], R - i + 1);
        while (i + z[i] <= n && s[i + z[i]] == s[1 + z[i]]) z[i]++;
        if (i + z[i] - 1 >= R){
            L = i;
            R = i + z[i] - 1;
        }
    }
    for (int i = 1; i <= n; i++) cout << z[i] << ' ';
    cout << endl;
}
signed main(){
    cin >> s + 1;
    n = strlen(s + 1);
    getZ(s);
    int cnt = 0;
    for (int i = 1; i <= n; i++){
        sum[i] += sum[i - 1];
        if (z[i] >= n - i + 1){
            sum[i] += 1;
            cnt++;
        }
    }
    cout << cnt << endl;
    for (int i = n; i >= 1; i--){
        if (z[i] >= n - i + 1){
            cout << n - i + 1 << ' ' << sum[i] << endl;
        }
    }
    return 0;
}