#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2 * 1e5 + 5;
template<typename T> inline void read(T &x) {
	x = 0;
	char c = getchar();
	for (;!isdigit(c); c = getchar());
	for (;isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
}
int a[maxn];
signed main(){
    int T;
    read(T);
    while(T--){
        int n;
        read(n);
        for (int i = 1; i <= n; i++){
            read(a[i]);
        }
        int ans = 0;
        sort(a + 1, a + n + 1);
        a[0] = -1;
        a[n + 1] = n + 1;
        for (int i = 0; i <= n; i++){
            if (a[i] != a[i + 1] && a[i] < i && a[i + 1] > i) ans++;
        }
        cout << ans << endl;
    }
    return 0;
}