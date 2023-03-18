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
        int n;
        read(n);
        if (n % 2 == 1) cout << -1 << endl;
        else cout << 1 << ' ' << n / 2 << endl;
    }
    return 0;
}