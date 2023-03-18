#include <bits/stdc++.h>
using namespace std;
#define int long long
template<typename T> inline void read(T &x) {
	x = 0;
	char c = getchar();
	for (;!isdigit(c); c = getchar());
	for (;isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
}
signed main(){
    int T;
    read(T);
    int w, d, h;
    int a, b, f, g;
    while(T--){
        read(w); read(d); read(h);
        read(a); read(b); read(f); read(g);
        int ans = 1e9;
        ans = min(ans, a + f + abs(g - b));
        ans = min(ans, b + g + abs(f - a));
        ans = min(ans, (w - a) + (w - f) + abs(g - b));
        ans = min(ans, (d - b) + (d - g) + abs(f - a));
        cout << ans + h << endl;
    }
    return 0;
}