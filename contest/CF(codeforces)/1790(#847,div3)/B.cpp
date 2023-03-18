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
        int n, s, r;
        read(n); read(s); read(r);
        int val = ceil(r / (n- 1));
        int tot = r - val * (n - 1);
        for (int i = 1; i <= n - tot - 1; i++) cout << val << " ";
        for (int i = n - tot; i <= n - 1; i++) cout << val + 1 << " ";
        cout << s - r << endl;
    }
    return 0;
}