#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int vis[maxn];
int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        int x;
        int gcd_ = 0;
        int maxnum = 0;
        for (int i = 1; i <= n; i++){
            cin >> x;
            if (!gcd_) gcd_ = x;
            gcd_ = __gcd(gcd_, x);
            maxnum = max(maxnum, x);
        }
        cout << maxnum / gcd_ << endl;
    }
    system("pause");
    return 0;
}