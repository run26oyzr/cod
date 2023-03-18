#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2 * 1e5 + 5;
template<typename T> inline void read(T &x) {
	x = 0;
	char c = getchar();
	for (;!isdigit(c); c = getchar());
	for (;isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
}
int dp[maxn];
int a[maxn];
int n, s;
int ylast;
int cal(int x, int y, int val){
    // int A = val / (x + y) * y;
    // int B = val - A;
    // if (A < s){
    //     A = s;
    //     B = val - A;
    // }
    // if (B < s){
    //     B = s;
    //     A = val - B;
    // }
    // ylast = B;
    // cout << A << ' ' << B << endl;
    // return B * (y - x);
    if (y > x) ylast = s;
    else ylast = val - s;
    return ylast * (y - x);
}
signed main(){
    int T;
    read(T);
    while(T--){
        read(n); read(s);
        for (int i = 1; i <= n; i++) read(a[i]);
        int x = a[1], y = a[3], val = a[2];
        int A = val / (x + y) * y;
        int B = val - A;
        if (A < s){
            A = s;
            B = val - A;
        }
        if (B < s){
            B = s;
            A = val - B;
        }
        ylast = B;
        cout << A << ' ' << B << endl;
        dp[3] = x * A + y * B;
        for (int i = 4; i <= n; i++){
            cout << a[i - 1] << ' ' << ylast << ' ' << a[i] << ' ' << cal(ylast, a[i], a[i - 1]) << endl;
            dp[i] = dp[i - 1] + cal(ylast, a[i], a[i - 1]);
        }
        cout << dp[n] << endl;
    }
    return 0;
}