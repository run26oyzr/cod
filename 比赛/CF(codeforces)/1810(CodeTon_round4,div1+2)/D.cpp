#include <bits/stdc++.h>
using namespace std;
#define int __int128
template<typename T> inline void read(T &x) {
	x = 0;
	char c = getchar();
	for (;!isdigit(c); c = getchar());
	for (;isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
}
inline void print(int n){
    if(n<0){
        putchar('-');
        n*=-1;
    }
    if(n>9) print(n/10);
    putchar(n % 10 + '0');
}
int Ceil(int a, int b){
    int res = ceil(a * 1.0 / b);
    for (int i = max((int)0, res - 50); i <= res + 50; i++){
        if (b * i >= a) return i;
    }
    return res;
}
signed main(){
    int T;
    read(T);
    while(T--){
        int q;
        read(q);
        int opt, a, b, val;
        int minh = 0, maxh = 2 * 1e18;
        while(q--){
            read(opt); read(a); read(b);
            if (opt == 1){
                read(val);
                int mintmp = (val - 2) * (a - b) + a + 1;
                int maxtmp = (val - 1) * (a - b) + a;
                if (val == 1){
                    mintmp = 0;
                    maxtmp = a;
                }
                if (maxtmp < minh || mintmp > maxh){
                    printf("0 ");
                    continue;
                }
                printf("1 ");
                minh = max(mintmp, minh);
                maxh = min(maxtmp, maxh);
            }
            if (opt == 2){
                // cout << minh << ' ' << maxh << endl;
                if (Ceil(max(maxh - a, (int)0), a - b) != Ceil(max(minh - a, (int)0), a - b)){
                    printf("-1 ");
                    continue;
                }
                print(Ceil(max(minh - a, (int)0), a - b) + 1);
                printf(" ");
           }
        }
        printf("\n");
    }
    return 0;
}