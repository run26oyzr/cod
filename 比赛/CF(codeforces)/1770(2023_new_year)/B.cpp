#include <bits/stdc++.h>
using namespace std;
const int maxn = 205;
int a[maxn];
int main(){
    int T;
    cin >> T;
    while(T--){
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n / 2; i++){
            cout << n - i + 1 << ' ' << i << ' ';
        }
        if (n % 2 == 1) cout << (n + 1) / 2 << ' ';
        cout << endl;
    }
    return 0;
}