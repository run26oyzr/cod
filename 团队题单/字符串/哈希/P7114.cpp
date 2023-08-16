#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = (1 << 20) + 5;
int n;
char s[maxn];
int z[maxn];
void getZ(){
    memset(z, 0, sizeof(z));
    int L = 1, R = 0;
    z[1] = n;
    for (int i = 2; i <= n; i++){
        if (i <= R) z[i] = min(z[i - L + 1], R - i + 1);
        while (i + z[i] <= n && s[i + z[i]] == s[1 + z[i]]) z[i]++;
        if (i + z[i] - 1 >= R){
            L = i;
            R = i + z[i] - 1;
        }
    }
}
int tree[30];
int lowbit(int x) {return x & (-x);}
void add(int id, int val = 1){
    while (id <= 27){
        tree[id] += val;
        id += lowbit(id);
    }
}
int sum(int id){
    int res = 0;
    while (id >= 1){
        res += tree[id];
        id -= lowbit(id);
    }
    return res;
}
int cnt[30];
int f1[maxn], f2[maxn]; //f1:1~i字串中出现奇数次字符的数量; f2:i~n字串中...
void init(){
    memset(tree, 0, sizeof(tree));
    f1[0] = 0; f2[n + 1] = 0;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n; i++){
        cnt[s[i] - 'a'] ^= 1;
        if (cnt[s[i] - 'a']) f1[i] = f1[i - 1] + 1;
        else f1[i] = f1[i - 1] - 1;
    }
    memset(cnt, 0, sizeof(cnt));
    for (int i = n; i >= 1; i--){
        cnt[s[i] - 'a'] ^= 1;
        if (cnt[s[i] - 'a']) f2[i] = f2[i + 1] + 1;
        else f2[i] = f2[i + 1] - 1;
    }
}
signed main(){
    int T;
    cin >> T;
    while (T--){
        cin >> s + 1;
        n = strlen(s + 1);
        init();
        getZ();
        for (int i = 1; i <= n; i++)
            if (i + z[i + 1] == n)
                z[i + 1]--;
        int ans = 0;
        add(f1[1] + 1);
        for (int i = 2; i <= n - 1; i++){
            int maxi = z[i + 1] / i + 1;
            ans += ((maxi + 1) / 2) * sum(f2[i + 1] + 1) + (maxi / 2) * sum(f2[1] + 1);
            add(f1[i] + 1);
        }
        cout << ans << endl;
    }
    return 0;
}