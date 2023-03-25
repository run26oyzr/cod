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
    string pi = "314159265358979323846264338327";
    while(T--){
        string s;
        cin >> s;
        int i = 0;
        for (i = 0; i < s.length(); i++){
            if (s[i] != pi[i]) break;
        }
        cout << i << endl;
    }
    return 0;
}