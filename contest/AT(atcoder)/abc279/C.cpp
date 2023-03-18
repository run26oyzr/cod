#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e5 + 5;
string s;
int cnt[maxn];
int main() {
    int h, w;
    cin >> h >> w;
    for (int i = 1; i <= h; i++){
        cin >> s;
        for (int j = 0; j < w; j++){
            if (s[j] == '#') cnt[i]++;
        }
    }
    int tot;
    for (int i = 1; i <= h; i++){
        cin >> s;
        tot = 0;
        for (int j = 0; j < w; j++){
            if (s[j] == '#') tot++;
        }
        if (tot != cnt[i]){
            cout << "No";
            // system("pause");
            return 0;
        }
    }
    cout << "Yes";
    // system("pause");
    return 0;
}