#include <bits/stdc++.h>
#define ing long long
using namespace std;
const int maxn = 5 * 1e5 + 5;
inline int read()
{
    char c=getchar();int x=0,f=1;
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar()) x=x*10+c-48;
    return x * f;
}
long long h[maxn];
long long tree[maxn];
long long lowbit(long long x){return x & (-x);}
long long n;
void add(long long id, long long val){
    while(id <= n){
        tree[id] += val;
        id += lowbit(id);
    }
}
long long query(long long id){
    long long res = 0;
    while(id > 0){
        res += tree[id];
        id -= lowbit(id);
    }
    return res;
}
long long minus_(long long x, long long y){
    return query(x) - query(y);
}
signed main(){
    // freopen("game.in", "r", stdin);
    // freopen("game.out", "w", stdout);
    n = read();
    long long m = read();
    for (int i = 1; i <= n; i++){
        h[i] = read();
        add(i, h[i] - h[i - 1]);
    }
    long long opt, x, y, z;
    while(m--){
        opt = read();
        if (opt == 1){
            // cin >> x >> y >> z; 快读！！！！！
            x = read(), y = read(), z = read();
            if (x > y) continue;
            add(x, z);
            add(y + 1, -z);
        }
        if (opt == 2){
            // cin >> x >> y; 快读！！！！！
            x = read(), y = read();
            if (y == 0){
                add(x + 1, minus_(x, x - 1));
                add(x, -minus_(x, x - 1));
            }
            if (y == 1){
                add(x, minus_(x + 1, x));
                add(x + 1, -minus_(x + 1, x));
            }
        }
        if (opt == 3){
            // cin >> x; 快读！！！！！
            x = read();
            printf("%lld\n", query(x));
        }
    }
    return 0;
}