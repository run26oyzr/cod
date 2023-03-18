#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;
int q[(int)(2.5 * 1e4)][maxn];
int cnt[maxn];
int k[maxn];
void jiao_huan(int x, int y, int r){
    int l = 1;
    for (int i = k[y] + r; i > r; i--){
        q[y][i] = q[y][i - r];
    }
    for (int i = 1; i <= r; i++){
        q[y][i] = q[x][i];
    }
    for (int i = 1; i <= k[x] - (r - l + 1); i++){
        q[x][i] = q[x][i + r];
    }
    k[x] -= r;
    k[y] += r;
}
int main(){
    int n;
    cin >> n;
    int totlen = 0;
    for (int i = 1; i <= n; i++){
        cin >> k[i];
        totlen += k[i];
        for (int j = 1; j <= k[i]; j++) cin >> q[i][j];
    }
    int cnt1 = 0, cnt2 = 0;
    int maxval = 0, pos_da = 0, pos_xiao = 0, mu_biao = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= k[j]; j++){
            if (q[i][j] > maxval){
                maxval = q[i][j];
                pos_da = i;
                pos_xiao = j;
            }
        }
    }
    if (pos_xiao != k[pos_da]){
        cnt1++;
        jiao_huan(pos_da, ++n, pos_xiao);
        mu_biao = n;
    }
    else mu_biao = pos_da;
        // for (int i = 1; i <= n; i++){
        //     if (k[i] == 0) continue;
        //     for (int j = 1; j <= k[i]; j++){
        //         cout << q[i][j] << ' ';
        //     }
        //     cout << endl;
        // }
        // cout << endl;
    for (int solved = 1; solved < totlen; solved++){
        maxval = 0, pos_da = 0, pos_xiao = 0;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= k[i]; j++){
                if (i == mu_biao && solved > k[mu_biao] - j) continue;
                // cout << i << ' ' << j << ' ' << q[i][j] << endl;
                if (q[i][j] > maxval){
                    maxval = q[i][j];
                    pos_da = i;
                    pos_xiao = j;
                }
            }
        }
        // cout << pos_da << ' ' << pos_xiao << endl;
        // cout << k[mu_biao] - solved << endl;
        if (pos_da == mu_biao && pos_xiao == k[mu_biao] - solved) continue;
        if (k[mu_biao] != solved) cnt1++;
        else jiao_huan(mu_biao, ++n, k[mu_biao] - solved);
        if (pos_da == mu_biao){
            jiao_huan(n, mu_biao, pos_xiao);
        }
        else{
            cnt2++; 
            jiao_huan(pos_da, mu_biao, pos_xiao); 
        }
        // for (int i = 1; i <= n; i++){
        //     if (k[i] == 0) continue;
        //     for (int j = 1; j <= k[i]; j++){
        //         cout << q[i][j] << ' ';
        //     }
        //     cout << endl;
        // }
        // cout << endl;
    }
    cout << cnt1 << ' ' << cnt2;
    return 0;
}