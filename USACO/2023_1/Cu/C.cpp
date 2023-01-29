#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {
	x = 0;
	char c = getchar();
	for (;!isdigit(c); c = getchar());
	for (;isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
}
string s;
int main(){
    int n;
    read(n);
    while(n--){
        cin >> s;
        int len = s.length();
        int ans = len - 3;
        if (s.find("MOO") <= 100) cout << ans << endl;
        else if (s.find("MOM") <= 100 || s.find("OOO") <= 100) cout << ans + 1 << endl;
        else if (s.find("OOM") <= 100) cout << ans + 2 << endl;
        else cout << -1 << endl;
    }
    return 0;
}