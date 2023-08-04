#include <bits/stdc++.h>
using namespace std;
const int maxn = 6 * 1e5 + 5, maxlog = 25;
int ch[maxn * maxlog][2], cnt[maxn * maxlog];
int rt[maxn], tot;
void add(int pre, int id, int x){
    int p = id;
    for (int i = maxlog - 1; i >= 0; i--){
        int y = (x >> i) & 1;
        cnt[p] = cnt[pre] + 1;
        // if (i <= 4) cout << (1 << i) << ' ' << y << ' ' << p << ' ' << cnt[p] << endl;
        ch[p][y ^ 1] = ch[pre][y ^ 1];
        ch[p][y] = ++tot;
        pre = ch[pre][y];
        p = ch[p][y]; 
    }
    cnt[p] = cnt[pre] + 1;
}
int solve(int l, int r, int x){
    int res = 0;
    for (int i = maxlog - 1; i >= 0; i--){
        int y = (x >> i) & 1;
        // if (i <= 2) cout << (1 << i) << ' ' << cnt[ch[r][y ^ 1]] << ' ' << cnt[ch[l][y ^ 1]] << endl;
        // if (i <= 2) cout << (1 << i) << ' ' << ch[r][y ^ 1] << ' ' << ch[l][y ^ 1] << endl;
        // if (i <= 2) cout << (1 << i) << ' ' << y << ' ' << l << ' ' << r << endl;
        if (cnt[ch[r][y ^ 1]] > cnt[ch[l][y ^ 1]])
            l = ch[l][y ^ 1], r = ch[r][y ^ 1], res += (1 << i);
        else
            l = ch[l][y], r = ch[r][y];
    }
    return res;
}
int a[maxn];
int main(){
    int n, m;
    cin >> n >> m;
    int x;
    rt[0] = ++tot;
    add(0, rt[0], 0);
    for (int i = 1; i <= n; i++){
        cin >> x;
        a[i] = a[i - 1] ^ x;
        rt[i] = ++tot;
        add(rt[i - 1], rt[i], a[i]);
    }
    char c;
    int l, r;
    while(m--){
        cin >> c;
        if (c == 'A'){
            cin >> x;
            n++;
            a[n] = a[n - 1] ^ x;
            rt[n] = ++tot;
            add(rt[n - 1], rt[n], a[n]);
        }else{
            cin >> l >> r >> x;
            // cout << "x: " << (a[n] ^ x) << endl;
            l--; r--;
            if (l == 0) cout << solve(0, rt[r], a[n] ^ x) << endl;
            else cout << solve(rt[l - 1], rt[r], a[n] ^ x) << endl;
        }
    }
    // for (int i = 1; i <= n; i++) cout << a[i] << ' ';
    return 0;
} 