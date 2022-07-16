#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e5 + 5;
int v[maxn], a[maxn], tree[maxn];
int n, m;
struct node{
    int id, val;
    bool operator < (const node T)const{
        return T.val < val;
    }
}b[maxn], c[maxn];
int lowbit(int x) {return x & (-x);}
void add (int id, int val = 1){
    while (id <= n){
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
signed main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> b[i].val;
        b[i].id = i;
    }
    for (int i = 1; i <= n; i++){
        cin >> c[i].val;
        c[i].id = i;
    }
    sort(b + 1, b + n + 1);
    sort(c + 1, c + n + 1);
    for (int i = 1; i <= n; i++){
        a[b[i].id] = c[i].id; 
    }
    int ans = 0;
    for (int i = n; i >= 1; i--){
        ans += sum(a[i] - 1);
        ans %= (int)1e8 - 3;
        add(a[i], 1);
    }
    cout << ans;
    system("Pause");
}