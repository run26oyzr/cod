#include <bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
    char c=getchar();int x=0,f=1;
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar()) x=x*10+c-48;
    return x*f;
}
long long n;
int m;
int len;
int what(int x, int y){
    long long n2 = n;
    n2 /= (int)(pow(10, (len - y)));
    return n2 % (int)(pow(10, (y - x + 1)));
}
long long f[25][25];
signed main(){
    // freopen("split.in", "r", stdin);
    // freopen("split.out", "w", stdout);
    int T = read();
    while(T--){
        cin >> n >> m;
        len = floor(log10(n)) + 1;
        if (m >= len) cout << 0 << endl;
        else{
            memset(f, -0x3f, sizeof(f));
            for (int i = 1; i <= len; i++){
                f[i][0] = what(1, i);
            }
            for (int i = 1; i <= len; i++){
                for (int j = 1; j <= min(m, i - 1); j++){
                    for (int k = j; k < i; k++){
                        f[i][j] = max(f[i][j], f[k][j - 1] * what(k + 1, i));
                    }
                }
            }
            int ans = 0;
            for (int i = 1; i <= len; i++){
                ans = max(ans, f[i][m]);
            }
            cout << ans << endl;
        }
    }
    return 0;
}