#include <bits/stdc++.h>
using namespace std;
#define int long long
template<typename T> inline void read(T &x) {
	x = 0;
	char c = getchar();
	for (;!isdigit(c); c = getchar());
	for (;isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
}
int prim[(int)(1e6 + 5)];
bool isp[(int)(1e7 + 5)];
int cnt = 0;
void init(){
    for (int i = 2; i <= 1e7; i++){
        if (!isp[i]) prim[++cnt] = i;
        for (int j = 1; j <= cnt && prim[j] * i <= 1e7; j++){
            isp[i * prim[j]] = 1;
            if (i % prim[j] == 0) break;
        }
    }
}
int p[5005], k[5005];
int used[(int)(1e7 + 5)];
int used_[5005];
signed main(){
    int T;
    read(T);
    init();
    while(T--){
        int n;
        read(n);
        int x;
        int tot = 0;
        while(n--){
            read(x);
            for (int i = 1; prim[i] * prim[i] <= x && i <= cnt; i++){
                if (x == 1) break;
                if (x % prim[i] == 0){
                    x /= prim[i];
                    if(!used[prim[i]]){
                        p[++tot] = prim[i];
                        used[prim[i]] = tot;
                        used_[tot] = prim[i];
                    }
                    k[used[prim[i]]]++;
                    while (x % prim[i] == 0){
                        x /= prim[i];
                        k[used[prim[i]]]++;
                    }
                }
            }
            if (x != 1){
                if(!used[x]){
                    p[++tot] = x;
                    used[x] = tot;
                    used_[tot] = x;
                }
                k[used[x]]++;
            }
        }
        int ans = 0, cnt_ = 0;
        for (int i = 1; i <= tot; i++){
            // cout << p[i] << ' ' << k[i] << endl;
            ans += k[i] / 2;
            k[i] = k[i] - k[i] / 2 * 2;
            if (k[i] == 1) cnt_++;
        }
        ans += cnt_ / 3;
        cout << ans << endl;
        for (int i = 1; i <= tot; i++){
            int tmp = used_[i];
            k[i] = 0;
            used[tmp] = 0;
            p[i] = 0;
        }
    }
    return 0;
}