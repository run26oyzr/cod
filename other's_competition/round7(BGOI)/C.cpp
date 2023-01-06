#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
int score[maxn];
int main(){
    // freopen("codeforces.in", "r", stdin);
    // freopen("codeforces.out", "w", stdout);
    int n, m, l;
    int useless;
    cin >> n >> m >> l;
    for (int i = 1; i <= 8; i++){
        cin >> useless >> useless;
    }
    if (n == 0) return 0;
    int x;
    char c;
    for (int i = 1; i <= l; i++){
        cin >> x >> useless >> c >> useless >> useless >> useless >> useless >> useless;
        score[x] -= 50;
        cout << "Unsuccessful" << endl;
    }
    sort(score + 1, score + n + 1);
    for (int i = 1; i <= n; i++) cout << score[i] << ' ';
    return 0;
}