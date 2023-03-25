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
    while(T--){
        int x;
        read(x);
        int a = x | (x >> 1);
        int b = x ^ a;
        if (a + b != 2 * x) cout << -1 << endl;
        else cout << a << ' ' << b << endl;
    }
    return 0;
}