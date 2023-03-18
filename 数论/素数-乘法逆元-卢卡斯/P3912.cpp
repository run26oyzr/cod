#include <bits/stdc++.h>
using namespace std;
int prim[(int)(1e8 + 5)];
bool isp[(int)(1e8 + 5)];
int main(){
    int cnt = 0;
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++){
        if (!isp[i]) prim[++cnt] = i;
        for (int j = 1; j <= cnt && prim[j] * i <= 1e8; j++){
            isp[i * prim[j]] = 1;
            if (i % prim[j] == 0) break;
        }
    }
    cout << cnt;
    return 0;
}