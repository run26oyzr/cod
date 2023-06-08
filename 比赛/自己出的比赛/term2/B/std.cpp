#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
const int mod = 998244353;
int c[maxn];
int book[maxn], sum[maxn], num[maxn], size[maxn];
int n, q;
int getsum(int l, int r){
    return ((l + r) * (r - l + 1) / 2) % mod;
}
int tot = 0;
void init(){
    int L, R;
    for(L = 1; L <= n; L = R + 1){
        ++tot;
		R = n / (n / L);
        num[tot] = L;
        size[tot] = R - L + 1;
        book[n / L] = tot;
		for(int j = L; j <= R; j++){
            sum[tot] = (sum[tot] + j * c[j]) % mod;
        }
	}
    int last;
    for(int i = n; i >= 1; i--){
        if(book[i] != 0) last = book[i];
        book[i] = last;
    }
}
void change(int l, int r, int val){
    int R = book[l], L = book[r];
    if(n / num[L] > r) L++;
    // cout << "LR:" << L << ' ' << R << endl;
    for(int i = L; i <= R; i++){
        // cout << "sum:" << num[i] << ' ' << num[i] + size[i] - 1 << ' ' << endl;
        sum[i] = (sum[i] + getsum(num[i], num[i] + size[i] - 1) * val) % mod;
    }
}
int query(int l, int r){
    int R = book[l], L = book[r];
    if(n / num[L] > r) L++;
    // cout << "LR:" << L << ' ' << R << endl;
    int res = 0;
    for(int i = L; i <= R; i++){
        res = (res + sum[i]) % mod;
    }
    return res;
}
signed main(){
    cin >> n >> q;
    for(int i = 1; i <= n; i++) scanf("%lld", &c[i]);
    init();
    int opt, l, r, val;
    while(q--){
        scanf("%lld %lld %lld", &opt, &l, &r);
        if(opt == 1){
            scanf("%lld", &val);
            change(l, r, val);
        }else{
            printf("%lld\n", query(l, r));
        }
        // for(int i = 1; i <= tot; i++) cout << sum[i] << ' ';
        // cout << endl;
    }
    return 0;
}