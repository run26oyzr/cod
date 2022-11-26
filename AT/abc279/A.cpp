#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    int len = s.length();
    int ans = 0;
    for (int i = 0; i < len; i++){
        if (s[i] == 'v') ans += 1;
        if (s[i] == 'w') ans += 2;
    }
    cout << ans;
    // system("pause");
    return 0;
}