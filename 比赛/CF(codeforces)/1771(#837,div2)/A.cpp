#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    int T; cin >> T;
    while(T--){
        int n; cin >> n;
        int x;
        int maxnum = -1, minnum = 1e5 + 5, maxcnt, mincnt;
        for (int i = 1; i <= n; i++){
            cin >> x;
            if (x > maxnum){
                maxcnt = 0;
                maxnum = x;
            }
            if (x < minnum){
                mincnt = 0;
                minnum = x;
            }
            if (x == maxnum) maxcnt++;
            if (x == minnum) mincnt++;
        } 
        if (maxnum == minnum) cout << n * (n - 1) << endl;
        else cout << maxcnt * mincnt * 2 << endl;
    }
    return 0;
}