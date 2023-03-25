#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5 * 1e5 + 5;
int a[maxn];
int score[maxn];
int f[maxn];
signed main(){
    int T;
    cin >> T;
    while(T--){
        int n, m;
        cin >> n >> m;
        int tot = 0;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            tot += a[i];
        }
        if (tot == m) cout << 1 << endl;
        else{
            
        }
    }
    return 0;
}