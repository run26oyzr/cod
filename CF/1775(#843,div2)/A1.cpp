#include <bits/stdc++.h>
using namespace std;
#define int long long
template<typename T> inline void read(T &x) {
	x = 0;
	char c = getchar();
	for (;!isdigit(c); c = getchar());
	for (;isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
}
string ask(string s, int l, int r){
    string res;
    for (int i = l; i <= r; i++) res += s[i];
    return res;
}
void solve(){
        string s;
        cin >> s;
        int len = s.length();
        for(int i = 0; i < len - 2; i++){
            for(int j = i + 1; j < len - 1; j++){
                string a = ask(s, 0, i);
                string b = ask(s, i + 1, j);
                string c = ask(s, j + 1, len - 1);
                if ((a >= b && c >= b) || (a <= b && c <= b)){
                    cout << a << ' ' << b << ' ' << c << endl;
                    return;
                }
            }
        }
        cout << ":(" << endl;
        return;
}
signed main(){
    int T;
    read(T);
    while(T--){
        solve();
    }
    return 0;
}