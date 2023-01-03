#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 105;
inline int read()
{
    register int x = 0,f = 1;
    char c = getchar();
    while(c < '0' || c > '9')
    {
        if(c == '-') f = -1;
        c = getchar();
    }
    while(c >= '0' && c <= '9') 
    {
        x = (x << 3) + (x << 1) + (c ^ 48);
        c = getchar();
    }
    return x * f;
}
signed main(){
    int T = read();
    int L = read(), R = read();
    char c;
    int x;
    while(T--){
        c = getchar(); x = read();
        if (c == 'L'){
            int res = -1 * ((x + 1) / 2 * 2 * L + x / 2 * 2 * R);
            printf("%lld\n", res);
        }
        if (c == 'R'){
            int res = (x + 1) / 2 * 2 * R + x / 2 * 2 * L;
            printf("%lld\n", res);
        }
    }
    return 0;
}